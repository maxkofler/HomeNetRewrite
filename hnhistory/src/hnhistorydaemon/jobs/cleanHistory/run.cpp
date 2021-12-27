#include "hnhistorydaemon/jobs/cleanHistory.h"
#include "hnparser.h"

#include "log.h"

#include <fstream>

static std::string fN = "Cleaning history: ";

void Jobs::CleanHistory::run(){
	FUN();
	this->_is_running = true;

	this->_historyDaemon->acquireFile(this->_path);

	LOGD(fN + "Starting cleanup of history file \"" + this->_path + "\"");

	{
		HNParser* historyParser = new HNParser();
		int linesParsed = 0;

		{//Open the file for reading
			this->_historyFile.open(this->_path, std::ios::in);
			if (!this->_historyFile.is_open() || this->_historyFile.bad()){
				LOGE(fN + "History file " + this->_path + " could not be opened!");
				this->_historyFile.close();
				this->_historyDaemon->releaseFile(this->_path);
				this->finished();
				return;
			}
		}

		{//Parse the file
			LOGF(fN + "Parsing file " + this->_path + "...");
			linesParsed = historyParser->parseStream(this->_historyFile);
			this->_historyFile.close();
			LOGD(fN + "Done parsing file " + this->_path + ": " + std::to_string(linesParsed) + " lines parsed");
		}

		std::vector<Parseline>* lines = historyParser->getLinesPointer();
		std::vector<Parseline>* newLines = new std::vector<Parseline>();
		newLines->reserve(lines->size());

		{//Clean up history
			LOGD(fN + "Entering cleaning stage");
			auto start = std::chrono::high_resolution_clock::now();

			Parseline curLine;
			newLines->push_back(lines->at(0));
			for (size_t i = 1; i < lines->size()-1; i++){
				curLine = lines->at(i);
				if (   !(   curLine.getBlock(2) == lines->at(i-1).getBlock(2) &&
							curLine.getBlock(2) == lines->at(i+1).getBlock(2))){
								newLines->push_back(curLine);
							}
			}
			newLines->push_back(lines->at(lines->size()-1));
			newLines->shrink_to_fit();

			auto stop = std::chrono::high_resolution_clock::now();
			auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
			LOGD(fN + "Finished cleaning, took " + std::to_string(duration.count()) + " µs");
		}

		{//We can delete the old lines from the parser
			historyParser->clear();
			lines = nullptr;
			historyParser->setLines(*newLines);
			delete newLines;
			newLines = nullptr;
		}

		{//Open the file for writing
			this->_historyFile.open(this->_path, std::ios::out);
			if (!this->_historyFile.is_open() || this->_historyFile.bad()){
				LOGE(fN + "History file " + this->_path + " could not be opened!");
				this->_historyFile.close();
				this->_historyDaemon->releaseFile(this->_path);
				this->finished();
				return;
			}
		}

		{//Write back results
			int outLines = historyParser->writeToStream(this->_historyFile);
			LOGI(	fN + "History cleanup of \"" + this->_path + "\" done: " +
					"Written back " + std::to_string(outLines) + " lines, " + 
					std::to_string(linesParsed - outLines) + " less than read");
			this->_historyFile.close();
		}

		delete historyParser;
	}

	LOGD(fN + "Finished cleanup of history file \"" + this->_path + "\"");

	this->_historyDaemon->releaseFile(this->_path);
	this->finished();
}
