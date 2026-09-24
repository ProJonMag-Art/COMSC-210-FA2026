
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

    Student()
    {
        this->id = 0;
        this->score = 0;
    }
};

// Function Declarations
// readData() takes the filename creates the readFile object, makes a temp Student and populates it with the data from each line, then pushes it into the vector<Student> dataArr
void readData(string filename, vector<Student>& dataArr);

// writeData creates the writeFile object using filename string and loops through dataArr.size() and writes it on each line
void writeData(string filename, vector<Student> dataArr);

// selectionSort works like any other implementation of selection sort, finding the lowest element to the right of the already sorted parts, and puts it in the i position in the array
void selectionSort(vector<Student>& dataArr);


Student* findMinAndMax(vector<Student> dataArr);
float findMean(vector<Student> dataArr);
Student findMedian(vector<Student> dataArr);
float findSD(vector<Student> dataArr);
void outputData(vector<Student> dataArr);

int main()
{
    string filename = "data/210-lab-13-grades.txt";
    vector<Student> dataArr; 

    
    readData(filename, dataArr);

    return 0;
}

void readData(string filename, vector<Student>& dataArr)
{
    ifstream readFile(filename);
    Student tempStu;

    int i = 0;

    // Save file contents into an array through a loop
    while(readFile >> tempStu.id >> tempStu.score)
    {
        dataArr.push_back(tempStu);
        i++;
    }

    readFile.close();
}

void writeData(string filename, vector<Student> dataArr)
{
    ofstream writeFile(filename);

    // Save contents of array into the file using loops
    for(int i = 0; i < dataArr.size(); i++)
    {
        writeFile << dataArr[i].id << dataArr[i].score << endl;
    }

    writeFile.close();
}

void selectionSort(vector<Student>& dataArr)
{
    int size = dataArr.size();
    int idxOfLowest = 0;
    Student tempStu = Student();

    // Do the following for every element in the array
    for(int i = 0; i < size - 1; i++)
    {
        // Do the following for remaining elements in the array (right side)
        for(int j = i + 1; j < size; j++)
        {
            // If we found a new lowest id in the array
            if(dataArr[j].id < dataArr[idxOfLowest].id)
            {
                // Save that index
                idxOfLowest = j;
            }
        }

        // Swap the i element and the lowest element
        tempStu = dataArr[idxOfLowest];
        dataArr[idxOfLowest] = dataArr[i];
        dataArr[i] = dataArr[idxOfLowest];
    }
}

Student* findMinAndMax(vector<Student> dataArr)
{
    int size = dataArr.size();
    Student* minAndMax = new Student[2] {dataArr[0], dataArr[0]};

    for(int i = 0; i < size; i++)
    {
        // Finds 
        if(minAndMax[1].score > dataArr[i].score)
        {
            minAndMax[1] = dataArr[i];
        }

        if(minAndMax[0].score < dataArr[i].score)
        {
            minAndMax[0] = dataArr[i];
        }
    }

    return minAndMax;
}