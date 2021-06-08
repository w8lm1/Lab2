#include "Interface.h"
#include <iostream>

void MainInterface() {
    int var;
    cout << "Выберете вариант, с которым будете работать\n"
        << "\t1: Линейная форма\n"
        << "\t2: Вектор\n"
        << "Введите число: ";
    cin >> var;

    switch (var) {
    case 1: InterfaceLinearForm(); break;
    case 2: InterfaceVector(); break;
    default: break;
    }
}
