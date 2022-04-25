#include <iostream>
#include <fstream>
#include <string>
#include "car.h"

using namespace std;

void MergeSort(Car*, int, int, int);
void Merge(Car*, int, int, int, int);
int BinarySearch(Car*, int, int, int, int);


int main()
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");


    int n;
    // cout << "Enter count of cars: "; 
    fin >> n;

    Car* arr = new Car[n];
    // cout << "Enter cars:\n";
    for (int i = 0; i < n; i++)
        fin >> arr[i];

    int s;
    cout << "Select how to sort ([0] label, [1] year, [2] price): "; cin >> s;

    MergeSort(arr, s, 0, n - 1);

    fout << "Sorted array:\n";
    for (int i = 0; i < n; i++)
        fout << "Car" << i + 1 << endl << arr[i] << endl;

    int i_find; fin >> i_find;
    int l; l = BinarySearch(arr, i_find, s, 0, n - 1);
    if (l == -1)
        fout << "Not find.";
    else
        fout << "Here is your element:\n" << arr[l];


    cout << "Success\n";
    fin.close();
    fout.close();
}

void MergeSort(Car* arr, int s, int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;

        MergeSort(arr, s, l, m);
        MergeSort(arr, s, m + 1, r);

        Merge(arr, s, l, m, r);
    }
}

void Merge(Car* arr, int s, int p, int q, int r)
{
    int n1 = q - p + 1;
    int n2 = r - q;

    Car* l = new Car[n1];
    Car* m = new Car[n2];

    for (int i = 0; i < n1; i++)
        l[i] = arr[p + i];
    for (int i = 0; i < n2; i++)
        m[i] = arr[q + i + 1];

    int i = 0, j = 0, k = p;

    while (i < n1 && j < n2)
    {
        if (s == 0 && l[i].GetLabel() <= m[j].GetLabel())
        {
            arr[k] = Car(l[i]);
            i++;
        } 
        else if (s == 1 && l[i].GetYear() <= m[j].GetYear())
        {
            arr[k] = Car(l[i]);
            i++;
        } 
        else if (s == 2 && l[i].GetPrice() <= m[j].GetPrice())
        {
            arr[k] = Car(l[i]);
            i++;
        } 
        else
        {
            arr[k] = Car(m[j]);
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

int BinarySearch(Car* arr, int i_find, int s, int l, int r)
{
    while (l < r)
    {
        int m = (l + r) / 2;

        if (s == 0 && arr[i_find].GetLabel() > arr[m].GetLabel()) l = m + 1; 
        else if (s == 1 && arr[i_find].GetYear() > arr[m].GetYear()) l = m + 1; 
        else if (s == 2 && arr[i_find].GetPrice() > arr[m].GetPrice()) l = m + 1; 
        else r = m;
    }

    if (s == 0 && arr[l].GetLabel() == arr[i_find].GetLabel()) return l; 
    else if (s == 1 && arr[l].GetPrice() == arr[i_find].GetYear()) return l; 
    else if (s == 2 && arr[l].GetYear() == arr[i_find].GetPrice()) return l; 
    else return -1;
}
