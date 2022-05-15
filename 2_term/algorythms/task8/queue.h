#pragma once
#include <iostream>
#include <fstream>

using namespace std;

template <typename T>
class Queue
{
    struct node
    {
        T data;
        node* next;
    };
    node* beg;
    node* end;
public:
    Queue(): beg(NULL), end(NULL) {}

    void push(const T obj)
    {
        node* p = new node;
        p->data = obj;
        p->next = nullptr;
        if (end) end->next = p;
        else beg = p;
        end = p;
    }

    void pop()
    {
        node* p = new node;
        p = beg->next;
        delete beg;
        beg = p;
    }

    T top()
    {
        return end->data;
    }

    int size()
    {
        if (!end) return 0;
        node* p = beg;
        int i = 0;
        do
        {
            i++;
        } while (p = p->next);
        return i;
    }

    T operator[](const int i)
    {
        node* p = beg;
        int j = 0;
        do
        {
            if (j == i) break;
            j++;
            p = p->next;
        } while (p->next != NULL);

        return j <= i ? p->data : 0;
    }

    friend ostream& operator <<(ostream& os, Queue& q)
    {
        node* p = q.beg;
        do
        {
            os << p->data << ' ';
        } while (p = p->next);
        cout << endl;
        return os;
    }
};
