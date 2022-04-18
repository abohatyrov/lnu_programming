#pragma once
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

class Garment
{
private:
    string label;
    int count;
    double price;
public:
    Garment()
    {
        label = "Empty";
        count = 0;
        price = 0;
    }
    Garment(string _label, int _count, double _price)
    {
        label = _label;
        count = _count;
        price = _price;
    }
    Garment(const Garment& item)
    {
        label = item.label;
        count = item.count;
        price = item.price;
    }


    void input(istream& in)
    {
        in >> label >> count >> price;
    }
    void output(ostream& out)
    {
        out << "Label: " << label << endl;
        out << "Count: " << count << endl;
        out << "Price: " << price << endl;
    }
    string GetLabel()
    {
        return label;
    }
    int GetCount()
    {
        return count;
    }
    double GetPrice()
    {
        return price;
    }
    double FullPrice()
    {
        return price * count;
    }
};
