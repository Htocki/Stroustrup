#include "gtest/gtest.h"
#include "Rational.h"



TEST(RationalTest, SubtractionOperatorTest) {
	EXPECT_EQ(
		Rational(5, 12) - Rational(1, 12),
		Rational(1, 3)
	);

	EXPECT_EQ(
		Rational() - Rational(3, 7),
		Rational(4, 7)
	);

	EXPECT_EQ(
		Rational(3, 1) - Rational(6, 7),
		Rational(15, 7)
	);
}