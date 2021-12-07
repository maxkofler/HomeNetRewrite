#ifndef GETHISTORY_H
#define GETHISTORY_H

#include "hnhistorydaemon/job.h"

namespace Jobs{

	class GetHistory : public Job{

	public:
		GetHistory(Args args);

		void					run() override;

	};

};

#endif
