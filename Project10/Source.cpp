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
    cout << "������ ������� ���� ������������ ������ 4 ���\n";
    myBitset.print();
    myBitset.flip(7);
    myBitset.flip(3);
    cout << "������ ������� ���� ������ flip ��� 8 � 4 ���\n";
    myBitset.print();
    cout << "������� ������������ ��������� []\nmyBitSet[1] = false\n";
    myBitset[1] = false;
    cout << "�������� ������� ��� ���� ������������ ���������[] = ";
    cout << boolalpha << myBitset[1];
    Bitset other;
    return 0;
}