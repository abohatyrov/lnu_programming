#include <iostream>
#include <fstream>
#include "consumer_sub.h"
#include "legal.h"
#include "individual.h"

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

    fout << "======== Consumer ========\n\n";
    for (size_t i = 0; i < n; i++)
    {
        fout << "Consumer " << i + 1 << endl;
        fout << con[i];
        con[i].ChangeDebt(20);
        int debt = con[i].GetDebt();
        fout << "Changed debt: " << debt << "\n\n";
    }
    fout << "======== Legal ========\n\n";

    Legal* leg = new Legal[n];
    for (size_t i = 0; i < n; i++)
        fin >> leg[i];

    for (size_t i = 0; i < n; i++)
    {
        fout << "Legal consumer " << i + 1 << endl;
        fout << leg[i];
        leg[i].ChangeDebt(20);
        int debt = leg[i].GetDebt();
        fout << "Changed debt: " << debt << "\n\n";
    }
    fout << "======== Individual ========\n\n";

    Individual* ind = new Individual[n];
    for (size_t i = 0; i < n; i++)
        fin >> ind[i];

    for (size_t i = 0; i < n; i++)
    {
        fout << "Individual consumer " << i + 1 << endl;
        fout << ind[i];
        ind[i].ChangeDebt(20);
        int debt = ind[i].GetDebt();
        fout << "Changed debt: " << debt << "\n\n";
    }


    cout << "Success\n";
    fin.close();
    fout.close();
}
