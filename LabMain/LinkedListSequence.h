#pragma once

#include "Sequence.h"
#include "LinkedList.h"

using namespace std;
template <class T> class LinkedListSequence : public Sequence<T>
{
private:
    LinkedList<T>* list;
public:
    LinkedListSequence() {  //создание пустой последовательности
        list = new LinkedList<T>;
    }

    LinkedListSequence(T* data, int x) { //копирование элементов из переданого массива
        list = new LinkedList<T>;


        for (int i = 0; i < x; i++) {
            list->Append(data[i]);
        }
    }

    LinkedListSequence(int index) {  // создание списка из одного элемента
        list = new LinkedList<T>(index);
    }

    LinkedListSequence(LinkedListSequence<T>& copy) {   //Копирующий конструктор
        list = new LinkedList<T>;
        for (int i = 0; i < copy.GetLength(); i++) {
            list->Append(copy.Get(i));
        }
    }

    T GetFirst() {  //Получение первого элемента
        return list->GetFirst();
    }

    T GetLast() {   // Получение последнего элемента
        return list->GetLast();
    }

    T Get(int index) {  // Получение элемента по индексу
        assert(index <= this->GetLength());
        return list->Get(index);
    }

    int GetLength() {  // Получение длины
        return list->GetLength();
    }

    void Resize(int newsize) {   //  Изменение размера
        list->Resize(newsize);
    }

    void Set(int index, T value) {  //  Задание элемента по индексу

        assert(index <= this->GetLength());
        list->Set(index, value);
    }

    void Append(T value) {   // Добавить в конец
        list->Append(value);
    }

    void Prepend(T value) {    // Добавить в начало
        list->Prepend(value);
    }

    void InsertAt(T value, int count) {   // Вставляет элемент в заданную позицию
        list->InsertAt(count, value);
    }

    LinkedListSequence<T>* GetSubsequence(int startIndex, int endIndex) {  // Последовательность с startIndex до endIndex
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

    LinkedListSequence<T>* Concat(Sequence<T>* data) {    // concat двух списков

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

