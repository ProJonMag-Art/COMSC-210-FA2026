
// COMSC-210 | Lab 7 | Jonvianney Maglasang

// Started September 11, 2026 at 5:58
// Finished September 11, 2026 at

#include <iostream>
#include <string>

using namespace std;

// Takes string pointer array of arrSize
// Saves a temporary string equal to the current indexed string
// Loops until arrSize/2 and swaps the position of *(arrSize + i) with *(arrSize + i - 1)
// Assigns *(arrSize + i - 1) = tempStr (swaps positions)
// I'm not sure if this works for even sized arrays or not
void reverseArray(string*& strArr, int arrSize);

// Takes string pointer array of arrSize
// Loops up until the size and couts each string in the array
void outputArrayContents(string* strArr, int arrSize);

// Takes string pointer array of arrSize
// Runs outputArrayContents() to cout contents then runs reverseArray()
// After flipping, it runs outputArrayContents() one more time to cout the transformed array
void displayArray(string*& strArr, int arrSize);

const int arrSize = 5;

int main()
{
    // Allocate Dynamic Memory
    string* namesArr = new string[arrSize];

    *(namesArr) = "Janet";
    *(namesArr + 1) = "Jeffe";
    *(namesArr + 2) = "Jin";
    *(namesArr + 3) = "Joe";
    *(namesArr + 4) = "Junio";

    displayArray(namesArr, arrSize);

    // Free Dynamic Memory
    delete [] namesArr;
    return 0;
}

void reverseArray(string*& strArr, int arrSize)
{
    string tempStr = "";
    for(int i = 0; i < arrSize/2; i++)
    {
        // Temp = current str
        tempStr = *(strArr + i);

        // Temp = i indices away from the last array element
        *(strArr + i) = *(strArr + arrSize - i - 1);
        *(strArr + arrSize - i - 1) = tempStr;
    }
}

void outputArrayContents(string* strArr, int arrSize)
{
    for(int i = 0; i < arrSize; i++)
    {
        cout << *(strArr + i) << " ";
    }
    cout << endl;
}

void displayArray(string*& strArr, int arrSize)
{
    cout << "Original Array: ";
    outputArrayContents(strArr, arrSize);

    cout << "Reversed Array: ";
    reverseArray(strArr, arrSize);
    outputArrayContents(strArr, arrSize);
}