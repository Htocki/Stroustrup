#include "gtest/gtest.h"
#include "Name_pairs.h"



TEST(Name_pairsTest, operatorEqTest) {
	Name_pairs one { 
		{ "Hallo", 1 }, 
		{ "My", 2 }, 
		{ "friend", 3 } 
	};

	Name_pairs two { 
		{ "Hallo", 1 }, 
		{ "My", 2 }, 
		{ "Little", 3 }, 
		{ "Friend", 4 } 
	};

	Name_pairs three;
	
	EXPECT_EQ(operator==(one, one), 1);
	EXPECT_EQ(operator==(one, two), 0);
	EXPECT_EQ(operator==(one, three), 0);
	EXPECT_EQ(operator==(three, three), 1);
}