#include "bitset.h"

void Bitset::set(int pos)
{
    data |= (1 << pos);
}

void Bitset::reset(int pos)
{
    data &= ~(1 << pos);
}

void Bitset::flip(int pos)
{
    data ^= (1 << pos);
}

bool Bitset::test(int pos) const
{
    return (data & (1 << pos)) != 0;
}

bool Bitset::none()
{
    for (int i = 0; i < size(); ++i)
    {
        if (test(i))
        {
            return false;
        }
    }
    return true;
}

bool Bitset::any()
{
    for (int i = 0; i < size(); ++i)
    {
        if (!test(i))
        {
            return false;
        }
    }
    return true;
}

int Bitset::count()
{
    int counter = 0;
    for (int i = sizeof(data) * 8 - 1; i >= 0; --i)
    {
        if (test(i))
            ++counter;
    }
    return counter;
}

int Bitset::size()
{
    return sizeof(data) * 8;
}

Bitset::BitProxy Bitset::operator[](int pos)
{
    return BitProxy(data, pos);
}

void Bitset::print() const
{
    for (int i = sizeof(data) * 8 - 1; i >= 0; --i)
    {
        if (test(i))
            std::cout << 1;
        else std::cout << 0;
    }
    std::cout << std::endl;
}