
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
void writeData(string fileName, array<float, 30> dataArr);

int main()
{
    array<float, arrSize> gradeData;
    gradeData.fill(0);

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

void readData(string fileName, array<float, 30>& dataArr)
{
    ofstream writeFile(fileName);
    int readSize = dataArr.size();

    for(int i = 0; i < readSize; i++)
    {
        writeFile << dataArr[i];
    }

    writeFile.close();
}