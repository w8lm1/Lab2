#pragma once

#include "Sequence.h"
#include "LinkedList.h"

using namespace std;
template <class T> class LinkedListSequence : public Sequence<T>
{
private:
    LinkedList<T>* list;
public:
    LinkedListSequence() {  //�������� ������ ������������������
        list = new LinkedList<T>;
    }

    LinkedListSequence(T* data, int x) { //����������� ��������� �� ���������� �������
        list = new LinkedList<T>;


        for (int i = 0; i < x; i++) {
            list->Append(data[i]);
        }
    }

    LinkedListSequence(int index) {  // �������� ������ �� ������ ��������
        list = new LinkedList<T>(index);
    }

    LinkedListSequence(LinkedListSequence<T>& copy) {   //���������� �����������
        list = new LinkedList<T>;
        for (int i = 0; i < copy.GetLength(); i++) {
            list->Append(copy.Get(i));
        }
    }

    T GetFirst() {  //��������� ������� ��������
        return list->GetFirst();
    }

    T GetLast() {   // ��������� ���������� ��������
        return list->GetLast();
    }

    T Get(int index) {  // ��������� �������� �� �������
        assert(index <= this->GetLength());
        return list->Get(index);
    }

    int GetLength() {  // ��������� �����
        return list->GetLength();
    }

    void Resize(int newsize) {   //  ��������� �������
        list->Resize(newsize);
    }

    void Set(int index, T value) {  //  ������� �������� �� �������

        assert(index <= this->GetLength());
        list->Set(index, value);
    }

    void Append(T value) {   // �������� � �����
        list->Append(value);
    }

    void Prepend(T value) {    // �������� � ������
        list->Prepend(value);
    }

    void InsertAt(T value, int count) {   // ��������� ������� � �������� �������
        list->InsertAt(count, value);
    }

    LinkedListSequence<T>* GetSubsequence(int startIndex, int endIndex) {  // ������������������ � startIndex �� endIndex
        assert(startIndex >= 0);
        assert(startIndex < this->GetLength());
        assert(endIndex >= 0);
        assert(endIndex <= this->GetLength());
        LinkedListSequence<T>* temp = new LinkedListSequence<T>;
        for (int i = startIndex; i < endIndex; i++) {
            temp->Append(this->Get(i));
        }
        return temp;
    }

    LinkedListSequence<T>* Concat(Sequence<T>* data) {    // concat ���� �������

        LinkedListSequence<T>* res = new LinkedListSequence<T>;
        for (int i = 0; i < this->GetLength(); i++) {

            res->Append(this->Get(i));
        }
        for (int i = 0; i < data->GetLength(); i++) {
            res->Append(data->Get(i));
        }

        return res;
    }
};

