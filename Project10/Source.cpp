#include <iostream>
#include <Windows.h>
#include "bitset.h"
using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Bitset myBitset;

    myBitset.set(0);
    myBitset.set(1);
    myBitset.set(2);
    myBitset.set(3);
    cout << "Бітова множина після встановлення перших 4 бітів\n";
    myBitset.print();
    myBitset.flip(7);
    myBitset.flip(3);
    cout << "Бітова множина після методу flip для 8 і 4 бітів\n";
    myBitset.print();
    cout << "Приклад використання оператора []\nmyBitSet[1] = false\n";
    myBitset[1] = false;
    cout << "Значення другого біту після використання оператора[] = ";
    cout << boolalpha << myBitset[1];
    Bitset other;
    return 0;
}