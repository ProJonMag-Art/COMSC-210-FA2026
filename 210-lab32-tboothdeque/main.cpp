
#include "Car.h"
#include <iostream>
#include <deque>
#include <cstdlib>
#include <ctime>

const int INITSIZE = 2;
const double PROB1 = 0.55;
const double PROB2 = PROB1 - 1;

using namespace std;

int randNum(int min, int max);

int main()
{
    srand(time(0));

    int t = 0;
    deque<Car> toll = { Car(), Car() };

    while(toll.size() != 0)
    {

    }

    return 0;
}