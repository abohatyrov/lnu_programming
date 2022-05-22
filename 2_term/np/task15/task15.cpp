#include <iostream>
#include <fstream>
#include <string>
#include <exception>
#include "aps.h"

using namespace std;

int main()
{
    ifstream fin;
    fin.exceptions(ifstream::failbit | ifstream::badbit);
    try {
        fin.open("input.txt");
        fin.peek();
        if (fin.eof())
        {
            cerr << "File is empty.\n"; 
            return 0;
        }
    }
    catch (ifstream::failure e) {
        cerr << "File does not exist.\n";
        return 0;
    }


    Aps station("Station 1");
    fin >> station;

    char menu_on = 'y';
    while (menu_on == 'y')
    {
        cout << station << endl;
        cout << "Select action:\n";
        cout << "- print full data (0)\n";
        cout << "- sort data (1)\n";
        cout << "- break on two (2)\n";
        cout << "- change a fee (3)\n";
        cout << "- print data analysis (4)\n";
        cout << "- find data (5)\n";
        cout << "- sum of all debt (6)\n";
        cout << "- add client (7)\n";
        cout << "- delete client (8)\n";
        cout << "- commands (m)\n";

        char sub_menu_on = 'y';
        while (sub_menu_on != 'n')
        {
            cout << "What to do?: ";
            char action; cin >> action;

            string str;

            switch (action)
            {
            case '0':
                station.print_full(cout);
                break;
            case '1':
                cout << "Sort by (phone [p], address [a], debt [d]): ";
                char sort; cin >> sort;
                switch (sort)
                {
                case 'p':
                    station.sort("Number");
                    cout << station << endl;
                    break;
                case 'a':
                    station.sort("Address");
                    cout << station << endl;
                    break;
                case 'd':
                    station.sort("Debt");
                    cout << station << endl;
                    break;
                }
            case '2':
                cout << "======== Break on two arrays ========\n";
                station.break_on_two();
                cout << "\n\n======== Individual ========\n";
                station.print_individual(cout);
                cout << "\n======== Legal ========\n";
                station.print_legal(cout);
                break;
            case '3':
                cout << "Enter fee in %: ";
                int fee; cin >> fee;
                station.fee(fee);
                cout << station << endl;
                break;
            case '4':
                station.analysis(cout);
                break;
            case '5':
                cout << "What you want to find (address [a], all debtors [d]): ";
                char to_find; cin >> to_find;
                
                switch (to_find)
                {
                case 'a':
                    cout << "Enter address: ";
                    getline(cin >> ws, str);
                    station.find_by_address(str, cout);
                    cout << endl;
                    break;
                case 'd':
                    station.find_debtors(cout);
                    cout << endl;
                    break;
                }
                break;
            case '6':
                cout << station.all_debt() << "\n\n";
                break;
            case '7':
                cout << "Enter user info in format (l 47 47958596 0 8 Shevchenko street 29):\n";
                getline(cin >> ws, str);
                station.add_client(str);
                cout << station << endl;
                break;
            case '8':
                cout << "Enter number of user to delete: ";
                long number; cin >> number;
                station.del_client(number);
                cout << station << endl;
                break;
            case 'm':
                cout << "Actions:\n";
                cout << "- print full data (0)\n";
                cout << "- sort data (1)\n";
                cout << "- break on two (2)\n";
                cout << "- change a fee (3)\n";
                cout << "- print data analysis (4)\n";
                cout << "- find data (5)\n";
                cout << "- sum of all debt (6)\n";
                cout << "- add client (7)\n";
                cout << "- delete client (8)\n";
                cout << "- commands (m)\n";
                break;
            }

            cout << "You want to continue? (y/n): ";
            cin >> menu_on;
            if (menu_on == 'y')
                continue;
            else if (menu_on == 'n')
            {
                cout << "Exit menu.\n";
                break;
            }
            else
            {
                cout << "Wrong input.\n";
                break;
            }
        }
    }
    

    cout << "Success\n";
    fin.close();
}