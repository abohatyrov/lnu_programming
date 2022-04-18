// Задано список деяких слів. Викреслити з списку слова, які починаються буквою ‘b’ або ‘d’, і порахувати, скільки було таких слів. 
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string* StrToArr(string str, size_t& k);

int main()
{ 
    fstream fin, fout;
    fin.open("D:\\Study\\Programming\\C++\\exam\\input_task3.txt", fstream::in);
    fout.open("D:\\Study\\Programming\\C++\\exam\\output.txt", fstream::out);

    string line;
    size_t k = 0;
    getline(fin, line);


    string* words = StrToArr(line, k);
    k++;

    int count = 0;
    for (size_t i = 0; i < k; i++)
        if (words[i].find('b') == 0 || words[i].find('d') == 0)
        {
            words[i] = "0";
            count++;
        }

    fout << "Your line without words, which begin on 'b' or 'd':" << endl;
    for(int i = 0; i < k; i++)
        if (words[i] != "0")
            fout << words[i] << ' ';
    fout << "\nCount: " << count;

    fin.close();
    fout.close();
    cout << "Success!";
}

string* StrToArr(string str, size_t& k)
{
    string* arr = new string[25];
    int spacePos;
    int currPos = 0;
    int prevPos = 0;
    do
    {
        spacePos = str.find(' ',currPos);

        if(spacePos >= 0)
        {
            currPos = spacePos;
            arr[k] = str.substr(prevPos, currPos - prevPos);
            currPos++;
            prevPos = currPos;
            k++;
        }
    }while(spacePos >= 0);
    arr[k] = str.substr(prevPos, str.length());
    arr[k].erase(arr[k].find('.'));
    return arr;
}