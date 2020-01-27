#include "gtest/gtest.h"
#include "Date.h"



TEST(DateTest, dayOfWeekTest) {
	EXPECT_EQ(
		Chrono::day_of_week(Chrono::Date(2019, 12, 1)), 
		Chrono::Day::Name::Sunday
	);

	EXPECT_EQ(
		Chrono::day_of_week(Chrono::Date(2020, 1, 27)), 
		Chrono::Day::Name::Monday
	);
	
	EXPECT_EQ(
		Chrono::day_of_week(Chrono::Date(2020, 3, 31)), 
		Chrono::Day::Name::Tuesday
	);
	
	EXPECT_EQ(
		Chrono::day_of_week(Chrono::Date(2020, 9, 30)), 
		Chrono::Day::Name::Wednesday
	);
	
	EXPECT_EQ(
		Chrono::day_of_week(Chrono::Date(2020, 7, 30)), 
		Chrono::Day::Name::Thursday
	);
	
	EXPECT_EQ(
		Chrono::day_of_week(Chrono::Date(2018, 8, 31)), 
		Chrono::Day::Name::Friday);
	
	EXPECT_EQ(
		Chrono::day_of_week(Chrono::Date(2020, 2, 29)), 
		Chrono::Day::Name::Saturday
	);
}