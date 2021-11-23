#ifndef __HNHISTORYDAEMON_H__
#define __HNHISTORYDAEMON_H__

#include <QThread>

#include "hnconfig.h"

#include <mutex>

/**
 * @brief This class implements a daemon for managing history access
 * It will spawn a thread for every operation until the thread budget is filled
 * Computing on threads will not always scale as expected, some tasks do not benefit from threading
 */
class HNHistoryDaemon : public QThread{
	Q_OBJECT
public:

	/**
	 * @brief	Constructs the history daemon
	 */
	HNHistoryDaemon();

	/**
	 * @brief	Initializes the history daemon
	 * @param	config			The config to get configs of
	 * @return
	 */
	bool						init(HNConfig& config);

	/**
	 * @brief	Releases the history daemon from sleep
	 * @note	If there is nothing to do it immediately returns to sleep
	 */
	void						release();

	void						run() override;

private:
	/**
	 * @brief	The maximum amount of threads this daemon can spawn before having to queue tasks
	 */
	size_t                      _maxThreads;

	bool						_run;

	/**
	 * @brief	As long as it is locked the event loop does nothing and waits for a command
	 * @note	Just unlocking is valid, DO NOT lock it
	 */
	std::mutex					_m_operationPending;
};

#endif
