
// COMSC-210 | Lab 23 | Jonvianney Maglasang

// Started October 17, 2026 at 6:58 PM
// Finished October 17, 2026 at 

#include <iostream>
#include <random>
#include <fstream>
#include <iomanip>
#include <set>
#include "Goat.h"


using namespace std;

const int SZ_NAMES = 200, SZ_COLORS = 25, MAX_AGE = 20;

int select_goat(set<Goat> trip);
void add_goat(set<Goat> &trip, string names[], string colors[]);
void delete_goat(set<Goat> &trip);
void display_trip(set<Goat> trip);
int get_rand_int(int min, int max);
int main_menu();
void handle_input(int choice, set<Goat> &trip, string names[], string colors[]);

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

    set<Goat> goats;

    int choice = 0;
    while(choice != 4)
    {
        choice = main_menu();
        handle_input(choice, goats, names, colors);
    }

    return 0;
}

int select_goat(set<Goat> trip)
{
    int choice;
    int size = trip.size();
    display_trip(trip);
    if(size != 0)
    {
        cout << "The number on the left is the goat's position, use it to reference the correct goat." << endl;
        cout << "Choice --> ";
        cin >> choice;
        return choice;
    } else
    {
        // Returns 1 instead of -1 for errors because add_goat will subtract by one to automatically add to the head
        return 1;
    }

    // Still return 1 just in case something messes up to insert at the head
    return 1;
}

void add_goat(set<Goat> &trip, string names[], string colors[])
{
    // Make new temp goat with a random name, random age, and random color (- 1 accounts for out of a bounds access)
    Goat temp = Goat(names[get_rand_int(0, SZ_NAMES - 1)], get_rand_int(0, MAX_AGE), colors[get_rand_int(0, SZ_COLORS - 1)]);

    // Iniserts temp in correct position automatically
    trip.insert(temp);
}

void delete_goat(set<Goat> &trip)
{
    if(trip.empty() == false)
    {
        int position = select_goat(trip) - 1;

        // Start at beginning of set, then move to chosen position
        auto it = trip.begin();
        advance(it, position);
        trip.erase(it);
    } else
    {
        cout << "\n*** LIST IS EMPTY! ***" << endl;
    }
}

void display_trip(set<Goat> trip)
{
    if(trip.empty() == false)
    {
        cout << "\n*** LIST OF GOATS ***" << endl;
        int idx = 1;
        for(auto it = trip.begin(); it != trip.end(); it++)
        {
            cout << "[" << idx << "]" << " " << it->get_name() << " (" << it->get_age() << ", " << it->get_color() << ")" << endl;
            idx++;
        }
        cout << endl;
    } else
    {
        cout << "\n*** LIST IS EMPTY! ***" << endl;
    }
}

int get_rand_int(int min, int max)
{
    return rand() % (max - min +1) + min;
}

int main_menu()
{
    // Input Validation (not accounting data types, only int values, doesn't use cin.fail)
    int choice = -1;
    do
    {
        cout << "\n*** GOAT MANAGER 3001 ***" << endl;
        cout << "[1] Add a goat" << endl;
        cout << "[2] Delete a goat" << endl;
        cout << "[3] List goats" << endl;
        cout << "[4] Quit" << endl;
        cout << "Choice --> ";
        cin >> choice;
    } while(choice < 0 || choice > 4);
    return choice;
}

void handle_input(int choice, set<Goat> &trip, string names[], string colors[])
{
    switch(choice)
    {
        case 1:
        {
            add_goat(trip, names, colors);
            break;
        }
        case 2:
        {
            delete_goat(trip);
            break;
        }
        case 3:
        {
            display_trip(trip);
            break;
        }
        default:
        {
            return;
            break;
        }
    }
}