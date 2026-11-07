
#include "Car.h"
#include <iostream>
#include <deque>
#include <cstdlib>
#include <ctime>

const int INITSIZE = 2;

// Probability for car to pay and leave
const int PROB1 = 55;
const int PROB2 = 100 - PROB1 ;

using namespace std;

int randNum(int min, int max);
bool runProb(int prob);
void printDeque(deque<Car> deq);

int main()
{
    srand(time(0));

    int t = 0;
    deque<Car> toll = { Car(), Car() };

    bool carExits;
    Car frontCar, backCar;

    printDeque(toll);
    while(toll.size() != 0)
    {
        // Save current front and back to temps
        frontCar = toll.front();
        backCar = toll.back();

        // Run probability, true if rolled number is less than probability, false if greater
        carExits = runProb(PROB1);
        t++;

        if(carExits == true)
        {
            cout << "Time: " << t << " Operation: Car Paid: ";
            cout << toll.front().print();
            toll.pop_front();
        } else
    }

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

    for(auto it = deq.begin(); it != deq.end(); ++it)
    {
        it->print();
    }
}
