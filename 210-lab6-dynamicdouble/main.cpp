
// COMSC-210 | Lab 6 | Jonvianney Maglasang

// Started September 11, 2026 at 3:25pm
// Finished September 11, 2026 at 3:37pm

#include <iostream>

using namespace std;

const int arrSize = 5;

// Receives a double pointer, and loops through arrSize to assign values to the array
void enterArrayData(double*& dynArr, int arrSize);

// Receives a double pointer, and couts the content into a single line
void outputArrayData(double* dynArr, int arrSize);

// Receives a double pointer and sums up the array contents
void sumArray(double* dynArr, int arrSize);

int main()
{
    // Dynamically Allocate Memory
    double* dynArr = new double[arrSize];

    enterArrayData(dynArr, arrSize);
    outputArrayData(dynArr, arrSize);
    sumArray(dynArr, arrSize);

    // Free Memory
    delete [] dynArr;
    return 0;
}

void enterArrayData(double*& dynArr, int arrSize)
{
    for(int i = 0; i < arrSize; i++)
    {
        cout << "PLease Enter a double for element " << i + 1 << ": ";
        cin >> *(dynArr + i);
    }

    cout << "\nData entry complete." << endl;
}

void outputArrayData(double* dynArr, int arrSize)
{
    cout << "Array Elements: ";
    for(int i = 0; i < arrSize; i++)
    {
        cout << *(dynArr + i) << " ";
    }
}

void sumArray(double* dynArr, int arrSize)
{
    double sum = 0;
    for(int i = 0; i < arrSize; i++)
    {
        sum += *(dynArr + i);
    }
    cout << "\nSum of values: " << sum << endl;
}