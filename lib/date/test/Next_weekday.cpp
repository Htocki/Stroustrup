#include "gtest/gtest.h"
#include "Date.h"



TEST(DateTest, nextWeekdayTest) {
	EXPECT_EQ(
		next_weekday(Date(2020, 1, 13)),
		Date(2020, 1, 14)
	);

	EXPECT_EQ(
		next_weekday(Date(2020, 1, 14)),
		Date(2020, 1, 15)
	);

	EXPECT_EQ(
		next_weekday(Date(2020, 1, 15)),
		Date(2020, 1, 16)
	);

	EXPECT_EQ(
		next_weekday(Date(2020, 1, 16)),
		Date(2020, 1, 17)
	);

	EXPECT_EQ(
		next_weekday(Date(2020, 1, 17)),
		Date(2020, 1, 20)
	);

	EXPECT_EQ(
		next_weekday(Date(2020, 1, 18)),
		Date(2020, 1, 20)
	);

	EXPECT_EQ(
		next_weekday(Date(2020, 1, 19)),
		Date(2020, 1, 20)
	);
}