#include "gtest/gtest.h"
#include "Date.h"



TEST(DateTest, nextWeekdayTest) {
	EXPECT_EQ(
		Chrono::next_weekday(Chrono::Date(2020, 1, 13)),
		Chrono::Date(2020, 1, 14)
	);

	EXPECT_EQ(
		Chrono::next_weekday(Chrono::Date(2020, 1, 14)),
		Chrono::Date(2020, 1, 15)
	);

	EXPECT_EQ(
		Chrono::next_weekday(Chrono::Date(2020, 1, 15)),
		Chrono::Date(2020, 1, 16)
	);

	EXPECT_EQ(
		Chrono::next_weekday(Chrono::Date(2020, 1, 16)),
		Chrono::Date(2020, 1, 17)
	);

	EXPECT_EQ(
		Chrono::next_weekday(Chrono::Date(2020, 1, 17)),
		Chrono::Date(2020, 1, 20)
	);

	EXPECT_EQ(
		Chrono::next_weekday(Chrono::Date(2020, 1, 18)),
		Chrono::Date(2020, 1, 20)
	);

	EXPECT_EQ(
		Chrono::next_weekday(Chrono::Date(2020, 1, 19)),
		Chrono::Date(2020, 1, 20)
	);
}