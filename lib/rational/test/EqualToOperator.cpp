#include "gtest/gtest.h"

#include "Rational.h"

TEST(RationalTest, EqualToOperatorTest) {
	EXPECT_EQ(
		operator==(Rational(1, 1), Rational(1, 1)),
		true
	);

	EXPECT_EQ(
		operator==(Rational(1, 2), Rational(1, 2)),
		true
	);

	EXPECT_EQ(
		operator==(Rational(2, 4), Rational(1, 2)),
		true
	);

	EXPECT_EQ(
		operator==(Rational(2, 1), Rational(1, 2)),
		false
	);
}