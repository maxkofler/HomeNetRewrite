#ifndef LOG_H
#define LOG_H

class Log;
#include "logfunction.h"

extern Log* hlog;

#define FUN() LogFunction logfun(__PRETTY_FUNCTION__, hlog)

#define LOGE(text) hlog->log(text, Log::E);
#define LOGW(text) hlog->log(text, Log::W);
#define LOGI(text) hlog->log(text, Log::I);
#define LOGD(text) hlog->log(text, Log::D);
#define LOGF(text) hlog->log(text, Log::F);
#define LOG(text, level) hlog->log(text, level);

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
