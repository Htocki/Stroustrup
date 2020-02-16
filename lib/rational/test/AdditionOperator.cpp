#include "Rational.h"

#include "gtest/gtest.h"

TEST(RationalTest, AdditionOperatorTest) {
	EXPECT_EQ(
		operator+(Rational(3, 8), Rational(4, 8)),
		Rational(7, 8)
	);

	EXPECT_EQ(
		operator+(Rational(3, 15), Rational(4, 18)),
		Rational(19, 45)
	);
}