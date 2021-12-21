#include "../t_pymodule.h"
#include <gtest/gtest.h>
#include <fstream>

TEST(PyModule, Remove_OK){
	//Create module
	std::ofstream outFile;
	outFile.open("myModule.py", std::ios::out);
	outFile << "def hello():\n" << "\tprint(\"Hello!\")\n";
	outFile.close();

	HNPython hnpython;
	hnpython.startPython();
	hnpython.appendPath(".");
	PyModule module(&hnpython);

	ASSERT_FALSE(module._is_imported);

	ASSERT_TRUE(module.import("myModule"));

	module.remove();
	EXPECT_FALSE(module._is_imported);
}
