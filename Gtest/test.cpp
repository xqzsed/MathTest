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