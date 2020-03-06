#include "gtest/gtest.h"

#include "Sum.h"

TEST(SumTest, SumNumbersFromFileTest) {
    EXPECT_EQ(
        sum_numbers_from_file("files/File1.txt"),
        4753
    );

    EXPECT_EQ(
        sum_numbers_from_file("files/File2.txt"),
        36
    );

    EXPECT_EQ(
        sum_numbers_from_file("files/File3.txt"),
        -43
    );
}