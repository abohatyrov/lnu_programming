// Дано ціле число m > 1. Знайти найбільше ціле k таке, що 4^k < m.
#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

int main()
{
    fstream fin, fout;
    fin.open("D:\\Study\\Programming\\C++\\exam\\input_task1.txt", fstream::in);
    fout.open("D:\\Study\\Programming\\C++\\exam\\output.txt", fstream::out);

    int m;
    fin >> m;
    
    int k = 1;
    while (true)
    {
        if (pow(4, k) < m)
            k++;
        else
        {
            --k;
            break;
        }
    }

    fout << "The biggest k: " << k;

    fin.close();
    fout.close();
    cout << "Success!";
}