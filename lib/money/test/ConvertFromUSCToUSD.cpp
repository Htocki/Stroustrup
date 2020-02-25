#include "gtest/gtest.h"

#include "Conversions.h"
#include "Currency.h"
#include "Money.h"

TEST(ConversionsTest, ConvertFromUSCToUSDTest) {
    EXPECT_EQ(
        ConvertFromUSCToUSD(2445),
        24.45
    );
}