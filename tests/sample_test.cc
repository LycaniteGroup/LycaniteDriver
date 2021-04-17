#include <gtest/gtest.h>

// Demonstrate some basic assertions.
TEST(SampleTest, BasicAssertions) {
    // Expect two strings not to be equal.
    EXPECT_STRNE("Sample", "test");
    // Expect equality.
    EXPECT_EQ(7 * 6, 42);
}