/*
Сутність «аудиторія» характеризується номером, площею, кількістю двох- і трьохмісних парт. Оголосіть шаблон класу "Аудиторія", параметризований типом площі (це міг би бути будь-який числовий тип). Об’єкти класу вміють виводити себе в потік, повідомляти кількість місць, номер, площу, поверх розташування (101 – перший, 201 – другий тощо). 
*/
#pragma once
#include <cmath>
#include <string>

using namespace std;

template <class T>
class Audience
{
private:
    int number;
    T area;
    int two_seater;
    int three_seater;
public:
    Audience();
    Audience(int, T, int, int);
    Audience(Audience<T>&);

    int floor();

    int get_number();
    T get_area();
    int get_two_seater();
    int get_three_seater();

    void set_number(int);
    void set_area(T);
    void set_two_seater(int);
    void set_three_seater(int);

    virtual void print(ostream&) const;
	virtual void input(istream&);
    template<class U> friend istream& operator>>(istream&, Audience<U>&);
    template<class U> friend ostream& operator<<(ostream&, Audience<U>&);
};