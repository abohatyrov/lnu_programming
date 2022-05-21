#pragma once
#include <iostream>
#include <string>
#include "consumer_sub.h"
#include "individual.h"
#include "legal.h"

using namespace std;

class Aps
{
    int n, m, k;
    Consumer** station;
    Consumer** leg;
    Consumer** ind;
    string name;
public:
    Aps(string);

    void print_full(ostream&);
    void sort(string);
    void break_on_two();
    void print_legal(ostream&);
    void print_individual(ostream&);
    void fee(const int);
    void analysis(ostream&);
    void find_by_address(string, ostream&);
    void find_debtors(ostream&);
    int all_debt();
    void add_client(string);
    void del_client(long);

    friend istream& operator >>(istream&, Aps&);
    friend ostream& operator <<(ostream&, Aps&);
};

Aps::Aps(string _name)
{
    name = _name;
}

void Aps::print_full(ostream& os)
{
    os << "Abonent phone station \"" << name << "\"\n\n";

    for (int i = 0; i < n; i++)
    {
        os << *station[i] << endl;
    }
}

void Aps::sort(string field)
{
    for (int i = 0; i < n; i++)
        for (int j = i; j < n; j++)
        {
            if (field == "Address" && station[i]->GetAddress() > station[j]->GetAddress())
            {
                Consumer* temp = station[i];
                station[i] = station[j];
                station[j] = temp;
            }
            else if ((field == "Number" || field == "Consumer Number") && station[i]->GetConsumerNumber() > station[j]->GetConsumerNumber())
            {
                Consumer* temp = station[i];
                station[i] = station[j];
                station[j] = temp;
            }
            else if (field == "Debt" && station[i]->GetDebt() < station[j]->GetDebt())
            {
                Consumer* temp = station[i];
                station[i] = station[j];
                station[j] = temp;
            }
        }
}

void Aps::break_on_two()
{   
    int q = 0, p = 0;
    for (int i = 0; i < n; i++)
    {
        if (typeid(*station[i]).name() == typeid(Individual).name())
            q++;
        else if (typeid(*station[i]).name() == typeid(Legal).name())
            p++;
    }

    k = q;
    m = p;
    ind = new Consumer*[k];
    leg = new Consumer*[m];
    q = 0, p = 0;
    for (int i = 0; i < n; i++)
    {
        if (typeid(*station[i]).name() == typeid(Individual).name())
        {
            ind[q] = station[i];
            q++;
        }
        else if (typeid(*station[i]).name() == typeid(Legal).name())
        {
            leg[p] = station[i];
            p++;
        }
    }
}

void Aps::print_legal(ostream& os)
{
    for (int i = 0; i < m; i++)
        os << *leg[i] << endl;
}

void Aps::print_individual(ostream& os)
{
    for (int i = 0; i < k; i++)
        os << *ind[i] << endl;
}

void Aps::fee(const int fee)
{
    for (int i = 0; i < n; i++)
        station[i]->ChangeDebt(fee);
}

void Aps::analysis(ostream& os)
{
    os << "Big debt:\n";
    for (int i = 0; i < n; i++)
        if (station[i]->GetDebt() > 0)
        {
            if (typeid(*station[i]).name() == typeid(Consumer).name())
                os << "Consumer:\t+" << station[i]->GetMobileNumber() << "\t Debt: " << station[i]->GetDebt() << "\t Address: " << station[i]->GetAddress() << endl;
            else if (typeid(*station[i]).name() == typeid(Individual).name())
                os << "Individual:\t+" << station[i]->GetMobileNumber() << "\t Debt: " << station[i]->GetDebt() << "\t Address: " << station[i]->GetAddress() << endl;
            else if (typeid(*station[i]).name() == typeid(Legal).name())
                os << "Legal:\t\t+" << station[i]->GetMobileNumber() << "\t Debt: " << station[i]->GetDebt() << "\t Address: " << station[i]->GetAddress() << endl;
        }

    os << "\nNo debt:\n";
    for (int i = 0; i < n; i++)
        if (station[i]->GetDebt() == 0)
        {
            if (typeid(*station[i]).name() == typeid(Consumer).name())
                os << "Consumer:\t+" << station[i]->GetMobileNumber() << "\t Debt: " << station[i]->GetDebt() << "\t Address: " << station[i]->GetAddress() << endl;
            else if (typeid(*station[i]).name() == typeid(Individual).name())
                os << "Individual:\t+" << station[i]->GetMobileNumber() << "\t Debt: " << station[i]->GetDebt() << "\t Address: " << station[i]->GetAddress() << endl;
            else if (typeid(*station[i]).name() == typeid(Legal).name())
                os << "Legal:\t\t+" << station[i]->GetMobileNumber() << "\t Debt: " << station[i]->GetDebt() << "\t Address: " << station[i]->GetAddress() << endl;
        }

    os << "\nNegative debt:\n";
    for (int i = 0; i < n; i++)
        if (station[i]->GetDebt() < 0)
        {
            if (typeid(*station[i]).name() == typeid(Consumer).name())
                os << "Consumer:\t+" << station[i]->GetMobileNumber() << "\t Debt: " << station[i]->GetDebt() << "\t Address: " << station[i]->GetAddress() << endl;
            else if (typeid(*station[i]).name() == typeid(Individual).name())
                os << "Individual:\t+" << station[i]->GetMobileNumber() << "\t Debt: " << station[i]->GetDebt() << "\t Address: " << station[i]->GetAddress() << endl;
            else if (typeid(*station[i]).name() == typeid(Legal).name())
                os << "Legal:\t\t+" << station[i]->GetMobileNumber() << "\t Debt: " << station[i]->GetDebt() << "\t Address: " << station[i]->GetAddress() << endl;
        }
}

