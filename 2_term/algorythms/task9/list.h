#pragma once
#include <iostream>
#include <fstream>

using namespace std;

template <typename T>
struct node
{
    T data;
    node *next;
};

template <typename T>
class List
{
    node<T>* beg;
    node<T>* end;
public:
    List(): beg(NULL), end(NULL) {}

    List(istream& is)
    {
        beg = NULL;
        end = NULL;
        while (!is.eof())
        {
            T input_data; 
            is >> input_data;
            add_end(input_data);
        }
    }

    ~List()
    {
        if(!beg) return;
        node<T>* q;
        do
        {
            q=beg;
            beg=beg->next;
            delete q;
        }
        while(beg);
    }

    bool is_empty()
    {
        return beg == NULL && end ==NULL;
    }

    void add_begin(const T t)
    {
        node<T>* r = new node<T>;
        r->data = t;
        r->next = beg;
        if (!beg)
        {
            end = r;
            end->next = NULL;
        }
        beg = r;
    }

    void add_end(const T t)
    {
        node<T>* r = new node<T>;
        r->data = t;
        r->next = NULL;
        if (end) end->next = r;
        else beg = r;
        end = r;
    }

    void del_begin()
    {
        if(!beg) return;

        node<T>* q = beg->next;
        delete beg;
        beg = q;
    }

    void del_end()
    {
        if(!beg) return;

        node<T>* q = beg;
        while(q = q->next)
        {
            if (q->next == end)
            {
                delete end;
                q->next = NULL;
                end = q;
            }  
        }
    }

    node<T>* begin() { return beg; }

    int size()
    {
        if (!end) return 0;
        node<T>* p = beg;
        int i = 0;
        do
        {
            i++;
        } while (p = p->next);
        return i;
    }

    int operator[](const int i)
    {
        node<T>* p = beg;
        int j = 0;
        do
        {
            if (j == i) break;
            j++;
            p = p->next;
        } while (p->next != NULL);

        return j <= i ? p->data : 0;
    }

    friend ostream& operator <<(ostream& os, const List<T>& lst)
    {
        if (!lst.beg) return os << "List is empty.";

        os << "List: ";
        node<T>* q = lst.beg;
        do
        {
            os << q->data << ' ';
        } while (q = q->next);
        os << endl;

        return os;
    }
};
