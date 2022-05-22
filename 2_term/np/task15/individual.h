// Похідні класи “Юридичний” (поле: кількість телефонних номерів) та “Фізичний” (поле: прізвище, ім’я, по-батькові у вигляді однієї стрічки).
#pragma once
#include <iostream>
#include <string>
#include "aps.h"
#include "consumer_sub.h"

using namespace std;

class Individual : public Consumer
{
private:
    string fullName;
public:
    Individual();
    Individual(int, string, long, int, string);
    Individual(Individual&);

    string GetFullName();
    void SetCountOfNumbers(int);

    void ChangeDebt(int const) override;
    string BreakIntoWords();

    void input(istream&) override;
    void print(ostream&) override;

    friend istream& operator >>(istream&, Individual&);
    friend ostream& operator <<(ostream&, Individual&);
};

Individual::Individual():Consumer()
{
    fullName = "John Doe Doe";
}

Individual::Individual(int _cn, string _a, long _mn, int _d, string _fullName):Consumer(_cn, _a, _mn, _d)
{
    fullName = _fullName;
}

Individual::Individual(Individual& ind):Consumer(ind.GetConsumerNumber(), ind.GetAddress(), ind.GetMobileNumber(), ind.GetDebt())
{
    fullName = ind.fullName;
}

string Individual::GetFullName() { return fullName; }

void Individual::SetCountOfNumbers(int _fn) { fullName = _fn; }

void Individual::ChangeDebt(int const percent)
{
    if (Consumer::GetDebt() < 1000)
        Consumer::ChangeDebt(percent);
}

string Individual::BreakIntoWords()
{
    int pos = 0, pos1;
    string str = "";
    for (int i = 0; i < fullName.length(); i++)
    {
        if (fullName[i] == ' ')
        {
            pos1 = i;
            str += fullName.substr(pos, pos1 - pos) + '\n';
            pos = pos1 + 1;
        }
        else if (i == fullName.length() - 1)
            str += fullName.substr(pos, fullName.length() - pos) + '\n';
    }
    return str;
}

void Individual::input(istream& is)
{
    Consumer::input(is);
    getline(is >> ws, fullName);
}

void Individual::print(ostream& os)
{
    os << "Full name:\n" << BreakIntoWords();
    Consumer::print(os);
}

istream& operator >>(istream& is, Individual& leg)
{
    leg.input(is);
    return is;
}

ostream& operator <<(ostream& os, Individual& leg)
{
    leg.print(os);
    return os;
}
