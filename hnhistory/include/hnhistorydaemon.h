#ifndef __HNHISTORYDAEMON_H__
#define __HNHISTORYDAEMON_H__

#include <QThread>

#include "hnconfig.h"
#include "hnvalue.h"
#include "valuehistory.h"
#include "hnhistorydaemon/job_type.h"
#include "hnhistorydaemon/args.h"

#include <mutex>

/**
 * @brief This class implements a daemon for managing history access
 * It will spawn a thread for every operation until the thread budget is filled
 * Computing on threads will not always scale as expected, some tasks do not benefit from threading
 */
class HNHistoryDaemon : public QThread{
	Q_OBJECT
public:

	HNHistoryDaemon();
	~HNHistoryDaemon();

	/**
	 * @brief	Initializes the history daemon
	 * @param	config			The config to get configs of
	 */
	bool						init(HNConfig& config);

	/**
	 * @brief	Stops the event loop and releases all resources
	 * @brief	Gets called by destructor
	 */
	bool						stop();

	/**
	 * @brief	Releases the history daemon from sleep
	 * @note	If there is nothing to do it immediately returns to sleep
	 */
	void						release();

	/**
	 * @brief	Queues a history read, emits onHistoryReady() once finished
	 * @param	value			The value to get the history from
	 */
	bool						getHistory(hnvalue_t value);

	/**
	 * @brief	The daemons main execution loop, gets run asynchronously
	 */
	void						run() override;

signals:

	/**
	 * @brief	Gets emited once a value history is ready
	 * @param	value			The value the history has been read of
	 * @param	history			A history object containing the history to access
	 */
	void						onHistoryRead(hnvalue_t value, ValueHistory history);

private:

	/**
	 * @brief	The maximum amount of threads this daemon can spawn before having to queue tasks
	 */
	size_t                      _maxThreads;

	/**
	 * @brief	Whether the event loop should keep on running
	 */
	bool						_run;

	/**
	 * @brief	As long as it is locked the event loop does nothing and waits for a command
	 * @note	Just unlocking is valid, DO NOT lock it
	 */
	std::mutex					_m_eventLoop;

	/**
	 * @brief	Is locked if an operation is pending and it is not allowed to write to event loop variables
	 */
	std::mutex					_m_reserved;

	/**
	 * @brief	Hold the type for the job that is to execute next
	 */
	job_type					_curJob_type;

	/**
	 * @brief	The argument list for the current job
	 */
	Args						_curJob_args;

	/**
	 * @brief	Holds a map of currently running jobs
	 */
	std::map<int, QThread*>		_running_jobs;
};

#endif
