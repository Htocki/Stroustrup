#include "gtest/gtest.h"
#include "Name_pairs.h"



TEST(Name_pairsTest, operatorNotEqTest) {
	Name_pairs one{
		{ "Hallo", 1 },
		{ "My", 2 },
		{ "friend", 3 }
	};

	Name_pairs two{
		{ "Hallo", 1 },
		{ "My", 2 },
		{ "Little", 3 },
		{ "Friend", 4 }
	};

	Name_pairs three;

	EXPECT_EQ(operator!=(one, one), 0);
	EXPECT_EQ(operator!=(one, two), 1);
	EXPECT_EQ(operator!=(one, three), 1);
	EXPECT_EQ(operator!=(three, three), 0);
}