
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
void runOps(array<deque<Car>, TOLLCNT> &arr, int &opNum, int laneNum);

int main()
{
    srand(time(0));
    array<deque<Car>, TOLLCNT> plaza;

    // Prints initial queue
    cout << "Initial Queue:" << endl;

    for(int i = 0; i < plaza.size(); i++)
    {
        // Adds Car() values to deque, takes constant size as paramter to allow for different sizings if need be
        initEmptyDeque(plaza[i], INITSIZE);
        cout << "Lane: " << (i + 1) << endl;
        printDeque(plaza[i]);
    }

    int operation, t = 0;
    while(t != SIMDURATION)
    {
        t++;
        cout << "Time: " << t << endl;

        // Loop through deque array
        for(int i = 0; i < plaza.size(); i++)
        {
            cout << "Lane: " << (i + 1) << " ";

            // Run probability, returns 1, 2, or 3 for the corresponding PROB param
            operation = runProb(PROB1, PROB2, PROB3);
            runOps(plaza, operation, i);
        }

        // Print queue
        for(int i = 0; i < plaza.size(); i++)
        {
            cout << "Lane " << (i + 1) << " Queue:" << endl;
            printDeque(plaza[i]);
        }
    }
    
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

void runOps(array<deque<Car>, TOLLCNT> &arr, int &opNum, int laneNum)
{
    if(arr[laneNum].size() == 0)
    {
        opNum = randNum(0, 100);
        if(opNum < 50)
        {
            opNum = 2;
        } else
        {
            cout << "Operation: N/A" << endl;
            return;
        }
    }

    if(opNum == 1)
    {
        // Pay operation
        cout << "Operation: Car Paid: ";
        arr[laneNum].front().print();
        arr[laneNum].pop_front();
    } else if(opNum == 2)
    {
        // Join operation
        cout << "Operation: Joined Lane: ";
        arr[laneNum].push_back(Car());
        arr[laneNum].back().print();
    } else
    {
        int newLane = 0;
        
        // Loops the randNum assignment on newLane to ensure the car doesn't switch to the same lane
        do
        {
            newLane = randNum(0, TOLLCNT - 1);
        } while (newLane == laneNum);

        // Switch operation
        cout << "Operation: Switched: ";
        arr[laneNum].back().print();
        arr[newLane].push_back(arr[laneNum].back());
        arr[laneNum].pop_back();
    }
}