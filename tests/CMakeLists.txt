cmake_minimum_required(VERSION 3.5)
project(HomeNetTests)

include_directories(
	../hnconfig/include
	../hndrivers/include
	../hnhistory/include
	../hnnetworking/include
	../hnparser/include
	../hnpython/include
	../homenet/include
)

add_subdirectory(tests/Sanity)