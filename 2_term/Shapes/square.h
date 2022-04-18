#pragma once
#include "shape.h"

class Square :   public Shape
{
    int a;
public:
    Square();
    Square(int);
    Square(const Square&);
    virtual double area();
    virtual int perimeter();
    virtual void input(istream&);
    virtual void print();
};