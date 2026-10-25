
// COMSC-210 | Lab 28 | Jonvianney Maglasang

// Started October 24, 2026 at 8:02 PM
// Finished October 24, 2026 at 7:05 PM

#include <iostream>
#include <fstream>
#include <iomanip>
#include <list>
#include <algorithm>
#include <functional>
#include <numeric>
#include "Goat.h"
using namespace std;

const int SZ_NAMES = 200, SZ_COLORS = 25;

int select_goat(list<Goat> trip);
void delete_goat(list<Goat> &trip);
void add_goat(list<Goat> &trip, string [], string []);
void display_trip(list<Goat> trip);
int main_menu();

int main() {
    srand(time(0));
    bool again;

    // read & populate arrays for names and colors
    ifstream fin("names.txt");
    string names[SZ_NAMES];
    int i = 0;
    while (fin >> names[i++]);
    fin.close();
    ifstream fin1("colors.txt");
    string colors[SZ_COLORS];
    i = 0;
    while (fin1 >> colors[i++]);
    fin1.close();

    // create & populate a trip of Goats using std::list of random size 8-15
    int tripSize = rand() % 8 + 8;
    list<Goat> trip;
    int age;
    string name, color;
    for (int i = 0; i < tripSize; i++) {
        age = rand() % MAX_AGE;  // defined in Goat.h
        name = names[rand() % SZ_NAMES];
        color = colors[rand() % SZ_COLORS];
        Goat tmp(name, age, color);
        trip.push_back(tmp);
    }
    
    // Goat Manager 3001 Engine
    int tempNum = 0;
    string tempStr = "";
    int sel = main_menu();
    while (sel != 12) {
        switch (sel) {
            case 1:
                {
                    cout << "Adding a goat.\n";
                    add_goat(trip, names, colors);
                    break;
                }
            case 2:    
                {
                    cout << "Removing a goat.\n";
                    delete_goat(trip);
                    break;
                }
            case 3:   
                {
                    cout << "Displaying goat data.\n";
                    display_trip(trip);
                    break;   
                }
            case 4:
                {
                    // Reverses list
                    cout << "Reversing goat data. \n";
                    reverse(trip.begin(), trip.end());
                    break;
                }
            case 5:
                {
                    // Adds to each goat's age by an inputted amount
                    do
                    {
                        cout << "\nHow many years should we add to each goat's age?: ";
                        cin >> tempNum;
                    } while (tempNum < 0);
                    cout << "\nAdding " << tempNum << " years to each goat's age. \n";
                    for_each(trip.begin(), trip.end(), [&tempNum](Goat &list)
                    { 
                        int currentAge = list.get_age();
                        list.set_age(currentAge + tempNum);
                    });
                    break;
                }

            case 6:
                {
                    cout << "Averaging all goats' ages.\n";

                    // Sums ages then divides by the size of the list
                    int ageSum = accumulate(trip.begin(), trip.end(), 0, [](int sum, const Goat &list){ return sum += list.get_age();});
                    cout << "Average of goats' ages: " << ageSum/trip.size() << endl; 
                }

            case 7:
                {
                    display_trip(trip);
                    cout << "Which goat would you like to replace?: ";
                    cin >> tempNum;

                    // Move to it
                    auto it = trip.begin();
                    advance(it, tempNum - 1);

                    // If a goat matches the goat whos values matches the inputted index, then it will get replaced with a random goat object
                    cout << "Replacing matched goats.\n";
                    replace(trip.begin(), trip.end(), (Goat){it->get_name(), it->get_age(), it->get_color()}, (Goat){names[rand() % SZ_NAMES], rand() % MAX_AGE, colors[rand() % SZ_COLORS]});
                    break;
                }

            case 8:
                {
                    cout << "Which goat would you like to look for?: ";
                    cin >> tempStr;

                    // If there is a goat's name who matches the inputted tempStr, list its index, otherwise they do not match the inputted name
                    cout << "Replacing matched goats.\n";
                    auto foundGoat = find_if(trip.begin(), trip.end(), [&tempStr](Goat &list){return list.get_name() == tempStr;});
                    if(foundGoat != trip.end())
                    {
                        int idx = 0;
                        for(auto it = trip.begin(); it != foundGoat; it++)
                        {
                            idx++;
                        }

                        cout << endl << tempStr << "Is the: " << idx + 1 << "th goat in the list" << endl;
                    } else
                    {
                        cout << endl << tempStr << " Was not found in the list." << endl;
                    }
                }

            case 9:
                {
                    cout << "Which age should goats be older than to be counted?: ";
                    cin >> tempNum;

                    // Increase a counter whenver an item in the list is greater than the inputted number
                    cout << "Counting goats.\n";
                    int numOfGoats = count_if(trip.begin(), trip.end(), [&tempNum](Goat &list){return list.get_age() >= tempNum;});
                    cout << "There are: " << numOfGoats << " goats older than: " << tempNum  << endl;
                }

            case 10:
                {
                    int max = 0;
                    do
                    {
                        cout << "What is the min of the range?: ";
                        cin >> tempNum;
                    } while (tempNum < 0);

                    do
                    {
                        cout << "What is the max of the range?: ";
                        cin >> max;
                    } while (max < 0);
                    
                    // Add to counter, and if that counter aka the index is in the listed range, delete the associated item
                    cout << "Deleting range.\n";
                    int counter = -1;
                    erase_if(trip, [&counter, tempNum, max](Goat &list)
                    {
                        counter++;
                        return counter > tempNum && counter < max;
                    });
                }

            case 11:
                {
                    cout << "Clearing list.\n";
                    trip.clear();
                }

            default:
                {
                    cout << "Invalid selection.\n";
                    break;
                }
        }
        sel = main_menu();
    }
    

    return 0;
}

