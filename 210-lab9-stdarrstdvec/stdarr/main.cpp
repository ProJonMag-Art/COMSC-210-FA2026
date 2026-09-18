
// COMSC-210 | Lab 7 | Jonvianney Maglasang

// Started September 17, 2026 at 5:17pm
// Finished September 17, 2026 at

#include <iostream>
#include <iomanip>
#include <fstream>
#include <array>
#include <string>

using namespace std;

const int arrSize = 30;

// Takes string filename as input to read data into an std::array through a loop going through its array size
void readData(string fileName, array<float, 30>& dataArr);

// Takes loat array as input, loops through its elements. If a negative 1 in the elements means it was uninitialized and the loop stops
// Uses the loop count to get the average of initialized data in the array.
float getAverage(array<float, arrSize> dataArr);


array<float, 3> getDataCheckpoints(array<float, arrSize> dataArr);
void outputData(array<float, arrSize> dataArr);

int main()
{
    array<float, arrSize> gradeData;
    gradeData.fill(-1);

    readData("data.txt", gradeData);

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

array<float, 3> getDataCheckpoints(array<float, arrSize> dataArr)
{
    int arrSize = dataArr.max_size();
    
    return {dataArr.front(), dataArr.at(arrSize/2), dataArr.back()};
}

void outputData(array<float, arrSize> dataArr)
{
    cout << "\nGrade Points:" << endl;
    cout << "------------";
}