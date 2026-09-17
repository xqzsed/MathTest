#include "pch.h"
#include "lib.h"

TEST(TaskConstructorTests, DefaultRange) {
    Task t;
    EXPECT_GE(t.num_1, -100);
    EXPECT_LE(t.num_1, 100);
    EXPECT_GE(t.num_2, -100);
    EXPECT_LE(t.num_2, 100);
}

TEST(TaskConstructorTests, OperationIsValid) {
    Task t;
    EXPECT_TRUE(t.operation == '+' || t.operation == '-' || t.operation == '*');
}

TEST(TaskConstructorTests, CustomRange) {
    Task t(1, 10);
    EXPECT_GE(t.num_1, 1);
    EXPECT_LE(t.num_1, 10);
    EXPECT_GE(t.num_2, 1);
    EXPECT_LE(t.num_2, 10);
}

TEST(TaskCalculateTests, Addition) {
    Task t;
    t.num_1 = 5;
    t.num_2 = 3;
    t.operation = '+';
    EXPECT_EQ(t.calculate(), 8);
}

TEST(TaskCalculateTests, Subtraction) {
    Task t;
    t.num_1 = 10;
    t.num_2 = 4;
    t.operation = '-';
    EXPECT_EQ(t.calculate(), 6);
}

TEST(TaskCalculateTests, Multiplication) {
    Task t;
    t.num_1 = 6;
    t.num_2 = 7;
    t.operation = '*';
    EXPECT_EQ(t.calculate(), 42);
}

TEST(TaskTest, CalculateDivision) {
    Task t(1, 1, '/');
    t.num_1 = 20;
    t.num_2 = 4;
    EXPECT_EQ(t.calculate(), 5);
}

TEST(TaskTest, CalculateDivisionByZeroThrows) {
    Task t(1, 1, '/');
    t.num_1 = 10;
    t.num_2 = 0;
    EXPECT_THROW(t.calculate(), std::invalid_argument);
}

TEST(TaskAnswerTests, AnswerMatchesOperation) {
    Task t;
    int expected = 0;
    switch (t.operation) {
    case '+': expected = t.num_1 + t.num_2; break;
    case '-': expected = t.num_1 - t.num_2; break;
    case '*': expected = t.num_1 * t.num_2; break;
    }
    EXPECT_EQ(t.answer, expected);
}

TEST(MathTestConstructorTests, SizeOnly) {
    MathTest mt(5);
    EXPECT_EQ(mt.getCount(), 5);
    EXPECT_EQ(mt.getCorrectCount(), 0);
}

TEST(MathTestConstructorTests, SizeZero) {
    MathTest mt(0);
    EXPECT_EQ(mt.getCount(), 0);
    EXPECT_EQ(mt.getCorrectCount(), 0);
}

TEST(MathTestConstructorTests, WithRange) {
    MathTest mt(3, 1, 10);
    EXPECT_EQ(mt.getCount(), 3);
    EXPECT_EQ(mt.getCorrectCount(), 0);
}

TEST(MathTestConstructorTests, WithNegativeRange) {
    MathTest mt(4, -20, -5);
    EXPECT_EQ(mt.getCount(), 4);
}

TEST(MathTestConstructorTests, WithOperationAddition) {
    MathTest mt(4, 1, 10, '+');
    EXPECT_EQ(mt.getCount(), 4);
    EXPECT_EQ(mt.getCorrectCount(), 0);
}

TEST(MathTestConstructorTests, WithOperationSubtraction) {
    MathTest mt(2, 1, 10, '-');
    EXPECT_EQ(mt.getCount(), 2);
}

TEST(MathTestConstructorTests, WithOperationMultiplication) {
    MathTest mt(6, 1, 5, '*');
    EXPECT_EQ(mt.getCount(), 6);
}