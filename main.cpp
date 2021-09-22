#include <QCoreApplication>
#include <QTimer>
#include <QThread>

#include "log.h"

#include "homenet.h"
#include "homenet_status.h"

Log* hlog;

homenet_status stateHomeNet;

int main(int argc, char** argv)
{
    stateHomeNet.running = true;

    bool ret;
    while(stateHomeNet.running){
        hlog = new Log(Log::I, false, true);
        {
            FUN();

            QCoreApplication app(argc, argv);

            HomeNet hn(&app);

            QObject::connect(&hn, &HomeNet::stop, &app, &QCoreApplication::quit);

            QTimer::singleShot(0, &hn, &HomeNet::start);

            ret = app.exec();
        }
        delete hlog;

        if (stateHomeNet.running){
            //Wait some time
            QThread::sleep(2);
        }
    }    

    return ret; 
}
