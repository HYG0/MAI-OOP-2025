#include <gtest/gtest.h>
#include "../include/lab.hpp"

TEST(AfraidNumberTest, Monday) {
    std::string TestDay = "Monday";
    EXPECT_EQ(AfraidNumber(&TestDay), 6);
}