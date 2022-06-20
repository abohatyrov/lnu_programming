#pragma once
#include "square_trinomial.h"

using namespace std;

template <class T>
class ConsolidatedSquareTrinomial : public SquareTrinomial<T>
{
    bool consolidated = false;
public:
    ConsolidatedSquareTrinomial();
    ConsolidatedSquareTrinomial(T, T, T);
    ConsolidatedSquareTrinomial(SquareTrinomial<T>&);
    ConsolidatedSquareTrinomial(ConsolidatedSquareTrinomial<T>&);

    void consolidate();

    void print(ostream&);
	void input(istream&);
    template<class U> friend istream& operator>>(istream&, ConsolidatedSquareTrinomial<U>&);
    template<class U> friend ostream& operator<<(ostream&, ConsolidatedSquareTrinomial<U>&);
};