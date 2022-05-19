#include <iostream>
#include <fstream>
#include "aps.h"

using namespace std;

int main()
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");


    Aps station = Aps("Station 1");
    while (!fin.eof())
        fin >> station;
    fout << station;


    cout << "Success\n";
    fin.close();
    fout.close();
}