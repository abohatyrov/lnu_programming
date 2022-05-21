#include <iostream>
#include <fstream>
#include <string>
#include "garment.h"

using namespace std;

int main()
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    if (!fin)
    {
        cout << "Input file error!";
        return 0;
    }
    if (!fout)
    {
        cout << "Output file error!";
        return 0;
    }
    
    int n;
    fin >> n;

    Garment* clothing = new Garment [n];

    for (int i = 0; i < n; i++)
        clothing[i].input(fin);

    for (int i = 0; i < n; i++)
    {
        fout << "[+] Item " << i + 1 << " [+]\n";
        clothing[i].output(fout);
        fout << "Full price: " << clothing[i].FullPrice() << "\n\n";
    }

    for (int i = 0; i < n; i++)
    {
        if (clothing[i].FullPrice() > 100)
        {
            fout << "[+] The most expencive items [+]\n\n" << clothing[i].GetLabel() << endl << clothing[i].FullPrice() << endl;
        }
    }
    

    cout << "[INFO] Success\n";
    fin.close();
    fout.close();
    return 0;
}

