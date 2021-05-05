#ifndef LOG_H
#define LOG_H

class Log;
#include "logfunction.h"

extern Log* hlog;

#define FUN() LogFunction logfun(__PRETTY_FUNCTION__, hlog)

#define LOGP(text) hlog->log(text, Log::P);
#define LOGE(text) hlog->log(text, Log::E);
#define LOGW(text) hlog->log(text, Log::W);
#define LOGI(text) hlog->log(text, Log::I);
#define LOGD(text) hlog->log(text, Log::D);
#define LOGF(text) hlog->log(text, Log::F);
#define LOG(text, level) hlog->log(text, level);
#define FLUSH() hlog->flush();

#include <vector>
#include <string>

class Log
{
public:
    Log(uint level);

    const static int P = 0;
    const static int E = 1;
    const static int W = 2;
    const static int I = 3;
    const static int D = 4;
    const static int F = 5;

    void                        push(LogFunction*);

    void                        pop();

    void                        log(std::string text, uint level);

    void                        flush();

private:
    std::vector<LogFunction* >  _functionStack;
    uint                        _curLevel;
};
#endif // LOG_H
