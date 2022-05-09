#include <iostream>
#include <fstream>
#include "list.h"

using namespace std;

void clear(node<double>* begq);

int main()
{
    ifstream fin("input_data.txt");

    List<double> lst(fin);
    if (lst.is_empty()) cout << "List is empty.\n\n";
    else cout << "List isn't empty.\n\n";
    cout << lst << endl;

    int sum = 0;
    for (int i = 0; i < lst.size(); i++)
        sum += lst[i];
    cout << "Arithmetic mean: " << sum / (double) lst.size() << endl;

    clear(lst.begin());
    cout << lst << endl;
    

    cout << "Success\n";
    fin.close();
}

void clear(node<double>* begq)
{
    node<double>* p = begq;
    node<double>* q = p->next;
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