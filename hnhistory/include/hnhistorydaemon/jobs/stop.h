#ifndef __STOP_H__
#define __STOP_H__

#include "hnhistorydaemon/job.h"

/**
 * @brief	This job stops the history daemon on execution
 */

namespace Jobs{

	class Stop : public Job{
	Q_OBJECT

	public:
		Stop(HNHistoryDaemon*);

		void					run() override;

	signals:
		void					stop();
	};

};

#endif
