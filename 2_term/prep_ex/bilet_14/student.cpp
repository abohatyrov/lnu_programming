#include <iostream>
#include "student.h"

using namespace std;

template <class T>
Student<T>::Student()
{
    for (int i = 0; i < 10; i++)
        marks[i] = 0;
}   

template <class T>
Student<T>::Student(T _rbn, string _ln, int* _marks)
{
    rb_number = _rbn;
    lastname = _ln;
    marks = _marks;
}

template <class T>
Student<T>::Student(Student<T>& student)
{
    rb_number = student.rb_number;
    lastname = student.lastname;
    marks = student.marks;
}


template <class T>
int Student<T>::good_marks(int min)
{
    int count = 0;
    for (int i = 0; i < 10; i++)
        if (marks[i] >= min)
            count++;
    return count;
}


template <class T>
int Student<T>::get_mark(int i)
{
    return marks[i - 1];
}

template <class T>
int* Student<T>::get_marks()
{
    return marks;
}

template <class T>
int Student<T>::get_rating()
{
    int sum = 0;
    for (int i = 0; i < 10; i++)
        sum += marks[i];
    return sum / 10;
}

template <class T>
string Student<T>::get_lastname()
{
    return lastname;
}

template <class T>
T Student<T>::get_record_book_number()
{
    return rb_number;
}


template <class T>
void Student<T>::set_marks(int* _marks)
{
    marks = _marks;
}

template <class T>
void Student<T>::set_lastname(string _lastname)
{
    lastname = _lastname;
}

template <class T>
void Student<T>::set_record_book_number(T _rbn)
{
    rb_number = _rbn;
}


template <class T>
bool operator<(Student<T>& student1, Student<T>& student2)
{
    int rating1 = 0, rating2 = 0;
    for (int i = 0; i < 10; i++)
    {
        rating1 += student1.marks[i];
        rating2 += student2.marks[i];
    }

    if (rating1 < rating2)
        return 1;

    return 0;
}

template <class T>
bool operator<=(Student<T>& student1, Student<T>& student2)
{
    int rating1 = 0, rating2 = 0;
    for (int i = 0; i < 10; i++)
    {
        rating1 += student1.marks[i];
        rating2 += student2.marks[i];
    }

    if (rating1 <= rating2)
        return 1;

    return 0;
}

template <class T>
bool operator>(Student<T>& student1, Student<T>& student2)
{
    int rating1 = 0, rating2 = 0;
    for (int i = 0; i < 10; i++)
    {
        rating1 += student1.marks[i];
        rating2 += student2.marks[i];
    }

    if (rating1 > rating2)
        return 1;

    return 0;
}

template <class T>
bool operator>=(Student<T>& student1, Student<T>& student2)
{
    int rating1 = 0, rating2 = 0;
    for (int i = 0; i < 10; i++)
    {
        rating1 += student1.marks[i];
        rating2 += student2.marks[i];
    }

    if (rating1 >= rating2)
        return 1;

    return 0;
}

template <class T>
bool operator==(Student<T>& student1, Student<T>& student2)
{
    int rating1 = 0, rating2 = 0;
    for (int i = 0; i < 10; i++)
    {
        rating1 += student1.marks[i];
        rating2 += student2.marks[i];
    }

    if (rating1 == rating2)
        return 1;

    return 0;
}


template <class T>
void Student<T>::print(ostream& os) const
{
    os << "Lastname: " << lastname << "\nRecord book number: " << rb_number << "\nMarks: ";
    for (int i = 0; i < 9; i++)
        os << marks[i] << ", ";
    os << marks[9] << endl;
}

template <class T>
void Student<T>::input(istream& is)
{
    T _rb_number;
    string _lastname;
    int* _marks = new int[10];

    is >> _rb_number;
    is >> _lastname;
    for (int i = 0; i < 10; i++) is >> _marks[i];
    
    this->set_record_book_number(_rb_number);
    this->set_lastname(_lastname);
    this->set_marks(_marks);
}

template <class T>
istream& operator>>(istream& is, Student<T>& student)
{
    student.input(is);
    return is;
}

template <class T>
ostream& operator<<(ostream& os, Student<T>& student)
{
    student.print(os);
    return os;
}
