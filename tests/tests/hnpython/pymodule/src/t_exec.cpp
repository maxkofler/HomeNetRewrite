#include "../t_pymodule.h"
#include <gtest/gtest.h>
#include <fstream>

//Python not running
TEST(PyModule, Exec_ES1){
	HNPython hnpython;
	PyModule module(&hnpython);

	EXPECT_EQ("ES1", module.exec("", nullptr));
}

//Module not imported
TEST(PyModule, Exec_ES2){
	HNPython hnpython;
	hnpython.startPython();
	PyModule module(&hnpython);
	PyArgs args(0);

	EXPECT_EQ("ES2", module.exec("", &args));
}

//Python function object failed
TEST(PyModule, Exec_ES3_ES4){
	std::ofstream outFile;
	outFile.open("myModule.py", std::ios::out);
	outFile.close();

	HNPython hnpython;
	hnpython.startPython();
	hnpython.appendPath(".");
	PyModule module(&hnpython);
	PyArgs args(0);

	ASSERT_TRUE(module.import("myModule"));
	std::string ret = module.exec("myFunction", &args);

	if (ret != "ES3" && ret != "ES4"){
		FAIL();
	}
}

TEST(PyModule, Exec_OK){
	std::ofstream outFile;
	outFile.open("myModule.py", std::ios::out);
	outFile << "def hello():\n" << "\tprint(\"Hello from Python!\")\n";
	outFile.close();

	HNPython hnpython;
	hnpython.startPython();
	hnpython.appendPath(".");
	PyModule module(&hnpython);
	PyArgs args(0);

	ASSERT_TRUE(module.import("myModule"));
	EXPECT_EQ("V", module.exec("hello", &args));
}
