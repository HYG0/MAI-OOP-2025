#include <gtest/gtest.h>
#include "../include/lab.hpp"

TEST(AfraidNumberTest, Wednesday) {
    std::string TestDay = "Среда";
    EXPECT_EQ(AfraidNumber(TestDay, 34), true);
}
TEST(AfraidNumberTest, Tuesday) {
    std::string TestDay = "Вторник";
    EXPECT_EQ(AfraidNumber(TestDay, 100), true);
}
TEST(AfraidNumberTest, Thursday) {
    std::string TestDay = "Четверг";
    EXPECT_EQ(AfraidNumber(TestDay, 0), true);
}
TEST(AfraidNumberTest, Friday) {
    std::string TestDay = "Пятница";
    EXPECT_EQ(AfraidNumber(TestDay, 5), false);
}
TEST(AfraidNumberTest, Monday) {
    std::string TestDay = "Понедельник";
    EXPECT_EQ(AfraidNumber(TestDay, 12), true);
}
TEST(AfraidNumberTest, Saturday) {
    std::string TestDay = "Суббота";
    EXPECT_EQ(AfraidNumber(TestDay, 56), true);
}
TEST(AfraidNumberTest, Sunday) {
    std::string TestDay = "Воскресенье";
    EXPECT_EQ(AfraidNumber(TestDay, -666), true);
}
TEST(AfraidNumberTest, Sunday_2) {
    std::string TestDay = "Воскресенье";
    EXPECT_FALSE(AfraidNumber(TestDay, 56));
}
TEST(AfraidNumberTest, Tuesday_2) {
    std::string TestDay = "Вторник";
    EXPECT_FALSE(AfraidNumber(TestDay, 56));
}