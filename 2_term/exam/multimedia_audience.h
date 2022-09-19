/*
Оголосіть клас (або шаблон класу) "Мультимедійна аудиторія". Екземпляр додатково пам’ятає перелік мультимедійного обладнання.
*/
#pragma once
#include <vector>
#include <string>
#include "audience.h"

using namespace std;

template <class T>
class MultimediaAudience : public Audience<T>
{
private:
    vector<string> equipment;
public:
    MultimediaAudience();
    MultimediaAudience(vector<string>, int, T, int, int);
    MultimediaAudience(vector<string>, Audience<T>&);
    MultimediaAudience(MultimediaAudience<T>&);

    vector<string> get_equipment();

    void set_equipment(vector<string>);
    void add_equipment(string);

    void print(ostream&) const;
	void input(istream&);
    template<class U> friend istream& operator>>(istream&, MultimediaAudience<U>&);
    template<class U> friend ostream& operator<<(ostream&, MultimediaAudience<U>&);
};