void Aps::find_by_address(string address, ostream& os)
{
    for (int i = 0; i < n; i++)
        if (station[i]->GetAddress() == address)
            os << *station[i] << endl;
}

void Aps::find_debtors(ostream& os)
{
    for (int i = 0; i < n; i++)
        if (station[i]->GetDebt() > 0)
            if (typeid(*station[i]).name() == typeid(Consumer).name())
                os << "Consumer:\t+" << station[i]->GetMobileNumber() << "\t Debt: " << station[i]->GetDebt() << "\t Address: " << station[i]->GetAddress() << endl;
            else if (typeid(*station[i]).name() == typeid(Individual).name())
                os << "Individual:\t+" << station[i]->GetMobileNumber() << "\t Debt: " << station[i]->GetDebt() << "\t Address: " << station[i]->GetAddress() << endl;
            else if (typeid(*station[i]).name() == typeid(Legal).name())
                os << "Legal:\t\t+" << station[i]->GetMobileNumber() << "\t Debt: " << station[i]->GetDebt() << "\t Address: " << station[i]->GetAddress() << endl;
}

int Aps::all_debt()
{
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += station[i]->GetDebt();
    
    return sum;
}

void Aps::add_client(string str)
{
    int q = n + 1;
    Consumer** station1 = new Consumer*[q];
    for (int i = 0; i < n; i++)
        station1[i] = station[i];

    string type;

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

    if (type == "c")
    {
        pos = pos1 + 1;
        pos1 = str.size();
        string address = str.substr(pos, pos1 - pos);

        station1[q - 1] = new Consumer(consumerNumber, address, mobileNumber, debt);
    }
    else if (type == "i")
    {
        pos = pos1 + 1;
        pos1 = str.find(' ', pos);
        pos1 = str.find(' ', pos1 + 1);
        pos1 = str.find(' ', pos1 + 1);
        string fullName = str.substr(pos, pos1 - pos);
        pos = pos1 + 1;
        pos1 = str.size();
        string address = str.substr(pos, pos1 - pos);
        
        station1[q - 1] = new Individual(consumerNumber, address, mobileNumber, debt, fullName);
    }
    else if (type == "l")
    {
        pos = pos1 + 1;
        pos1 = str.find(' ', pos);
        int countOfNumbers = stoi(str.substr(pos, pos1 - pos));
        pos = pos1 + 1;
        pos1 = str.size();
        string address = str.substr(pos, pos1 - pos);
        
        station1[q - 1] = new Legal(consumerNumber, address, mobileNumber, debt, countOfNumbers);
    }
    else
    {
        cout << "Wrong data\n";
    }

    n = q;
    station = station1;
}

void Aps::del_client(long number)
{
    for (int i = 0; i < n; i++)
    {
        if (station[i]->GetMobileNumber() == number)
        {
            int q = n - 1;
            Consumer** station1 = new Consumer*[q];
            for (int j = 0; j < i; j++)
                station1[j] = station[j];
            for (int j = i + 1; j < n; j++)
                station1[j - 1] = station[j];
            
            n = q;
            station = station1;
            break;
        }
    }
}

istream& operator >>(istream& is, Aps& aps)
{
    is >> aps.n;
    aps.station = new Consumer*[aps.n];

    for (int i = 0; i < aps.n; i++)
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

        if (type == "c")
        {
            pos = pos1 + 1;
            pos1 = str.size();
            string address = str.substr(pos, pos1 - pos);

            aps.station[i] = new Consumer(consumerNumber, address, mobileNumber, debt);
        }
        else if (type == "i")
        {
            pos = pos1 + 1;
            pos1 = str.find(' ', pos);
            pos1 = str.find(' ', pos1 + 1);
            pos1 = str.find(' ', pos1 + 1);
            string fullName = str.substr(pos, pos1 - pos);
            pos = pos1 + 1;
            pos1 = str.size();
            string address = str.substr(pos, pos1 - pos);
        
            aps.station[i] = new Individual(consumerNumber, address, mobileNumber, debt, fullName);
        }
        else if (type == "l")
        {
            pos = pos1 + 1;
            pos1 = str.find(' ', pos);
            int countOfNumbers = stoi(str.substr(pos, pos1 - pos));
            pos = pos1 + 1;
            pos1 = str.size();
            string address = str.substr(pos, pos1 - pos);
        
            aps.station[i] = new Legal(consumerNumber, address, mobileNumber, debt, countOfNumbers);
        }
        else
        {
            cout << "Wrong data\n";
        }
    }

    return is;
}

ostream& operator <<(ostream& os, Aps& aps)
{
    os << "Abonent phone station \"" << aps.name << "\"\n\n";

    for (int i = 0; i < aps.n; i++)
    {
        if (typeid(*aps.station[i]).name() == typeid(Consumer).name())
            os << "Consumer:\t+" << aps.station[i]->GetMobileNumber() << "\t Debt: " << aps.station[i]->GetDebt() << "\t Address: " << aps.station[i]->GetAddress() << endl;
        else if (typeid(*aps.station[i]).name() == typeid(Individual).name())
            os << "Individual:\t+" << aps.station[i]->GetMobileNumber() << "\t Debt: " << aps.station[i]->GetDebt() << "\t Address: " << aps.station[i]->GetAddress() << endl;
        else if (typeid(*aps.station[i]).name() == typeid(Legal).name())
            os << "Legal:\t\t+" << aps.station[i]->GetMobileNumber() << "\t Debt: " << aps.station[i]->GetDebt() << "\t Address: " << aps.station[i]->GetAddress() << endl;
    }

    return os;
}