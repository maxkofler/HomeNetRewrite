#include "log.h"

#include <iostream>


Log::Log(){
}

void Log::log(std::string text, int level){
    std::cout << "[" << this->_functionStack.back()->name() << "]>>" << text << std::endl;
}

void Log::push(LogFunction *fun){
    this->_functionStack.push_back(fun);
}

void Log::pop(){
    this->_functionStack.pop_back();
}
