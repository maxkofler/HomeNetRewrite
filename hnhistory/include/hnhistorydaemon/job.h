#ifndef __JOB_H__
#define __JOB_H__

#include <QThread>

#include "job_type.h"

class Job : public QThread{
	Q_OBJECT

public:
	explicit Job(job_type expected_job_type, job_type actual_job_type);

protected:
	job_type				_expected_job_type;

private:
	job_type				_job_type;
};

#endif
