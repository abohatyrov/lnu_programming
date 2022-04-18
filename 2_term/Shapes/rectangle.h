#pragma once
#include "shape.h"

class Rectangle :   public Shape
{
    int a;
    int b;
public:
    Rectangle();
    Rectangle(int, int);
    Rectangle(const Rectangle&);
    virtual double area();
    virtual int perimeter();
    virtual void input(istream&);
    virtual void print();
};