
#include "Car.h"
#include <iostream>
#include <deque>
#include <cstdlib>
#include <ctime>

const int INITSIZE = 2;
const int PROB1 = 0.55;
const int PROB2 = 100 - PROB1 ;

using namespace std;

int randNum(int min, int max);
bool runProb(int prob);

int main()
{
    srand(time(0));

    int t = 0;
    deque<Car> toll = { Car(), Car() };

    bool carExits, carEnters;
    while(toll.size() != 0)
    {
        carExits = runProb(PROB1);
        carEnters = runProb(PROB2);       
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
