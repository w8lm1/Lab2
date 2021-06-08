#include "pch.h"
#include "gtest/gtest.h"
#include "../LabMain/Vector.h"
#include "../LabMain/ArraySequence.h"

TEST(TestVector, TestLiniarCreation) {
    double* d1 = new double[4];
    d1[0] = 1;
    d1[1] = 2;
    d1[2] = 3;
    d1[3] = 4;
    Vector<double>* D1 = new Vector<double>(d1, 4);
    for (int i = 0; i < D1->GetVectorLen(); i++)
        EXPECT_TRUE(D1->GetCoord(i), d1[i]);
}
TEST(TestVector, Sum) {
    double* d1 = new double[4];
    d1[0] = 1;
    d1[1] = 2;
    d1[2] = 3;
    d1[3] = 4;
    Vector<double>* D1 = new Vector<double>(d1, 4);
    double* d2 = new double[4];
    d2[0] = 5;
    d2[1] = 6;
    d2[2] = 7;
    d2[3] = 8;
    Vector<double>* D2 = new Vector<double>(d2, 4);
    D1->SumVec(*D2);
    for (int i = 0; i < D1->GetVectorLen(); i++)
        EXPECT_EQ(D1->GetCoord(i), d1[i] + d2[i]);
}
TEST(TestVector, TestMultScalar) {
    double* d1 = new double[4];
    d1[0] = 1;
    d1[1] = 2;
    d1[2] = 3;
    d1[3] = 4;
    int x = 7;
    Vector<double>* D1 = new Vector<double>(d1, 4);
    D1->MultScalar(x);
    for (int i = 0; i < D1->GetVectorLen(); i++)
        EXPECT_EQ(D1->GetCoord(i), d1[i] * x);
}
TEST(TestVector, TestMultVec) {
    double* d1 = new double[4];
    d1[0] = 1;
    d1[1] = 2;
    d1[2] = 3;
    d1[3] = 4;
    Vector<double>* D1 = new Vector<double>(d1, 4);
    Vector<double>* D2 = new Vector<double>(d1, 4);

    D1->MultVec(*D2);
    for (int i = 0; i < D1->GetVectorLen(); i++)
        EXPECT_EQ(D1->GetCoord(i), d1[i]*d1[i]);
}
