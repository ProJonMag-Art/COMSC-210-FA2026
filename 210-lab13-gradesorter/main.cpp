
// COMSC-210 | Lab 11 | Jonvianney Maglasang

// Started September 20, 2026 at 11:54am
// Finished September 20, 2026 at 2:19pm

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

struct Student
{
    int id;
    float score;
    Student(int idInput, float scoreInput)
    {
        this->id = idInput;
        this->score = scoreInput;
    }
};

void readData(string filename, vector<Student>& dataArr);
void writeData(string filename, vector<Student>& dataArr);
Student findMin(vector<Student> dataArr);
Student findMax(vector<Student> dataArr);
float findMean(vector<Student> dataArr);
Student findMedian(vector<Student> dataArr);
float findSD(vector<Student> dataArr);
void outputData(vector<Student> dataArr);

int main()
{
    string filename = "210-lab-13-grades.txt";
    vector<Student> dataArr; 


    return 0;
}

void readData(string filename, vector<Student>& dataArr)
{
    ifstream readFile(filename);

    int i = 0;
    while(readFile >> dataArr[i].id)
    {
        i++;
        
        readFile >> dataArr[i].score;
        i++;
    }

    readFile.close();
}