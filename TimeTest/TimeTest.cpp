#include "../LabMain/ArraySequence.h"
#include "../LabMain/LinkedlistSequence.h"
#include <ctime>
#include <iostream>
#include <fstream>

#include <iostream>

using namespace std;

int main()
{
    ofstream fout("Time.txt");
    cout << 1;
    fout << "\nAppend DynamicArraySeq\n";
    for (int i = 1; i < 15; i++) {
        int start = clock();
        ArraySequence<int>* D1 = new ArraySequence<int>;
        for (int j = 0; j < pow(2, i); j++) {
            D1->Append(1);
        }

        int end = clock();
        int x = end - start;
        fout << x << " " << pow(2, i) << "\n";
    }

    cout << 2;
    fout << "\nPrepend DynamicArraySeq\n";
    for (int i = 1; i < 15; i++) {
        int start = clock();
        ArraySequence<int>* D1 = new ArraySequence<int>;
        for (int j = 0; j < pow(2, i); j++) {
            D1->Prepend(1);
        }

        int end = clock();
        int x = end - start;
        fout << x << " " << pow(2, i) << "\n";
    }
    cout << 3;
    fout << "\nSet DynamicArraySeq\n";
    for (int i = 1; i < 15; i++) {
        int* d1 = new int[pow(2, i)];
        ArraySequence<int>* D1 = new ArraySequence<int>(d1,pow(2, i));
        int start = clock();
        for (int j = 0; j < pow(2, i); j++) {
            D1->Set(i, 1);
        }

        int end = clock();
        int x = end - start;
        fout << x << " " << pow(2, i) << "\n";
    }
    cout << 4;
    fout << "\nAppend LinkedListSeq\n";
    for (int i = 1; i < 15; i++) {
        int start = clock();
        LinkedListSequence<int>* D1 = new LinkedListSequence<int>;
        for (int j = 0; j < pow(2, i); j++) {
            D1->Append(1);
        }
        int end = clock();
        int x = end - start;
        fout << x << " " << pow(2, i) << "\n";
    }
    cout << 5;
    fout << "\nPrepend LinkedListSeq\n";
    for (int i = 1; i < 15; i++) {
        int start = clock();
        LinkedListSequence<int>* D1 = new LinkedListSequence<int>;
        for (int j = 0; j < pow(2, i); j++) {
            D1->Prepend(1);
        }
        int end = clock();
        int x = end - start;
        fout << x << " " << pow(2, i) << "\n";
    }
    cout << 6;
    fout << "\nSet LinkedListSeq\n";
    for (int i = 1; i < 15; i++) {
        int* d1 = new int[pow(2, i)];
        LinkedListSequence<int>* D1 = new LinkedListSequence<int>(d1,pow(2, i));
        int start = clock();

        for (int j = 0; j < pow(2, i); j++) {
            D1->Set(i, 1);
        }

        int end = clock();
        int x = end - start;
        fout << x << " " << pow(2, i) << "\n";
    }
}




