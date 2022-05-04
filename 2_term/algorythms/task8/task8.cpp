#include <istream>
#include <fstream>
#include <string>
#include "queue.h"

using namespace std;

int main()
{
    ifstream fin("input.txt");


    Queue q;
    string temp;
    while (!fin.eof())
    {
        int item;
        fin >> item;
        q.push(item);
    }
    
    for (int i = 0; i < q.GetSize(); i++)
    {
        cout << q.GetFirstItem() << ' ';
        q.pop();
    }
    cout << endl;

    cout << "Success\n";
    fin.close();
}