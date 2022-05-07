#pragma once

using namespace std;

struct node
{
    char data;
    node *next;
};

template <typename T>
class Stack
{
    node* beg;
    node* end;
public:
    Stack(): beg(NULL), end(NULL) {}

    Stack(istream& is)
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

    ~Stack()
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

    void push(const T t)
    {
        node* r = new node;
        r->data = t;
        r->next = NULL;
        if (end) end->next = r;
        else beg = r;
        end = r;
    }

    void pop()
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

    T top()
    {
        return end->data;
    }
};




// class Bracket
// {
//     node* open_beg;
//     node* open_end;
//     node* close_beg;
//     node* close_end;
// public:
//     Bracket();
//     Bracket(const char);
//     void add_bracket(const char);
//     bool check_brakets();
// };

// Bracket::Bracket() 
// { 
//     open_beg = open_end = close_beg = close_end = nullptr; 
// }

// Bracket::Bracket(const char t)
// {
//     node* p = new node;
//     p->bracket = t;
// }

// void Bracket::add_bracket(const char t)
// {
//     node* r = new node;
//     r->bracket = t;
//     r->next = nullptr;
//     if (t == '(' || t == '[' || t == '{')
//     {
//         if (open_beg == nullptr) 
//         {
//             open_beg = r;
//             open_end = r;
//         }
//         else
//         {
//             open_end->next = r;
//             open_end = open_end->next;
//         }
//     }
//     else 
//     {
//         if (close_beg == nullptr) 
//         {
//             close_beg = r;
//             close_end = r;
//         }
//         else
//         {
//             close_end->next = r;
//             close_end = close_end->next;
//         } 
//     } 
// }

// bool Bracket::check_brakets()
// {
//     bool is_ok = true;
//     node* p = open_beg;
//     node* q = close_beg;
//     do
//     {
//         if (p->bracket == '(' && q->bracket != ')' ||
//             p->bracket == '[' && q->bracket != ']' ||
//             p->bracket == '{' && q->bracket != '}')
//         {
//             is_ok = false;
//             break;
//         }
        
//         if (q->next == nullptr) break;
//         else q = q->next;
//     } while (p = p->next);

//     return is_ok;
// }
