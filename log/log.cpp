#include "log.h"

#include <iostream>


Log::Log(uint level){
    this->_curLevel = level;
}

void Log::log(std::string text, uint level){
    if (level <= _curLevel){
        std::cout.flush();
        std::cout << "(" << level << ")";
        std::cout << "[" << this->_functionStack.back()->name() << "]>>" << text << std::endl;
        std::cout.flush();
    }
}

void Log::flush(){
    std::cout.flush();
}

void Log::push(LogFunction *fun){
    this->_functionStack.push_back(fun);
}

void Log::pop(){
    this->_functionStack.pop_back();
}
