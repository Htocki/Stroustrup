#include <sstream>

#include "gtest/gtest.h"

#include "Roman_int.h"

TEST(Roman_intTest, InputOperatorTest) {
    std::stringstream ss;
    Roman_int roman;
    ss << "XLXX";
    ss >> roman;
    EXPECT_EQ(roman, Roman_int("XLXX"));
}