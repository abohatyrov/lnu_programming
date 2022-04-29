// Похідні класи “Юридичний” (поле: кількість телефонних номерів) та “Фізичний” (поле: прізвище, ім’я, по-батькові у вигляді однієї стрічки).
#pragma once
#include <iostream>
#include <string>
#include "consumer_sub.h"

using namespace std;

class Legal : public Consumer
{
private:
    int countOfNumbers;
public:
    Legal();
    Legal(int, string, long, int, int);
    Legal(Legal&);

    int GetCountOfNumbers();
    void SetCountOfNumbers(int);

    void ChangeDebt(int const) override;

    void input(istream&) override;
    void print(ostream&) override;

    friend istream& operator >>(istream&, Legal&);
    friend ostream& operator <<(ostream&, Legal&);
};

Legal::Legal():Consumer()
{
    countOfNumbers = 1;
}

Legal::Legal(int _cn, string _a, long _mn, int _d, int _countOfNumbers):Consumer(_cn, _a, _mn, _d)
{
    countOfNumbers = _countOfNumbers;
}

Legal::Legal(Legal& leg):Consumer(leg.GetConsumerNumber(), leg.GetAddress(), leg.GetMobileNumber(), leg.GetDebt())
{
    countOfNumbers = leg.countOfNumbers;
}

int Legal::GetCountOfNumbers() { return countOfNumbers; }

void Legal::SetCountOfNumbers(int _con) { countOfNumbers = _con; }

void Legal::ChangeDebt(int const percent)
{
    Consumer::ChangeDebt(percent);
    SetDebt(GetDebt() - GetDebt() * ((countOfNumbers / 5 * 10) / 100.0));
}

void Legal::input(istream& is)
{
    Consumer::input(is);
    is >> countOfNumbers;
}

void Legal::print(ostream& os)
{
    Consumer::print(os);
    os << "Count of numbers: " << countOfNumbers << endl;
}

istream& operator >>(istream& is, Legal& leg)
{
    leg.input(is);
    return is;
}

ostream& operator <<(ostream& os, Legal& leg)
{
    leg.print(os);
    return os;
}