int main_menu() {
    cout << "*** GOAT MANAGER 3001 ***\n";
    cout << "[1] Add a goat\n";
    cout << "[2] Delete a goat\n";
    cout << "[3] List goats\n";
    cout << "[4] Reverse goats' order\n";
    cout << "[5] Add to all goats' ages\n";
    cout << "[6] Average all goats' ages\n";
    cout << "[7] Replace goat\n";
    cout << "[8] Find goat\n";
    cout << "[9] Count goats older than a certain age\n";
    cout << "[10] Remove range\n";
    cout << "[11] Clear list\n";
    cout << "[12] Quit\n";
    cout << "Choice --> ";
    int choice;
    cin >> choice;
    while (choice < 1 || choice > 12) {
        cout << "Invalid, again --> ";
        cin >> choice;
    }
    return choice;
}

void delete_goat(list<Goat> &trip) {
    cout << "DELETE A GOAT\n";
    int index = select_goat(trip);
    auto it = trip.begin();
    advance(it, index-1);
    trip.erase(it);
    cout << "Goat deleted. New trip size: " << trip.size() << endl;
}

void add_goat(list<Goat> &trip, string nms[], string cls[]) {
    cout << "ADD A GOAT\n";
    int age = rand() % MAX_AGE;
    string nm = nms[rand() % SZ_NAMES];
    string cl = cls[rand() % SZ_COLORS];
    Goat tmp(nm, age, cl);
    trip.push_back(tmp);
    cout << "Goat added. New trip size: " << trip.size() << endl;
}

void display_trip(list<Goat> trp) {
    int i = 1;
    for (auto gt: trp)
        cout << "\t" 
             << "[" << i++ << "] "
             << gt.get_name() 
             << " (" << gt.get_age() 
             << ", " << gt.get_color() << ")\n";
}

int select_goat(list<Goat> trp) {
    int input;
    cout << "Make a selection:\n";
    display_trip(trp);
    cout << "Choice --> ";
    cin >> input;
    while (input < 1 or input > trp.size()) {
        cout << "Invalid choice, again --> ";
        cin >> input;
    }
    return input;
}