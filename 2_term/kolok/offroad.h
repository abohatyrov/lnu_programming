#include <iostream>
#include <string>
#include "carservice.h"

using namespace std;

class Bus : public OffRoad
{
private:
    string brand;
    double mass;
    int countOfSeats;
    double costOfDetails;
    double priceOfWorks;
public:
    Bus() {};

    Bus(string _brand, double _mass, int _countOfSeats, double _cod, double _pow)
    {
        brand = _brand;
        mass = _mass;
        countOfSeats = _countOfSeats;
        costOfDetails = _cod;
        priceOfWorks = _pow;
    }

    Bus(Bus& offRoad)
    {
        brand = offRoad.GetBrand();
        mass = offRoad.GetMass();
        costOfDetails = offRoad.GetCostOfDetails();
        priceOfWorks = offRoad.GetPriceOfWorks();
    }

    string GetBrand() { return brand; }
    double GetMass() { return mass; }
    int GetCountOfSeats() { return countOfSeats; }
    double GetCostOfDetails() { return costOfDetails; }
    double GetPriceOfWorks() { return priceOfWorks + 0.001 * mass + countOfSeats; }

    string SetBrand(string _brand) { brand = _brand; }
    double SetMass(double _mass) { mass = _mass; }
    int SetCountOfSeats(int _cos) { countOfSeats = _cos; }
    double SetCostOfDetails(double _cod) { costOfDetails = _cod; }
    double SetPriceOfWorks(double _pow) { priceOfWorks = _pow; }

    friend istream& operator >>(istream& is, Bus& cs);
    friend ostream& operator <<(ostream& os, Bus& cs);
};

istream& operator >>(istream& is, Bus& or)
{
    string brand;
    double mass;
    int countOfSeats;
    double costOfDetails;
    double priceOfWorks;

    is >> brand >> mass >> countOfSeats >> costOfDetails >> priceOfWorks;

    or.SetBrand(brand);
    or.SetMass(mass);
    or.SetCountOfSeats(countOfSeats);
    or.SetCostOfDetails(costOfDetails);
    or.SetPriceOfWorks(priceOfWorks);

    return is;
}

ostream& operator <<(ostream& os, Bus& or)
{
    os << "Brand: " << or.GetBrand() << endl;
    os << "Cost of details: " << or.GetCostOfDetails() << endl;
    os << "Price of works: " << or.GetPriceOfWorks() << endl;

    return os;
}
