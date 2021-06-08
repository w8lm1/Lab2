#pragma once

template <class T>
class DynamicArray {
private:
    T* array;
    int len; // ����� �������
    int size; // ������(���-�� ����� � �������)
public:
    class IndexOutOfRange {};

    // ��������
    DynamicArray(T* items, int count); // ����������� ��������� �� ����������� �������
    DynamicArray(int newSize); // �������� ������� ������� ������� �����
    DynamicArray(DynamicArray<T> const& dynamicArray); // ���������� �����������
    DynamicArray(); // �������� ������� ������

    // ������������
    T Get(int index); // �������� ������� �� �������
    int GetSize(); // �������� ������ �������
    int GetLen(); // �������� ����� �������

    // ��������
    void Set(T value, int index); // ������ ������� �� �������
    void Resize(int newSize); // �������� ������ �������
    void Relen(int newLen); // �������� ����� �������

    // �������� ����������
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


