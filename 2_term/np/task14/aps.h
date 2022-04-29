#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "consumer_sub.h"
#include "legal.h"
#include "individual.h"

class Aps
{
private:
    int n;
    Consumer* consumers = new Consumer[n];
public:
    Aps(){}
    Aps(Consumer[]);

    int GetSize();
    void add_consumer(istream&, string);

    friend ostream& operator <<(ostream&, Aps&);
};

int Aps::GetSize() { return n; }

void Aps::add_consumer(istream& is, string type)
{
    int consumerNumber;
    string address;
    long mobileNumber;
    int debt;

    ++n;
    if (type == "consumer")
    {
        is >> consumerNumber;
        getline(is >> ws, address);
        is >> mobileNumber;
        is >> debt;
        consumers[n-1] = Consumer(consumerNumber, address, mobileNumber, debt);
    }
    else if (type == "legal")
    {
        int countOfNumbers;
        is >> consumerNumber;
        getline(is >> ws, address);
        is >> mobileNumber;
        is >> debt;
        is >> countOfNumbers;
        consumers[n-1] = Legal(consumerNumber, address, mobileNumber, debt, countOfNumbers);
    }
    else if (type == "individual")
    {
        string fullName;
        is >> consumerNumber;
        getline(is >> ws, address);
        is >> mobileNumber;
        is >> debt;
        getline(is >> ws, fullName);
        consumers[n-1] = Individual(consumerNumber, address, mobileNumber, debt, fullName);
    }
}

ostream& operator <<(ostream& os, Aps& consumers)
{
    for (int i = 0; i < consumers.GetSize(); i++)
    {
        os << consumers.consumers[i];
        cout << endl;
    }
    return os;
}