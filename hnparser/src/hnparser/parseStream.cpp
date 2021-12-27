#include "hnparser.h"

#include <chrono>

int HNParser::parseStream(std::istream& instream, bool acceptEmpty){
    FUN();

    if (!instream.good()){
        LOGE("Stream for parsing is bad!");
        return -1;
    }

    std::string buf;
	uint32_t time_entries = 0;
    //While the stream is not ended
	auto start = std::chrono::high_resolution_clock::now();
    while (!instream.eof() && !instream.bad()){
        getline(instream, buf);
        if (!buf.empty()){
            //Create a new line instance and let it parse from the line
            Parseline newLine;
            newLine.parseFromLine(buf, '<', '>', acceptEmpty);
            this->_lines.push_back(newLine);
			time_entries++;
        }
    }

	auto stop = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
	uint32_t avg = duration.count() / time_entries;
	LOGD(	"Parsing of a line took " + std::to_string(avg) + " µs in average, total for " + 
			std::to_string(time_entries) + " lines: " + std::to_string(duration.count()) + " µs");

    return this->_lines.size();
}
