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
            if (stack.top() == '[' || stack.top() == '{')
                return false;
            stack.pop();
            break;
        case ']':
            if (stack.top() == '(' || stack.top() == '{')
                return false;
            stack.pop();
            break;
        case '}':
            if (stack.top() == '(' || stack.top() == '[')
                return false;
            stack.pop();
            break;
        }
    }

    return true;
}