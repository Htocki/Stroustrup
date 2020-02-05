#include "gtest/gtest.h"
#include "Date.h"



TEST(DateTest, dayOfWeekTest) {
	EXPECT_EQ(
		day_of_week(Date(2019, 12, 1)), 
		Day::Name::Sunday
	);

	EXPECT_EQ(
		day_of_week(Date(2020, 1, 27)), 
		Day::Name::Monday
	);
	
	EXPECT_EQ(
		day_of_week(Date(2020, 3, 31)), 
		Day::Name::Tuesday
	);
	
	EXPECT_EQ(
		day_of_week(Date(2020, 9, 30)), 
		Day::Name::Wednesday
	);
	
	EXPECT_EQ(
		day_of_week(Date(2020, 7, 30)), 
		Day::Name::Thursday
	);
	
	EXPECT_EQ(
		day_of_week(Date(2018, 8, 31)), 
		Day::Name::Friday);
	
	EXPECT_EQ(
		day_of_week(Date(2020, 2, 29)), 
		Day::Name::Saturday
	);
}