
// COMSC-210 | Lab 29 | Jonvianney Maglasang

// Started October 31, 2026 at 1:11 AM
// Finished October 31, 2026 at 

// Include headers and namespace
#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <map>
#include <ctime>
#include <cstdlib>
#include <cmath>

using namespace std;

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
};

// Define function that updates vector values based on key force values, takes either vec type as input (possibly overloaded definition)
// Define function that reads data from file

void readData(string filename, map<Polar2DVec *, list<Cart2DVec>[3]> &);
double randNum(int min, int max);

int main()
{
    srand(time(0));
    string filename = "data.txt";
    int t = 25;

    map<Polar2DVec *, list<Cart2DVec>[3]> forceSim;
    for(int i = 0; i < t; i++)
    {

    }


    return 0;
}

void readData(string filename, map<Polar2DVec *, list<Cart2DVec>[3]> &bodyState)
{
    ifstream readFile(filename);
    Polar2DVec *tempPol = &Polar2DVec();
    Cart2DVec tempCartArr[3];

    for(auto it = bodyState.begin(); it != bodyState.end(); it++)
    {
        readFile >> tempPol->mag >> tempPol->angle;
        for(int i = 0; i < 3; i++)
        {
            readFile >> tempCartArr[i].xComp >> tempCartArr[i].yComp;
        }
        bodyState.insert(tempPol, tempCartArr);
    }

    readFile.close();
}

double randNum(int min, int max)
{
    double num = rand() % ((max - min + 1) + min) / (double) 100;
    
    return num;
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