#include <iostream>

using namespace std;

void MergeSort(int*, int, int);
void Merge(int*, int, int, int);

int main()
{
    int n;
    cout << "Enter size of array: "; cin >> n;

    int* arr = new int[n];
    cout << "Enter array:\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    MergeSort(arr, 0, n - 1);

    cout << "Sorted array:\n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << ' ';

    cout << endl;
}

void MergeSort(int* arr, int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;

        MergeSort(arr, l, m);
        MergeSort(arr, m + 1, r);

        Merge(arr, l, m, r);
    }
}

void Merge(int* arr, int p, int q, int r)
{
    int n1 = q - p + 1;
    int n2 = r - q;

    int* l = new int[n1];
    int* m = new int[n2];

    for (int i = 0; i < n1; i++)
        l[i] = arr[p + i];
    for (int i = 0; i < n2; i++)
        m[i] = arr[q + i + 1];

    int i = 0, j = 0, k = p;

    while (i < n1 && j < n2)
    {
        if (l[i] <= m[j])
        {
            arr[k] = l[i];
            i++;
        } else
        {
            arr[k] = m[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = l[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = m[j];
        j++;
        k++;
    }
}
