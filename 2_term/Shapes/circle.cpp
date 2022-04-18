#include "circle.h"


Circle::Circle()
{
    r = 1;

}

Circle::Circle(int _r)
{
    if (_r > 0)
    {
        r = _r;
    }
    else
    {
        cout << "Incorrect data\n";
        r = 0;
    }
}

Circle::Circle(const Circle& c)
{
    r = c.r;
}

double Circle::area()
{
    return 3.1415 * r * r;
}

int Circle::perimeter()
{
    return 2 * 3.1415 * r;
}

void Circle::input(istream& in)
{
    in >> r;
}

void Circle::print()
{
    cout << "Circle: r = " << r << ", S = " << area() << ", P = " << perimeter() << endl;
}
