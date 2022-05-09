#include <iostream>
#include <fstream>
#include <string>
#include "garment.h"

using namespace std;

Garment The_Most_Expencive(Garment*, int);

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

    Garment max = The_Most_Expencive(clothing, n);
    fout << "[+] The most expencive item [+]\n" << max.GetLabel() << endl << max.FullPrice() << endl;

    cout << "[INFO] Success\n";
    fin.close();
    fout.close();
    return 0;
}

Garment The_Most_Expencive(Garment* items, int n)
{
    Garment max = Garment();
    for (size_t i = 0; i < n; i++)
    {
        double temp = items[i].FullPrice();
        if (max.FullPrice() < temp)
            max = items[i];
    }
    return max;
}