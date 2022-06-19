/*
Оголосіть клас (або шаблон класу) "Бакалавр" – це студент, який захистив бакалаврську
роботу і має оцінку за неї. Бакалавр може перездати один з предметів і змінити відповідну
оцінку.
*/
#pragma once
#include "student.h"

using namespace std;

template <class T>
class Bachelor : public Student<T>
{
private:
    int grade_for_bachelor_thesis;
public:
    Bachelor();
    Bachelor(int, T, string, int*);
    Bachelor(int, Student<T>&);
    Bachelor(Bachelor<T>&);

    int get_grade_for_bachelor_thesis();

    void set_grade_for_bachelor_thesis(int);

    void reassignment(int, int);

    void print(ostream&) const;
	void input(istream&);
    template<class U> friend istream& operator>>(istream&, Bachelor<U>&);
    template<class U> friend ostream& operator<<(ostream&, Bachelor<U>&);
};