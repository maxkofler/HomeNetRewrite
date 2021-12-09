#ifndef __CLEANHISTORY_H__
#define __CLEANHISTORY_H__

#include <fstream>
#include <string>

#include "hnhistorydaemon/job.h"
#include "hnvalue.h"

namespace Jobs{

	class CleanHistory : public Job{

	public:
		CleanHistory(HNHistoryDaemon*, hnvalue_t* value);

		void					run() override;

	private:

		std::fstream			_historyFile;
		hnvalue_t*				_value;
		std::string				_path;
	};

};

#endif
