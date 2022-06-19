#pragma once
#include <cmath>
#include <vector>

using namespace std;

template <class T>
class SquareTrinomial
{
private:
    T a;
    T b;
    T c;
public:
    SquareTrinomial();
    SquareTrinomial(T, T, T);
    SquareTrinomial(SquareTrinomial<T>&);

    T discriminant();
    T* roots();

    T get_a();
    T get_b();
    T get_c();

    void set_a(T);
    void set_b(T);
    void set_c(T);

    void operator+(SquareTrinomial<T>&);
    void operator-(SquareTrinomial<T>&);
    void operator*(T);

    virtual void print(ostream&);
	virtual void input(istream&);
    template<class U> friend istream& operator>>(istream&, SquareTrinomial<U>&);
    template<class U> friend ostream& operator<<(ostream&, SquareTrinomial<U>&);
};