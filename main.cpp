#include <QCoreApplication>
#include <QTimer>

#include "log.h"

#include "homenet.h"

Log* hlog;

int main(int argc, char** argv)
{
    hlog = new Log(Log::I, false, true);
    FUN();

    QCoreApplication app(argc, argv);

    HomeNet hn(&app);

    QObject::connect(&hn, &HomeNet::stop, &app, &QCoreApplication::quit);

    QTimer::singleShot(0, &hn, &HomeNet::start);

    return app.exec();
}
