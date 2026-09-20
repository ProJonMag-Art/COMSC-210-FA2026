
// COMSC-210 | Lab 11 | Jonvianney Maglasang

// Started September 20, 2026 at 11:54am
// Finished September 20, 2026 at 

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

// Stores
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

    // Default Constructor makes items have 0 values, but allows updates in the future
    Date()
    {
        this->month = 0;
        this->day = 0;
        this->year = 0;
    }

    // Couts date in M/D/Y
    void printDate()
    {
        cout << this->month << "/" << this->day << "/" << this->year;
    }
};

// Struct Declarations
// Stores the name of the item, when the item was first listed, it's price, and a dynamic array containing any the full record of prices (stores the date of new and old prices)
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

    // Default Constructor sets values to 0, but allows updates in the future
    Item()
    {
        this->name = " ";
        this->date = Date();
        this->price = 0;
        this->priceRecord = nullptr;
    }

    // Destructor should delete the priceRecord ptr object and assign it to null ptr when Item object is destroyed or out of scope
    ~Item()
    {
        delete [] this->priceRecord;
        this->priceRecord = nullptr;
    }
};

// Global Variables
const int arrSize = 10;

// Function Declarations
void printItemArr(Item item)
{
    item.date.printDate();
    
}

int main()
{
    Item* itemArr = new Item[arrSize];
    for(int i = 0; i < arrSize; i++)
    {
        itemArr[i] = Item();

        itemArr[i].date.printDate(); // Couts full date M/D/Y
        cout << itemArr[i].name << " " << itemArr[i].price;
    }

    return 0;
}