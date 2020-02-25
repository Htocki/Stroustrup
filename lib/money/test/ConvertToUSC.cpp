#include "gtest/gtest.h"

#include "Conversions.h"
#include "Currency.h"
#include "Money.h"

TEST(ConversionsTest, ConvertToUSCTest) {
    EXPECT_EQ(
        ConvertToUSC(2.0, Currency::USD),
        ConvertToUSC(3.0, Currency::DKK)
    );
}