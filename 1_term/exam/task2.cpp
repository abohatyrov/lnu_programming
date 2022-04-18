// Задано дійсну квадратну матрицю. Знайти найбільший елемент серед мінімальних елементів тих рядків, в яких є від’ємний елемент на головній діагоналі.
#include <iostream>
#include <fstream>
using namespace std;

int MaxOfMin(int** matrix, int n);

int main() 
{
    fstream fin, fout;
    fin.open("D:\\Study\\Programming\\C++\\exam\\input_task2.txt", fstream::in);
    fout.open("D:\\Study\\Programming\\C++\\exam\\output.txt", fstream::out);

    int n;
    fin >> n;
    int** matrix = new int* [n];
    for (size_t i = 0; i < n; i++)
    {
        matrix[i] = new int[n];
        for (size_t j = 0; j < n; j++)
            fin >> matrix[i][j];
    } 

    int max = MaxOfMin(matrix, n);    
    fout << "Max of min: " << max;

    fin.close();
    fout.close();
    cout << "Success!";
}

int MaxOfMin(int** matrix, int n)
{
    int max = INT32_MIN;
    for (size_t i = 0; i < n; i++)
    {
        if (matrix[i][i] < 0)
        {
            int min = 0;
            for (size_t j = 0; j < n; j++)
                if (matrix[i][j] < min)
                    min = matrix[i][j];
            if (min > max)
                max = min;
        }
    }
    return max;
}