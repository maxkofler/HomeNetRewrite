#ifndef LOG_H
#define LOG_H

class Log;
#include "logfunction.h"

extern Log* log;

#define FUN() LogFunction logfun(__PRETTY_FUNCTION__, log)

#define LOGE(text) log->log(text, Log::E);
#define LOGW(text) log->log(text, Log::W);
#define LOGI(text) log->log(text, Log::I);
#define LOGD(text) log->log(text, Log::D);
#define LOGF(text) log->log(text, Log::F);
#define LOG(text, level) log->log(text, level);

#include <vector>
#include <string>

class Log
{
public:
    Log();

    const static int E = 0;
    const static int W = 1;
    const static int I = 2;
    const static int D = 3;
    const static int F = 4;

    void                        push(LogFunction*);

    void                        pop();

    void                        log(std::string text, int level);

private:
    std::vector<LogFunction* >  _functionStack;
};
#endif // LOG_H
