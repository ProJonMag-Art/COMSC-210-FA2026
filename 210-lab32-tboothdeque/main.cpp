
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
int runProb(int prob1, int prob2, int prob3);
void printDeque(deque<Car> deq);
void initEmptyDeque(deque<Car> &deq, int size);
void runOperation(deque<Car> &deq, int opNum, int time);

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

    int operation = 0;
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

// Returns which probability the rolledNum lands on
int runProb(int prob1, int prob2, int prob3)
{
    int rolledNum = randNum(0, 100);

    if(rolledNum < prob1)
    {
        // Ex: Between 0 and 46
        return 1;
    } else if(rolledNum > prob1 && rolledNum < 100 - prob3)
    {
        // Ex: Between 46 and 84
        return 2;
    } else if(rolledNum > (prob1 + prob2))
    {
        // Ex: Between 84 and 100
        return 3;
    } else
    {
        // If rolledNum is exactly equal to any probabilities, rerun
        return runProb(prob1, prob2, prob3);
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

void runOperation(deque<Car> &deq, int opNum, int time)
{
    if(opNum == 1)
    {
        // Pay operation
        cout << "Time: " << time << " Operation: Car Paid: ";
        deq.front().print();
        deq.pop_front();
    } else
    {
        // Join operation
        cout << "Time: " << time << " Operation: Joined Lane: ";
        deq.push_back(Car());
        deq.back().print();
    }
}