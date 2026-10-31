
// COMSC-210 | Lab 29 | Jonvianney Maglasang

// Started October 30, 2026 at 7:43 PM
// Finished October 30, 2026 at 

/*

#include <list>
#include <map>
#include <iostream>
#include <fstream>

using namespace std;

// Define vector structs
struct Cart2DVec()
{
    double x;
    double y;
};

struct Polar2DVec()
{
    double magnitude;
    double angle;
};

// Define function that updates vector values based on key force values, takes either vec type as input (possibly overloaded definition)
void updateVecs(vectorType &);

// Define function that reads data from file
void readData(string filename, map<Polar2DVec *, list<Polar2DVec>[3]);

// Define main Function
int main()
{
    // Initializes a map that stores every force, displacement, velocity, and acceleration vector as a polar vector
    // Key is pointer to force values, and value is each displacement, velocity, and acceleration in each time step
    map<Polar2DVec *netForce, list<Polar2DVec>[3] bodyState>;

    // Begin a time-based simulation for physics changes
        // For 20 time intervals
            // Iterate through each net force key in the map
                // For each force, simulate changes
                    // Randomly decide if the force's magnitude or angle will change
                        // If force changes
                            // For each list in the array
                                // Update vector values using kinematic equations with the update force values
                        // If not changing
                            // For each list in the array
                                // Update vector values using kinematic equations with the same force values
                    // Print the changes for this interval, e.g., "Changed force magnitude by {amount} and angle to {amount} leading to following changes in pos, vel, and acc {amount, amount, amount}"

            // Simulate more complex net forces, maybe using the sum of multiple forces instead of just one forces as the key
            // Random forces impacting the object
}

// Open an external file to read initial data about climate zones and populate the map
void readData(string filename, map<Polar2DVec *, list<Polar2DVec>[3])
{
    // If file does not open, print an error and exit

    // Read data from file and populate map
        // For each line, extract climate zone and species data
        // Insert species into the appropriate list in the array for their climate zone

    // Close the file
}

*/