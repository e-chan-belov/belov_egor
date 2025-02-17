#include "list.h"

#include <gtest.h>

TEST(List, can_create_lists) {
    ASSERT_NO_THROW(List<int> s);
}

TEST(List, can_create_nonempty_lists) {
    ASSERT_NO_THROW(List<int> s(10));
}

TEST(List, can_copy_lists) {
    List<int> a(5);
    ASSERT_NO_THROW(List<int> b(a));
}

TEST(List, can_copy_lists_correctly) {
    List<int> a;
    a.push_back(1);
    a.push_back(2);
    List<int> b(a);
    a.pop_back();
    EXPECT_EQ(a.size(), 1);
    EXPECT_EQ(b.size(), 2);
}

TEST(List, can_equate) {
    List<int> a(2);
    ASSERT_NO_THROW(List<int> b = a);
}

TEST(List, can_equate_correctly) {
    List<int> a;
    a.push_back(1);
    a.push_back(2);
    List<int> b = a;
    a.pop_back();
    EXPECT_EQ(a.size(), 1);
    EXPECT_EQ(b.size(), 2);
}

TEST(List, can_size) {
    List<int> a;
    a.push_back(1);
    a.push_back(2);
    ASSERT_NO_THROW(a.size());
}

TEST(List, can_size_correctly) {
    List<int> a;
    a.push_back(1);
    a.push_back(2);
    EXPECT_EQ(a.size(), 2);
}

TEST(List, can_push) {
    List<int> a;
    ASSERT_NO_THROW(a.push_back(1));
}

TEST(List, can_push_correctly) {
    List<int> a;
    a.push_back(1);
    a.push_back(2);
    EXPECT_EQ(a.top(), 2);
    a.pop_back();
    EXPECT_EQ(a.top(), 1);
}

TEST(List, can_top) {
    List<int> a;
    a.push_back(1);
    ASSERT_NO_THROW(a.top());
}

TEST(List, can_top_correctly) {
    List<int> a;
    a.push_back(1);
    EXPECT_EQ(a.top(), 1);
}

TEST(List, throws_top) {
    List<int> a;
    ASSERT_ANY_THROW(a.top());
}

TEST(List, can_pop) {
    List<int> a;
    a.push_back(1);
    ASSERT_NO_THROW(a.pop_back());
}

TEST(List, can_pop_correctly) {
    List<int> a;
    a.push_back(1);
    a.push_back(2);
    a.pop_back();
    EXPECT_EQ(a.top(), 1);
}

TEST(List, throws_pop) {
    List<int> a;
    ASSERT_ANY_THROW(a.pop_back());
}

TEST(List, can_create_iterators) {
    ASSERT_NO_THROW(List<int>::Iterator iter);
}

TEST(List, can_get_iterators) {
    List<int> a(2);
    ASSERT_NO_THROW(List<int>::Iterator iter = a.begin());
}

TEST(List, iterators_read_correctly) {
    List<int> a;
    a.push_back(2);
    a.push_back(1);
    List<int>::Iterator iter = a.begin();
    EXPECT_EQ(iter.current(), 1);
    ASSERT_NO_THROW(iter++);
    EXPECT_EQ(iter.current(), 2);
}

TEST(List, iterators_move_correctly) {
    List<int> a;
    a.push_back(2);
    a.push_back(1);
    List<int>::Iterator iter = a.begin();
    iter++;
    EXPECT_EQ(iter.current(), 2);
    EXPECT_EQ(iter.hasNext(), false);
    EXPECT_EQ(iter.isAtList(), true);
    iter--;
    EXPECT_EQ(iter.hasNext(), true);
}

TEST(List, iterators_push_correctly) {
    List<int> a;
    a.push_back(1);
    List<int>::Iterator iter = a.begin();
    ASSERT_NO_THROW(iter.push(2));
    EXPECT_EQ(iter.current(), 2);
}
