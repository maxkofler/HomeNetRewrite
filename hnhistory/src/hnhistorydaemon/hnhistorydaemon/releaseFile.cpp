#include "hnhistorydaemon.h"
#include "log.h"

bool HNHistoryDaemon::releaseFile(std::string path){
	FUN();

	{
		std::lock_guard<std::mutex> lock (this->_m_file_mutexes);
		if (this->_file_mutexes.count(path) <= 0){
			LOGD(this->_cN + "File \"" + path + "\" was never acquired");
			return false;
		}

		if (this->_file_mutexes[path]->try_lock()){
			this->_file_mutexes[path]->unlock();
			LOGD(this->_cN + "File \"" + path + "\" was never acquired (not locked)");
			return false;
		}

		//Unlock the file mutex and so release the file
		this->_file_mutexes[path]->unlock();
	}

	emit fileReleased(path);

	return true;
}
