#include <iostream>
#include "consumer.h"

using namespace std;

int main()
{
    int n;
    cout << "Enter size of arrey: "; cin >> n;

    Consumer* con = new Consumer[n];
    for (size_t i = 0; i < n; i++)
        cin >> con[i]; cout << endl;

    for (size_t i = 0; i < n; i++)
    {
        cout << "Consumer " << i + 1 << endl;
        cout << con[i];
        con[i].ChangeDebt(20);
        int debt = con[i].GetDebt();
        cout << "Changed debt: " << debt << "\n\n";
    }
}