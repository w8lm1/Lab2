#pragma once

#include <iostream>
#include <cassert>

using namespace std;

template <typename T> class Item
{
public:
	T data;	
	Item<T>* next;	
	Item<T>* previous;
};

template <class T> class LinkedList
{
	Item<T>* head;	
	Item<T>* tail;
	int lenght;	
public:

	// Конструкторы
	LinkedList()// Создание пустого списока
	{
		head = NULL;
		tail = NULL;
		lenght = 0;
	};

	LinkedList(T* items, int count) //	Копирование элементов из переданного массива
	{
		head = NULL;
		tail = NULL;

		for (int i = 0; i < count; i++)
		{
			Append(items[i]);
		}
	}
	
	LinkedList(LinkedList <T>& list)  // Копирующий конструктор
	{
		head = NULL;
		tail = NULL;
		for (int i = 0; i < list.lenght; i++)
		{
			Append(list.Get(i));
		}
	};
	// Декомпозиция

	T GetFirst() // Получить первый элемент в списке
	{
		return T(head->data);
	}

	T GetLast() // Получить последний элемент в списке
	{
		return T(tail->data);
	}

	Item<T>* operator[](int index)
	{
		if (index == 0 && lenght == 0)
			return NULL;
		assert(index >= 0);
		assert(index < lenght);
		Item<T>* buf = head;
		for (int i = 0; i < index; i++)
		{
			buf = buf->next;
		}
		return buf;
	}

	T Get(int index) // Получить элемент по индексу
	{
		assert(!(index == 0 && lenght == 0));
		assert(index >= 0);
		assert(index < lenght);
		Item<T>* buf = head;
		for (int i = 0; i < index; i++)
		{
			buf = buf->next;
		}
		return buf->data;
	}

	// Получить список из всех элементов, начиная с startIndex и заканчивая endIndex.
	LinkedList<T>* GetSubList(int startIndex, int endIndex)
	{
		assert(startIndex >= 0);
		assert(endIndex <= lenght);
		LinkedList<T>* buf = new LinkedList<T>();
		for (int i = startIndex; i <= endIndex; i++)
		{
			buf->Append(Get(i));
		}
		return buf;
	}

	int GetLength()	// Получить длину списка
	{
		return lenght;
	}

	void Resize(int x) {
		this->lenght = x;
	}

	void Set(int index, T data)
	{
		assert(!(index == 0 && lenght == 0));
		assert(index >= 0);
		assert(index < lenght);
		Item<T>* buf = head;
		for (int i = 0; i < index; i++)
		{
			buf = buf->next;
		}
		buf->data = data;
	}

	// Операции
		// Добавляет элемент в конец списка
	void Append(T item)
	{
		lenght++;	
		Item<T>* buf = new Item<T>;
		buf->next = NULL;
		buf->data = item;
		if (head == NULL)
		{
			head = buf;
			head->previous = NULL;
			tail = head;
		}
		else
		{
			tail->next = buf;
			buf->previous = tail;
			tail = buf;
		}
	}
	void Prepend(T item) // Добавляет элемент в начало списка
	{
		lenght++;
		Item<T>* buf = new Item<T>;
		buf->next = NULL;
		buf->data = item;
		if (head == NULL)
		{
			head = buf;
			head->previous = NULL;
			tail = head;
		}
		else
		{
			head->previous = buf;
			buf->next = head;
			head = buf;
		}
	}

	void InsertAt(T item, int index) // Вставляет элемент в заданную позицию. 
									
	{
		assert(index >= 0);
		assert(index < lenght); 
		Item<T>* itemBefor = (*this)[index];

		if (itemBefor == NULL)
			Append(item);
		else
		{
			Item<T>* buf = new Item<T>;
			buf->data = item;
			buf->previous = itemBefor;
			buf->next = itemBefor->next;
			itemBefor->next->previous = buf;
			itemBefor->next = buf;
			lenght++;
		}

	}

	//Сцепляет два списка
	LinkedList<T>* Concat(LinkedList<T>* list)
	{
		for (int i = 0; i < list->lenght; i++)
			Append(list->Get(i));
		return this;
	}

};
