#pragma once
#include "shape.h"


class Triangle :    public Shape
{
    int a;
    int b;
    int c;
public:
    Triangle();
    Triangle(int, int, int);
    Triangle(const Triangle&);
    virtual double area();
    virtual int perimeter();
    virtual void input(istream&);
    virtual void print();
};
