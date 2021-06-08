#pragma once
#include "Sequence.h"
#include "DynamicArray.h"
#include "DynamicArray.cpp"

template <class T> class ArraySequence : public Sequence<T> {
private:
    DynamicArray<T> dynamicArray;
public:
    class IndexOutOfRange : DynamicArray<T> ::IndexOutOfRange {};

    // // Копирование элементов из переданного массива
    ArraySequence(T* items, int count) {
        dynamicArray = DynamicArray<T>(items, count);
    }
    // Создание пустого массива
    ArraySequence() {
        dynamicArray = DynamicArray<T>(0);
    }
    // Копирующий конструктор
    ArraySequence(const DynamicArray<T>& dynamicArray) {
        dynamicArray = DynamicArray<T>(dynamicArray);
    }

    // Декомпозиция

    // Получение первого элемента
    T GetFirst() {
        return dynamicArray.Get(0);
    }
    // Получение последнего элемента
    T GetLast() {
        return dynamicArray.Get(dynamicArray.GetLen() - 1);
    }
    // Получение элемента по индексу
    T Get(int index) {
        return dynamicArray.Get(index);
    }
    // Получить список из всех элементов, начиная с startIndex и заканчивая endIndex.
    ArraySequence<T>* GetSubsequence(int startIndex, int endIndex) {
        if (startIndex >= dynamicArray.GetLen() || endIndex >= dynamicArray.GetLen() || startIndex < 0 || endIndex < 0) {
            throw IndexOutOfRange();
        }

        auto* new_arraySequence = new ArraySequence<T>;
        int iter;
        if (startIndex < endIndex) {
            iter = 1;
        }
        else {
            iter = -1;
        }

        for (int i = startIndex; i != endIndex; i += iter) {
            new_arraySequence->Append(dynamicArray.Get(i));
        }

        return new_arraySequence;
    }
    // Получить длину
    int GetLength() {
        return dynamicArray.GetLen();
    }

    // Опереции

    void Resize(int newlen) {
        assert(newlen >= 0);
        dynamicArray.Resize(newlen);
        dynamicArray.Relen(newlen);
    }

    // Вставить элемент на позицию
    ArraySequence<T>& Set(T item, int index) {
        dynamicArray.Set(item, index);
        return *this;
    }
    // Добавить в конец
    void Append(T item) {
        int free_cells = dynamicArray.GetSize() - dynamicArray.GetLen();
        if (free_cells == 0) {
            dynamicArray.Resize(dynamicArray.GetSize() + 200);
        }
        dynamicArray.Relen(dynamicArray.GetLen() + 1);
        dynamicArray.Set(item, dynamicArray.GetLen() - 1); //
    }

    // Добавить в начало
    void Prepend(T item) {
        dynamicArray.Resize(dynamicArray.GetLen() + 1);
        dynamicArray.Relen(dynamicArray.GetLen() + 1);
        T saved_cell = dynamicArray.Get(0);
        T this_cell;
        dynamicArray.Set(item, 0); //

        for (int i = 1; i < dynamicArray.GetLen(); i++) {
            this_cell = dynamicArray.Get(i);
            dynamicArray.Set(saved_cell, i); //
            saved_cell = this_cell;
        }
    }
    // Вставить элемент на позицию
    void InsertAt(T item, int index) {
        if (index < 0 || index >= this->GetLength()) { throw IndexOutOfRange(); }

        dynamicArray.Resize(dynamicArray.GetLen() + 1);
        dynamicArray.Relen(dynamicArray.GetLen() + 1);
        T this_cell;
        T saved_cell = dynamicArray.Get(index);
        dynamicArray.Set(item, index); //
        for (int i = index + 1; i < dynamicArray.GetLen(); i++) {
            this_cell = dynamicArray.Get(i);
            dynamicArray.Set(saved_cell,i); //
            saved_cell = this_cell;
        }
    }
    // concat двух списков
    ArraySequence<T>* Concat(Sequence<T>* list) {
        auto* new_arraySequence = new ArraySequence<T>;
        //new_arraySequence = ArraySequence<T>();

        for (int i = 0; i < dynamicArray.GetLen(); i++) {
            new_arraySequence->Append(dynamicArray.Get(i));
        }
        for (int i = 0; i < list->GetLength(); i++) {
            new_arraySequence->Append(list->Get(i));
        }

        return new_arraySequence;
    }

    // оператор перегрузки
    ArraySequence<T>& operator = (ArraySequence<T> n_dynamicArray) {
        dynamicArray = n_dynamicArray.dynamicArray;
        return *this;
    }
};

