#include <iostream>
#include <fstream>
#include <string>
#include "polynom.h"

using namespace std;

int main()
{
    ifstream fin("input_data.txt");
    ofstream fout("ouput_data.txt");

    // Input polynoms
    Polynom pol1 = Polynom();
    Polynom pol2 = Polynom();
    double x;

    fin >> pol1;
    fin >> pol2;
    fin >> x;
    
    Polynom pol3 = Polynom(pol1);
    Polynom pol4 = Polynom(pol2);
    Polynom pol5 = Polynom(pol3);
    Polynom pol6 = Polynom(pol4);
    Polynom pol7 = Polynom(pol5);
    Polynom pol8 = Polynom(pol6);

    // Create new polynoms and do operations
    Polynom pol_sum = pol3 + pol4;
    Polynom pol_diff = pol5 - pol6;
    Polynom pol_mult = pol7 * pol8;
    Polynom pol_der1 = pol1.derivative();
    Polynom pol_der2 = pol2.derivative();

    // Output all polynoms
    fout << "First polynom: " << pol1 << endl;
    fout << "Second polynom: " << pol2 << "\n\n";
    fout << "Sum (+):\n" << pol_sum << "\nValue: "<< pol_sum.value(x) << "\n\n";
    fout << "Difference (-):\n" << pol_diff << "\nValue: "<< pol_diff.value(x) << "\n\n";
    fout << "Product (*):\n" << pol_mult << "\nValue: "<< pol_mult.value(x) << "\n\n";
    fout << "Derivative 1:\n" << pol_der1 << "\nValue: "<< pol_der1.value(x) << "\n\n";
    fout << "Derivative 2:\n" << pol_der2 << "\nValue: "<< pol_der2.value(x) << endl;

    cout << "Success\n";
    fin.close();
    fout.close();
}