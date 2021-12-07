#include <gtest/gtest.h>
#include "../t_job.h"

TEST(Job, Constructor){
	Args args;
	Job job(JOB_GET_HISTORY, JOB_GET_HISTORY, args);

	EXPECT_EQ(JOB_GET_HISTORY, job._job_type);
	EXPECT_EQ(args, job._args);
}

TEST(Job, Constructor_Wrong_Type){
	try{
		Args args;
		Job job(JOB_GET_HISTORY, JOB_NONE, args);
		
		//Should not reach this far
		FAIL() << "Job does not react to wrong type";
	} catch (JobTypeMissmatchException& e){
		
	} catch (HomeNetException& e){
		FAIL() << "Job throws wrong HomeNetException: " << e.what();
	} catch (...){
		FAIL() << "Job throws unknown exception";
	}
}
