
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
        cout << "Relationship Level: " << get<0>(pair.second) << ", Species: " << get<1>(pair.second) << ", Catchphrase: " << get<2>(pair.second);
        cout << endl;
    }

    // access the map using iterators
    cout << "\nVillagers and their favorite colors (iterators):" << endl;
    for (map<string, tuple<int, string, string>>::iterator it = villagerColors.begin(); it != villagerColors.end(); ++it) {
        cout << it->first << ": ";
        cout << "Relationship Level: " << get<0>(it->second) << ", Species: " << get<1>(it->second) << ", Catchphrase: " << get<2>(it->second);
        cout << endl;
    }

    // delete an element
    villagerColors.erase("Raymond");

    // search for an element using .find() to avoid errors
    string searchKey = "Audie";
    auto it = villagerColors.find(searchKey);
    if (it != villagerColors.end()) {  // the iterator points to beyond the end of the map
                                       // if searchKey is not found
        cout << "\nFound " << searchKey << "'s Details: ";
        cout << "Relationship Level: " << get<0>(it->second) << ", Species: " << get<1>(it->second) << ", Catchphrase: " << get<2>(it->second);
        cout << endl;
    } else
        cout << endl << searchKey << " not found." << endl;

    // report size, clear, report size again to confirm map operations
    cout << "\nSize before clear: " << villagerColors.size() << endl;
    villagerColors.clear();
    cout << "Size after clear: " << villagerColors.size() << endl;

    return 0;
}
