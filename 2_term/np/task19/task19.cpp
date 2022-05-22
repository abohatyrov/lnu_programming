#include <iostream>
#include <fstream>
#include <list>
#include <algorithm>
#include <iterator>
#include <numeric>
#include "consumer.h"

using namespace std;

int main()
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");


    list<Consumer> v;
    while (!fin.eof())
    {
        string str;
        getline(fin >> ws, str);

        int pos = 0, pos1 = str.find(' ');
        int consumerNumber = stoi(str.substr(pos, pos1 - pos));
        pos = pos1 + 1;
        pos1 = str.find(' ', pos);
        long mobileNumber = stol(str.substr(pos, pos1 - pos));
        pos = pos1 + 1;
        pos1 = str.find(' ', pos);
        int debt = stoi(str.substr(pos, pos1 - pos));
        if (debt < 10) continue;
        pos = pos1 + 1;
        pos1 = str.size();
        string address = str.substr(pos, pos1 - pos);

        Consumer con(consumerNumber, address, mobileNumber, debt);
        v.emplace_back(con);
    }

    for (auto iter = v.begin(); iter != v.end(); iter++)
    {
        cout << *iter << endl;
    }

    cout << "Enter number to replace: ";
    int number;
    cin >> number;
    for (auto iter = v.begin(); iter != v.end(); iter++)
    {
        if (iter->GetConsumerNumber() == number)
        {
            Consumer con;

            cout << "Enter new number: ";
            long mobile_number; cin >> mobile_number;
            con = Consumer(mobile_number / 1000000, iter->GetAddress(), mobile_number, iter->GetDebt());
            *iter = con;
        }
    }
    cout << endl;

    copy(v.begin(), v.end(), ostream_iterator<Consumer>(cout, "\n"));

    auto lambda = [&](int sum, Consumer con2) { return sum + con2.GetDebt(); };
    int sum = accumulate(v.begin(), v.end(), 0, lambda);

    cout << "Sum: " << sum << "\n\n";

    cout << "You want to save data with sum or not? (y/n): ";
    char save; cin >> save;
    if (save == 'y')
    {
        copy(v.begin(), v.end(), ostream_iterator<Consumer>(cout, "\n"));
        fout << "Sum: " << sum;
    }
    else
        copy(v.begin(), v.end(), ostream_iterator<Consumer>(cout, "\n"));


    cout << "Success\n";
    fin.close();
    fout.close();
}