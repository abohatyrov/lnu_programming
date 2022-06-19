#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <iterator>
#include <numeric>
#include "square_trinomial.h"
#include "square_trinomial.cpp"
#include "consolidated_square_trinomial.h"
#include "consolidated_square_trinomial.cpp"

using namespace std;

template <class T>
vector<ConsolidatedSquareTrinomial<T>*> input_from_file(string file_name)
{
    ifstream file(file_name);
    vector<ConsolidatedSquareTrinomial<T>*> csts;
    vector<string> data;
    copy(istream_iterator<string>(file), istream_iterator<string>(), back_inserter(data));

    ConsolidatedSquareTrinomial<T>* cst = new ConsolidatedSquareTrinomial<T>;
    int pointer = 0;

    for (int i = 0; i < data.size(); i++)
    {   
        pointer++;
        if (pointer == 1)
        {
            cst->set_a(stoi(data[i]));
        }
        else if (pointer == 2)
            cst->set_b(stoi(data[i]));
        else if (pointer == 3)
        {
            cst->set_c(stoi(data[i]));
            csts.push_back(new ConsolidatedSquareTrinomial<T>(*cst));
            pointer = 0;
        }
    }

    file.close();
    return csts;
}

int main()
{
    // SquareTrinomial<double>* square_trinomial1 = new SquareTrinomial<double>;
    // cin >> *square_trinomial1;
    // SquareTrinomial<double>* square_trinomial2 = new SquareTrinomial<double>;
    // cin >> *square_trinomial2;

    // cout << *square_trinomial1 << endl << *square_trinomial2 << "\n\n";

    // if (!square_trinomial1->roots() || !square_trinomial2->roots())
    //     cout << "Wrong!\n";
    // else
    // {
    //     double x1 = square_trinomial1->roots()[0]; 
    //     double x2 = square_trinomial1->roots()[1]; 
    //     double x3 = square_trinomial2->roots()[0];
    //     double x4 = square_trinomial2->roots()[1];
    //     cout << "Roots of 1 polynom: ";
    //     cout << x1 << ' ';
    //     cout << x2 << ' ';
    //     cout << "\nRoots of 2 polynom: ";
    //     cout << x3 << ' ';
    //     cout << x4 << ' ';

    //     cout << "\nIs roots1 belong to roots2 set?: ";
    //     if (x1 < x4 && x1 > x3 && x2 < x4 && x2 > x3)
    //         cout << "YES\n\n";
    //     else
    //         cout << "NO\n\n";
    // }

    // *square_trinomial1 + *square_trinomial2;
    // *square_trinomial1 * 0.5;
    // cout << *square_trinomial1;
    

    // Task 4
    vector<ConsolidatedSquareTrinomial<int>*> csts = input_from_file<int>("input.txt");
    
    for_each(csts.begin(), csts.end(), [](ConsolidatedSquareTrinomial<int>* cst){
        cout << *cst << endl;
    });
    cout << "\n==================================\n";

    vector<ConsolidatedSquareTrinomial<int>*> full_squares;

    for_each(csts.begin(), csts.end(), [&](ConsolidatedSquareTrinomial<int>* cst){
        if (cst->roots() && pow(cst->get_a() * 2 * cst->roots()[0] + cst->get_b(), 2) == cst->discriminant())
            full_squares.push_back(new ConsolidatedSquareTrinomial<int>(*cst));
    });

    cout << "\nFull squares: " << full_squares.size();
    cout << "\n\n==================================\n\n";

    vector<ConsolidatedSquareTrinomial<int>*> no_roots;

    for_each(csts.begin(), csts.end(), [&](ConsolidatedSquareTrinomial<int>* cst){
        if (!cst->roots())
            no_roots.push_back(new ConsolidatedSquareTrinomial<int>(*cst));
    });

    cout << "\nNo roots: " << no_roots.size();
    cout << "\n\n==================================\n\n";

    vector<ConsolidatedSquareTrinomial<int>*> difference_roots;

    for_each(csts.begin(), csts.end(), [&](ConsolidatedSquareTrinomial<int>* cst){
        auto roots = cst->roots();
        if (cst->roots() && roots[0] == roots[1])
            difference_roots.push_back(new ConsolidatedSquareTrinomial<int>(*cst));
    });

    cout << "\nDifferent roots: " << difference_roots.size();
    cout << "\n\n==================================\n\n";

    for_each(csts.begin(), csts.end(), [](ConsolidatedSquareTrinomial<int>* cst){
        cst->consolidate();
        cout << *cst << endl;
    });

    // sort(csts.begin(), csts.end(), [](ConsolidatedSquareTrinomial<string>* bach1, ConsolidatedSquareTrinomial<string>* bach2) {
    //     return bach1->get_grade_for_ConsolidatedSquareTrinomial_thesis() > bach2->get_grade_for_ConsolidatedSquareTrinomial_thesis();
    // });

    // cout << "Sorted by grade for ConsolidatedSquareTrinomial's thesis:\n\n";
    // for_each(csts.begin(), csts.end(), [](ConsolidatedSquareTrinomial<string>* ConsolidatedSquareTrinomial){
    //     cout << *ConsolidatedSquareTrinomial << endl;
    // });

    // int m_size1 = magisters.size();
    // for_each(csts.begin(), csts.end(), [&](ConsolidatedSquareTrinomial<string>* ConsolidatedSquareTrinomial){
    //     ConsolidatedSquareTrinomial->reassignment(3, 95);
    //     cout << *ConsolidatedSquareTrinomial << endl;
    //     if (ConsolidatedSquareTrinomial->get_rating() > 70 && ConsolidatedSquareTrinomial->get_rating() < 90)
    //         magisters.push_back(new ConsolidatedSquareTrinomial<string>(*ConsolidatedSquareTrinomial));
    // });

    // cout << "Magisters: " << magisters.size() << endl;
    // cout << "Is number of magisters changed?: ";
    // if (magisters.size() == m_size1)
    //     cout << "NO";
    // else
    //     cout << "YES";

    cout << endl;
}