#include <iostream>
#include <fstream>
#include "list.h"

using namespace std;

int main()
{
    ifstream fin("input_data.txt");


    List<double> lst(fin);
    if (lst.is_empty()) cout << "List is empty.\n\n";
    else cout << "List isn't empty.\n\n";
    cout << lst << endl;

    int sum = 0;
    for (int i = 0; i < lst.size(); i++)
        sum += lst[i];
    cout << "Arithmetic mean: " << sum / (double) lst.size() << endl;
    

    cout << "Success\n";
    fin.close();
}
