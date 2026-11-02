
// COMSC-210 | Lab 29 | Jonvianney Maglasang

// Started October 31, 2026 at 1:11 AM
// Finished October 31, 2026 at 

// Include headers and namespace
#include <iostream>
#include <iomanip>
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
const int FORCE = 3;
const int VALSIZE = 4;

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

    Polar2DVec convertToPolar()
    {
        double mag = sqrt(this->xComp * this->xComp + this->yComp * this->yComp);
        double angle = atan(this->yComp/this->xComp) * 180/M_PI;

        return Polar2DVec(mag, angle);
    }
};

// Define function that updates vector values based on key force values, takes either vec type as input (possibly overloaded definition)
// Define function that reads data from file

int readData(string filename, map<Polar2DVec *, array<list<Cart2DVec>, VALSIZE>> &simObjs);
double randNum(int min, int max);
void changeForce(Polar2DVec *pVec, int chance, Polar2DVec maxForce);
void printData(auto it, int interval, double timeStep);
void runSimulation(map<Polar2DVec *, array<list<Cart2DVec>, VALSIZE>> &simObjs, int interval, int stepSize, int mass);

int main()
{
    double mass = 1;
    double dt = 1;

    // Seed randomness
    srand(time(0));
    string filename = "data.txt";
    int t = 25;

    map<Polar2DVec *, array<list<Cart2DVec>, VALSIZE>> forceSim;
    int mapSize = readData(filename, forceSim);
    runSimulation(forceSim, t, dt, mass);

    int choice1, choice2 = 0;
    do
    {
        cout << "\nOptions:" << endl << "   1. Print Data" << endl << "   2. Exit" << endl;
        cout << "Choice: ";
        cin >> choice1;

        switch(choice1)
        {
            case 1:
            {
                do
                {
                    cout << "This program had: " << mapSize << " simulations. Which simulation's data would you like to see? (1-" << mapSize << "): " << endl;
                    cout << "Choice: ";
                    cin >> choice2; 

                    int idx = 0;

                    // Walk through map
                    for(auto it = forceSim.begin(); it != forceSim.end(); it++)
                    {
                        // If current key value pair is the same idx as the user's choice
                        if(idx == choice2)
                        {
                            // Print data
                            printData(it, t, dt);
                        }
                        idx++;
                    }
                } while(choice2 < 1 || choice2 > mapSize);

                break;
            }

            case 2:
            {
                break;
            }

        }
    } while (choice1 != 2);

    // Free memory
    for(auto it = forceSim.begin(); it != forceSim.end(); it++)
    {
        delete it->first;
    }

    return 0;
}

int readData(string filename, map<Polar2DVec *, array<list<Cart2DVec>, VALSIZE>> &simObjs)
{
    ifstream readFile(filename);
    Cart2DVec tempVec = Cart2DVec();
    double tempVal1, tempVal2;
    int mapSize = 0;

    // While there are still lines to read from the read file
    while(readFile >> tempVal1 >> tempVal2)
    {
        array<list<Cart2DVec>, VALSIZE> tempList;

        // Allocate new memory to a key which is a Polar2DVec ptr
        Polar2DVec *tempPol = new Polar2DVec(tempVal1, tempVal2);
        for(int i = 0; i < VALSIZE - 1; i++)
        {
            // Read the next 6 doubles and save them to a temp Cart2DVec object that is pushed into the list array object
            readFile >> tempVec.xComp >> tempVec.yComp;
            tempList[i].push_front(tempVec);
        }
        // Initialize force using conversion from polar to cartesian vector
        double forceX = tempPol->mag * cos(tempPol->getRadAngle());
        double forceY = tempPol->mag * sin(tempPol->getRadAngle());

        tempList[FORCE].push_front({ forceX, forceY });

        // Insert a new key value pair using the polar2DVec ptr and the array<list<Cart2DVec>> object
        simObjs.insert( {tempPol, tempList} );
        mapSize++;
    }

    readFile.close();
    return mapSize;
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

    if(diceRoll <= chance)
    {
        // Static casted to int to run randNum(), then turned back to double by dividing by 100 to generate decimals up to the hundreth's place
        pVec->mag = randNum(0, static_cast<int>(maxForce.mag * 100))/(double) 100;
        pVec->angle = randNum(0, static_cast<int>(maxForce.angle * 100))/(double) 100;
    }
}

