
// COMSC-210 | Lab 33 | Jonvianney Maglasang

// Started November 6, 2026 at 10:36 PM
// Finished November 7, 2026 at 

// November 6, 2026 10:51 PM Note: On break, will probably finish tomorrow

#include "Car.h"
#include <iostream>
#include <deque>
#include <cstdlib>
#include <ctime>
#include <array>

const int INITSIZE = 2;
const int PROB1 = 46;
const int PROB2 = 39;
const int PROB3 = 100 - (PROB1 + PROB2);
const int TOLLCNT = 4;
const int SIMDURATION = 20;

using namespace std;

int randNum(int min, int max);
bool runProb(int prob);
void printDeque(deque<Car> deq);
void initEmptyDeque(deque<Car> &deq, int size);

int main()
{
    srand(time(0));
    deque<Car> toll;
    array<deque<Car>, TOLLCNT> plaza;

    // Adds Car() values to deque, takes constant size as paramter to allow for different sizings if need be
    initEmptyDeque(toll, INITSIZE);

    // Prints initial queue
    cout << "Initial Queue:" << endl;
    //printDeque(toll);

    for(int i = 0; i < plaza.size(); i++)
    {
        initEmptyDeque(plaza[i], INITSIZE);
        cout << "Lane: " << (i + 1) << endl;
        printDeque(plaza[i]);
    }

    bool carExits;
    int t = 0;
    
    /*
    while(t != SIMDURATION)
    {
        // Run probability, true if rolled number is less than probability, false if greater
        carExits = runProb(PROB1);
        t++;

        if(carExits == true)
        {
            cout << "Time: " << t << " Operation: Car Paid: ";
            toll.front().print();
            toll.pop_front();
        } else
        {
            cout << "Time: " << t << " Operation: Joined Lane: ";
            toll.push_back(Car());
            toll.back().print();
        }

        // Print queue
        cout << "Queue:" << endl;
        printDeque(toll);
    }
    */
    return 0;
}

int randNum(int min, int max)
{
    int num = (rand() % (max - min + 1)) + min;
    
    return num;
}

// Returns true if random number is less than probability, false if greater, and recursively reruns if it equals the probability
bool runProb(int probability)
{
    int rolledNum = randNum(0, 100);

    if(rolledNum < probability)
    {
        return true;
    } else if(rolledNum > probability)
    {
        return false;
    } else
    {
        return runProb(probability);
    }
}

void printDeque(deque<Car> deq)
{
    if(deq.size() != 0)
    {
        for(auto it = deq.begin(); it != deq.end(); ++it)
        {
            cout << "   ";
            it->print();
        }
    } else
    {
        cout << "   Empty" << endl;
    }
    cout << endl;
}

void initEmptyDeque(deque<Car> &deq, int size)
{
    for(int i = 0; i < size; i++)
    {
        deq.push_back(Car());
    }
}