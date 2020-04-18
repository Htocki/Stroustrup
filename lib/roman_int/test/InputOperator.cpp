#include <sstream>
#include <iostream>

#include "gtest/gtest.h"

#include "RomanInt.h"

TEST(RomanIntTest, InputOperatorTest) {
  std::stringstream ss;
  RomanInt roman;
  ss << "XLXX";
  ss >> roman;
  EXPECT_EQ(roman, RomanInt("XLXX"));
}
