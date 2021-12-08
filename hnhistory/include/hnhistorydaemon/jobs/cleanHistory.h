#ifndef __CLEANHISTORY_H__
#define __CLEANHISTORY_H__

#include <fstream>
#include <string>

#include "hnhistorydaemon/job.h"
#include "hnvalue.h"

namespace Jobs{

	class CleanHistory : public Job{

	public:
		CleanHistory(HNHistoryDaemon*, std::string path);

		void					run() override;

	private:

		std::fstream			_historyFile;
		std::string				_path;
	};

};

#endif
