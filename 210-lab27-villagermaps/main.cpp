
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
    auto it = villagerDetails.find(searchKey);
    if (it != villagerDetails.end()) 
    {  // the iterator points to beyond the end of the map
                                       // if searchKey is not found
        cout << "\nFound " << searchKey << "'s Details: ";
        cout << "[" << get<0>(it->second) << ", " << get<1>(it->second) << ", " << get<2>(it->second) << "]";
        cout << endl;
    } else
    {
        cout << endl << searchKey << " not found." << endl;
    }

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