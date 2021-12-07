#ifndef __JOB_H__
#define __JOB_H__

#include <QThread>

#include <string>
#include <vector>

#include "job_type.h"
#include "args.h"

#include "exceptions.h"

class Job : public QThread{
	Q_OBJECT

public:
	explicit Job(job_type type, Args args);

#ifndef FRIEND_JOB
protected:
#endif
	Args						_args;

#ifndef FRIEND_JOB
private:
#endif

	job_type					_job_type;
};

#endif
