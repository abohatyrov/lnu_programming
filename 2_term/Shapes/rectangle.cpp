#include "rectangle.h"


Rectangle::Rectangle()
{
    a = 2;
    b = 1;

}

Rectangle::Rectangle(int _a, int _b)
{
    if (_a > 0 && _b > 0)
    {
        a = _a;
        b = _b;
    }
    else
    {
        cout << "Incorrect data\n";
        a = 0;
        b = 0;
    }
}

Rectangle::Rectangle(const Rectangle& r)
{
    a = r.a;
    b = r.b;
}

double Rectangle::area()
{
    return a * b;
}

int Rectangle::perimeter()
{
    return 2 * (a + b);
}

void Rectangle::input(istream& in)
{
    in >> a;
    in >> b;
}

void Rectangle::print()
{
    cout << "Rectangle: a = " << a << ", b = " << b << ", S = " << area() << ", P = " << perimeter() << endl;
}
