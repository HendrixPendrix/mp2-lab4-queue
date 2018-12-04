#include "JobStream.h"
#include <gtest.h>
#include "proc.h"

TEST(TProc, can_create_proc)
{
	ASSERT_NO_THROW(TProc tmp(0.9,5,0.5,5));
}
TEST(TProc, cant_create_proc_without_correct_rate)
{
	ASSERT_NO_THROW(TProc tmp(1.5, 5, 0.5,5));
}
TEST(TProc, cant_create_proc_without_correct_intense)
{
	ASSERT_NO_THROW(TProc tmp(0.9, 5, 1.5, 5));
}
TEST(TProc, can_job)
{
	TProc tmp(0.9, 5, 0.5, 5);
	ASSERT_ANY_THROW(tmp.RunNewJob(3));
}