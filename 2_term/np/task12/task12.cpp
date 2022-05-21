#include <iostream>
#include <fstream>
#include <string>
#include "consumer_op.h"

using namespace std;

void BubbleSort(Consumer*, int);

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

    BubbleSort(con, n);

    string all_consumers = "";
    for (size_t i = 0; i < n; i++)
    {
        fout << "Consumer " << i + 1 << endl;
        fout << con[i];
        con[i].ChangeDebt(20);
        int debt = con[i].GetDebt();
        fout << "Changed debt: " << debt << "\n\n";
        i < n - 1 ? all_consumers += (string) con[i] + ", " : all_consumers += (string) con[i];
    }
    fout << "All numbers: " << all_consumers << endl;

    cout << "Success\n";
    fin.close();
    fout.close();
}

void BubbleSort(Consumer* con, int n)
{
    for (size_t i = 0; i < n; i++)
        for (size_t j = 0; j < n - 1; j++)
            if (con[j] > con[j + 1])
            {
                Consumer temp = con[j];
                con[j] = con[j + 1];
                con[j + 1] = temp;
            }
}
