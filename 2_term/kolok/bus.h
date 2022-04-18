#include <iostream>
#include <string>
#include "carservice.h"

using namespace std;

class OffRoad : public CarService
{
private:
    string brand;
    double mass;
    double costOfDetails;
    double priceOfWorks;
public:
    OffRoad() {};

    OffRoad(string _brand, double _mass, double _cod, double _pow)
    {
        brand = _brand;
        mass = _mass;
        costOfDetails = _cod;
        priceOfWorks = _pow;
    }

    OffRoad(OffRoad& offRoad)
    {
        brand = offRoad.GetBrand();
        mass = offRoad.GetMass();
        costOfDetails = offRoad.GetCostOfDetails();
        priceOfWorks = offRoad.GetPriceOfWorks();
    }

    string GetBrand() { return brand; }
    double GetMass() { return mass; }
    double GetCostOfDetails() { return costOfDetails; }
    double GetPriceOfWorks() { return priceOfWorks + 0.001 * mass; }

    string SetBrand(string _brand) { brand = _brand; }
    double SetMass(double _mass) { mass = _mass; }
    double SetCostOfDetails(double _cod) { costOfDetails = _cod; }
    double SetPriceOfWorks(double _pow) { priceOfWorks = _pow; }

    friend istream& operator >>(istream& is, OffRoad& cs);
    friend ostream& operator <<(ostream& os, OffRoad& cs);
};

istream& operator >>(istream& is, OffRoad& or)
{
    string brand;
    double mass;
    double costOfDetails;
    double priceOfWorks;

    is >> brand >> mass >> costOfDetails >> priceOfWorks;

    or.SetBrand(brand);
    or.SetMass(mass);
    or.SetCostOfDetails(costOfDetails);
    or.SetPriceOfWorks(priceOfWorks);

    return is;
}

ostream& operator <<(ostream& os, OffRoad& or)
{
    os << "Brand: " << or.GetBrand() << endl;
    os << "Cost of details: " << or.GetCostOfDetails() << endl;
    os << "Price of works: " << or.GetPriceOfWorks() << endl;

    return os;
}
