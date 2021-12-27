#ifndef __JOB_H__
#define __JOB_H__

class Job;

#include <QThread>

#include <string>
#include <vector>

#include "job_type.h"
#include "exceptions.h"
#include "hnhistorydaemon.h"

class Job : public QThread{
	Q_OBJECT

public:
	explicit Job(HNHistoryDaemon* daemon, job_type type);

	/**
	 * @brief	Returns the job's id
	 */
	size_t						getId(){return this->_id;}

	void						finished();
	bool						isRunning(){return this->_is_running;}

	friend class HNHistoryDaemon;
signals:

	/**
	 * @brief	Gets emitted once the job has finished its work and is ready to get killed
	 */
	void						jobFinished(size_t id);

#ifndef FRIEND_JOB
protected:
#endif

	bool						_is_running = false;
	HNHistoryDaemon*			_historyDaemon;

#ifndef FRIEND_JOB
private:
#endif

	job_type					_job_type;
	size_t						_id;
};

#endif
