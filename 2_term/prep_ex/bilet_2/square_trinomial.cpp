#include <iostream>
#include "square_trinomial.h"

using namespace std;

template <class T>
SquareTrinomial<T>::SquareTrinomial()
{
    a = 0;
    b = 0;
    c = 0;
}   

template <class T>
SquareTrinomial<T>::SquareTrinomial(T _a, T _b, T _c)
{
    a = _a;
    b = _b;
    c = _c;
}

template <class T>
SquareTrinomial<T>::SquareTrinomial(SquareTrinomial<T>& st)
{
    a = st.a;
    b = st.b;
    c = st.c;
}

template <class T>
T SquareTrinomial<T>::discriminant()
{
    return b*b - 4 * a * c;
}

template <class T>
T* SquareTrinomial<T>::roots()
{
    if (discriminant() < 0)
        return 0;
    
    T* x = new T[2];
    x[0] = (-b - sqrt(discriminant())) / (2 * a);
    x[1] = (-b + sqrt(discriminant())) / (2 * a);
    if (x[0] > x[1])
    {
        T temp = x[0];
        x[0] = x[1];
        x[1] = x[0];
    }
    return x;
}


template <class T>
T SquareTrinomial<T>::get_a()
{
    return a;
}

template <class T>
T SquareTrinomial<T>::get_b()
{
    return b;
}

template <class T>
T SquareTrinomial<T>::get_c()
{
    return c;
}


template <class T>
void SquareTrinomial<T>::set_a(T _a)
{
    a = _a;
}

template <class T>
void SquareTrinomial<T>::set_b(T _b)
{
    b = _b;
}

template <class T>
void SquareTrinomial<T>::set_c(T _c)
{
    c = _c;
}


template<class T> 
void SquareTrinomial<T>::operator+(SquareTrinomial<T>& st)
{
    a += st.a;
    b += st.b;
    c += st.c;
}

template <class T>
void SquareTrinomial<T>::operator-(SquareTrinomial<T>& st)
{
    a -= st.a;
    b -= st.b;
    c -= st.c;
}

template <class T>
void SquareTrinomial<T>::operator*(T scalar)
{
    a *= scalar;
    b *= scalar;
    c *= scalar;
}


template <class T>
void SquareTrinomial<T>::print(ostream& os)
{
    if (a != 0)
    {
        if (a != 1)
            os << a;
        os << "x^2 ";
        if (b > 0) 
        {
            os << "+ " << b << "x ";
            if (c > 0) 
                os << "+ " << c;
            else if (c != 0)
                os << "- " << c * -1;
        }
        else if (b < 0)
        {
            os << "- " << b * -1 << "x ";
            if (c > 0) 
                os << "+ " << c;
            else if (c != 0)
                os << "- " << c * -1;
        }
        else
        {
            if (c > 0) 
                os << "+ " << c;
            else if (c != 0)
                os << "- " << c * -1;
        }
    }
    else
    {
        if (b > 0) 
        {
            os << b << "x ";
            if (c > 0) 
                os << "+ " << c;
            else if (c != 0)
                os << "- " << c * -1;
        }
        else if (b < 0)
        {
            os << b << "x ";
            if (c > 0) 
                os << "+ " << c;
            else if (c != 0)
                os << "- " << c * -1;
        }
        else
        {
            if (c > 0) 
                os << c;
            else if (c != 0)
                os << c;
        }
    } 
}

template <class T>
void SquareTrinomial<T>::input(istream& is)
{
    T _a, _b, _c;
    cout << "[+] Enter polynom [+]\n";
    cout << "Enter a: ";
    is >> _a;
    cout << "Enter b: ";
    is >> _b;
    cout << "Enter c: ";
    is >> _c;
    cout << endl;

    this->set_a(_a);
    this->set_b(_b);
    this->set_c(_c);
}

template <class T>
istream& operator>>(istream& is, SquareTrinomial<T>& st)
{
    st.input(is);
    return is;
}

template <class T>
ostream& operator<<(ostream& os, SquareTrinomial<T>& st)
{
    st.print(os);
    return os;
}
