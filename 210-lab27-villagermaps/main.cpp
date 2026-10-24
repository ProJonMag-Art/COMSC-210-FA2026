
// COMSC-210 | Lab 27 | Jonvianney Maglasang

// Started October 23, 2026 at 9:27 PM
// Finished October 23, 2026 at 

#include <iostream>
#include <map>
#include <vector>
#include <tuple>

using namespace std;

void menu(map<string, tuple<int, string, string>> &mapping, int &choice);
void printMap(map<string, tuple<int, string, string>> mapping);
bool searchMap(map<string, tuple<int, string, string>> mapping);
void changeFriendship(map<string, tuple<int, string, string>> &mapping, int incOrDec);

int main() {
    // declarations
    map<string, tuple<int, string, string>> villagerDetails;
    int choice = 0;

    // insert elements into the map
    // note how the right-hand side of the assignment are the vector elements
    villagerDetails["Audie"] = {2, "Dolphin", "Booyah"};
    villagerDetails["Raymond"] = {7, "Shark", "RAAAHHH"};
    villagerDetails.insert({"Marshal", {8, "Sea Mouse", "Mew"}});

    do
    {
        menu(villagerDetails, choice);
        switch(choice)
        {
            case 1:
            {
                changeFriendship(villagerDetails, choice);
            }

            case 2:
            {
                changeFriendship(villagerDetails, choice);
            }

            case 3:
            {
               searchMap(villagerDetails);
            }
        }
    } while (true);
    

    printMap(villagerDetails);

    // delete an element
    villagerDetails.erase("Raymond");

    searchMap(villagerDetails);

    // report size, clear, report size again to confirm map operations
    cout << "\nSize before clear: " << villagerDetails.size() << endl;
    villagerDetails.clear();
    cout << "Size after clear: " << villagerDetails.size() << endl;

    return 0;
}


void menu(map<string, tuple<int, string, string>> &mapping, int &choice)
{
    printMap(mapping);
    do
    {
        cout << "Choice: ";
        cin >> choice;
    } while (choice < 1 || choice > 4);
    
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

bool searchMap(map<string, tuple<int, string, string>> mapping)
{
    cout << "Which villager would you like to search for?: ";
    cin >> searchKey;

    auto it = mapping.find(searchKey);

     // the iterator points to beyond the end of the map
    if (it != mapping.end()) 
    {
        // if searchKey is not found
        cout << "\nFound " << searchKey << "'s Details: ";
        cout << "[" << get<0>(it->second) << ", " << get<1>(it->second) << ", " << get<2>(it->second) << "]";
        cout << endl;
        return true;
    } else
    {
        cout << endl << searchKey << " not found." << endl;
        return false;
    }
}

void changeFriendship(map<string, tuple<int, string, string>> &mapping, int incOrDec)
{
    string choice = "";
    if(incOrDec = 1)
    {
        printMap(mapping);
        cout << "Which villager's friendship level do you want to increase?: ";
        cin >> choice;

        if(searchMap(mapping, choice) == true)
        {
            // If searchKey is found and its friendship level is between 0 and 10
            auto foundKey = mapping.find(choice);
            if(get<0>(foundKey->second) >= 0 && get<0>(foundKey->second) < 10)
            {
                get<0>(foundKey->second) += 1;
            }
        }
    } else if(incOrDec = 2)
    {
        printMap(mapping);
        cout << "Which villager's friendship level do you want to decrease?: ";
        cin >> choice;

        if(searchMap(mapping, choice) == true)
        {
            // If searchKey is found and its friendship level is between 0 and 10
            auto foundKey = mapping.find(choice);
            if(get<0>(foundKey->second) > 0 && get<0>(foundKey->second) <= 10)
            {
                get<0>(foundKey->second) -= 1;
            }
        }
    }
    
    
}