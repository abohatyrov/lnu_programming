#include "triangle.h"


Triangle::Triangle()
{
    a = 1;
    b = 1;
    c = 1;
}

Triangle::Triangle(int _a, int _b, int _c)
{
    if (_a > 0 && _b > 0 && _c > 0 && _a + _b > _c && _b + _c > _a && _a + _c > _b)
    {
        a = _a;
        b = _b;
        c = _c;
    }
    else
    {
        cout << "Incorrect data\n";
        a = 0;
        b = 0;
        c = 0;
    }
}

Triangle::Triangle(const Triangle& t)
{
    a = t.a;
    b = t.b;
    c = t.c;
}

double Triangle::area()
{
    double p = (a + b + c) / 2.0;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}

int Triangle::perimeter()
{
    return a + b + c;
}

void Triangle::input(istream& in)
{
    in >> a;
    in >> b;
    in >> c;
}

void Triangle::print()
{
    cout << "Triangle: a = " << a << ", b = " << b << ", c = " << c << ", S = " << area() << ", P = " << perimeter() << endl;
}
