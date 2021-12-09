#ifndef __HNHISTORYDAEMON_H__
#define __HNHISTORYDAEMON_H__

class HNHistoryDaemon;

#include <QThread>

#include "hnconfig.h"
#include "hnvalue.h"
#include "valuehistory.h"
#include "hnhistorydaemon/job_type.h"
#include "hnhistorydaemon/job.h"

#include <mutex>
#include <queue>

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
	 * @brief	Queues a history append of the value provided
	 * @param	value			The value to append the history of
	 */
	bool						d_appendHistory(hnvalue_t value);

	/**
	 * @brief	Queues a history read, emits onHistoryReady() once finished
	 * @param	value			The value to get the history from
	 */
	bool						d_getHistory(hnvalue_t value);

	/**
	 * @brief	Queues a history cleanup, emits onHistoryCleaned() once finished
	 * @param	path			The path to the history file to clean up
	 */
	bool						d_cleanHistory(hnvalue_t* value);

	/**
	 * @brief	The daemons main execution loop, gets run asynchronously
	 */
	void						run() override;

	/**
	 * @brief	Acquires the specified file path
	 * @param	path			The path to aqcuire
	 * @return	false if acquiring failed (TODO: timeout)
	 */
	bool						acquireFile(std::string path);

	/**
	 * @brief	Releases an acquired file path
	 * @param	path			The path of the file to release
	 * @return	false if file was never acquired
	 */
	bool						releaseFile(std::string path);

	/**
	 * @brief	Returns the file location of the history
	 */
	std::string					getHistoryDir(){return this->_historyDir;}

signals:

	/**
	 * @brief	Gets emited once a value history is ready
	 * @param	value			The value the history has been read of
	 * @param	history			A history object containing the history to access
	 */
	void						onHistoryRead(hnvalue_t value, ValueHistory history);

	/**
	 * @brief	Gets emited once a file has been released
	 * @param	path			The path to the file released
	 */
	void						fileReleased(std::string path);

#ifndef FRIEND_HNHISTORYDAEMON
private:
#endif

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
	 * @brief	Is locked as long as the history daemon is reserved for some operation
	 */
	std::mutex					_m_reserved;

	/**
	 * @brief	Hold the type for the job that is to execute next
	 */
	job_type					_curJob_type;

	/**
	 * @brief	A map containing mutexes for all files that are locked and thus can not
	 *			be accessed TODO: delete mutexes at destructor
	 */
	std::map<std::string, std::mutex*>	_file_mutexes;
	std::mutex							_m_file_mutexes;

	/**
	 * @brief	Holds a map of currently running jobs
	 */
	std::map<size_t, Job*>		_running_jobs;
	std::mutex					_m_running_jobs;

	/**
	 * @brief 	Contains all the jobs that are still waiting for execution
	 */
	std::queue<Job*>			_waiting_jobs;
	std::mutex					_m_waiting_jobs;

	/**
	 * @brief	Holds the next job id that gets given to new jobs
	 */
	size_t						_nextJobID = 0;

	std::string					_historyDir;

	/**
	 * @brief	Connects the provided job with the daemons slots
	 * @param	job				The job to connect slots to
	 */
	void						connectJob(Job* job);

	/**
	 * @brief	Add a job to the running map
	 * @param	job				The job to add
	 * @return	false if the thread budget is maxed
	 */
	bool						addRunningJob(Job* job);

	/**
	 * @brief	Cleans up all old and finished jobs from _running_jobs
	 * @return	false if nothing was cleaned
	 */
	bool						cleanFinishedJobs();

	/**
	 * @brief	Tries to move waiting jobs to running unless budget is maxed
	 * @return	false if no budget was left or no jobs were waiting
	 */
	bool						moveJobs();

	/**
	 * @brief	Aqcuires the history daemons mutex for _running_jobs
	 * @param	context			A string hinting the context the mutex is needed for
	 */
	void						lock_waiting(std::string context);

	/**
	 * @brief	Contains the log prefix for all messages coming from this class
	 */
	std::string					_cN = "History daemon: ";

private slots:
	void						jobJoined(size_t id);
};

#endif
