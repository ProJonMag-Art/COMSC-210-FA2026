
// COMSC-210 | Lab 23 | Jonvianney Maglasang

// Started October 16, 2026 at 2:11 PM
// Finished October 16, 2026 at 

#include <iostream>
#include <fstream>
#include <iomanip>
#include <list>
#include "Goat.h"
using namespace std;

const int SZ_NAMES = 200, SZ_COLORS = 25, MAX_AGE = 20;

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




    return 0;
}

void add_goat(list<Goat> &trip, string [], string [])
{

}

int main_menu(list<Goat> &trip)
{
    // Input Validation (not accounting data types, only int values)
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

    switch(choice)
    {
        case1:
        {
            break;
        }
        case2:
        {
            break;
        }
        case3:
        {
            break;
        }
        case4:
        {
            break;
        }
    }
}

