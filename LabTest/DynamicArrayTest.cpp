#include "gtest/gtest.h"
#include "pch.h"
#include "../LabMain/DynamicArray.h"

TEST(DynamicArrayTest, ConstructTest) {
    double* d1 = new double[4];
    d1[0] = 1;
    d1[1] = 1;
    d1[2] = 1;
    d1[3] = 2;
    DynamicArray<double>* D1 = new DynamicArray<double>(d1,4);
    EXPECT_EQ(d1[0], D1->Get(0));
    EXPECT_EQ(d1[1], D1->Get(1));
    EXPECT_EQ(d1[2], D1->Get(2));
    EXPECT_EQ(d1[3], D1->Get(3));


}

TEST(DynamicArrayTest, SetTest) {
    double* d1 = new double[4];
    d1[0] = 1;
    d1[1] = 1;
    d1[2] = 1;
    d1[3] = 2;
    DynamicArray<double>* D1 = new DynamicArray<double>(d1, 4);
    D1->Set(12, 0);
    D1->Set(13, 1);
    D1->Set(14, 2);
    D1->Set(15, 3);
    EXPECT_EQ(D1->Get(0), 12);
    EXPECT_EQ(D1->Get(1), 13);
    EXPECT_EQ(D1->Get(2), 14);
    EXPECT_EQ(D1->Get(3), 15);


}
