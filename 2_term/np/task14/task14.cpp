#include <iostream>
#include <fstream>
#include "aps.h"

using namespace std;

int main()
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");


    Aps station("Station 1");
    fin >> station;
    fout << station;
    fout << "\n===============================\n";
    station.print_full(fout);

    fout << "\n======== Sort by phone ========\n";
    station.sort("Number");
    fout << station;

    fout << "\n\n======== Sort by address ========\n";
    station.sort("Address");
    fout << station;

    fout << "\n\n======== Sort by debt ========\n";
    station.sort("Debt");
    fout << station;

    station.break_on_two();
    fout << "\n\n======== Individual ========\n";
    station.print_individual(fout);
    fout << "\n======== Legal ========\n";
    station.print_legal(fout);

    station.fee(20);
    fout << "\n======== Fee is accrued ========\n";
    fout << station;

    fout << "\n\n======== Station analysis ========\n";
    station.analysis(fout);

    fout << "\n======== Find by address ========\n";
    station.find_by_address("Nadpil'na 196" ,fout);

    fout << "\n======== Find debtors ========\n";
    station.find_debtors(fout);

    fout << "\n======== Sum of all debt ========\n";
    fout << station.all_debt() << endl;

    fout << "\n======== Add client ========\n";
    station.add_client("l 47 47958596 0 8 Shevchenko street 29");
    fout << station;

    fout << "\n======== Delete client ========\n";
    station.del_client(42958671);
    fout << station;
    

    cout << "Success\n";
    fin.close();
    fout.close();
}