#pragma once
#include <iostream>
#include <fstream>

using namespace std;

struct node
{
    double data;
    node *next;
};

class List
{
    node* beg;
    node* end;
public:
    List(): beg(NULL), end(NULL) {}
    List(istream&);
    ~List();
    bool is_empty();
    void add_begin(const double);
    void add_end(const double);
    void del_begin();
    void del_end();
    double sum();
    void del_all_e(double);
    friend ostream& operator <<(ostream&,const List&);
};

List::List(istream& is)
{
    beg = NULL;
    end = NULL;
    while (!is.eof())
    {
        double input_data; 
        is >> input_data;
        add_end(input_data);
    }
}

List::~List()
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

bool List::is_empty()
{
	return beg == NULL && end ==NULL;
}

void List::add_begin(const double t)
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

void List::add_end(const double t)
{
    node* r = new node;
    r->data = t;
    r->next = NULL;
    if (end) end->next = r;
    else beg = r;
    end = r;
}

void List::del_begin()
{
    if(!beg) return;

    node* q = beg->next;
    delete beg;
    beg = q;
}

void List::del_end()
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

double List::sum()
{
    if(!beg) return -1;
    return beg->data + end->data;
}

void List::del_all_e(double e)
{
    if(!beg) return;
	
	node *p = beg, *q = p->next;
	while(q)
	{
		if (q->data == e)
        {
            p->next = q->next;
            delete q;
            q = p->next;
        }
        else 
        {
            p = q;
            q = q->next;
        }
	}
}

ostream& operator <<(ostream& os, const List& lst)
{
    if (!lst.beg) return os << "List is empty.";

    os << "List: ";
    node* q = lst.beg;
    do
    {
        os << q->data << ' ';
    } while (q = q->next);
    os << endl;

    return os;
}