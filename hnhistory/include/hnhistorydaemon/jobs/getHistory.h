#ifndef GETHISTORY_H
#define GETHISTORY_H

#include "hnhistorydaemon/job.h"
#include "hnvalue.h"

namespace Jobs{

	class GetHistory : public Job{

	public:
		GetHistory(HNHistoryDaemon*, hnvalue_t value);

		void					run() override;

	};

};

#endif
