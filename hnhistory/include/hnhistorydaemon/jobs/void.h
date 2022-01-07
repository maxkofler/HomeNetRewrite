#ifndef __VOID_H__
#define __VOID_H__

#include "hnhistorydaemon/job.h"

/**
 * @brief	A job dedicated to 
 */

namespace Jobs{

	class Void : public Job{

	public:
		Void(HNHistoryDaemon*, int time);

		void					run() override;

	private:
		int						_waittime;

	};

};

#endif