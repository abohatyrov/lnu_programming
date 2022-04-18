#include <iostream>
#include <string>

using namespace std;

class CarService
{
private:
    string brand;
    double costOfDetails;
    double priceOfWorks;
public:
    CarService() {};

    CarService(string _brand, double _cod, double _pow)
    {
        brand = _brand;
        costOfDetails = _cod;
        priceOfWorks = _pow;
    }

    CarService(CarService& carService)
    {
        brand = carService.GetBrand();
        costOfDetails = carService.GetCostOfDetails();
        priceOfWorks = carService.GetPriceOfWorks();
    }

    string GetBrand() { return brand; }
    double GetCostOfDetails() { return costOfDetails; }
    double GetPriceOfWorks() { return priceOfWorks; }

    string SetBrand(string _brand) { brand = _brand; }
    double SetCostOfDetails(double _cod) { costOfDetails = _cod; }
    double SetPriceOfWorks(double _pow) { priceOfWorks = _pow; }

    friend istream& operator >>(istream& is, CarService& cs);
    friend ostream& operator <<(ostream& os, CarService& cs);
};

istream& operator >>(istream& is, CarService& cs)
{
    string brand;
    double costOfDetails;
    double priceOfWorks;

    is >> brand >> costOfDetails >> priceOfWorks;

    cs.SetBrand(brand);
    cs.SetCostOfDetails(costOfDetails);
    cs.SetPriceOfWorks(priceOfWorks);

    return is;
}

ostream& operator <<(ostream& os, CarService& cs)
{
    os << "Brand: " << cs.GetBrand() << endl;
    os << "Cost of details: " << cs.GetCostOfDetails() << endl;
    os << "Price of works: " << cs.GetPriceOfWorks() << endl;

    return os;
}
