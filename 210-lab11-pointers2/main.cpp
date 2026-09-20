
// COMSC-210 | Lab 11 | Jonvianney Maglasang

// Started September 20, 2026 at 11:54am
// Finished September 20, 2026 at 

#include <iostream>
#include <string>

using namespace std;

struct Date
{
    int month;
    int day;
    int year;
    Date(int month, int day, int year)
    {
        this->month = month;
        this->day = day;
        this->year = year;
    }
};

// Stores the name of the item, when the item was first listed, it's price, and a dynamic array containing any the full record or prices (stores the date of the update, and the new price)
// Date format is M/D/Y

struct Item
{
    string name;
    Date date;
    float price;
    Item* priceRecord;
    Item(string name, Date date, float price, Item* priceRecord)
    {
        this->name = name;
        this->date = date;
        this->price = price;
        this->priceRecord = priceRecord;
    }
};

int main()
{

    return 0;
}