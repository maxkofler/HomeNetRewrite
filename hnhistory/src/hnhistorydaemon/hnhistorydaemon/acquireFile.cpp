#include "hnhistorydaemon.h"
#include "log.h"

bool HNHistoryDaemon::acquireFile(std::string path){
	FUN();

	{
		std::lock_guard<std::mutex> guard (this->_m_file_mutexes);

		std::mutex *mutex;
		
		{//Get the mutex
			if (this->_file_mutexes.count(path) > 0){
				//Mutex exists
				mutex = this->_file_mutexes[path];
			}else{
				mutex = new std::mutex;
				this->_file_mutexes[path] = mutex;
			}
		}
		
		//Lock the mutex
		mutex->lock();
	}

	return true;
}
