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
            //First of all cut all contents after a '#':
            {
                size_t pos_h = buf.find('#');
                //If the symbol was found
                if (pos_h != std::string::npos){
                    std::string oldBuf = buf;
                    if (pos_h > 1)
                        buf = buf.substr(0, pos_h-1);
                    else
                        buf = buf.substr(0, pos_h);
                    LOGD("Cut from \"" + oldBuf + "\" to \"" + buf + "\", ignoring the rest of this line...");
                }
            }

            //Once the line was cut to its size, parse it into blocks
            ParseBlock block;
            block.parseFromLine(buf);

            //Check whether the parse was successfull
            if (block.getBlockCount() > 0){
                //And take it into the list
                LOGF("Parsed line: " + block.toString());
                this->_entries.push_back(block);
            }
        }

    }else{
        LOGE("Could not open file " + path);
        this->_curFile.close();
        return -1;
    }

    this->_curFile.close();

    return this->_entries.size();
}
