
// COMSC-210 | Lab 27 | Jonvianney Maglasang

// Started October 23, 2026 at 9:27 PM
// Finished October 23, 2026 at 

#include <iostream>
#include <map>
#include <vector>
#include <tuple>

using namespace std;

int main() {
    // declarations
    map<string, tuple<int, string, string>> villagerColors;

    // insert elements into the map
    // note how the right-hand side of the assignment are the vector elements
    villagerColors["Audie"] = {2, "Dolphin", "Booyah"};
    villagerColors["Raymond"] = {7, "Shark", "RAAAHHH"};
    villagerColors.insert({"Marshal", {8, "Sea Mouse", "Mew"}});

    // access the map using a range-based for loop
    cout << "Villagers, their friendship level, their species, and their catchphrase (range-based for loop):" << endl;
    for (auto pair : villagerColors) {
        cout << pair.first << ": ";
        cout << get<0>(pair.second) << " " << get<1>(pair.second) << " " << get<2>(pair.second);
        cout << endl;
    }

    // access the map using iterators
    cout << "\nVillagers and their favorite colors (iterators):" << endl;
    for (map<string, vector<string>>::iterator it = villagerColors.begin(); 
                                               it != villagerColors.end(); ++it) {
        cout << it->first << ": ";
        for (auto color : it->second) {
            cout << color << " ";
        }
        cout << endl;
    }

    // delete an element
    villagerColors.erase("Raymond");

    // search for an element using .find() to avoid errors
    string searchKey = "Audie";
    auto it = villagerColors.find(searchKey);
    if (it != villagerColors.end()) {  // the iterator points to beyond the end of the map
                                       // if searchKey is not found
        cout << "\nFound " << searchKey << "'s favorite colors: ";
        for (auto color : it->second)  // range loop to traverse the value/vector
            cout << color << " ";
        cout << endl;
    } else
        cout << endl << searchKey << " not found." << endl;

    // report size, clear, report size again to confirm map operations
    cout << "\nSize before clear: " << villagerColors.size() << endl;
    villagerColors.clear();
    cout << "Size after clear: " << villagerColors.size() << endl;

    return 0;
}
