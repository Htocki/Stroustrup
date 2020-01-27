#include "gtest/gtest.h"
#include "Date.h"



TEST(DateTest, nextSundayTest) {
	EXPECT_EQ(
		Chrono::next_sunday(Chrono::Date(2020, 1, 27)),
		Chrono::Date(2020, 2, 2)
	);

	EXPECT_EQ(
		Chrono::next_sunday(Chrono::Date(2020, 1, 28)),
		Chrono::Date(2020, 2, 2)
	);

	EXPECT_EQ(
		Chrono::next_sunday(Chrono::Date(2020, 1, 29)),
		Chrono::Date(2020, 2, 2)
	);

	EXPECT_EQ(
		Chrono::next_sunday(Chrono::Date(2020, 1, 30)),
		Chrono::Date(2020, 2, 2)
	);

	EXPECT_EQ(
		Chrono::next_sunday(Chrono::Date(2020, 1, 31)),
		Chrono::Date(2020, 2, 2)
	);

	EXPECT_EQ(
		Chrono::next_sunday(Chrono::Date(2020, 2, 1)),
		Chrono::Date(2020, 2, 2)
	);

	EXPECT_EQ(
		Chrono::next_sunday(Chrono::Date(2020, 2, 2)),
		Chrono::Date(2020, 2, 9)
	);
}