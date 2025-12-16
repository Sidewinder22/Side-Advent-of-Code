#include "Dial.hpp"
#include <cstdint>
#include <gtest/gtest.h>

using namespace ::testing;

class DialTests : public Test
{
protected:
    DialTests()
        : dial_(50, 100)
    {
    }

    Dial dial_;
};

TEST_F(DialTests, OneTurnLeftLessThanInitialPositionTest)
{
    uint32_t shift = 18;
    EXPECT_EQ(dial_.turnLeft(shift), 32);
}

TEST_F(DialTests, OneTurnRightLessThanSizeTest)
{
    uint32_t shitf = 32;
    EXPECT_EQ(dial_.turnRight(shitf), 82);
}
