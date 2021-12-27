#include "parseline.h"

int Parseline::parseFromLine(std::string line, char opener, char closer, bool acceptEmpty){
    FUN();

	/*
    //Clear the current vector
    this->_blocks.clear();

    size_t pos1 = 0;
    size_t pos2 = 0;

    while(true){
        pos1 = line.find(opener, pos2);
        pos2 = line.find(closer, pos1);

        //If a block was found
        if (pos1 != std::string::npos && pos2 != std::string::npos){
            if (!line.substr(pos1+1, pos2-pos1-1).empty() || acceptEmpty){
                this->_blocks.push_back(line.substr(pos1+1, pos2-pos1-1));
                LOGF("Adding block \"" + this->_blocks.back() + "\"");
            }
        }else
            break;
    }
	*/

	//Clear old vector
	this->_blocks.clear();

	std::string curBlock;
	char curChar;

	for(size_t i = 0; i < line.length(); i++){
		curChar = line[i];

		if(curChar == opener){
			curBlock.clear();
		}else if(curChar == closer){
			if (acceptEmpty || !curBlock.empty())
				this->_blocks.push_back(curBlock);
		}else{
			curBlock += curChar;
		}
	}

    return this->_blocks.size();
}
