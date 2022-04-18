#include <iostream>
using namespace std;

void input_arr(int n, int* arr);
void def(int m, int n, int* arr);

int main()
{
    int n, m;

    cout << "Enter size of arrey: ";
    cin >> n;
    cout << endl;

    int* arr = new int [n];
    input_arr(n, arr);

    cout << "Enter m: ";
    cin >> m;
    cout << endl;

    def(m, n, arr);

    return 0;
}

void input_arr(int n, int* arr)
{
    cout << "Enter arrey:\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << endl;
}

void def(int m, int n, int* arr)
{
    int count = 0;
	for (int i = 0; i < n; i++)
	{
        if (arr[i] == m * m)
        {
            cout << "Element on the position: " << i + 1 << endl;
            count++;
        }
	}
    if (count == 0)
        cout << "There are no elements equal to " << m * m << endl;
    else
        cout << endl << "The number of elements that are equal to " << m * m << ": " << count << endl;
}