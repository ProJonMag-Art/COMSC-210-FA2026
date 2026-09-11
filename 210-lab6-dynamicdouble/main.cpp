#include <iostream>

using namespace std;

const int arrSize = 5;

int main()
{
    // Dynamically Allocate Memory
    double* dynArr = new double[arrSize];

    // Free Memory
    delete [] dynArr;
    return 0;
}

void enterArrayData(double*& dynArr, int arrSize)
{
    for(int i = 0; i < arrSize; i++)
    {
        
    }
}

void outputArrayData(double* dynArr)
{

}

void sumArray(double* dynArr)
{

}