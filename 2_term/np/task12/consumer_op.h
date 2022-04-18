// Для класу, описаного у завданні 1, перевантажити оператори введення-виведення, порівняння, присвоєння, приведення до типу string. Зміст оператора порівняння уточнений у варіанті завдання.
// Порівняння двох екземплярів класу робити за адресою.
// Сортування масиву виконувати за спаданням із використанням методу бульбашки.
#include <iostream>
#include <string>
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
    void ChangeDebt(int);

    bool operator==(Consumer);
    bool operator>(Consumer);
    bool operator>=(Consumer);
    bool operator<(Consumer);
    bool operator<=(Consumer);
    void operator=(Consumer);
    operator string();

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

void Consumer::ChangeDebt(int percent)
{
    debt += (int) (debt * percent / 100.0);
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
Consumer::operator string() { return to_string(mobileNumber); }

istream& operator >>(istream& is, Consumer& con)
{
    long mobileNumber;
    // cout << "Enter consumer number (2): "; 
    is >> con.consumerNumber;
    // cout << "Enter your address: "; 
    getline(is >> ws, con.address);
    // cout << "Enter mobile number (8): "; 
    is >> con.mobileNumber;
    while (!con.CheckNumber()) 
    {
        // cout << "Wrong number! Try again\n" << "Enter mobile number (8): ";
        is >> con.mobileNumber;
    }
    // cout << "Enter your debt: "; 
    is >> con.debt;

    return is;
}

ostream& operator <<(ostream& os, Consumer& con)
{
    os << "Consumer number: " << con.consumerNumber << endl;
    os << "Your address: " << con.address << endl;
    os << "Mobile number: +" << con.mobileNumber << endl;
    os << "Your debt: " << con.debt << endl;

    return os;
}
