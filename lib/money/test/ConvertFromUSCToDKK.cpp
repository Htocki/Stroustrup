#include "gtest/gtest.h"

#include "Conversions.h"
#include "Currency.h"
#include "Money.h"

TEST(ConversionsTest, ConvertFromUSCToDKKTest) {
    EXPECT_EQ(
        ConvertFromUSCToDKK(200),
        3
    );
}