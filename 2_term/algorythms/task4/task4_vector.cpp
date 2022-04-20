// 4.У заданому масиві цілих чисел знайти найдовшу підпослідовність елементів, сума цифр яких рівна заданому числу с. Вивести її на екран, вказавши індекси першого і останнього елементів підпослідовності.
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int c; cout << "Enter c: "; cin >> c;
    int n; cout << "Enter size of vector: "; cin >> n;
    int* arr = new int[n];
    cout << "Enter vector: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int posStart = 0, posEnd = 0, sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += arr[j];
            if (sum > c)
                break;
            else if (sum == c && j - i > posEnd - posStart)
            {
                posStart = i;
                posEnd = j;
            }
        }
    }

    cout << "Start position: " << posStart;
    cout << "\tEnd position: " << posEnd;
    cout << "\nSubsequence: ";
    for (int i = posStart; i <= posEnd; i++)
        cout << arr[i] << ' ';

    cout << endl;
}

// 7, 15, 7 1 6 1 2 8 5 6 -1 -1 -1 1 2 1 2
// 5, 10, 3 2 4 1 3 1 1 1 1 1