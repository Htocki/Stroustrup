#include <sstream>

#include "gtest/gtest.h"

#include "Currency.h"
#include "Money.h"

TEST(MoneyTest, InputOperatorTest) {
    std::stringstream ss;
    Money m;
    ss << "USD1.32";
    ss >> m;
    EXPECT_EQ(m, Money(1.32, Currency::USD));
}