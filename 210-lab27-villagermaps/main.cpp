
// COMSC-210 | Lab 27 | Jonvianney Maglasang

// Started October 23, 2026 at 9:27 PM
// Finished October 23, 2026 at 

#include <iostream>
#include <map>
#include <vector>
#include <tuple>

using namespace std;

void menu(map<string, tuple<int, string, string>> mapping);
void printMap(map<string, tuple<int, string, string>> mapping);
auto searchMap(map<string, tuple<int, string, string>> mapping, string searchKey);
void changeFriendship(map<string, tuple<int, string, string>> mapping, int incOrDec);

int main() {
    // declarations
    map<string, tuple<int, string, string>> villagerDetails;

    // insert elements into the map
    // note how the right-hand side of the assignment are the vector elements
    villagerDetails["Audie"] = {2, "Dolphin", "Booyah"};
    villagerDetails["Raymond"] = {7, "Shark", "RAAAHHH"};
    villagerDetails.insert({"Marshal", {8, "Sea Mouse", "Mew"}});

    printMap(villagerDetails);

    // delete an element
    villagerDetails.erase("Raymond");

    // search for an element using .find() to avoid errors
    string searchKey = "Audie";
    searchMap(villagerDetails, searchKey);

    // report size, clear, report size again to confirm map operations
    cout << "\nSize before clear: " << villagerDetails.size() << endl;
    villagerDetails.clear();
    cout << "Size after clear: " << villagerDetails.size() << endl;

    return 0;
}


void menu(map<string, tuple<int, string, string>> &mapping)
{
    int choice = 0;
    printMap(mapping);
    do
    {
        
    } while (choice != 4);
    
}

void printMap(map<string, tuple<int, string, string>> mapping)
{
    // access the map using iterators
    cout << "\nVillager Details:" << endl;
    for (map<string, tuple<int, string, string>>::iterator it = mapping.begin(); it != mapping.end(); ++it) {
        cout << endl << it->first << ": ";
        cout << "[" << get<0>(it->second) << ", " << get<1>(it->second) << ", " << get<2>(it->second) << "]";
        cout << endl;
    }
}

auto searchMap(map<string, tuple<int, string, string>> mapping, string searchKey)
{
    auto it = mapping.find(searchKey);

     // the iterator points to beyond the end of the map
    if (it != mapping.end()) 
    {
        // if searchKey is not found
        cout << "\nFound " << searchKey << "'s Details: ";
        cout << "[" << get<0>(it->second) << ", " << get<1>(it->second) << ", " << get<2>(it->second) << "]";
        cout << endl;
        return it;
    } else
    {
        cout << endl << searchKey << " not found." << endl;
        return it;
    }
}

void changeFriendship(map<string, tuple<int, string, string>> mapping, int incOrDec)
{
    string choice = 0;
    if(incOrDec = 1)
    {
        printMap(mapping);
        cout << "Which villager's friendship level do you want to increase?: ";
        cin >> choice;
    } else if(incOrDec = 2)
    {
        printMap(mapping);
        cout << "Which villager's friendship level do you want to decrease?: ";
        cin >> choice;
    }
    
    
}