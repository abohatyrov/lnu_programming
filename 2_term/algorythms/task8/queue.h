#pragma once
#include <iostream>
#include <fstream>

using namespace std;

class Queue
{
private:
    int* arr;
    int n;
public:
    Queue() { n = 0; }
    Queue(const Queue& obj)
    {
        n = obj.n;
        arr = new int[n];

        for (int i = 0; i < n; i++)
            arr[i] = obj.arr[i];
    }

    void push(int item)
    {
        int* arr2 = arr;

        arr = new int[n + 1];
        for (int i = 0; i < n; i++)
            arr[i] = arr2[i];
        arr[n] = item;
        n++;

        
    }

    int pop()
    {
        if (n == 0) return 0;

        int item = arr[0];

        int* arr2 = new int[n - 1];
        n--;
        for (int i = 0; i < n; i++)
            arr2[i] = arr[i + 1];

        if (n > 0) delete[] arr;
        arr = arr2;

        return item;
    }

    int GetFirstItem()
    {
        if (n > 0)
            return arr[0];
        else
            return 0;
    }

    int GetSize() { return n; }

    void clear()
    {
        if (n > 0)
        {
            delete[] arr;
            n = 0;
        }
    }

    Queue& operator=(const Queue& obj)
    {
        if (n > 0) delete[] arr;

        arr = new int[obj.n];
        n = obj.n;
        for (int i = 0; i < n; i++)
            arr[i] = obj.arr[i];

        return *this;
     }
};
