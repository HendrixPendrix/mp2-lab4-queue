#include "queue.h"
#include <gtest.h>

TEST(TQueue, can_create_queue)
{
	ASSERT_NO_THROW(TQueue <int> tmp(3));
}
TEST(TQueue, can_create_queue_with_large_length)
{
	ASSERT_ANY_THROW(TQueue <int> tmp(MaxQueueSize + 3));
}
TEST(TQueue, can_create_queue_with_negative_length)
{
	ASSERT_ANY_THROW(TQueue <int> tmp(-1));
}
TEST(TQueue, check_queue_on_empty)
{
	TQueue <int> tmp(3);
	EXPECT_TRUE(tmp.IsEmpty());
}
TEST(TQueue, check_queue_on_full)
{
	TQueue <int> tmp(3);
	while (tmp.IsFull == false)
		tmp.Push(1);
	EXPECT_TRUE(tmp.IsFull());
}
TEST(TQueue, can_pop_when_queue_empty)
{
	TQueue <int> tmp(3);
	ASSERT_ANY_THROW(tmp.Pop());
}
TEST(TQueue, can_push_when_queue_full)
{
	TQueue <int> tmp(3);
	while (tmp.IsFull == false)
		tmp.Push(1);
	ASSERT_ANY_THROW(tmp.Push(1));
}
