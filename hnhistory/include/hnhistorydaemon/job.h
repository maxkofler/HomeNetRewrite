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
	explicit Job(job_type expected_job_type, job_type actual_job_type, Args args);

protected:
	job_type					_expected_job_type;
	Args						_args;

private:
	job_type					_job_type;
};

#endif
