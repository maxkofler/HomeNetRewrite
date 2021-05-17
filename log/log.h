#ifndef LOG_H
#define LOG_H

class Log;
#include "logfunction.h"

extern Log hlog;

#define FUN() LogFunction logfun(__PRETTY_FUNCTION__, hlog)


#define LOGUE(text) hlog.log(text, Log::UE);
#define LOGUW(text) hlog.log(text, Log::UW);
#define LOGU(text) hlog.log(text, Log::U);
#define LOGP(text) hlog.log(text, Log::P);
#define LOGE(text) hlog.log(text, Log::E);
#define LOGW(text) hlog.log(text, Log::W);
#define LOGI(text) hlog.log(text, Log::I);
#define LOGD(text) hlog.log(text, Log::D);
#define LOGF(text) hlog.log(text, Log::F);

#define LOGSP(level) hlog.startProgress(level);
#define LOGPP(text, level) hlog.printProgress(text, level);
#define LOGEP(level) hlog.endProgress(level);

#define LOG(text, level) hlog.log(text, level);
#define FLUSH() hlog.flush();

#include <vector>
#include <string>

class Log
{
public:
    Log(uint level, bool printFunNames);

    const static int UE = 1;
    const static int UW = 2;
    const static int U = 3;
    const static int P = 4;
    const static int E = 5;
    const static int W = 6;
    const static int I = 7;
    const static int D = 8;
    const static int F = 9;

    const static int FUNCALLS = 75;
    const static int A = 100;

    void                        push(LogFunction*);

    void                        pop();

    void                        log(std::string text, uint level);

    void                        logw(std::string text, uint level);

    void                        startProgress(uint level);

    void                        printProgress(std::string text, uint level);

    void                        endProgress(uint level);

    void                        flush();

private:
    std::vector<LogFunction* >  _functionStack;
    uint                        _curLevel;

    bool                        _inProgress;

    bool                        _printFunNames;
};
#endif // LOG_H
