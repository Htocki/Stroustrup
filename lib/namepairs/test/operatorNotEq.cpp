#include "gtest/gtest.h"
#include "Namepairs.h"



TEST(NamepairsTest, operatorNotEqTest) {
	Namepairs one{
		{ "Hallo", 1 },
		{ "My", 2 },
		{ "friend", 3 }
	};

	Namepairs two{
		{ "Hallo", 1 },
		{ "My", 2 },
		{ "Little", 3 },
		{ "Friend", 4 }
	};

	Namepairs three;

	EXPECT_EQ(operator!=(one, one), 0);
	EXPECT_EQ(operator!=(one, two), 1);
	EXPECT_EQ(operator!=(one, three), 1);
	EXPECT_EQ(operator!=(three, three), 0);
}