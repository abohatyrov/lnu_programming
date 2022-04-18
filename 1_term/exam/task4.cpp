//Створити клас для опису вказаної у відповідному варіанті сутності, який містить 3 private-поля. Визначити усі конструктори (за замовчуванням, з параметрами і копіювання), методи введення та виведення на екран, методи доступу до полів класу. 
// Створити масив з об’єктів класу. Вивести всі об’єкти, які задовольняють певну умову.
// Мережа магазинів (нехай 3) торгує різними продуктами. Кожен магазин склав список замовлень для постачальника. Постачальнику необхідно знати: 1) які товари фігурують в замовленнях; 2) які товари є найбільш популярними і фігурують у всіх замовленнях.
//ws - Пропускати пробілові символи
#include <iostream>
#include <fstream>
#include <string>
#include "task4_header.h"

using namespace std;

int main()
{ 
    fstream fin, fout;
    fin.open("D:\\Study\\Programming\\C++\\exam\\input_task4.txt", fstream::in);
    fout.open("D:\\Study\\Programming\\C++\\exam\\output.txt", fstream::out);

    int n, m, k;
    fin >> n;
    Item* store_1 = new Item [n];
    fin >> m;
    Item* store_2 = new Item [m];
    fin >> k;
    Item* store_3 = new Item [k];

    for (int i = 0; i < n; i++)
    {
        string article;
        int price;
        string category;
        
        getline(fin >> ws, article);
        fin >> price;
        fin.ignore();
        getline(fin, category);

        Item item = Item(article, price, category);
        store_1[i] = item;
    }

    for (int i = 0; i < m; i++)
    {
        string article;
        int price;
        string category;
        
        getline(fin >> ws, article);
        fin >> price;
        fin.ignore();
        getline(fin, category);

        Item item = Item(article, price, category);
        store_2[i] = item;
    }

    for (int i = 0; i < k; i++)
    {
        string article;
        int price;
        string category;
        
        getline(fin >> ws, article);
        fin >> price;
        fin.ignore();
        getline(fin, category);

        Item item = Item(article, price, category);
        store_3[i] = item;
    }

    fout << "Store_1 order: " << endl;
    for (size_t i = 0; i < n; i++)
        fout << store_1[i].GetArticle() << endl << store_1[i].GetPrice() << endl << store_1[i].GetCategory() << endl;
    fout << endl;

    fout << "Store_2 order: " << endl;
    for (size_t i = 0; i < m; i++)
        fout << store_2[i].GetArticle() << endl << store_2[i].GetPrice() << endl << store_2[i].GetCategory() << endl;
    fout << endl;

    fout << "Store_3 order: " << endl;
    for (size_t i = 0; i < k; i++)
        fout << store_3[i].GetArticle() << endl << store_3[i].GetPrice() << endl << store_3[i].GetCategory() << endl;
    fout << endl;

    int max = 0;
    Item pop = Item();
    for (size_t i = 0; i < n; i++)
    {
        int count = 0;
        for (size_t j = 0; j < m; j++)
            for (size_t t = 0; t < k; t++)
                if (store_1[i] == store_2[j] && store_2[j] == store_3[t])
                    count++;
        if (count > max)
        {
            max = count;
            pop = Item(store_1[i]);
        }
    }
    
    if (max > 0)
        fout << "Most popular item:" << endl << pop.GetArticle() << endl << pop.GetPrice() << endl << pop.GetCategory() << endl;
    else
        fout << "There is no article which are repeated";
    
    fin.close();
    fout.close();
    cout << "Success!";
}
