#include "gtest/gtest.h"
#include "Rational.h"



TEST(RationalTest, DivisionOperatorTest) {
	EXPECT_EQ(
		Rational() / Rational(),
		Rational()
	);

	EXPECT_EQ(
		Rational(4, 7) / Rational(2, 5),
		Rational(10, 7)
	);

	EXPECT_EQ(
		Rational(5, 9) / Rational(2, 1),
		Rational(5, 18)
	);
}