#include <gtest/gtest.h>
#include "../t_hnhistorydaemon.h"

TEST(HNHistoryDaemon, Init_Default_Threads){
	HNConfig config;
	HNHistoryDaemon daemon;

	{//Set history dir
		Parseline line;
		line.parseFromLine("<historydir><./>", '<', '>');
		config._parser.append(line);
	}
	
	daemon.init(config);

	EXPECT_EQ(2, daemon._maxThreads);
}

TEST(HNHistoryDaemon, Init_Specified_Threads){
	HNConfig config;
	HNHistoryDaemon daemon;

	{//Set threads
		Parseline line;
		line.parseFromLine("<historyThreads><100>", '<', '>');
		config._parser.append(line);
	}

	{//Set history dir
		Parseline line;
		line.parseFromLine("<historydir><./>", '<', '>');
		config._parser.append(line);
	}

	ASSERT_TRUE(daemon.init(config));

	EXPECT_EQ(100, daemon._maxThreads);
}