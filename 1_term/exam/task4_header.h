#include <iostream>
#include <string>

using namespace std;

class Item
{
private:
    string article;
    int price;
    string category;
public:
    Item()
    {
    }

    Item(string article, int price, string category)
    {
        this->article = article;
        this->price = price;
        this->category = category;
    }

    Item(Item* item)
    {
        this->article = item->GetArticle();
        this->price = item->GetPrice();
        this->category = item->GetCategory();
    }

    void SetArticle(string article)
    {
        this->article = article;
    }

    string GetArticle()
    {
        return article;
    }

    void SetPrice(int price)
    {
        this->price = price;
    }

    int GetPrice()
    {
        return price;
    }

    void SetCategory(int category)
    {
        this->category = category;
    }

    string GetCategory()
    {
        return category;
    }
};

bool operator < (Item left, Item rigth)
{
    return left.GetPrice() < rigth.GetPrice();
}

bool operator > (Item left, Item rigth)
{
    return left.GetPrice() > rigth.GetPrice();
}

bool operator == (Item left, Item rigth)
{
    return left.GetArticle() == rigth.GetArticle();
}