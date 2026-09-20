
// COMSC-210 | Lab 11 | Jonvianney Maglasang

// Started September 20, 2026 at 11:54am
// Finished September 20, 2026 at 

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

// Stores M/D/Y
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

// Struct Declarations and Definitions
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
        this->name = "";
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

int main()
{
    // Allocated Memory
    Item* catalogue = new Item[CatalogueSize];
    Item* pRecord = new Item[ItemRSize];
    Item* sRecord = new Item[ItemRSize];
    Item* vRecord = new Item[ItemRSize];
    
    // Define catalogue entries;
    catalogue[0] = Item("Pasta", {9, 18, 2026}, 5.22, nullptr);
    catalogue[1] = Item("Steak", {9, 18, 2026}, 12.36, nullptr);
    catalogue[2] = Item("Frozen Veggies", {9, 18, 2026}, 3.25, nullptr);

    // Assign values to Item* record vars
    for(int i = 0; i < ItemRSize; i++)
    {
        // priceRecord children are kept nameless and pointed to nullptr because they belong to a named item already
        // (i + 1) just makes sure the date is different from the current record
        // ((i + 1) * 0.25) just makes sure that the difference in price is interesting
        pRecord[i] = Item("", {9, 19 + (i + 1), 2026}, catalogue[0].price - ((i + 1) * 0.25), nullptr);
        sRecord[i] = Item("", {9, 19 + (i + 1), 2026}, catalogue[1].price - ((i + 1) * 0.25), nullptr);
        vRecord[i] = Item("", {9, 19 + (i + 1), 2026}, catalogue[2].price - ((i + 1) * 0.25), nullptr);
    }

    // Copies record arrays into catalogue array
    catalogue[0].priceRecord = pRecord;
    catalogue[1].priceRecord = sRecord;
    catalogue[2].priceRecord = vRecord;

    // Should print Item first, then all record contents for the entire catalogue array
    for(int i = 0; i < CatalogueSize; i++)
    {
        catalogue[i].printItemData();
        catalogue[i].printRecordData(ItemRSize);
    }

    // Free Memory
    delete [] catalogue;
    delete [] pRecord;
    delete [] sRecord;
    delete [] vRecord;

    return 0;
}

void formatOutput(Item* catalogue, int catalogueSize)
{
    int spaceSize = 5;
    for(int i = 0; i < catalogueSize; i++)
    {
        cout << setw(spaceSize) << "Item: " << catalogue[i].name << setw(spaceSize) << "Date: ";
        catalogue[i].date.printDate();
        cout << setw(spaceSize) << "Price: " << catalogue[i].price;
    }
}