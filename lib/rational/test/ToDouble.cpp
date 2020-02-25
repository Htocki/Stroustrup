#include "gtest/gtest.h"

#include "Rational.h"

TEST(RationalTest, ToDoubleTest) {
	EXPECT_EQ(
		Rational(1, 1).ToDouble(),
		1.
	);

	EXPECT_EQ(
		Rational(1, 5).ToDouble(),
		.2
	);

	EXPECT_EQ(
		Rational(1, 3).ToDouble(),
		1/3.
	);

	EXPECT_EQ(
		Rational(22, 7).ToDouble(),
		22/7.
	);
}