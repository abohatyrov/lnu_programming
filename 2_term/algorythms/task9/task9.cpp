#include <iostream>
#include <fstream>
#include "list.h"

using namespace std;

int main()
{
    ifstream fin("input_data.txt");


    List<double> lst(fin);
    if (!lst.is_empty())
    {
        cout << "List:\n" << lst << endl;

        cout << "Arithmetic mean: ";
        double sum = lst[0];
        for (int i = 1; i < lst.size(); i++)
            sum += lst[i];
        cout << sum / lst.size() << "\n\n";

        lst.clear();
        cout << "List without repeatings:\n" << lst << endl;
    }
    else cout << "List is empty\n";
    

    cout << "Success\n";
    fin.close();
}
