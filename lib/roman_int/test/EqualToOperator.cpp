#include "gtest/gtest.h"

#include "Roman_int.h"

TEST(Roman_intTest, EqualToOperatorTest) {
    EXPECT_EQ(
        operator==(Roman_int(), Roman_int()),
        true
    );

    EXPECT_EQ(
        operator==(Roman_int("XXX"), Roman_int("XXX")),
        true
    );

    EXPECT_EQ(
        operator==(Roman_int("IX"), Roman_int("IX")),
        true
    );

    EXPECT_EQ(
        operator==(Roman_int("XXX"), Roman_int("II")),
        false
    );

    EXPECT_EQ(
        operator==(Roman_int("MCMXLIX"), Roman_int("MCMXLIX")),
        true
    );
}