#include <QCoreApplication>
#include <QTimer>

#include <gtest/gtest.h>
#include "../t_hnhistorydaemon.h"

extern int glob_argc;
extern char** glob_argv;

/*
	This is a special test that checks if the history daemon hangs itself if there are loads of requests coming in
 */
TEST(HNHistoryDaemon, Spam){
	HNConfig config;
	HNHistoryDaemon daemon;
	QCoreApplication app(glob_argc, glob_argv);

	{//Set history dir
		Parseline line;
		line.parseFromLine("<historydir><./>", '<', '>');
		config._parser.append(line);
	}
	
	daemon.init(config);

	ASSERT_EQ(2, daemon._maxThreads);

	daemon.start();

	QTimer::singleShot(2, &daemon, &HNHistoryDaemon::stop);

	app.exec();
}