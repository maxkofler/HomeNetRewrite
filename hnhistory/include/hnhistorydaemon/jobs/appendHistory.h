#ifndef __APPENDHISTORY_H__
#define __APPENDHISTORY_H__

#include "hnhistorydaemon/job.h"
#include "hnvalue.h"

namespace Jobs{

	class AppendHistory : public Job{

	public:
		AppendHistory(HNHistoryDaemon*, hnvalue_t value);

		void					run() override;

	private:
		hnvalue_t				_value;
		std::string				_path;
		std::string				_directory;

	};

};

#endif
