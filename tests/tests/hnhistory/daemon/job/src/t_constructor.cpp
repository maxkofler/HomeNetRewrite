#include <gtest/gtest.h>
#include "../t_job.h"

TEST(Job, Constructor){
	Job job(nullptr, JOB_GET_HISTORY);

	EXPECT_EQ(JOB_GET_HISTORY, job._job_type);
}
