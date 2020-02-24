#include "gtest/gtest.h"

#include "Money.h"

TEST(MoneyTest, EqualToOperatorTest) {
	EXPECT_EQ(
		operator==(
			Money{ 13.21, Currency::USD },
			Money{ 13.21, Currency::USD }),
		true
	);

	EXPECT_EQ(
		operator==(
			Money{ 1.433, Currency::USD },
			Money{ 1.430, Currency::USD }),
		true
	);

	EXPECT_EQ(
		operator==(
			Money{ 1.43, Currency::USD },
			Money{ 1.429, Currency::USD }),
		true
	);
}