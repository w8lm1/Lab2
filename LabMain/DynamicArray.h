#pragma once

template <class T>
class DynamicArray {
private:
    T* array;
    int len; // длина массива
    int size; // размер(кол-во ячеек в массиве)
public:
    class IndexOutOfRange {};

    // Создание
    DynamicArray(T* items, int count); // Копирование элементов из переданного массива
    DynamicArray(int newSize); // создание пустого массива заданой длины
    DynamicArray(DynamicArray<T> const& dynamicArray); // копирующий конструктор
    DynamicArray(); // создание пустого масива

    // Декомпозиция
    T Get(int index); // Получить элемент по индексу
    int GetSize(); // Получить размер массива
    int GetLen(); // Получить длину массива

    // Операции
    void Set(T value, int index); // Задать элемент по индексу
    void Resize(int newSize); // Изменить размер массива
    void Relen(int newLen); // Изменить длину массива

    // Оператор перегрузки
    DynamicArray<T>& operator = (DynamicArray<T> dynamicArray) {
        Resize(dynamicArray.GetSize());
        size = dynamicArray.GetSize();
        len = dynamicArray.GetLen();
        for (int i = 0; i < len; i++) {
            array[i] = dynamicArray.array[i];
        }
        return *this;
    }
};


