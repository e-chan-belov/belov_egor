#include "tmatrix.h"

#include <gtest.h>

TEST(TDynamicVector, can_create_vector_with_positive_length)
{
  ASSERT_NO_THROW(TDynamicVector<int> v(5));
}

TEST(TDynamicVector, cant_create_too_large_vector)
{
  ASSERT_ANY_THROW(TDynamicVector<int> v(MAX_VECTOR_SIZE + 1));
}

TEST(TDynamicVector, throws_when_create_vector_with_negative_length)
{
  ASSERT_ANY_THROW(TDynamicVector<int> v(-5));
}

TEST(TDynamicVector, can_create_copied_vector)
{
  TDynamicVector<int> v(10);

  ASSERT_NO_THROW(TDynamicVector<int> v1(v));
}

TEST(TDynamicVector, copied_vector_is_equal_to_source_one)
{
  TDynamicVector<int> v(10);
  TDynamicVector<int> v1(v);

  EXPECT_EQ((v1 == v), true);
}

TEST(TDynamicVector, copied_vector_has_its_own_memory)
{
  TDynamicVector<int> v(10);
  TDynamicVector<int> v1(v);

  EXPECT_NE(&v, &v1);
}

TEST(TDynamicVector, can_get_size)
{
  TDynamicVector<int> v(4);

  EXPECT_EQ(4, v.size());
}

TEST(TDynamicVector, can_set_and_get_element)
{
 TDynamicVector<int> v(4);
 v[0] = 4;

 EXPECT_EQ(4, v[0]);
}

TEST(TDynamicVector, throws_when_set_element_with_negative_index)
{
  TDynamicVector<int> v(5);
 
  ASSERT_ANY_THROW(v.at(-2) = 5);
}

TEST(TDynamicVector, throws_when_set_element_with_too_large_index)
{
  TDynamicVector<int> v(5);
 
  ASSERT_ANY_THROW(v.at(10) = 5);
}

TEST(TDynamicVector, can_assign_vector_to_itself)
{
  TDynamicVector<int> v(5);
  for (size_t i = 0; i < v.size(); i++) {
    v[i] = i;
  }
  v = v;

  EXPECT_NE(1, v[0]);
  EXPECT_EQ(4, v[4]);
}

TEST(TDynamicVector, can_assign_vectors_of_equal_size)
{
  TDynamicVector<int> v(5);
  TDynamicVector<int> v1(5);
  for (size_t i = 0; i < v1.size(); i++) {
    v1[i] = i;
  }
  v = v1;

  EXPECT_NE(1, v[0]);
  EXPECT_EQ(4, v[4]);
}

TEST(TDynamicVector, assign_operator_change_vector_size)
{
  TDynamicVector<int> v(5);
  TDynamicVector<int> v1(10);
  for (size_t i = 0; i < v1.size(); i++) {
    v1[i] = i;
  }
  v = v1;

  EXPECT_EQ(10, v.size());
}

TEST(TDynamicVector, can_assign_vectors_of_different_size)
{
  TDynamicVector<int> v(5);
  TDynamicVector<int> v1(10);
  for (size_t i = 0; i < v1.size(); i++) {
    v1[i] = i;
  }
  v = v1;

  EXPECT_EQ(0, v[0]);
  EXPECT_EQ(9, v[9]);
}

TEST(TDynamicVector, compare_equal_vectors_return_true)
{
  TDynamicVector<int> v(5);
  TDynamicVector<int> v1(5);
  for (size_t i = 0; i < v1.size(); i++) {
    v[i] = i;
    v1[i] = i;
  }

  EXPECT_EQ(true, (v1 == v));
}

TEST(TDynamicVector, compare_vector_with_itself_return_true)
{
  TDynamicVector<int> v(5);

  EXPECT_EQ(true, (v == v));
}

TEST(TDynamicVector, vectors_with_different_size_are_not_equal)
{
  TDynamicVector<int> v(5);
  TDynamicVector<int> v1(10);

  EXPECT_EQ(true, (v != v1));
}

TEST(TDynamicVector, can_add_scalar_to_vector)
{
  TDynamicVector<int> v(5);
  TDynamicVector<int> v1(5);
  for (size_t i = 0; i < v.size(); i++) {
      v[i] = i;
  }
  v1 = v + 10;

  EXPECT_EQ(10, v1[0]);
  EXPECT_EQ(14, v1[4]);
}

TEST(TDynamicVector, can_subtract_scalar_from_vector)
{
  TDynamicVector<int> v(5);
  TDynamicVector<int> v1(5);
  for (size_t i = 0; i < v.size(); i++) {
      v[i] = i;
  }
  v1 = v - 10;

  EXPECT_EQ(-10, v1[0]);
  EXPECT_EQ(-6, v1[4]);
}

TEST(TDynamicVector, can_multiply_scalar_by_vector)
{
  TDynamicVector<int> v(5);
  TDynamicVector<int> v1(5);
  for (size_t i = 0; i < v.size(); i++) {
      v[i] = i;
  }
  v1 = v * 10;

  EXPECT_EQ(0, v1[0]);
  EXPECT_EQ(40, v1[4]);
}

TEST(TDynamicVector, can_add_vectors_with_equal_size)
{
  TDynamicVector<int> v(5);
  TDynamicVector<int> v1(5);
  TDynamicVector<int> res(5);
  for (size_t i = 0; i < v.size(); i++) {
    v[i] = i;
    v1[i] = i + 5;
  }

  res = v + v1;
  
  EXPECT_EQ(5, res[0]);
  EXPECT_EQ(13, res[4]);
}

TEST(TDynamicVector, cant_add_vectors_with_not_equal_size)
{
  TDynamicVector<int> v(5);
  TDynamicVector<int> v1(6);
  for (size_t i = 0; i < v.size(); i++) {
    v[i] = i;
    v1[i] = i + 10;
  }
  v1[5] = 0;
  
  ASSERT_ANY_THROW(v + v1);
}

TEST(TDynamicVector, can_subtract_vectors_with_equal_size)
{
  TDynamicVector<int> v(5);
  TDynamicVector<int> v1(5);
  TDynamicVector<int> res(5);
  for (size_t i = 0; i < v.size(); i++) {
    v[i] = i + 5;
    v1[i] = i;
  }

  res = v - v1;
  
  EXPECT_EQ(5, res[0]);
  EXPECT_EQ(5, res[4]);
}

TEST(TDynamicVector, cant_subtract_vectors_with_not_equal_size)
{
  TDynamicVector<int> v(5);
  TDynamicVector<int> v1(6);
  for (size_t i = 0; i < v.size(); i++) {
    v[i] = i + 5;
    v1[i] = i;
  }
  v1[5] = 0;
  
  ASSERT_ANY_THROW(v - v1);
}

TEST(TDynamicVector, can_multiply_vectors_with_equal_size)
{
  TDynamicVector<int> v(5);
  TDynamicVector<int> v1(5);
  int res = 0;
  for (size_t i = 0; i < v.size(); i++) {
    v[i] = i;
    v1[i] = i + 5;
  }

  res = v * v1;
  
  EXPECT_EQ(80, v * v1);
}

TEST(TDynamicVector, cant_multiply_vectors_with_not_equal_size)
{
  TDynamicVector<int> v(5);
  TDynamicVector<int> v1(6);
  for (size_t i = 0; i < v.size(); i++) {
    v[i] = i + 5;
    v1[i] = i;
  }
  v1[5] = 0;
  
  ASSERT_ANY_THROW(v * v1);
}

