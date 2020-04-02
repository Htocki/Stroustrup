#include "gtest/gtest.h"

#include "RomanInt.h"

TEST(RomanIntTest, EqualToOperatorTest) {
  EXPECT_EQ(operator==(RomanInt(), RomanInt()), true);
  EXPECT_EQ(operator==(RomanInt("XXX"), RomanInt("XXX")), true);
  EXPECT_EQ(operator==(RomanInt("IX"), RomanInt("IX")), true);
  EXPECT_EQ(operator==(RomanInt("XXX"), RomanInt("II")), false);
  EXPECT_EQ(operator==(RomanInt("MCMXLIX"), RomanInt("MCMXLIX")), true);
}
