#include "../t_pymodule.h"
#include <gtest/gtest.h>
#include <fstream>
#include <iostream>

TEST(PyModule, Import_no_Python){
	HNPython hnpython;
	PyModule pyModule(&hnpython);

	ASSERT_FALSE(pyModule.import("myTestModule"));
}

TEST(PyModule, Import_wrong_name){
	HNPython hnpython;
	hnpython.startPython();

	PyModule module(&hnpython);
	EXPECT_FALSE(module.import("myWrongModule"));
}

TEST(PyModule, Import_OK){
	std::ofstream outFile;
	outFile.open("myModule.py", std::ios::out);
	outFile << "def hello():\n" << "\tprint(\"Hello!\")\n";
	outFile.close();

	HNPython hnpython;
	hnpython.startPython();
	hnpython.appendPath(".");
	PyModule module(&hnpython);

	EXPECT_TRUE(module.import("myModule"));
	std::cout.flush();
}

