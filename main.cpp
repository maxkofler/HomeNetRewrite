#include <QCoreApplication>
#include <QTimer>
#include <QThread>

#include "log.h"

#include "homenet.h"
#include "homenet_status.h"

Log::Log* hlog;

homenet_status stateHomeNet;

int main(int argc, char** argv)
{
	stateHomeNet.running = true;

	bool ret;
	while(stateHomeNet.running){
		hlog = new Log::Log(Log::D);
		hlog->setFeature(Log::FEATURE_PRINTFUNNAMES, false);
		{
			FUN();

			QCoreApplication app(argc, argv);

			HomeNet hn(&app);

			QObject::connect(&hn, &HomeNet::stop, &app, &QCoreApplication::quit);

			QTimer::singleShot(0, &hn, &HomeNet::start);

			ret = app.exec();
		}

		LOGU("HomeNet server stopped, good bye!");

		delete hlog;

		if (stateHomeNet.running){
			//Wait some time
			QThread::sleep(2);
		}
	}

	return ret;
}
