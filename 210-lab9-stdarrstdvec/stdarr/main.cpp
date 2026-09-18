
// COMSC-210 | Lab 7 | Jonvianney Maglasang

// Started September 17, 2026 at 5:17pm
// Finished September 17, 2026 at 6:41pm

#include <iostream>
#include <iomanip>
#include <fstream>
#include <array>
#include <string>

using namespace std;

const int arrSize = 30;

// Takes string filename as input to read data into an std::array through a loop going through its array size
void readData(string fileName, array<float, 30>& dataArr);

// Takes float array as input, loops through its elements. If a negative 1 in the elements means it was uninitialized and the loop stops
// Uses the loop count to get the average of initialized data in the array.
float getAverage(array<float, arrSize> dataArr);

// Takes float array as input, runs get average, and then outputs data elements in a formatted way. Then outputs the first value, middle value, and end value.
void outputData(array<float, arrSize> dataArr);

int main()
{
    array<float, arrSize> gradeData;
    gradeData.fill(-1);

    readData("data.txt", gradeData);
    outputData(gradeData);

    return 0;
}

void readData(string fileName, array<float, arrSize>& dataArr)
{
    ifstream readFile(fileName);
    int readSize = dataArr.size();

    for(int i = 0; i < readSize; i++)
    {
        readFile >> dataArr[i];
    }

    readFile.close();
}

float getAverage(array<float, arrSize> dataArr)
{
    int arrSize = dataArr.size();
    int loopCount = 0;
    float sum = 0;

    for(int i = 0; i < arrSize; i++)
    {
        // If a data element is -1, it is considered uninitialized and ends the loop
        if(dataArr.at(i) != -1)
        {
            sum += dataArr.at(i);
            loopCount = i + 1;
        } else
        {
            break;
        }
    }

    return sum/loopCount;
}

void outputData(array<float, arrSize> dataArr)
{
    int arrSize = dataArr.max_size();

    cout << "\nGrade Points:" << endl;
    cout << "------------" << endl;
    for(int i = 0; i < arrSize; i++)
    {
        cout << setw(6) << dataArr.at(i) << endl;
    }

    cout << "\nAverage (GPA): " << getAverage(dataArr) << endl;
    cout << "Data First Value: " << dataArr.front() << endl;
    cout << "Data Middle Value: " << dataArr.at(arrSize/2) << endl;
    cout << "Data End Value: " << dataArr.back() << endl;
}