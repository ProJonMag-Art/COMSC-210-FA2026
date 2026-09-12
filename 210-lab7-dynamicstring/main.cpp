
// COMSC-210 | Lab 7 | Jonvianney Maglasang

// Started September 11, 2026 at 5:58
// Finished September 11, 2026 at

#include <iostream>
#include <string>

using namespace std;

// Takes string pointer array of arrSize and
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
    string* namesArr = new string[arrSize];
    namesArr = { "Janet", "Jeffe", "Jin", "Joe", "Junio" };
    displayArray(namesArr, arrSize);

    return 0;
}

void reverseArray(string*& strArr, int arrSize)
{

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