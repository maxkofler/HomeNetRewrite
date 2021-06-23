#include "hnparser.h"

int HNParser::parseStream(std::istream& instream){
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
            LOGF("Parsing line \"" + buf + "\"");
            Parseline* newLine = new Parseline();
            newLine->parseFromLine(buf, '<', '>');
            this->_lines.push_back(newLine);
        }
    }

    return this->_lines.size();
}
