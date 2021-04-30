#include "parser.h"

int Parser::parseFile(std::string path){
    FUN();

    //Open the file
    this->_curFile.open(path);

    //Check if the file was opened correctly
    if (this->_curFile.is_open()){

        //Holds the current line
        std::string buf;

        //Read line by line until eof
        while(getline(this->_curFile, buf)){
            ParseBlock block;
            block.parseFromLine(buf);
            LOGF("Parsed line: " + block.toString());
            this->_entries.push_back(block);
        }

    }else{
        LOGE("Could not open file " + path);
        this->_curFile.close();
        return -1;
    }

    this->_curFile.close();

    return this->_entries.size();
}
