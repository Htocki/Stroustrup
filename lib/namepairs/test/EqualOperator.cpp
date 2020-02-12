#include "gtest/gtest.h"
#include "Namepairs.h"



TEST(NamepairsTest, EqualOperatorTest) {
	Namepairs one { 
		{ "Hallo", 1 }, 
		{ "My", 2 }, 
		{ "friend", 3 } 
	};

	Namepairs two { 
		{ "Hallo", 1 }, 
		{ "My", 2 }, 
		{ "Little", 3 }, 
		{ "Friend", 4 } 
	};

	Namepairs three;
	
	EXPECT_EQ(operator==(one, one), 1);
	EXPECT_EQ(operator==(one, two), 0);
	EXPECT_EQ(operator==(one, three), 0);
	EXPECT_EQ(operator==(three, three), 1);
}