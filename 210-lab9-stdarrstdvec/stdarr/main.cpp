
// COMSC-210 | Lab 7 | Jonvianney Maglasang

// Started September 17, 2026 at 5:17pm
// Finished September 17, 2026 at

#include <iostream>
#include <fstream>
#include <array>
#include <string>

using namespace std;

const int arrSize = 30;

// Takes string filename as input to read data into an std::array through a loop going through its array size
void readData(string fileName, array<float, 30>& dataArr);
float getAverage(array<float, 30> dataArr);
array<float, 3> getDataCheckpoints(array<float, 30> dataArr);
void outputData(array<float, 30> dataArr);

int main()
{
    array<float, arrSize> gradeData;
    gradeData.fill(-1);

    readData("data.txt", gradeData);

    return 0;
}

void readData(string fileName, array<float, 30>& dataArr)
{
    ifstream readFile(fileName);
    int readSize = dataArr.size();

    for(int i = 0; i < readSize; i++)
    {
        readFile >> dataArr[i];
    }

    readFile.close();
}

float getAverage(array<float, 30> dataArr)
{
    int arrSize = dataArr.size();
    float sum = 0;

    for(int i = 0; i < arrSize; i++)
    {
        if(dataArr.at(i) != -1)
        {
            sum += dataArr.at(i);
        }
    }
}