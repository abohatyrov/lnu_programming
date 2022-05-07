#include <iostream>
#include <string>
#include "stack.h"

using namespace std;
// {(()[])}
// ({)[(])[(])}

bool is_brackets_balanced(string);

int main()
{
    string expression;
    cout << "Enter your expression: ";
    getline(cin, expression);

    is_brackets_balanced(expression) ? 
        cout << "Brackets balanced.\n" : 
        cout << "Brackets not balanced.\n";
}

bool is_brackets_balanced(string str)
{
    Stack<char> stack;
    char x;

    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '(' || str[i] == '[' ||
            str[i] == '{')
        {
            stack.push(str[i]);
            continue;
        }

        switch (str[i])
        {
        case ')':
            x = stack.top();
            stack.pop();
            if (x == '[' || x == '{')
                return false;
            break;
        case ']':
            x = stack.top();
            stack.pop();
            if (x == '(' || x == '{')
                return false;
            break;
        case '}':
            x = stack.top();
            stack.pop();
            if (x == '(' || x == '[')
                return false;
            break;
        }
    }

    return true;
}