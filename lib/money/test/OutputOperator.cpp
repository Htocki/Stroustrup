#include <sstream>

#include "gtest/gtest.h"

#include "Currency.h"
#include "Money.h"

TEST(MoneyTest, OutputOperatorTest) {
    std::ostringstream oss;
    Money money = { 120.32, Currency::USD };
    oss << money;
    EXPECT_EQ("USD120.32", oss.str());

    oss.str("");
    money = Money{ 1.995, Currency::USD };
    oss << money;
    EXPECT_EQ("USD2", oss.str());

    oss.str("");
    money = Money{ 1.994, Currency::USD };
    oss << money;
    EXPECT_EQ("USD1.99", oss.str());
}