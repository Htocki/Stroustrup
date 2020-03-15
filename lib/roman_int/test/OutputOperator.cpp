#include <sstream>

#include "gtest/gtest.h"

#include "Roman_int.h"

TEST(Roman_intTest, OutputOperatorTest) {
    std::ostringstream oss;
    Roman_int roman("XIV");
    oss << roman;
    EXPECT_EQ("XIV", oss.str());

    oss.str("");
    roman = Roman_int();
    oss << roman;
    EXPECT_EQ("I", oss.str());

    oss.str("");
    roman = Roman_int("MCMXL");
    oss << roman;
    EXPECT_EQ("MCMXL", oss.str());
}