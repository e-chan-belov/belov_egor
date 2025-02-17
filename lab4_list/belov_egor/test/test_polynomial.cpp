#include "polynomial.h"

#include <gtest.h>

TEST(Polynomial, can_create_module) {
    ASSERT_NO_THROW(Polynomial p);
}

TEST(Polynomial, can_push) {
    Polynomial p;
    ASSERT_NO_THROW(p.push(Term()));
}

TEST(Polynomial, can_compare) {
    Polynomial p1;
    Polynomial p2;
    ASSERT_NO_THROW(p1 == p2);
}

TEST(Polynomial, can_compare_correctly) {
    Polynomial p1;
    Polynomial p2;
    p1.push(Term(1, 0, 0, 0));
    p1.push(Term(3, 1, 1, 0));
    p1.push(Term(4, 0, 0, 3));
    
    p2.push(Term(1, 0, 0, 0));
    p2.push(Term(4, 0, 0, 3));
    p2.push(Term(3, 1, 1, 0));
    EXPECT_EQ(p1, p2);
}

TEST(Polynomial, can_add_correctly) {
    Polynomial p1;
    Polynomial p2;
    p1.push(Term(1, 0, 0, 0));
    p1.push(Term(3, 1, 1, 0));
    p1.push(Term(4, 0, 0, 3));
    
    p2.push(Term(1, 0, 0, 0));
    p2.push(Term(4, 0, 0, 3));
    p2.push(Term(3, 1, 1, 0));
    
    Polynomial p3;
    p3.push(2, 0, 0, 0);
    p3.push(6, 1, 1, 0);
    p3.push(8, 0, 0, 3);
    
    EXPECT_EQ(p1 + p2, p3);
}

TEST(Polynomial, can_add_correctly_creates_zero) {
    Polynomial p1;
    Polynomial p2;
    
    p1.push(1, 1, 0, 0);
    
    p2.push(-1, 1, 0, 0);
    p2.push(2, 1, 1, 1);
    
    Polynomial p3;
    p3.push(2, 1, 1, 1);
    
    EXPECT_EQ(p1 + p2, p3);
}

TEST(Polynomial, can_add_correctly_creates_zero2) {
    Polynomial p1;
    Polynomial p2;
    
    p1.push(1, 1, 0, 0);
    
    p2.push(-1, 1, 0, 0);
    
    Polynomial p3;
    p3.push(0, 0, 0, 0);
    
    EXPECT_EQ(p1 + p2, p3);
}

TEST(Polynomial, can_multiply_correcly) {
    Polynomial p1;
    Polynomial p2;
    p1.push(Term(1, 0, 0, 0));
    p1.push(Term(3, 1, 1, 0));
    p1.push(Term(4, 0, 0, 3));
    
    p2.push(Term(1, 0, 0, 0));
    p2.push(Term(4, 0, 0, 3));
    p2.push(Term(3, 1, 1, 0));
    
    Polynomial p3;
    p3.push(1, 0, 0, 0);
    p3.push(6, 1, 1, 0);
    p3.push(8, 0, 0, 3);
    p3.push(9, 2, 2, 0);
    p3.push(24, 1, 1, 3);
    p3.push(16, 0, 0, 6);
    
    EXPECT_EQ(p1 * p2, p3);
}

TEST(Polynomial, can_multiply_correcly_2) {
    Polynomial p1;
    Polynomial p2;
    p1.push(Term(2, 1, 0, 0));
    p1.push(Term(3, 0, 1, 0));
    
    p2.push(Term(2, 1, 0, 0));
    p2.push(Term(-3, 0, 1, 0));
    
    Polynomial p3;
    p3.push(4, 2, 0, 0);
    p3.push(-9, 0, 2, 0);
    
    EXPECT_EQ(p1 * p2, p3);
}
