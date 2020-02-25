#include "gtest/gtest.h"

#include "Rational.h"

TEST(RationalTest, MultiplicationOperatorTest) {
	EXPECT_EQ(
		operator*(Rational(2, 5), Rational(3, 4)),
		Rational(3, 10)
	);

	EXPECT_EQ(
		operator*(Rational(24, 35), Rational(25, 36)),
		Rational(10, 21)
	);
}