#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int c; cout << "Enter c: "; cin >> c;
    int n; cout << "Enter size of vector: "; cin >> n;
    vector<int> v;
    cout << "Enter vector: ";
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        v.push_back(temp);
    }

    for (int i = 0; i < n; i++)
    {
        vector<int> sub;
        for (int j = i; j < n; j++)
        {
            sub.push_back(v[j]);
            
        }
    }
}