/*
Оголосіть клас (або шаблон класу) "Мультимедійна аудиторія". Екземпляр додатково пам’ятає перелік мультимедійного обладнання.
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include "audience.h"
#include "multimedia_audience.h"

template <class T>
MultimediaAudience<T>::MultimediaAudience() : Audience<T>()
{
}

template <class T>
MultimediaAudience<T>::MultimediaAudience(vector<string> _equip, int _number, T _area, int _twos, int _threes)
    : Audience<T>(_number, _area, _twos, _threes)
{
    equipment = _equip;
}

template <class T>
MultimediaAudience<T>::MultimediaAudience(vector<string> _equip, Audience<T>& aud)
    : Audience<T>(aud)
{
    equipment = _equip;
}

template <class T>
MultimediaAudience<T>::MultimediaAudience(MultimediaAudience<T>& maud)
    : Audience<T>(maud.get_number(), maud.get_area(), maud.get_two_seater(), maud.get_three_seater())
{
    equipment = maud.equipment;
}


template <class T>
vector<string> MultimediaAudience<T>::get_equipment()
{
    return equipment;
}

template <class T>
void MultimediaAudience<T>::set_equipment(vector<string> _equip)
{
     equipment = _equip;
}

template <class T>
void MultimediaAudience<T>::add_equipment(string obj)
{
     equipment.push_back(obj);
}


template <class T>
void MultimediaAudience<T>::print(ostream& os) const
{
    Audience<T>::print(os);
    os << "Equipment:\n";
    if (equipment.size() == 0)
        os << "Empty\n";
    else
        for_each(equipment.begin(), equipment.end(), [&](string obj){
            os << obj << endl;
        });
}

template <class T>
void MultimediaAudience<T>::input(istream& is)
{
    Audience<T>::input(is);
    copy(istream_iterator<string>(is), istream_iterator<string>(), back_inserter(equipment));
}

template <class T>
istream& operator>>(istream& is, MultimediaAudience<T>& maud)
{
    maud.input(is);
    return is;
}

template <class T>
ostream& operator<<(ostream& os, MultimediaAudience<T>& maud)
{
    maud.print(os);
    return os;
}