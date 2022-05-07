#include <iostream>
#include <fstream>
#include "list.h"

using namespace std;

int main()
{
    ifstream fin("input_data.txt");
    ofstream fout("output_data.txt");


    List lst = List(fin);
    if (lst.is_empty()) fout << "List is empty.\n\n";
    else fout << "List isn't empty.\n\n";
    fout << lst << endl;

    lst.del_end();
    cout << "Delete last element\n" << lst << endl;

    lst.del_begin();
    fout << "Delete first element\n" << lst << endl;

    double sum = lst.sum();
    fout << "Sum of first and last element: " << sum << endl << endl;

    lst.del_all_e(7.5);
    fout << "Delete all equal to 7.5 elements\n" << lst;


    cout << "Success\n";
    fin.close();
    fout.close();
}
