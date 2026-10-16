
// COMSC-210 | Lab 23 | Jonvianney Maglasang

// Started October 16, 2026 at 2:11 PM
// Finished October 16, 2026 at 

#include <iostream>
#include <random>
#include <fstream>
#include <iomanip>
#include <list>
#include "Goat.h"

using namespace std;

const int SZ_NAMES = 200, SZ_COLORS = 25, MAX_AGE = 20;

int select_goat(list<Goat> trip);
void add_goat(list<Goat> &trip, string names[], string colors[]);
void delete_goat(list<Goat> &trip);
void display_trip(list<Goat> trip);
int get_rand_int(int min, int max);
int main_menu();
void handle_input(int choice, list<Goat> &trip, string names[], string colors[]);

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

    list<Goat> goats;
    for(int i = 0; i < SZ_NAMES; i++)
    {

    }

    int choice = 0;
    while(choice != 4)
    {
        choice = main_menu();
        handle_input(choice, goats, names, colors);
    }


    return 0;
}

int select_goat(list<Goat> trip)
{
    int choice;
    display_trip(trip);
    cout << "The number on the left is the goat's position, use it to reference the correct goat." << endl;
    cout << "Choice --> ";
    cin >> choice;
    return choice;
}

void add_goat(list<Goat> &trip, string names[], string colors[])
{
    // Make new temp goat with a random name, random age, and random color (- 1 accounts for out of a bounds access)
    Goat temp = Goat(names[get_rand_int(0, SZ_NAMES - 1)], get_rand_int(0, MAX_AGE), colors[get_rand_int(0, SZ_COLORS - 1)]);
    int position = select_goat(trip) - 1;

    // Start at beginning of list, then move to chosen position
    auto it = trip.begin();
    advance(it, position);
    trip.insert(it, temp);
}

void delete_goat(list<Goat> &trip)
{
    int position = select_goat(trip) - 1;

    // Start at beginning of list, then move to chosen position
    auto it = trip.begin();
    advance(it, position);
    trip.erase(it);
}

void display_trip(list<Goat> trip)
{
    cout << "\n*** LIST OF GOATS ***" << endl;
    for(auto it = trip.begin(); it != trip.end(); it++)
    {
        int idx = 1;
        cout << "[" << idx << "]" << " " << it->get_name() << " (" << it->get_age() << ", " << it->get_color() << ")" << endl;
    }
    cout << endl;
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
        cout << "*** GOAT MANAGER 3001 ***" << endl;
        cout << "[1] Add a goat" << endl;
        cout << "[2] Delete a goat" << endl;
        cout << "[3] List goats" << endl;
        cout << "[4] Quit" << endl;
        cout << "Choice --> ";
        cin >> choice;
    } while(choice < 0 || choice > 4);
}

void handle_input(int choice, list<Goat> &trip, string names[], string colors[])
{
    switch(choice)
    {
        case1:
        {
            add_goat(trip, names, colors);
            break;
        }
        case2:
        {
            delete_goat(trip);
            break;
        }
        case3:
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