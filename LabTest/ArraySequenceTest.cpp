#include "gtest/gtest.h"
#include "pch.h"
#include "../LabMain/ArraySequence.h"
TEST(ArraySequenceTest, Con) {
    double* d1 = new double[4];
    d1[0] = 1;
    d1[1] = 2;
    d1[2] = 3;
    d1[3] = 4;
    ArraySequence<double>* D1 = new ArraySequence<double>(d1, 4);
    for (int i = 0; i < 4; i++)
        EXPECT_EQ(D1->Get(i), d1[i]);
    double* d2 = new double[6];
    d2[0] = 5;
    d2[1] = 6;
    d2[2] = 7;
    d2[3] = 8;
    ArraySequence<double>* D2 = new ArraySequence<double>(d2, 4);
    ArraySequence<double>* Conc = new ArraySequence<double>(*D2->Concat(D1));
    ArraySequence<double>* Sub = new ArraySequence<double>(*Conc->GetSubsequence(2, 4));
    for (int i = 0; i < D2->GetLength(); i++)
        EXPECT_EQ(D2->Get(i), Conc->Get(i));
    for (int i = 0; i < D1->GetLength(); i++)
        EXPECT_EQ(D1->Get(i), Conc->Get(i + D2->GetLength()));
    for (int i = 0; i < Sub->GetLength(); i++)
        EXPECT_EQ(Sub->Get(i), Conc->Get(i + 2));
}

TEST(ArraySequenceTest, ConcatAndSub) {
    double* d1 = new double[4];
    d1[0] = 1;
    d1[1] = 2;
    d1[2] = 3;
    d1[3] = 4;
    ArraySequence<double>* D1 = new ArraySequence<double>(d1, 4);
    double* d2 = new double[6];
    d2[0] = 5;
    d2[1] = 6;
    d2[2] = 7;
    d2[3] = 8;
    ArraySequence<double>* D2 = new ArraySequence<double>(d2, 4);
    ArraySequence<double>* Conc = new ArraySequence<double>(*D2->Concat(D1));
    ArraySequence<double>* Sub = new ArraySequence<double>(*Conc->GetSubsequence(2, 4));
    for (int i = 0; i < D2->GetLength(); i++)
        EXPECT_EQ(D2->Get(i), Conc->Get(i));
    for (int i = 0; i < D1->GetLength(); i++)
        EXPECT_EQ(D1->Get(i), Conc->Get(i + D2->GetLength()));
    for (int i = 0; i < Sub->GetLength(); i++)
        EXPECT_EQ(Sub->Get(i), Conc->Get(i + 2));
}

TEST(ArraySequenceTest, FunctionTest) {
    double* d1 = new double[4];
    d1[0] = 1;
    d1[1] = 2;
    d1[2] = 3;
    d1[3] = 4;
    ArraySequence<double>* D1 = new ArraySequence<double>(d1, 4);
    D1->Append(12);
    D1->Prepend(31);
    EXPECT_EQ(D1->GetFirst(), 31);
    EXPECT_EQ(D1->GetLast(), 12);
    EXPECT_EQ(D1->GetLength(), 6);
}

TEST(ArraySequenceTest, InsertTest) {
    double* d1 = new double[4];
    d1[0] = 1;
    d1[1] = 2;
    d1[2] = 3;
    d1[3] = 4;
    ArraySequence<double>* D2 = new ArraySequence<double>(d1,4);
    D2->InsertAt(123, 2);
    EXPECT_EQ(D2->Get(2), 123);
}
