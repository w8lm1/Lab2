#pragma once

#include "ArraySequence.h"

    template<class T> class Vector {
    private:
        ArraySequence<T>* vector;
    public:
        // �������� ������� �������
        Vector() {
            vector = new ArraySequence<T>;
        }
        // // ����������� ��������� �� ����������� �������
        Vector(T* coords, int count) {
            vector = new ArraySequence<T>[count];
            for (int i = 0; i < count; i++)
                vector->Append(coords[i]);
        }
        // // ���������� �����������
        Vector(ArraySequence<T>& n_vector) {
            int l = n_vector.GetLength();
            vector = new ArraySequence<T>;
            for (int i = 0; i < l; i++)
                vector->Append(n_vector.Get(i));
        }

        // ������������
        T GetCoord(int index) {
            return vector->Get(index);
        }
        int GetVectorLen() {
            return vector->GetLength();
        }

        // ��������
        void SumVec(Vector<T> b) {
            if (this->GetVectorLen() == b.GetVectorLen()) {
                for (int i = 0; i < b.GetVectorLen(); i++) {
                    this->vector->Set(b.GetCoord(i) + this->GetCoord(i), i);
                }
            }
            else cout << "������� ������ ������������\n";
        }
        
        void MultVec(Vector<T> b) {
            if (this->GetVectorLen() == b.GetVectorLen()) {
                for (int i = 0; i < b.GetVectorLen(); i++) {
                    this->vector->Set(b.GetCoord(i) * this->vector->Get(i), i);
                }
            }
            else cout << "������� ������ ������������\n";
        }

        void MultScalar(T x) {
            for (int i = 0; i < this->GetVectorLen(); i++)
                this->vector->Set(this->vector->Get(i) * x, i);
        }

       T Norm() {
            T sum = 0;
            for (int i = 0; i < this->GetVectorLen(); i++)
                sum = sum + (this->vector->Get(i)) * (this->vector->Get(i));
            sum = sqrt(sum);
            return sum;
        }

        void PrintinfoVec() {
            cout << "\n�����:\n" << this->GetVectorLen() << "\n����������:\n";
            cout << '{';
            for (int i = 0 ; i <= this->GetVectorLen() - 1; i++) {
                cout << this->GetCoord(i);
                if (i != this->GetVectorLen() - 1) {
                    cout << ", ";
                }
            }
            cout << "}\n";
        };
       
        // overloading operators "="
        Vector<T>& operator = (Vector<T> n_vector) {
            vector = n_vector.vector;
            return *this;
        }
    };
