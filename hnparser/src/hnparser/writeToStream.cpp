#include "hnparser.h"

int HNParser::writeToStream(std::ostream &outstream){
    FUN();

    if (outstream.bad()){
        LOGE("Output stream is bad!");
        return -1;
    }

    int linesWritten = 0;
    for (auto i : this->_lines){
        outstream << i.toParseLine('<', '>') << std::endl;
        LOGF("Written \"" + i.toParseLine('<', '>') + "\" to stream");
        linesWritten++;
    }

    return linesWritten;
}
