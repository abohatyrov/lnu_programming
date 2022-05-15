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

    Queue<int> q1;
    Queue<int> q2;
    Queue<int> q3;

    for (int i = 0; i < q.size(); i++)
    {
        if (q[i] != 0 && sqrt(q[i]) * sqrt(q[i]) == q[i])
            q1.push(q[i]);
        else if (q[i] < 0)
            q2.push(q[i]);
        else
            q3.push(q[i]);
    }

    cout << "\nFull squares: " << q1;
    cout << "\nNegative values: " << q2;
    cout << "\nOther values: " << q3;



    cout << "\nSuccess\n";
    fin.close();
}