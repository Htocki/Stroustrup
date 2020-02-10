#include "gtest/gtest.h"
#include "Rational.h"



TEST(RationalTest, AdditionOperatorTest) {
	EXPECT_EQ(
		Rational(3, 8) + Rational(4, 8),
		Rational(7, 8)
	);

	EXPECT_EQ(
		Rational(3, 15) + Rational(4, 18),
		Rational(19, 45)
	);
}