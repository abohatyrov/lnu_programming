#pragma once
#include <iostream>
#include <string>
#include <tuple>
#include <vector>
#include "consumer_sub.h"
#include "legal.h"
#include "individual.h"

typedef tuple<Consumer, Individual, Legal> station;

class Aps
{
private:
    station arr;
    string name;
public:
    Aps(): arr(), name("empty") {}
    Aps(string _name): arr(), name(_name) {}
    Aps(const Aps&);

    int GetSize();
    void add_consumer(istream&, string);

    friend istream& operator >>(istream&, Aps&);
    friend ostream& operator <<(ostream&, Aps&);
};

Aps::Aps(const Aps& aps)
{
    arr = aps.arr;
    name = aps.name;
}

istream& operator >>(istream& is, Aps& aps)
{
    string str, type;
    getline(is >> ws, str);

    int pos = 0, pos1 = str.find(' ');
    type = str.substr(pos, pos1);

    pos = pos1 + 1;
    pos1 = str.find(' ', pos);
    int consumerNumber = stoi(str.substr(pos, pos1 - pos));
    pos = pos1 + 1;
    pos1 = str.find(' ', pos);
    long mobileNumber = stol(str.substr(pos, pos1 - pos));
    pos = pos1 + 1;
    pos1 = str.find(' ', pos);
    int debt = stoi(str.substr(pos, pos1 - pos));

    if (type == "Consumer")
    {
        pos = pos1 + 1;
        pos1 = str.size() - 1;
        string address = str.substr(pos, pos1 - pos);
        vector<station> v;
        Consumer new_con(consumerNumber, address, mobileNumber, debt);
        aps.arr = make_tuple(aps.arr, new_con);
    }
    else if (type == "Individual")
    {
        pos = pos1 + 1;
        pos1 = str.find(' ', pos);
        pos1 = str.find(' ', pos1 + 1);
        pos1 = str.find(' ', pos1 + 1);
        string fullName = str.substr(pos, pos1 - pos);
        pos = pos1 + 1;
        pos1 = str.size() - 1;
        string address = str.substr(pos, pos1 - pos);
    
        Individual new_ind(consumerNumber, address, mobileNumber, debt, fullName);
        make_tuple(aps.arr, new_ind);
    }
    else if (type == "Legal")
    {
        pos = pos1 + 1;
        pos1 = str.find(' ', pos);
        int countOfNumbers = stoi(str.substr(pos, pos1 - pos));
        pos = pos1 + 1;
        pos1 = str.size() - 1;
        string address = str.substr(pos, pos1 - pos);
    
        Legal new_leg(consumerNumber, address, mobileNumber, debt, countOfNumbers);
        make_tuple(aps.arr, new_leg);
    }
    else
    {
        cout << "Wrong data\n";
    }

    return is;
}

ostream& operator <<(ostream& os, Aps& aps)
{
    os << "Consumers:\n\n";
    for (int i = 0; i < aps.con.size(); i++)
        os << aps.con[i];
    
    os << "\nIndividual:\n\n";
    for (int i = 0; i < aps.ind.size(); i++)
        os << aps.ind[i];

    os << "\nLegal:\n\n";
    for (int i = 0; i < aps.leg.size(); i++)
        os << aps.leg[i];

    return os;
}