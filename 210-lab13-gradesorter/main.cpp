
// COMSC-210 | Lab 11 | Jonvianney Maglasang

// Started September 20, 2026 at 6:50pm
// Finished September 20, 2026 at 9:55pm

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <iomanip>
#include <cmath>

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

// findMinMedMex() finds the student element with the lowest score, highest score, and median score. The element after the median element is saved in case the array is even sized
// The median of an even array are two different student values
// Min and Max are found through looped checks
Student* findMinMedMax(vector<Student> dataArr);

// findMeanSD() finds the average by dividing sum, which you get by using a loop, by the size of the array
// Finds sd by using a formula I found online, which is sqrt(((sum((datapoint - mean)^2))/size))
float* findMeanSD(vector<Student>);

// outputData() uses findMeanSD() and infdMinMedMax and outputs all of the summary data. It also deletes the allocated memory from those two functions
void outputData(vector<Student> dataArr);

int main()
{
    string filename = "data/210-lab-13-grades.txt";
    vector<Student> dataArr; 
    Student* minMaxMed;
    float* meanSD;
    
    readData(filename, dataArr);

    selectionSort(dataArr);
    outputData(dataArr);

    writeData("data/210-lab-13-grades-sorted.txt", dataArr);

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
        writeFile << dataArr[i].id << " " << dataArr[i].score << endl;
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

Student* findMinMedMax(vector<Student> dataArr)
{
    int size = dataArr.size();
    
    // [0] = min, [1] = max, [2] = median (odd, only output this for median) [3] = median (when dataset is even, there are two median values, output both values)
    Student* minMaxMed = new Student[4] { dataArr[0], dataArr[0], dataArr[size/2], dataArr[size/2 + 1] };

    for(int i = 0; i < size; i++)
    {
        // Finds min
        if(minMaxMed[1].score > dataArr[i].score)
        {
            minMaxMed[1] = dataArr[i];
        }

        // Finds max
        if(minMaxMed[0].score < dataArr[i].score)
        {
            minMaxMed[0] = dataArr[i];
        }
    }
    
    return minMaxMed;
}

float* findMeanSD(vector<Student> dataArr)
{
    int size = dataArr.size();
    float sumOfDiffs = 0;
    float arrSum = 0;

    // [0] = mean, [1] = sd
    float* meanSD = new float[2] { 0, 0 };

    // Get sum of scores
    for(int i = 0; i < size; i++)
    {
        arrSum += dataArr[i].score;
    }

    // Save mean
    meanSD[0] = arrSum/size;

    // Square the sum of each datapoint - the mean
    for(int j = 0; j < size; j++)
    {
        sumOfDiffs += pow((dataArr[j].score - meanSD[0]), 2);
    }

    // Save the sd which is the previous divided by the size of the array
    meanSD[1] = sqrt((sumOfDiffs/size));

    return meanSD;
}

void outputData(vector<Student> dataArr)
{
    int size = dataArr.size();
    int spaceSize = 10;
    Student* minMaxMed;
    float* meanSD;
    bool evenDataset;

    minMaxMed = findMinMedMax(dataArr);
    meanSD = findMeanSD(dataArr);

    if(size % 2 == 0)
    {
        evenDataset = true;
    } else
    {
        evenDataset = false;
    }

    cout << "\n --- Summary Statistics --- " << endl;
    cout << "Minimum: " << minMaxMed[1].score << " (Student ID: " << minMaxMed[1].id << ")" << endl;
    cout << "Maximum: " << minMaxMed[0].score << " (Student ID: " << minMaxMed[0].id << ")" << endl;
    cout << "Mean: " << meanSD[0] << endl;

    if(evenDataset == true)
    {
        cout << "Median: " << minMaxMed[2].score << " (Student ID: " << minMaxMed[2].id << ") and " << minMaxMed[3].score << " (Student ID: " << minMaxMed[3].id << ")" << endl;
    } else
    {
        cout << "Median: " << minMaxMed[2].score << " (Student ID: " << minMaxMed[2].id << ")" << endl;
    }

    cout << "Standard Deviation: " << meanSD[1] << endl;

    delete [] minMaxMed;
    delete [] meanSD;
}