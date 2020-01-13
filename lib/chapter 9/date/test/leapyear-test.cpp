#include "gtest/gtest.h"
#include "Date.h"



TEST(DateTest, leapyearTest) {
	EXPECT_EQ(Chrono::leapyear(Chrono::Year(1991)), false);
	EXPECT_EQ(Chrono::leapyear(Chrono::Year(1944)), true);
	EXPECT_EQ(Chrono::leapyear(Chrono::Year(2100)), false);
	EXPECT_EQ(Chrono::leapyear(Chrono::Year(2000)), true);
}