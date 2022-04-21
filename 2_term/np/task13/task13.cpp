#include <iostream>
#include <fstream>
#include "consumer_sub.h"

using namespace std;

int main()
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    
    int n;
    // cout << "Enter size of arrey: "; cin >> n;
    fin >> n;

    Consumer* con = new Consumer[n];
    for (size_t i = 0; i < n; i++)
        fin >> con[i];

    for (size_t i = 0; i < n; i++)
    {
        fout << "Consumer " << i + 1 << endl;
        fout << con[i];
        con[i].ChangeDebt(20);
        int debt = con[i].GetDebt();
        fout << "Changed debt: " << debt << "\n\n";
    }

    cout << "Success\n";
    fin.close();
    fout.close();
}
