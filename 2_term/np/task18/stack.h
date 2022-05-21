#pragma once

using namespace std;


template <typename T>
class Stack
{
    struct node
    {
        T data;
        node *next;
    };
    node* end;
public:
    Stack(): end(NULL) {}

    ~Stack()
    {
        if(!end) return;
        node* q;
        do
        {
            q=end;
            end=end->next;
            delete q;
        }
        while(end);
    }

    void push(const T t)
    {
        node* r = new node;
        r->data = t;
        r->next = end;
        end = r;
    }

    void pop()
    {
        if(!end) return;

        node* q = end->next;
        delete end;
        end = q;
    }

    T top()
    {
        return end->data;
    }
};