void printData(auto it, int interval, double timeStep)
{
    auto posIt = it->second[POS].begin();
    auto velIt = it->second[VEL].begin();
    auto accelIt = it->second[ACCEL].begin();
    auto forceIt = it->second[FORCE].begin();

    for(int i = 0; i < interval; i++)
    {
        Polar2DVec polarForce = forceIt->convertToPolar();

        cout << "\nTime [s]: " << setw(20) << "Force [N]:" << setw(40) << "Position [m]: " << setw(40) << "Velocity [m/s]: " << setw(40) << "Acceleration [m/s^2]: " << endl;
        cout << timeStep * i << setw(20) 
        << polarForce.mag << " at " << polarForce.angle << " [DEG] NE" << setw(20) 
        << posIt->xComp << " i, " << posIt->yComp << " j" << setw(25) 
        << velIt->xComp << " i, " << velIt->yComp << " j" << setw(25) 
        << accelIt->xComp << " i, " << accelIt->yComp << " j" << endl;

        posIt++;
        velIt++;
        accelIt++;
        forceIt++;
    }
    /* Logic for printing when the simulation is running
    cout << "\nTime step: " << timeStep * interval << endl;
    cout << "Force: " << it->first->mag << " [N] at an angle: " << it->first->angle << " [DEG] North of East" << endl;
    cout << "Position: " << it->second[POS].back().xComp << " i, " << it->second[POS].back().yComp << " j [m]" << endl;
    cout << "Veclocity: " << it->second[VEL].back().xComp << " i, " << it->second[VEL].back().yComp << " j [m/s]" << endl;
    cout << "Acceleration: " << it->second[ACCEL].back().xComp << " i, " << it->second[ACCEL].back().yComp << " j [m/s^2]" << endl; 
    */
}

void runSimulation(map<Polar2DVec *, array<list<Cart2DVec>, VALSIZE>> &simObjs, int interval, int stepSize, int mass)
{
    // Loop for entire time duration
    double tempX = 0;
    double tempY = 0;
    for(int i = 0; i < interval; i++)
    {
        // For every map value
        for(auto it = simObjs.begin(); it != simObjs.end(); it++)
        {
            Cart2DVec oldPos = Cart2DVec(it->second[POS].back().xComp, it->second[POS].back().yComp);
            Cart2DVec oldVel = Cart2DVec(it->second[VEL].back().xComp, it->second[VEL].back().yComp);
            Cart2DVec oldAcc = Cart2DVec(it->second[ACCEL].back().xComp, it->second[ACCEL].back().yComp);

            // Saves current force value to fourth value index
            tempX = it->first->mag * cos(it->first->getRadAngle());
            tempY = it->first->mag * sin(it->first->getRadAngle());

            it->second[FORCE].push_back(Cart2DVec(tempX, tempY));

            // Change force
            changeForce(it->first, 50, {randNum(0, 500), randNum(0, 360)} );
            // Update bodystate using kinematic equations
            
            // it->first->mag refers to the magnitude of the key force, it->first->getRadAngle() refers to the angle of the key force converted from degrees to radians
            // dividing by mass satisfies the F=ma relationship, since we only want a, we divide m on both sides
            tempX = it->first->mag * cos(it->first->getRadAngle()) / mass;
            tempY = it->first->mag * sin(it->first->getRadAngle()) / mass;
            
            it->second[ACCEL].push_back(Cart2DVec(tempX, tempY));

            // it->second[VEL].back() refers to the latest velocity vector object
            // The kinematic equation for velocity is vf = vi + a * dt
            tempX = oldVel.xComp + (it->second[ACCEL].back().xComp * stepSize);
            tempY = oldVel.yComp + (it->second[ACCEL].back().yComp * stepSize);

            it->second[VEL].push_back(Cart2DVec(tempX, tempY));

            // it->second[POS].back() refers to the latest position vector object
            // The kinematic equation for velocity is xf = xi + v * dt +  0.5 * a * dt^2
            tempX = oldPos.xComp + (stepSize * oldVel.xComp) + (0.5 * stepSize * stepSize * it->second[ACCEL].back().xComp);
            tempY = oldPos.yComp + (stepSize * oldVel.yComp) + (0.5 * stepSize * stepSize * it->second[ACCEL].back().yComp); 

            it->second[POS].push_back(Cart2DVec(tempX, tempY));

        }
    }
}