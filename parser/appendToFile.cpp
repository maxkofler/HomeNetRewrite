#include "parser.h"

#include <fstream>

bool Parser::appendToFile(std::string path, ParseBlock entry){
    FUN();
    std::ofstream file;

    file.open(path, std::ios::app);

    //Check if the file is writeable
    if (!file.is_open()){
        LOGE("Error in opening file \"" + path + "\" for append!");
        file.close();
        return false;
    }

    for (size_t i = 0; i < entry.getBlockCount(); i++){

        //Check again for file existance
        if (file.bad()){
            LOGE("File went bad on write attempt!");
            file.close();
            return false;
        }

        file << "<" << entry.getBlockAt(i) << ">";
    }

    //Check again for file existance
    if (file.bad()){
        LOGE("File went bad on write attempt!");
        file.close();
        return false;
    }

    file << std::endl;
    file.close();

    LOGF("Written entry " + entry.toString() + " to " + path + "!");

    return true;
}
