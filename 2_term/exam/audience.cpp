/*
Сутність «аудиторія» характеризується номером, площею, кількістю двох- і трьохмісних парт. Оголосіть шаблон класу "Аудиторія", параметризований типом площі (це міг би бути будь-який числовий тип). Об’єкти класу вміють виводити себе в потік, повідомляти кількість місць, номер, площу, поверх розташування (101 – перший, 201 – другий тощо). 
*/
#include <iostream>
#include <string>
#include "audience.h"

using namespace std;

template <class T>
Audience<T>::Audience()
{
    number = 0;
    area = 0;
    two_seater = 0;
    three_seater = 0;
}   

template <class T>
Audience<T>::Audience(int _number, T _area, int _twos, int _threes)
{
    number = _number;
    area = _area;
    two_seater = _twos;
    three_seater = _threes;
}

template <class T>
Audience<T>::Audience(Audience<T>& aud)
{
    number = aud.number;
    area = aud.area;
    two_seater = aud.two_seater;
    three_seater = aud.three_seater;
}


template <class T>
int Audience<T>::floor()
{
    int n = number;
    while (n >= 5) 
        n /= 10;
    return n;
}


template <class T>
int Audience<T>::get_number()
{
    return number;
}

template <class T>
T Audience<T>::get_area()
{
    return area;
}

template <class T>
int Audience<T>::get_two_seater()
{
    return two_seater;
}

template <class T>
int Audience<T>::get_three_seater()
{
    return three_seater;
}

template <class T>
void Audience<T>::set_number(int _number)
{
    number = _number;
}

template <class T>
void Audience<T>::set_area(T _area)
{
    area = _area;
}

template <class T>
void Audience<T>::set_two_seater(int _twos)
{
    two_seater = _twos;
}

template <class T>
void Audience<T>::set_three_seater(int _threes)
{
    three_seater = _threes;
}


template <class T>
void Audience<T>::print(ostream& os) const
{
    os << "Number: " << number;
    os << "\nArea: " << area;
    os << "\nTwo seater: " << two_seater;
    os << "\nThree seater: " << three_seater << endl;
}

template <class T>
void Audience<T>::input(istream& is)
{
    cout << "Enter number: ";
    is >> number;
    cout << "Enter area: ";
    is >> area;
    cout << "Enter two seater: ";
    is >> two_seater;
    cout << "Enter three seater: ";
    is >> three_seater;
}

template <class T>
istream& operator>>(istream& is, Audience<T>& aud)
{
    aud.input(is);
    return is;
}

template <class T>
ostream& operator<<(ostream& os, Audience<T>& aud)
{
    aud.print(os);
    return os;
}