#pragma once
#include <iostream>

class Bitset 
{
private:
    unsigned char data;

public:
    class BitProxy
    {
    private:
        unsigned char& byte;
        int position;

    public:
        BitProxy(unsigned char& byte_ref, int pos) : byte(byte_ref), position(pos) {}

        operator bool() const
        {
            return (byte & (1 << position)) != 0;
        }
        BitProxy& operator=(bool value)
        {
            if (value)
                byte |= (1 << position);
            else
                byte &= ~(1 << position);
            return *this;
        }
    };
    Bitset() : data(0) {}

    void set(int pos);
    
    void reset(int pos);

    void flip(int pos);

    bool test(int pos) const;

    bool none();
   
    bool any();
    
    int count();
   
    int size();
    
    BitProxy operator[](int pos);
    
    void print() const;
};