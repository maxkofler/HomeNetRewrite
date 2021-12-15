#include "hnhistorydaemon/jobs/appendHistory.h"
#include "log.h"

#include <fstream>
#include <filesystem>

void Jobs::AppendHistory::run(){
	FUN();

	this->_historyDaemon->acquireFile(this->_path);
	{
		LOGD("Appending history file \"" + this->_path + "\"");
		std::filesystem::create_directories(this->_directory);

		std::ofstream file;
		file.open(this->_path, std::ios::app);

		if (!file.is_open()){
			LOGE("Failed to open file \"" + this->_path + "\"");
			file.close();
		} else {
			file << "<" << this->_value.syncTime << ">";
			file << "<" << this->_value.datatype << ">";
			file << "<" << this->_value.value << ">" << std::endl;
			file.close();
		}
	}

	this->_historyDaemon->releaseFile(this->_path);
	this->finished();
}
