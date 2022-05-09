// Використати чергу для розв’язування задачі. Задано файл цілих чисел. За один перегляд файлу вивести на екран спочатку всі числа, які є повними квадратами, потім – всі від’ємні, і в кінці – всі інші числа, зберігаючи вихідний взаємний порядок у кожній із трьох груп чисел.
#include <istream>
#include <fstream>
#include <string>
#include <cmath>
#include <queue>
#include "queue.h"

using namespace std;

int main()
{
    ifstream fin("input.txt");


    Queue<int> q;
    string temp;
    while (!fin.eof())
    {
        int item;
        fin >> item;
        q.push(item);
    }
    
    cout << "List: " << q;

    cout << "\nFull squares: ";
    for (int i = 0; i < q.size(); i++)
    {
        int a = q[i];
        a = round(sqrt(a));
        if (a * a == q[i])
            cout << q[i] << ' ';
    }
    cout << endl;

    cout << "\nFull squares: ";
    for (int i = 0; i < q.size(); i++)
    {
        int a = q[i];
        a = round(sqrt(a));
        if (a * a == q[i])
            cout << q[i] << ' ';
    }
    cout << endl;


    cout << "\nSuccess\n";
    fin.close();
}