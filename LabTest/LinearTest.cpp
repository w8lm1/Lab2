#include "pch.h"
#include "gtest/gtest.h"
#include "../LabMain/LinearForm.h"
#include "../LabMain/ArraySequence.h"

TEST(TestLinearform, TestLiniarCreation) {
    double* d1 = new double[4];
    d1[0] = 1;
    d1[1] = 2;
    d1[2] = 3;
    d1[3] = 4;
    LiniarForm<double>* D1 = new LiniarForm<double>(d1, 4);
    for (int i = 0; i < D1->GetSize(); i++)
        EXPECT_TRUE(D1->Get(i),d1[i]);
}
TEST(TestLinearform, Sum) {
    double* d1 = new double[4];
    d1[0] = 1;
    d1[1] = 2;
    d1[2] = 3;
    d1[3] = 4;
    LiniarForm<double>* D1 = new LiniarForm<double>(d1, 4);
    double* d2 = new double[4];
    d2[0] = 5;
    d2[1] = 6;
    d2[2] = 7;
    d2[3] = 8;
    LiniarForm<double>* D2 = new LiniarForm<double>(d2, 4);
    D1->Sum(*D2);
    for (int i = 0; i < D1->GetSize(); i++)
        EXPECT_EQ(D1->Get(i), d1[i]+d2[i]);
}
TEST(TestLinearform, TestMult) {
    double* d1 = new double[4];
    d1[0] = 1;
    d1[1] = 2;
    d1[2] = 3;
    d1[3] = 4;
    int x = 7;
    LiniarForm<double>* D1 = new LiniarForm<double>(d1, 4);
    D1->Multiplication(x);
    for (int i = 0; i < D1->GetSize(); i++)
        EXPECT_EQ(D1->Get(i), d1[i] * x);
}
TEST(TestLinearform, TestValue) {
    double* d1 = new double[4];
    d1[0] = 1;
    d1[1] = 2;
    d1[2] = 3;
    d1[3] = 4;
    LiniarForm<double>* D1 = new LiniarForm<double>(d1, 4);
    ArraySequence<double>* A = new ArraySequence<double>(d1, 4);
    int x = D1->value(A);
    EXPECT_EQ(x, 30);
}