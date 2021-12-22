#include <QCoreApplication>
#include <QCommandLineParser>
#include <QTimer>
#include <QThread>

#include "log.h"

#include "homenet.h"
#include "homenet_status.h"

Log::Log* hlog;

homenet_status stateHomeNet;

void parseArgs(QCoreApplication& app);

int main(int argc, char** argv)
{
	stateHomeNet.running = true;

	bool ret;
	while(stateHomeNet.running){
		hlog = new Log::Log(Log::I);
		hlog->setFeature(Log::FEATURE_PRINTFUNNAMES, false);
		{
			FUN();

			QCoreApplication app(argc, argv);

			parseArgs(app);

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

void parseArgs(QCoreApplication& app){
	QCommandLineParser parser;

	QCommandLineOption op_verbose("v", "Enable verbose output, a little more verbose than default");
	QCommandLineOption op_debugVerbose("debugVerbose", "Enable debug output, prints file operations and everything except function calls (cleanups will stuff console)");
	QCommandLineOption op_callVerbose("callVerbose", "Enable call verbose output, this prints all the function calls (cleanups will stuff console)");

	{//Set up parser
		parser.setApplicationDescription("HomeNet server");
		parser.addHelpOption();
	}

	{//Add options
		parser.addOption(op_verbose);
		parser.addOption(op_debugVerbose);
		parser.addOption(op_callVerbose);
	}
	
	parser.process(app);

	{//Process options
		{//"-v"
			if (parser.isSet(op_verbose)){
				LOGI("Enabling verbose output");
				hlog->setLevel(Log::D);
			}
		}

		{//"--debugVerbose"
			if (parser.isSet(op_debugVerbose)){
				LOGI("Enabling debug verbose output");
				hlog->setLevel(Log::MEM);
			}
		}

		{//"--callVerbose"
			if (parser.isSet(op_callVerbose)){
				LOGI("Enabling call verbose output");
				hlog->setLevel(Log::A);
			}
		}
	}
}