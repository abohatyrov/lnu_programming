#include <iostream>

using namespace std;

int main()
{
    int n;
    cout << "Enter size of matrix: ";
    cin >> n;
    cout << endl;

    int** matrix = new int* [n];
    for (int i = 0; i < n; i++)
        matrix[i] = new int[n];

    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            matrix[i][j] = j + 1;
            cout << matrix[i][j] << '\t';
        }
        for (int j = 0; j < i; j++)
            cout << 0 << '\t';
        cout << endl << endl;
    }
}