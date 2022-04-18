#include "square.h"


Square::Square()
{
    a = 1;
}

Square::Square(int _a)
{
    if (_a > 0)
    {
        a = _a;
    }
    else
    {
        cout << "Incorrect data\n";
        a = 0;
    }
}

Square::Square(const Square& s)
{
    a = s.a;
}

double Square::area()
{
    return a * a;
}

int Square::perimeter()
{
    return 4 * a;
}

void Square::input(istream& in)
{
    in >> a;
}

void Square::print()
{
    cout << "Square: a = " << a << ", S = " << area() << ", P = " << perimeter() << endl;
}
