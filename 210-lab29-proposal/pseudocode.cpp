
// COMSC-210 | Lab 29 | Jonvianney Maglasang

// Started October 31, 2026 at 1:11 AM
// Finished October 31, 2026 at 

// Include headers and namespace
#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <map>
#include <array>
#include <ctime>
#include <cstdlib>
#include <cmath>

using namespace std;

// Constants for better time understanding the code
const int POS = 0;
const int VEL = 1;
const int ACCEL = 2;

// Define cartesian vector structs
// Contains two doouble members representing the x and y component of the vector
struct Cart2DVec
{
    double xComp;
    double yComp;
    Cart2DVec(double inputX = 0, double inputY = 0)
    {
        this->xComp = inputX;
        this->yComp = inputY;
    }

    void updateVals(Cart2DVec inputVec)
    {
        this->xComp += inputVec.xComp;
        this->yComp += inputVec.yComp;
    }
};

// Define polar vector structs
// Contains two double members representing the magnitude and angle of the vector (angle north of the west direction, moving ccw)
struct Polar2DVec
{
    double mag;
    double angle;
    Polar2DVec(double inputM = 0, double inputA = 0)
    {
        this->mag = inputM;
        this->angle = inputA;
    }

    void updateVals(Polar2DVec inputVec)
    {
        this->mag += inputVec.mag;
        this->angle += inputVec.angle;
    }

    double getRadAngle()
    {
        return angle * M_PI / 180;
    }
};

// Define function that updates vector values based on key force values, takes either vec type as input (possibly overloaded definition)
// Define function that reads data from file

void readData(string filename, map<Polar2DVec *, array<list<Cart2DVec>, 3>> &simObjs);
double randNum(int min, int max);
void changeForce(Polar2DVec *pVec, int chance, Polar2DVec maxForce);

int main()
{
    double mass = 1;

    // Seed randomness
    srand(time(0));
    string filename = "data.txt";
    int t = 25;

    Polar2DVec *testVec = new Polar2DVec(100, 30);
    changeForce(testVec, 50, {200, 360});

    map<Polar2DVec *, array<list<Cart2DVec>, 3>> forceSim;
    //readData(filename, forceSim);
    // Loop for entire time duration
    double tempX = 0;
    double tempY = 0;
    for(int i = 0; i < t; i++)
    {
        // For every map value
        for(auto it = forceSim.begin(); it != forceSim.end(); it++)
        {
            // Print current time step data
            //cout << "Time step " << i << ": "
            // Change force
            changeForce(it->first, 50, static_cast<int>(randNum(0, 500)));
            // Update bodystate
            
            // it->first->mag refers to the magnitude of the key force, it->first->getRadAngle() refers to the angle of the key force converted from degrees to radians
            // dividing by mass satisfies the F=ma relationship, since we only want a, we divide m on both sides
            tempX = it->first->mag * cos(it->first->getRadAngle()) / mass;
            tempX = it->first->mag * sin(it->first->getRadAngle()) / mass;
            
            it->second[2].push_back(Cart2DVec(tempX, tempY));
            
            
        }
    }

    delete testVec;

    return 0;
}

void readData(string filename, map<Polar2DVec *, array<list<Cart2DVec>, 3>> &simObjs)
{
    ifstream readFile(filename);
    Cart2DVec tempVec = Cart2DVec();
    array<list<Cart2DVec>, 3> tempList;
    double tempVal1, tempVal2;

    // While there are still lines to read from the read file
    while(readFile >> tempVal1 >> tempVal2)
    {
        // Allocate new memory to a key which is a Polar2DVec ptr
        Polar2DVec *tempPol = new Polar2DVec(tempVal1, tempVal2);
        for(int i = 0; i < 3; i++)
        {
            // Read the next 6 doubles and save them to a temp Cart2DVec object that is pushed into the list array object
            readFile >> tempVec.xComp >> tempVec.yComp;
            tempList[i].push_front(tempVec);
        }
        // Insert a new key value pair using the polar2DVec ptr and the array<list<Cart2DVec>> object
        simObjs.insert( {tempPol, tempList} );
    }

    readFile.close();
}

// Gets random int and turns it into a double
double randNum(int min, int max)
{
    double num = rand() % ((max - min + 1) + min);
    
    return num;
}

void changeForce(Polar2DVec *pVec, int chance, Polar2DVec maxForce)
{
    double diceRoll = randNum(0, 10000)/(double) 100;
    cout << "Rolled number: " << diceRoll << endl;
    cout << "Magnitude: " << pVec->mag << " Angle: " << pVec->angle << endl;

    if(diceRoll <= chance)
    {
        // Statuc casted to int to run randNum(), then turned back to double
        pVec->mag = randNum(0, static_cast<int>(maxForce.mag * 100))/(double) 100;
        pVec->angle = randNum(0, static_cast<int>(maxForce.angle * 100))/(double) 100;
    }

    cout << "New Magnitude: " << pVec->mag << " New Angle: " << pVec->angle << endl;
}
// Define main function
    // Initializes a map that stores every force, displacement, velocity, and acceleration vector as a polar vector
    // Key is pointer to force values, and value is each displacement, velocity, and acceleration in each time step

    // Call readData to save file data into initialized map

    // Begin a time-based simulation for physics changes
        // For 20 time intervals
            // Iterate through each net force key in the map
                // For each force, simulate changes
                    // Randomly decide if the force's magnitude or angle will change
                        // If force changes
                            // For each list in the array
                                // Update vector values using kinematic equations with the update force values, using defined updateVec function
                        // If not changing
                            // For each list in the array
                                // Update vector values using kinematic equations with the same force values, using defined updateVec function
                    // Print the changes for this interval, e.g., "Changed force magnitude by {amount} and angle to {amount} leading to following changes in pos, vel, and acc {amount, amount, amount}"

            // Simulate more complex net force chagnes, maybe using the sum of multiple forces instead of just one forces as the key
            // Random forces impacting the object
// End of main function

// Define updateVec function
    // Update key vector values by input paramters
    // Update value vector values based on current key vector values
// End updateVec function

// Open an external file to read initial data about climate zones and populate the map
// Define readData function
    // If file does not open, print an error and exit

    // Read data from file and populate map
        // For each line, extract climate zone and species data
        // Insert species into the appropriate list in the array for their climate zone

    // Close the file
// End of readData function