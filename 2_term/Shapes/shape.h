#pragma once
#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

class Shape
{
public:
    virtual double area() = 0;
    virtual int perimeter() = 0;
    virtual void input(istream&) = 0;
    virtual void print() = 0;
};