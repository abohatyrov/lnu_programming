// Визначивши клас із завдання 1 за базовий, сформувати похідні класи. Перевизначити методи базового класу та описати нові методи згідно з варіантом завдання. Перевантажити оператори введення-виведення для базового та похідних класів зі застосуванням віртуальних функцій читання та запису інформації у потоки.
// Похідні класи “Юридичний” (поле: кількість телефонних номерів) та “Фізичний” (поле: прізвище, ім’я, по-батькові у вигляді однієї стрічки).
// Зміна стану заборгованості у випадку юридичної особи відбувається за загальними правилами і додатково зі збільшенням відсотка за визначеним тарифом для юридичних осіб. Якщо стан заборгованості фізичної особи перевищує встановлену суму, то пільгу не нараховують.
// Описати метод обрахунку пільгової вартості для першого класу з урахуванням того, що за кожні 5 номерів надають знижку 10 %. Для другого класу додати метод, який ділить поле класу на три окремі стрічки.
#pragma once
#include <iostream>
#include <string>
#include <cmath>
#include "aps.h"

using namespace std;

class Consumer
{
private:
    int consumerNumber;
    string address;
    long mobileNumber;
    int debt;
public:
    Consumer();
    Consumer(int, string, long, int);
    Consumer(Consumer&);

    void SetConsumerNumber(int);
    void SetAddress(string);
    void SetMobileNumber(long);
    void SetDebt(int);

    int GetConsumerNumber();
    string GetAddress();
    long GetMobileNumber();
    int GetDebt();

    bool CheckNumber();
    virtual void ChangeDebt(int const);

    bool operator==(Consumer);
    bool operator>(Consumer);
    bool operator>=(Consumer);
    bool operator<(Consumer);
    bool operator<=(Consumer);
    void operator=(Consumer);
    operator string() const;

    virtual void input(istream&);
    virtual void print(ostream&);
    friend istream& operator >>(istream&, Consumer&);
    friend ostream& operator <<(ostream&, Consumer&);
};

Consumer::Consumer()
{
    consumerNumber = 44;
    address = "None";
    mobileNumber = 44123456;
    debt = 0;
}

Consumer::Consumer(int _consumerNumber, string _address, long _mobileNumber, int _debt)
{
    consumerNumber = _consumerNumber;
    address = _address;
    mobileNumber = _mobileNumber;
    debt = _debt;
}

Consumer::Consumer(Consumer& con)
{
    consumerNumber = con.consumerNumber;
    address = con.address;
    mobileNumber = con.mobileNumber;
    debt = con.debt;
}

void Consumer::SetConsumerNumber(int cn) { consumerNumber = cn; }
void Consumer::SetAddress(string _address) { address = _address; }
void Consumer::SetMobileNumber(long mn) { mobileNumber = mn; }
void Consumer::SetDebt(int _debt) { debt = _debt; }

int Consumer::GetConsumerNumber() { return consumerNumber; }
string Consumer::GetAddress() { return address; }
long Consumer::GetMobileNumber() { return mobileNumber; }
int Consumer::GetDebt() { return debt; }

bool Consumer::CheckNumber()
{
    return mobileNumber / 100000000 == 0 && mobileNumber / 1000000 == consumerNumber ? true : false;
}

void Consumer::ChangeDebt(int const percent)
{
    debt -= abs((debt) * percent / 100);
}

bool Consumer::operator==(Consumer con) { return address == con.GetAddress(); }
bool Consumer::operator>(Consumer con) { return address > con.GetAddress(); }
bool Consumer::operator>=(Consumer con) { return address >= con.GetAddress(); }
bool Consumer::operator<(Consumer con) { return address < con.GetAddress(); }
bool Consumer::operator<=(Consumer con) { return address <= con.GetAddress(); }
void Consumer::operator=(Consumer con)
{
    consumerNumber = con.consumerNumber;
    address = con.address;
    mobileNumber = con.mobileNumber;
    debt = con.debt;
}
Consumer::operator string() const { return to_string(mobileNumber); }


void Consumer::input(istream& is)
{
    // cout << "Enter consumer number (2): "; 
    is >> consumerNumber;
    // cout << "Enter your address: "; 
    getline(is >> ws, address);
    // cout << "Enter mobile number (8): "; 
    is >> mobileNumber;
    while (!CheckNumber()) 
    {
        // cout << "Wrong number! Try again\n" << "Enter mobile number (8): ";
        is >> mobileNumber;
    }
    // cout << "Enter your debt: "; 
    is >> debt;
}

void Consumer::print(ostream& os)
{
    os << "Consumer number: " << consumerNumber << endl;
    os << "Your address: " << address << endl;
    os << "Mobile number: +" << mobileNumber << endl;
    os << "Your debt: " << debt << endl;
}

istream& operator >>(istream& is, Consumer& con)
{
    con.input(is);
    return is;
}

ostream& operator <<(ostream& os, Consumer& con)
{
    con.print(os);
    return os;
}
