#include "gtest/gtest.h"
#include "Date.h"



TEST(DateTest, nextSundayTest) {
	EXPECT_EQ(
		next_sunday(Date(2020, 1, 27)),
		Date(2020, 2, 2)
	);

	EXPECT_EQ(
		next_sunday(Date(2020, 1, 28)),
		Date(2020, 2, 2)
	);

	EXPECT_EQ(
		next_sunday(Date(2020, 1, 29)),
		Date(2020, 2, 2)
	);

	EXPECT_EQ(
		next_sunday(Date(2020, 1, 30)),
		Date(2020, 2, 2)
	);

	EXPECT_EQ(
		next_sunday(Date(2020, 1, 31)),
		Date(2020, 2, 2)
	);

	EXPECT_EQ(
		next_sunday(Date(2020, 2, 1)),
		Date(2020, 2, 2)
	);

	EXPECT_EQ(
		next_sunday(Date(2020, 2, 2)),
		Date(2020, 2, 9)
	);
}