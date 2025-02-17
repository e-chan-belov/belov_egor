#include "queue_priority.h"

#include <gtest.h>

TEST(Queue, priority_can_create_default_queue) {
    ASSERT_NO_THROW(Queue<int> a);
}

TEST(Queue, priority_can_copy_queues) {
    Queue<int> a;
    ASSERT_NO_THROW(Queue<int> b(a));
}

TEST(Queue, priority_can_copy_queues_correctly) {
    Queue<int> a;
    a.push(1);
    a.push(2);
    a.push(3);
    a.push(4);
    Queue<int> b(a);
    a.pop();
    EXPECT_EQ(1, b.top());
    std::cout << "HI!" << std::endl;
    ASSERT_NO_THROW(b.pop());
    EXPECT_EQ(2, b.top());
    ASSERT_NO_THROW(b.pop());
    EXPECT_EQ(3, b.top());
    ASSERT_NO_THROW(b.pop());
    EXPECT_EQ(4, b.top());
    ASSERT_NO_THROW(b.pop());
}

TEST(Queue, priority_can_get_size) {
    Queue<int> a;
    ASSERT_NO_THROW(a.size());
}

TEST(Queue, priority_can_get_size_correctly) {
    Queue<int> a;
    EXPECT_EQ(0, a.size());
    a.push(1);
    a.push(2);
    a.push(3);
    EXPECT_EQ(3, a.size());
    a.pop();
    a.pop();
    a.pop();
    a.push(4);
    a.push(5);
    a.push(6);
    EXPECT_EQ(3, a.size());
}

TEST(Queue, priority_can_top) {
    Queue<int> a;
    a.push(1);
    ASSERT_NO_THROW(a.top());
}

TEST(Queue, priority_can_top_correctly) {
    Queue<int> a;
    a.push(1);
    a.push(2);
    EXPECT_EQ(1, a.top());
    a.pop();
    a.pop();
    a.push(1);
    a.push(2);
    a.push(3);
    EXPECT_EQ(1, a.top());
}

TEST(Queue, priority_can_pop) {
    Queue<int> a;
    a.push(1);
    ASSERT_NO_THROW(a.pop());
}

TEST(Queue, priority_empty_pop_throws) {
    Queue<int> a;
    ASSERT_ANY_THROW(a.pop());
}

TEST(Queue, priority_can_pop_correctly) {
    Queue<int> a;
    a.push(1);
    a.push(2);
    a.push(3);
    a.pop();
    EXPECT_EQ(2, a.top());
}

TEST(Queue, priority_pop_changes_size) {
    Queue<int> a;
    a.push(1);
    a.push(2);
    a.push(3);
    int sz = a.size();
    a.pop();
    EXPECT_EQ(sz - 1, a.size());
}

TEST(Queue, priority_can_push) {
    Queue<int> a;
    ASSERT_NO_THROW(a.push(1));
}

TEST(Queue, priority_can_push_with_priority) {
    Queue<int> a;
    ASSERT_NO_THROW(a.push(1, 1));
}

TEST(Queue, priority_can_push_correctly) {
    Queue<int> a;
    a.push(1);
    EXPECT_EQ(1, a.top());
}

TEST(Queue, priority_push_changes_size) {
    Queue<int> a;
    a.push(1);
    a.push(2);
    a.push(3);
    int sz = a.size();
    a.push(4);
    EXPECT_EQ(sz + 1, a.size());
}

TEST(Queue, priority_can_push_full) {
    Queue<int> a;
    ASSERT_NO_THROW(a.push(1));
    ASSERT_NO_THROW(a.push(2));
    ASSERT_NO_THROW(a.push(3));
}

TEST(Queue, priority_can_push_with_priority_correctly) {
    Queue<int> a;
    a.push(1, 1);
    a.push(2, 2);
    a.push(3, 1);
    a.push(4, 10);
    a.push(5, 9);
    
    EXPECT_EQ(4, a.top());
    a.pop();
    EXPECT_EQ(5, a.top());
    a.pop();
    EXPECT_EQ(2, a.top());
    a.pop();
    EXPECT_EQ(1, a.top());
    a.pop();
    EXPECT_EQ(3, a.top());
}
