#include <iostream>
#include <fstream>
#include <string>
#include "car.h"

using namespace std;

void MergeSort(Car*, int, int, int);
void Merge(Car*, int, int, int, int);
int BinarySearchLabel(Car*, string, int);
int BinarySearchYear(Car*, int, int);
int BinarySearchPrice(Car*, double, int);


int main()
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    // Sorting array

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

    // Binary search part

    int l;
    if (s == 0)
    {
        string label;
        cout << "Enter label to search for: "; getline(cin >> ws, label);
        l = BinarySearchLabel(arr, label, n - 1);
    }
    else if (s == 1)
    {
        int year;
        cout << "Enter year to search for: "; cin >> year;
        l = BinarySearchYear(arr, year, n - 1);
    }
    else
    {
        double price;
        cout << "Enter price to search for: "; cin >> price;
        l = BinarySearchPrice(arr, price, n - 1);
    }

    // Output

    cout << "Sorted array:\n";
    for (int i = 0; i < n; i++)
        cout << "Car " << i + 1 << endl << arr[i] << endl;

    cout << "=======================================\n\n";

    if (l == -1)
        cout << "Not found.";
    else
        cout << "Here is your element on position " << l << ":\n" << arr[l];


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
            arr[k] = l[i];
            i++;
        } 
        else if (s == 1 && l[i].GetYear() <= m[j].GetYear())
        {
            arr[k] = l[i];
            i++;
        } 
        else if (s == 2 && l[i].GetPrice() <= m[j].GetPrice())
        {
            arr[k] = l[i];
            i++;
        } 
        else
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

int BinarySearchLabel(Car* arr, string found, int r)
{
    int l = 0;
    while (l < r)
    {
        int m = (l + r) / 2;

        if (found > arr[m].GetLabel()) l = m + 1;  else r = m;
    }

    if (arr[l].GetLabel() == found) return l;
    else return -1;
}

int BinarySearchYear(Car* arr, int found, int r)
{
    int l = 0;
    while (l < r)
    {
        int m = (l + r) / 2;

        if (found > arr[m].GetYear()) l = m + 1;  else r = m;
    }

    if (arr[l].GetYear() == found) return l;
    else return -1;
}

int BinarySearchPrice(Car* arr, double found, int r)
{
    int l = 0;
    while (l < r)
    {
        int m = (l + r) / 2;

        if (found > arr[m].GetPrice()) l = m + 1;  else r = m;
    }

    if (arr[l].GetPrice() == found) return l;
    else return -1;
}
