#include <iostream>
#include "student.h"
#include "bachelor.h"

template <class T>
Bachelor<T>::Bachelor() : Student<T>()
{
    grade_for_bachelor_thesis = 0;
}

template <class T>
Bachelor<T>::Bachelor(int _gfbt, T _rbn, string _ln, int* _marks)
    : Student<T>(_rbn, _ln, _marks)
{
    grade_for_bachelor_thesis = _gfbt;
}

template <class T>
Bachelor<T>::Bachelor(int _gfbt, Student<T>& student)
    : Student<T>(student)
{
    grade_for_bachelor_thesis = _gfbt;
}

template <class T>
Bachelor<T>::Bachelor(Bachelor<T>& bachelor)
    : Student<T>(bachelor.get_record_book_number(), bachelor.get_lastname(), bachelor.get_marks())
{
    grade_for_bachelor_thesis = bachelor.grade_for_bachelor_thesis;
}


template <class T>
void Bachelor<T>::reassignment(int i, int mark)
{
    int* marks = Student<T>::get_marks();
    marks[i - 1] = mark;
    Student<T>::set_marks(marks);
}

template <class T>
int Bachelor<T>::get_grade_for_bachelor_thesis()
{
    return grade_for_bachelor_thesis;
}

template <class T>
void Bachelor<T>::set_grade_for_bachelor_thesis(int _gfbt)
{
     grade_for_bachelor_thesis = _gfbt;
}


template <class T>
void Bachelor<T>::print(ostream& os) const
{
    Student<T>::print(os);
    os << "Grade for Bachelor's thesis: " << grade_for_bachelor_thesis << endl;
}

template <class T>
void Bachelor<T>::input(istream& is)
{
    Student<T>::input(is);
    is >> grade_for_bachelor_thesis;
}

template <class T>
istream& operator>>(istream& is, Bachelor<T>& bachelor)
{
    bachelor.input(is);
    return is;
}

template <class T>
ostream& operator<<(ostream& os, Bachelor<T>& bachelor)
{
    bachelor.print(os);
    return os;
}