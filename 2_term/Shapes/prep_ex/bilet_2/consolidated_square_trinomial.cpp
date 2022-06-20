#include <iostream>
#include "square_trinomial.h"
#include "consolidated_square_trinomial.h"

template <class T>
ConsolidatedSquareTrinomial<T>::ConsolidatedSquareTrinomial() : SquareTrinomial<T>()
{
}

template <class T>
ConsolidatedSquareTrinomial<T>::ConsolidatedSquareTrinomial(T _a, T _b, T _c)
    : SquareTrinomial<T>(_a, _b, _c)
{
}

template <class T>
ConsolidatedSquareTrinomial<T>::ConsolidatedSquareTrinomial(SquareTrinomial<T>& st)
    : SquareTrinomial<T>(1, st.get_b() / st.get_a(), st.get_c() / st.get_a())
{
}

template <class T>
ConsolidatedSquareTrinomial<T>::ConsolidatedSquareTrinomial(ConsolidatedSquareTrinomial<T>& cst)
    : SquareTrinomial<T>(cst.get_a(), cst.get_b(), cst.get_c())
{
}


template <class T>
void ConsolidatedSquareTrinomial<T>::consolidate()
{
    consolidated = true;
    T a = SquareTrinomial<T>::get_a();
    if (a == 0) return;
    T b = SquareTrinomial<T>::get_b() / a;
    T c = SquareTrinomial<T>::get_c() / a;
    SquareTrinomial<T>::set_b(b);
    SquareTrinomial<T>::set_c(c);
    SquareTrinomial<T>::set_a(1);
}


template <class T>
void ConsolidatedSquareTrinomial<T>::print(ostream& os)
{
    if (SquareTrinomial<T>::get_a() != 1 && consolidated)
        os << "Can't consolidate\n";
    else if (consolidated)
        os << "Consolidated: ";
    SquareTrinomial<T>::print(os);
}

template <class T>
void ConsolidatedSquareTrinomial<T>::input(istream& is)
{
    SquareTrinomial<T>::input(is);
}

template <class T>
istream& operator>>(istream& is, ConsolidatedSquareTrinomial<T>& ConsolidatedSquareTrinomial)
{
    ConsolidatedSquareTrinomial.input(is);
    return is;
}

template <class T>
ostream& operator<<(ostream& os, ConsolidatedSquareTrinomial<T>& ConsolidatedSquareTrinomial)
{
    ConsolidatedSquareTrinomial.print(os);
    return os;
}