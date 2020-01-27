#include "gtest/gtest.h"
#include "Date.h"



TEST(DateTest, dayOfWeekTest) {
	EXPECT_EQ(Chrono::day_of_week(Chrono::Date(2019, 12, 1)), Day::Sunday);
	EXPECT_EQ(Chrono::day_of_week(Chrono::Date(2020, 1, 27)), Day::Monday);
	EXPECT_EQ(Chrono::day_of_week(Chrono::Date(2020, 3, 31)), Day::Tuesday);
	EXPECT_EQ(Chrono::day_of_week(Chrono::Date(2020, 9, 30)), Day::Wednesday);
	EXPECT_EQ(Chrono::day_of_week(Chrono::Date(2020, 7, 30)), Day::Thursday);
	EXPECT_EQ(Chrono::day_of_week(Chrono::Date(2018, 8, 31)), Day::Friday);
	EXPECT_EQ(Chrono::day_of_week(Chrono::Date(2020, 2, 29)), Day::Saturday);
}