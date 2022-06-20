/*
Введіть з клавіатури дані про кількох студентів (номери залікових задано цілими числами).
Скільки з них мають виключно відмінні оцінки? Надрукуйте прізвища тих, хто має оцінки E, D
(від 51 до 70).
За допомогою алгоритмів STL прочитайте з текстового файла список бакалаврів (залікові
задано рядками). Виведіть їх на екран. Впорядкуйте послідовність бакалаврів за спаданням
середнього бала. Скільки з них може претендувати на навчання в магістратурі (середній бал 
4)? Якщо кожен з бакалаврів перездасть третій предмет на 95, чи зміниться кількість
претендентів?
*/
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <iterator>
#include <numeric>
#include "student.h"
#include "student.cpp"
#include "bachelor.h"
#include "bachelor.cpp"

using namespace std;

template <class T>
vector<Bachelor<T>*> input_from_file(string file_name)
{
    ifstream file(file_name);
    vector<Bachelor<T>*> bachelors;
    vector<string> data;
    copy(istream_iterator<string>(file), istream_iterator<string>(), back_inserter(data));

    Bachelor<string>* bachelor;
    int pointer = 0, i_mark;

    for (int i = 0; i < data.size(); i++)
    {   
        pointer++;
        if (pointer == 1)
        {
            bachelor = new Bachelor<T>;
            bachelor->set_record_book_number(data[i]);
            i_mark = 1;
        }
        else if (pointer == 2)
            bachelor->set_lastname(data[i]);
        else if (pointer == 13)
        {
            bachelor->set_grade_for_bachelor_thesis(stoi(data[i]));
            bachelors.push_back(new Bachelor<T>(*bachelor));
            pointer = 0;
        }
        else
        {
            bachelor->reassignment(i_mark, stoi(data[i]));
            i_mark++;
        }
    }

    file.close();
    return bachelors;
}

int main()
{
    // int n;
    // vector<Student<int>*> students;

    // cout << "Enter number of students: "; cin >> n;
    // for (int i = 0; i < n; i++)
    // {
    //     Student<int>* student = new Student<int>;
    //     cin >> *student;
    //     students.push_back(student);
    // }

    // int count_of_exellent_students = 0;
    // for (int i = 0; i < n; i++)
    //     if (students[i]->get_rating() > 89)
    //         count_of_exellent_students++;
    // cout << "Number of exellent students: " << count_of_exellent_students;

    // cout << "\nStudents with E or D:\n";
    // for (int i = 0; i < n; i++)
    //     if (students[i]->get_rating() > 50 && students[i]->get_rating() < 71)
    //         cout << students[i]->get_lastname() << endl;

    // Task 4
    vector<Bachelor<string>*> bachelors = input_from_file<string>("input.txt");
    
    for_each(bachelors.begin(), bachelors.end(), [](Bachelor<string>* bachelor){
        cout << *bachelor << endl;
    });
    cout << "==================================\n";

    sort(bachelors.begin(), bachelors.end(), [](Bachelor<string>* bach1, Bachelor<string>* bach2) {
        return bach1->get_grade_for_bachelor_thesis() > bach2->get_grade_for_bachelor_thesis();
    });

    cout << "Sorted by grade for Bachelor's thesis:\n\n";
    for_each(bachelors.begin(), bachelors.end(), [](Bachelor<string>* bachelor){
        cout << *bachelor << endl;
    });

    vector<Bachelor<string>*> magisters;

    for_each(bachelors.begin(), bachelors.end(), [&](Bachelor<string>* bachelor){
        if (bachelor->get_rating() > 70 && bachelor->get_rating() < 90)
            magisters.push_back(new Bachelor<string>(*bachelor));
    });
    cout << "Magisters: " << magisters.size();
    cout << "\n\n==================================\n\n";

    int m_size1 = magisters.size();
    for_each(bachelors.begin(), bachelors.end(), [&](Bachelor<string>* bachelor){
        bachelor->reassignment(3, 95);
        cout << *bachelor << endl;
        if (bachelor->get_rating() > 70 && bachelor->get_rating() < 90)
            magisters.push_back(new Bachelor<string>(*bachelor));
    });

    cout << "Magisters: " << magisters.size() << endl;
    cout << "Is number of magisters changed?: ";
    if (magisters.size() == m_size1)
        cout << "NO";
    else
        cout << "YES";

    cout << endl;
}