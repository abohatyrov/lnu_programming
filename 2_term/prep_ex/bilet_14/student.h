/*
Оголосіть шаблон класу "Студент", що містить номер залікової, прізвище студента, перелік 10
оцінок за вивчені предмети. Шаблон параметризовано типом номера залікової (число або
рядок). Об’єкти класу вміють виводити себе в потік, повідомляти оцінку за номером, прізвище
та номер залікової, кількість оцінок певного ґатунку. Студентів порівнюють за рейтингом –
сумою отриманих оцінок.
*/
#pragma once
#include <cmath>
#include <string>

using namespace std;

template <class T>
class Student
{
private:
    T rb_number;
    string lastname;
    int* marks = new int[10];
public:
    Student();
    Student(T, string, int*);
    Student(Student<T>&);

    int good_marks(int);

    int get_mark(int);
    int* get_marks();
    int get_rating();
    string get_lastname();
    T get_record_book_number();

    void set_marks(int*);
    void set_lastname(string);
    void set_record_book_number(T);

    template<class U> friend bool operator<(Student<U>&, Student<U>&);
    template<class U> friend bool operator<=(Student<U>&, Student<U>&);
    template<class U> friend bool operator>(Student<U>&, Student<U>&);
    template<class U> friend bool operator>=(Student<U>&, Student<U>&);
    template<class U> friend bool operator==(Student<U>&, Student<U>&);

    virtual void print(ostream&) const;
	virtual void input(istream&);
    template<class U> friend istream& operator>>(istream&, Student<U>&);
    template<class U> friend ostream& operator<<(ostream&, Student<U>&);
};