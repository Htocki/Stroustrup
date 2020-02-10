#include "gtest/gtest.h"
#include "Rational.h"



TEST(RationalTest, ToDoubleTest) {
	EXPECT_EQ(
		Rational(1, 1).toDouble(),
		1.
	);

	EXPECT_EQ(
		Rational(1, 5).toDouble(),
		.2
	);

	EXPECT_EQ(
		Rational(1, 3).toDouble(),
		1/3.
	);

	EXPECT_EQ(
		Rational(22, 7).toDouble(),
		22/7.
	);
}