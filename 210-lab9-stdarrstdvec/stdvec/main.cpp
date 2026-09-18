
// COMSC-210 | Lab 7 | Jonvianney Maglasang

// Started September 18, 2026 at 11:45am
// Finished September 17, 2026 at 6:41pm

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

const int arrSize = 30;

// Takes string filename as input to read data into an std::vector through a loop going through its vector size
void readData(string fileName, vector<float>& dataArr, int arrSize);

// Takes float vector as input, loops through its elements. If a negative 1 in the elements means it was uninitialized and the loop stops
// Uses the loop count to get the average of initialized data in the vector.
float getAverage(vector<float> dataArr);

// Takes float vector as input, runs get average, and then outputs data elements in a formatted way. Then outputs the first value, middle value, and end value.
void outputData(vector<float> dataArr);

int main()
{
    vector<float> gradeData;

    readData("data.txt", gradeData, arrSize);
    outputData(gradeData);

    return 0;
}

void readData(string fileName, vector<float>& dataArr, int arrSize)
{
    ifstream readFile(fileName);

    float temp = 0;
    for(int i = 0; i < arrSize; i++)
    {
        readFile >> temp;
        dataArr.push_back(temp);
    }

    readFile.close();
}

float getAverage(vector<float> dataArr)
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

void outputData(vector<float> dataArr)
{
    int arrSize = dataArr.size();

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