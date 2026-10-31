
// COMSC-210 | Lab 29 | Jonvianney Maglasang

// Started October 30, 2026 at 7:43 PM
// Finished October 30, 2026 at 8:30 PM

// Include headers and namespace

// Define cartesian vector structs
// Contains two doouble members representing the x and y component of the vector

// Define polar vector structs
// Contains two double members representing the magnitude and angle of the vector (angle north of the west direction, moving ccw)

// Define function that updates vector values based on key force values, takes either vec type as input (possibly overloaded definition)
// Define function that reads data from file

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