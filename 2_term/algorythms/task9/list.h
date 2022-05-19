#pragma once
#include <iostream>
#include <fstream>

using namespace std;

template <typename T>
class List
{
    struct node
    {
        T data;
        node *next;
    };
    node* beg;
    node* end;
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
        node* q;
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
        if (beg == NULL && end == NULL)
            return true;
        else
            return false;
    }

    void add_begin(const T t)
    {
        node* r = new node;
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
        node* r = new node;
        r->data = t;
        r->next = NULL;
        if (end) end->next = r;
        else beg = r;
        end = r;
    }

    void del_begin()
    {
        if(!beg) return;

        node* q = beg->next;
        delete beg;
        beg = q;
    }

    void del_end()
    {
        if(!beg) return;

        node* q = beg;
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

    node* begin() { return beg; }

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

    int operator[](const int i)
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

    void clear()
    {
        node* p = beg;
        node* q = p->next;
        do
        {
            if (p->data == q->data)
            {
                p->next = q->next;
                delete q;
                q = p->next;
                continue;
            }
            p = p->next;
        } while (q = p->next);
    }

    friend ostream& operator <<(ostream& os, const List<T>& lst)
    {
        if (!lst.beg) return os << "List is empty.";

        node* q = lst.beg;
        do
        {
            os << q->data << ' ';
        } while (q = q->next);
        os << endl;

        return os;
    }
};

