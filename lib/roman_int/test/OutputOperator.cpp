#include <sstream>

#include "gtest/gtest.h"

#include "RomanInt.h"

TEST(RomanIntTest, OutputOperatorTest) {
  std::ostringstream oss;
  RomanInt roman("XIV");
  oss << roman;
  EXPECT_EQ("XIV", oss.str());

  oss.str("");
  roman = RomanInt();
  oss << roman;
  EXPECT_EQ("I", oss.str());

  oss.str("");
  roman = RomanInt("MCMXL");
  oss << roman;
  EXPECT_EQ("MCMXL", oss.str());
}
