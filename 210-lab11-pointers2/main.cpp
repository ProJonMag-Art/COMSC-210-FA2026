
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

    // Prints name, date, and price
    void printItemData()
    {
        cout << this->name << " ";
        this->date.printDate();
        cout << " " << this->price << endl;
    }

    // Prints name, date, and price of whichever Item* priceRecord for its entire size
    // All priceRecord children point to nullptr by default, stopping infinite recursion
    void printRecordData(int recordSize)
    {
        if(this->priceRecord != nullptr)
        {
            for(int i = 0; i < recordSize; i++)
            {
                this->priceRecord[i].printItemData();
            }
        }
    }
};

// Global Variables
const int CatalogueSize = 3;
const int ItemRSize = 2;

// Function Declarations
void printItemArr(Item item);

int main()
{
    Item* catalogue = new Item[CatalogueSize];
    Item* pRecord = new Item[ItemRSize];
    Item* sRecord = new Item[ItemRSize];
    Item* vRecord = new Item[ItemRSize];

    
    
    catalogue[0] = Item("Pasta", {9, 20, 2026}, 5.22, pRecord);
    catalogue[1] = Item("Steak", {9, 20, 2026}, 12.36, sRecord);
    catalogue[2] = Item("Frozen Veggies", {9, 20, 2026}, 3.25, vRecord);

    return 0;
}