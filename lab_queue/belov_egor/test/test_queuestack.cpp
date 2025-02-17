#include "queue_stack.h"

#include <gtest.h>

TEST(Queue, stack_can_create_default_queue) {
    ASSERT_NO_THROW(Queue<int> a);
}

TEST(Queue, stack_can_copy_queues) {
    Queue<int> a;
    ASSERT_NO_THROW(Queue<int> b(a));
}

TEST(Queue, stack_can_copy_queues_correctly) {
    Queue<int> a;
    a.push(1);
    a.push(2);
    a.push(3);
    a.push(4);
    std::cerr << "HI1 " << std::endl;
    Queue<int> b(a);
    std::cerr << b.top() << std::endl;
    b.pop();
    std::cerr << b.right_s.top() << std::endl;
    a.pop();
    EXPECT_EQ(1, b.top());
    b.pop();
    
    EXPECT_EQ(2, b.top());
    ASSERT_NO_THROW(b.pop());
    EXPECT_EQ(3, b.top());
    ASSERT_NO_THROW(b.pop());
    EXPECT_EQ(4, b.top());
    ASSERT_NO_THROW(b.pop());
}

TEST(Queue, stack_can_get_size) {
    Queue<int> a;
    ASSERT_NO_THROW(a.size());
}

TEST(Queue, stack_can_get_size_correctly) {
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

TEST(Queue, stack_can_top) {
    Queue<int> a;
    a.push(1);
    ASSERT_NO_THROW(a.top());
}

TEST(Queue, stack_can_top_correctly) {
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

TEST(Queue, stack_can_pop) {
    Queue<int> a;
    a.push(1);
    ASSERT_NO_THROW(a.pop());
}

TEST(Queue, stack_empty_pop_throws) {
    Queue<int> a;
    ASSERT_ANY_THROW(a.pop());
}

TEST(Queue, stack_can_pop_correctly) {
    Queue<int> a;
    a.push(1);
    a.push(2);
    a.push(3);
    a.pop();
    EXPECT_EQ(2, a.top());
}

TEST(Queue, stack_pop_changes_size) {
    Queue<int> a;
    a.push(1);
    a.push(2);
    a.push(3);
    int sz = a.size();
    a.pop();
    EXPECT_EQ(sz - 1, a.size());
}

TEST(Queue, stack_can_push) {
    Queue<int> a;
    ASSERT_NO_THROW(a.push(1));
}

TEST(Queue, stack_can_push_correctly) {
    Queue<int> a;
    a.push(1);
    EXPECT_EQ(1, a.top());
}

TEST(Queue, stack_push_changes_size) {
    Queue<int> a;
    a.push(1);
    a.push(2);
    a.push(3);
    int sz = a.size();
    a.push(4);
    EXPECT_EQ(sz + 1, a.size());
}

TEST(Queue, stack_can_push_full) {
    Queue<int> a;
    ASSERT_NO_THROW(a.push(1));
    ASSERT_NO_THROW(a.push(2));
    ASSERT_NO_THROW(a.push(3));
}
