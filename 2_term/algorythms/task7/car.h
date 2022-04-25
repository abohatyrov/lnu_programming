#pragma once
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Car
{
private:
    string label;
    int year;
    double price;
public:
    Car(){}
    Car(string, int, double);
    Car(Car&);

    string GetLabel();
    int GetYear();
    double GetPrice();

    void SetLabel(string);
    void SetYear(int);
    void SetPrice(double);

    void operator=(Car);

    friend istream& operator >>(istream&, Car&);
    friend ostream& operator <<(ostream&, Car&);
};

Car::Car(string _label, int _year, double _price)
{
    label = _label;
    year = _year;
    price = _price;
}

Car::Car(Car& car)
{
    label = car.label;
    year = car.year;
    price = car.price;
}

string Car::GetLabel() { return label; }
int Car::GetYear() { return year; }
double Car::GetPrice() { return price; }

void Car::SetLabel(string _label) { label = _label; }
void Car::SetYear(int _year) { year = _year; }
void Car::SetPrice(double _price) { price = _price; }

void Car::operator=(Car car)
{
    label = car.label;
    year = car.year;
    price = car.price;
}

istream& operator >>(istream& is, Car& car)
{
    // cout << "Enter label: "; 
    getline(is >> ws, car.label);
    // cout << "Enter year: ";
    is >> car.year;
    // cout << "Enter price: ";
    is >> car.price;

    return is;
}

ostream& operator <<(ostream& os, Car& car)
{
    os << "Label: " << car.GetLabel() << endl;
    os << "Year: " << car.GetYear() << endl;
    os << "Price: " << car.GetPrice() << endl;

    return os;
}