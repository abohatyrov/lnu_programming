// 1. Розробити тип для задання автосервісу за атрибутами: марка автомобіля, вартість деталей, вартість робіт. 
// Утворити перелік виконаних сервісів за допомогою вектора і заповнити його кількома обєктами з різними даними. 
// Вивести в стандартний потік вміст переліку та марку авто з найдорожчим обслуговуванням.

// 2. Розробити тип для обслуговування позашляховиків, якщо вартість робіт для них збільшується на величину 0.001*m, 
// де m- маса авто. Ввести дані таких сервісів з файлу у перелік, заданий за допомогою вектора. Для кожного авто вивести суману вартість 
// обслуговування та марку авто з найдорожчим обслуговуванням.

// 3. Вартість робіт для автобусів розраховується за аналогією до позашляховиків, але ще збільшується на величину к*50, де к - кількість місць для сидіння.

// 4. Створити масив, спільний для автомобілів, позашляховиків та автобусів, посортувати за загальною вартістю ремонту.
#include <iostream>
#include "carservice.h"
#include "offroad.h"
#include "bus.h"

using namespace std;

int main()
{
    int n;
    cout << "Enter n: ";
    cin >> n;

    CarService* cars = new CarService[n];

    for (size_t i = 0; i < n; i++)
        cin >> cars[i];

    CarService most_expensive = CarService();
    for (size_t i = 0; i < n; i++)
        cars[i].GetPriceOfWorks() > most_expensive.GetPriceOfWorks() ? most_expensive = cars[i] : most_expensive = most_expensive;

    cout << most_expensive;


    OffRoad* cars_or = new OffRoad[n];

    for (size_t i = 0; i < n; i++)
        cin >> cars_or[i];

    OffRoad most_expensive_or = OffRoad();
    for (size_t i = 0; i < n; i++)
        cars_or[i].GetPriceOfWorks() > most_expensive_or.GetPriceOfWorks() ? most_expensive_or = cars_or[i] : most_expensive_or = most_expensive_or;

    cout << most_expensive_or;


    Bus* bus = new Bus[n];

    for (size_t i = 0; i < n; i++)
        cin >> bus[i];

    Bus most_expensive_bus = Bus();
    for (size_t i = 0; i < n; i++)
        bus[i].GetPriceOfWorks() > most_expensive_bus.GetPriceOfWorks() ? most_expensive_bus = bus[i] : most_expensive_bus = most_expensive_bus;

    cout << most_expensive_bus;
}