
// COMSC-210 | Lab 20 | Jonvianney Maglasang

// Started October 9, 2026 at 7:59pm
// Finished October 9, 2026 at 

#include <iostream>
#include <iomanip>
#include <ctime>
#include <random>

using namespace std;

// Constant Declaraion
const int SIZE = 3;
const int MIN = 10000;
const int MAX = 99999;

// Function Declaration
double getRandNum(int min, int max);

class Chair 
{
    private:
        int legs;
        double * prices;
    public:

// constructors
        Chair() 
        {
            prices = new double[SIZE];

            // 50/50 to decide between 3 and 4 legs
            if(getRandNum(0, 100) < 50)
            {
                legs = 3;
            } else
            {
                legs = 4;
            }

            for (int i = 0; i < SIZE; i++)
            {
                prices[i] = getRandNum(MIN, MAX);
            }
        }

        Chair(int l, double inputPrices[SIZE]) 
        {
            prices = new double[SIZE];
            legs = l;
            for (int i = 0; i < SIZE; i++)
            {
                prices[i] = inputPrices[i];
            }
        }

        // setters and getters
        void setLegs(int l) { legs = l; }
        int getLegs() { return legs; }

        void setPrices(double p1, double p2, double p3) 
        {
            prices[0] = p1; prices[1] = p2; prices[2] = p3;
        }

        double getAveragePrices() 
        {
            double sum = 0;
            for (int i = 0; i < SIZE; i++)
            {
                sum += prices[i];
            }
            return sum / SIZE;
        }

        void print() 
        {
            cout << "CHAIR DATA - legs: " << legs << endl;
            cout << "Price history: " ;

            for (int i = 0; i < SIZE; i++)
            {
                cout << prices[i] << " ";
            }

            cout << endl << "Historical avg price: " << getAveragePrices();
            cout << endl << endl;
    }
};

int main() {
    cout << fixed << setprecision(2);
    
    //creating pointer to first chair object
    Chair *chairPtr = new Chair;
    chairPtr->setLegs(4);
    chairPtr->setPrices(121.21, 232.32, 414.14);
    chairPtr->print();

    //creating dynamic chair object with constructor
    double prices[SIZE] = {525.25, 434.34, 252.52};
    Chair *livingChair = new Chair(3, prices);
    livingChair->setPrices(525.25, 434.34, 252.52);
    livingChair->print();
    delete livingChair;
    livingChair = nullptr;

    //creating dynamic array of chair objects
    Chair *collection = new Chair[SIZE];

    for (int i = 0; i < SIZE; i++)
    {
        collection[i] = Chair();
        collection[i].print();
    }

    return 0;
}

// Function Definition
double getRandNum(int min, int max)
{
    double num = rand() % ((max - min + 1) + min) / (double) 100;
    
    return num;
}