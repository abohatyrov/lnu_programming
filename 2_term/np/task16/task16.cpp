#include <iostream>
#include <fstream>
#include "polynom.h"

using namespace std;

int main ()
{
    ifstream fin("input_data.txt");
    ofstream fout("ouput_data.txt");

    // Input polynoms
    Polynom pol1 = Polynom();
    Polynom pol2 = Polynom();
    double a, b, h, c;

    // First number is power, all next are multipliers
    fin >> pol1;
    fin >> pol2;
    // [a;b] with step h, c - multipier
    fin >> a >> b >> h >> c;
    
    // Create new polynoms and do operations
    Polynom pol_sum = pol1 + pol2;
    Polynom pol_diff = pol1 - pol2;
    Polynom pol_mult = pol1 * pol2;

    // Output all polynoms
    fout << "First polynom: " << pol1 << endl;
    fout << "Second polynom: " << pol2 << "\n\n";
    fout << "Sum (+):\n" << pol_sum << "\n\n";
    fout << "Difference (-):\n" << pol_diff << "\n\n";
    fout << "Product (*):\n" << pol_mult << "\n\n";

    fout << "Polynoms values:\n" << "pol1 | pol2\n-----|-----\n";
    for (int i = a; i <= b; i += h)
        fout << pol1.value(i) << "\t |\t" << pol2.value(i) << endl;
    fout << endl;

    if (pol1 == pol2)
    {
        Polynom pol3 = pol1.derivative();
        fout << "Polynoms are equal\n\n";
        fout << "Derivative: " << pol3; 
    }
    else if (pol1 != pol2)
    {
        Polynom pol3 = pol1 * c;
        Polynom pol4 = pol2 * c;
        fout << "Polynoms aren't equal\n\n" << "pol1 | pol2\n-----|-----\n";
        for (int i = a; i <= b; i += h)
            fout << pol3.value(i) << "\t |\t" << pol4.value(i) << endl;
    }

    cout << "Success\n";
    fin.close();
    fout.close();
}