#pragma once

#include "ArraySequence.h"

template <class T> class LiniarForm {
private:
	ArraySequence<T>* data;
public:

	LiniarForm() {  // Создание пустой линейной формы
		data = new ArraySequence<T>;
	}

	LiniarForm(T* ndata, int l) {   // Копирование элементов из переданного массива
		data = new ArraySequence<T>[l];
		for (int i = 0; i < l; i++)
			data->Append(ndata[i]);
	}

	LiniarForm(LiniarForm<T>& Lin) {   // Копирующий конструктор
		int l = Lin.GetSize();
		data = new ArraySequence<T>;
		for (int i = 0; i < l; i++)
			data->Append(Lin.Get(i));
	}

	int GetSize() {  // Получение размера
		return data->GetLength();
	}

	T Get(int index) {    // Получение элемента по индексу
		return data->Get(index);
	}

	void Sum(LiniarForm<T> b) {   // Суммирование
		if (this->GetSize() > b.GetSize()) {
			for (int i = 0; i < b.GetSize(); i++) {
 				this->data->Set(b.Get(i) + this->data->Get(i), i);
			}
		}
		else {

			for (int i = 0; i < this->GetSize(); i++) {
				this->data->Set(b.Get(i) + this->data->Get(i), i);
			}

			int l = this->GetSize();
			this->data->Resize(b.GetSize());
			for (int i = l; i < this->GetSize(); i++) {
				this->data->Set(b.Get(i),i);
			}
		}
	}

	void Subtraction(LiniarForm<T> b) {   // Вычитание
		if (this->GetSize() > b.GetSize()) {
			for (int i = 0; i < b.GetSize(); i++) {
				this->data->Set(this->data->Get(i) - b.Get(i), i);
			}
		}
		else {

			for (int i = 0; i < this->GetSize(); i++) {
				this->data->Set(this->data->Get(i) - b.Get(i), i);
			}
			int l = this->GetSize();
			this->data->Resize(b.GetSize());
			for (int i = l; i < this->GetSize(); i++) {
				this->data->Set(b.Get(i) * (-1), i);
			}
		}

	}

	void Multiplication(T x) {   //  Умножение
		for (int i = 0; i < this->GetSize(); i++)
			this->data->Set(this->data->Get(i) * x, i);
	}

	T value(ArraySequence<T>* x) {
		assert(x->GetLength() == this->GetSize());
		T sum = 0;
		for (int i = 0; i < this->GetSize(); i++) {
			T y = this->Get(i) * x->Get(i);
			sum = sum + y;
		}
		return sum;
	}

	void Printinfo() {  
		cout << "\nДлина:\n" << this->GetSize() << "\nИнформация:\n";
		for (int i = this->GetSize() - 1; i >= 0; i--)
			cout << "+(" << data->Get(i) << ")*x" << i;
		cout << "\n";
	};
};
