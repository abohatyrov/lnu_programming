// Напишіть програму для обходу прямокутної матриці “вертикальною змійкою”, починаючи з нижнього лівого кута.
#include <iostream>

using namespace std;

int main()
{
    int row, col;
    cout << "Enter rows and columns of matrix:\n";
    cin >> row >> col;

    int** matrix = new int*[row];
    cout << "Enter matrix:\n";
    for (int i = 0; i < row; i++)
    {
        matrix[i] = new int[col];
        for (int j = 0; j < col; j++)
            cin >> matrix[i][j];
    }

    int* path = new int[row * col];
    int k = 0;
    for (int j = 0; j < col; j++)
    {
        if (j % 2 == 0)
            for (int i = row - 1; i >= 0; i--)
            {
                path[k] = matrix[i][j];
                k++;
            }
        else
            for (int i = 0; i < row; i++)
            {
                path[k] = matrix[i][j];
                k++;
            }
    }

    cout << "Vertical snake path:\n";
    for (int i = 0; i < k; i++)
    {
        if (i % row == 0 && i != 0) cout << "  ";
        cout << path[i] << ' ';
    }

    cout << endl;
}

// 4 6
// 1 2 3 4 5 6
// 7 8 9 0 1 2
// 3 4 5 6 7 8
// 9 0 1 2 3 4