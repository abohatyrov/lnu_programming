#pragma once
#include "shape.h"

class Circle :   public Shape
{
    int r;
public:
    Circle();
    Circle(int);
    Circle(const Circle&);
    virtual double area();
    virtual int perimeter();
    virtual void input(istream&);
    virtual void print();
};