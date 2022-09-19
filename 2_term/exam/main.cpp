/*
Введіть з клавіатури декілька аудиторій (площі задані цілими числами), надрукуйте їх. Знайдіть найбільшу, наймісткішу, найпросторішу аудиторії. Обчисліть загальну місткість аудиторій, розташованих на другому поверсі.
За допомогою алгоритмів STL прочитайте з текстового файла перелік аудиторій деякого триповерхового навчального корпусу (площі – дійсні числа). Виведіть їх на екран. Обчисліть сумарну площу всіх аудиторій. Відсортуйте їх за місткістю. Обчисліть кількість аудиторій на кожному поверсі. На яких поверхах розташовано мультимедійні аудиторії?
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <iterator>
#include <numeric>
#include "audience.h"
#include "audience.cpp"
#include "multimedia_audience.h"
#include "multimedia_audience.cpp"

using namespace std;

template <class T>
vector<MultimediaAudience<T>*> input_from_file(string file_name);


int main()
{
    int n;
    vector<Audience<int>*> audiences;

    cout << "Enter number of audiences: "; cin >> n;
    for (int i = 0; i < n; i++)
    {
        Audience<int>* audience = new Audience<int>;
        cin >> *audience;
        audiences.push_back(audience);
    }

    for_each(audiences.begin(), audiences.end(), [](Audience<int>* audience){
        cout << *audience << endl;
    });

    cout << "The biggest audience:\n" << 
        **max_element(audiences.begin(), audiences.end(), [](Audience<int>* audience1, Audience<int>* audience2){
        return audience1->get_area() < audience2->get_area();
    }) << endl;

    cout << "The most capacious audience:\n" << 
        **max_element(audiences.begin(), audiences.end(), [](Audience<int>* audience1, Audience<int>* audience2){
        return audience1->get_three_seater() + audience1->get_two_seater() < audience2->get_three_seater() + audience2->get_two_seater();
    }) << endl;

    vector<Audience<int>*> second_floor;
    for_each(audiences.begin(), audiences.end(), [&](Audience<int>* audience){
        if (audience->floor() == 2)
            second_floor.push_back(new Audience<int>(*audience));
    });
    cout << "Count of audience on the second floor: " << second_floor.size() << endl;

    // Task 4

    // vector<MultimediaAudience<double>*> mauds = input_from_file<double>("input.txt");
    
    // for_each(mauds.begin(), mauds.end(), [](MultimediaAudience<double>* maud){
    //     cout << *maud << endl;
    // });

    // double area = 0;
    // for_each(mauds.begin(), mauds.end(), [&](MultimediaAudience<double>* maud){
    //     area += maud->get_area();
    // });
    // cout << "Full area: " << area << endl;

    // sort(mauds.begin(), mauds.end(), [](MultimediaAudience<double>* maud1, MultimediaAudience<double>* maud2) {
    //     return maud1->get_three_seater() + maud1->get_two_seater() > maud2->get_three_seater() + maud2->get_two_seater();

    // });

    // cout << "\nSorted audiences:\n";
    // for_each(mauds.begin(), mauds.end(), [](MultimediaAudience<double>* maud){
    //     cout << *maud << endl;
    // });

    // vector<MultimediaAudience<double>*> first;
    // vector<MultimediaAudience<double>*> second;
    // vector<MultimediaAudience<double>*> third;
    // for_each(mauds.begin(), mauds.end(), [&](MultimediaAudience<double>* maud){
    //     if (maud->floor() == 1)
    //         first.push_back(new MultimediaAudience<double>(*maud));
    //     else if (maud->floor() == 2)
    //         second.push_back(new MultimediaAudience<double>(*maud));
    //     else if (maud->floor() == 3)
    //         third.push_back(new MultimediaAudience<double>(*maud));
    // });
    // cout << "First floor: " << first.size() << endl;
    // cout << "Second floor: " << second.size() << endl;
    // cout << "Third floor: " << third.size() << endl;

    // vector<int> mult;
    // for_each(mauds.begin(), mauds.end(), [&](MultimediaAudience<double>* maud){
    //     if (!maud->get_equipment().empty())
    //         mult.push_back(maud->floor());
    // });

    // cout << "Floors with multimedia: ";
    // for_each(mult.begin(), mult.end(), [](int maud1) {
    //     cout << maud1 << ' ';
    // });

    
    cout << endl;
}

template <class T>
vector<MultimediaAudience<T>*> input_from_file(string file_name)
{
    ifstream file(file_name);
    vector<MultimediaAudience<T>*> mauds;
    vector<string> data;
    copy(istream_iterator<string>(file), istream_iterator<string>(), back_inserter(data));

    MultimediaAudience<T>* maud;
    int pointer = 0;

    for (int i = 0; i < data.size(); i++)
    {   
        pointer++;
        if (pointer == 1)
        {
            maud = new MultimediaAudience<T>;
            maud->set_number(stoi(data[i]));
        }
        else if (pointer == 2)
            maud->set_area(stod(data[i]));
        else if (pointer == 3)
            maud->set_two_seater(stoi(data[i]));
        else if (pointer == 4)
            maud->set_three_seater(stoi(data[i]));
        else if (pointer == 5)
            maud->add_equipment(data[i]);
        else if (pointer == 6)
        {
            maud->add_equipment(data[i]);
            mauds.push_back(new MultimediaAudience<T>(*maud));
            pointer = 0;
        }
    }

    file.close();
    return mauds;
}