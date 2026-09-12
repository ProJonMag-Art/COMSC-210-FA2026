
#include <iostream>
#include <string>

using namespace std;

void reverseArray(string*& strArr, int arrSize);
void outputArray(string* strArr, int arrSize);
void displayArray(string* strArr, int arrSize);

const int arrSize = 5;

int main()
{

    return 0;
}

void reverseArray(string*& strArr, int arrSize)
{

}

void outputArray(string* strArr, int arrSize)
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
    outputArray(strArr, arrSize);

    cout << "Reversed Array: ";
    reverseArray(strArr, arrSize);
    outputArray(strArr, arrSize);
}