#include "hnparser.h"

int HNParser::parseStream(std::istream& instream, bool acceptEmpty){
    FUN();

    if (!instream.good()){
        LOGE("Stream for parsing is bad!");
        return -1;
    }

    std::string buf;
    //While the stream is not ended
    while (!instream.eof() && !instream.bad()){
        getline(instream, buf);
        if (!buf.empty()){

            //Create a new line instance and let it parse from the line
            Parseline newLine;
            newLine.parseFromLine(buf, '<', '>', acceptEmpty);
            this->_lines.push_back(newLine);
            LOGF("Parsed line \"" + this->_lines.back().toParseLine('<', '>') + "\" lines: " + std::to_string(this->_lines.size()));
        }
    }

    return this->_lines.size();
}
