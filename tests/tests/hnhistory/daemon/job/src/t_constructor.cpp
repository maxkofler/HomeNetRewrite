#include <gtest/gtest.h>
#include "../t_job.h"

TEST(Job, Constructor){
	Args args;
	Job job(JOB_GET_HISTORY, args);

	EXPECT_EQ(JOB_GET_HISTORY, job._job_type);
}
