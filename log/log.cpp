#include "log.h"

#include <iostream>


Log::Log(uint level, bool printFunNames){
    this->_curLevel = level;
    this->_printFunNames = printFunNames;
}

void Log::log(std::string text, uint level){
    if (level <= _curLevel){
        std::cout.flush();
        if (this->_printFunNames){
            std::cout << "(" << level << ")";
            std::cout << "[" << this->_functionStack.back()->name() << "]>>";
        }
        std::cout << text << std::endl;
        std::cout.flush();
    }
}

void Log::logw(std::string text, uint level){
    if (level <= _curLevel){
        std::cout.flush();
        if (this->_printFunNames){
            std::cout << "(" << level << ")";
            std::cout << "[" << this->_functionStack.back()->name() << "]>>";
        }
        std::cout << text;
        std::cout.flush();
    }
}

inline void Log::flush(){
    std::cout.flush();
}

void Log::push(LogFunction *fun){
    this->_functionStack.push_back(fun);
}

void Log::pop(){
    this->_functionStack.pop_back();
}


void Log::startProgress(uint level){
    if (level <= _curLevel)
        this->_inProgress = true;
}

void Log::printProgress(std::string text, uint level){
    if (level <= _curLevel){
        this->logw(text, level);
        std::cout << "\r";
        this->flush();
    }
}

void Log::endProgress(uint level){
    if (level <= _curLevel){
        std::cout << std::endl;
        this->_inProgress = false;
    }
}
