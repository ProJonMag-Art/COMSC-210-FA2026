
// COMSC-210 | Lab 26 | Jonvianney Maglasang

// Started October 23, 2026 at  3:46 PM
// Finished October 23, 2026 at 

#include <iostream>
#include <iomanip>
#include <fstream>
#include <chrono>
#include <algorithm>
#include <list>
#include <set>
#include <vector>
#include <string>

using namespace std;
using namespace std::chrono;

// Constants
const int DATASET_SIZE = 20000;
const int SPACING_SIZE = 20;
const int ROW_CNT = 4;
const int COL_CNT = 3;
const int SIMULATION_CNT = 15;

// Function Declarations
void readDataV(string filename, vector<string> &strVec);
void readDataL(string filename, list<string> &strList);
void readDataS(string filename, set<string> &strSet);

void sortDataV(vector<string> &strVec);
void sortDataL(list<string> &strList);

void insertDataV(int position, string item, vector<string> &strVec);
void insertDataL(int position, string item, list<string> &strList);
void insertDataS(string item, set<string> &strSet);

void deleteDataV(int position, vector<string> &strVec);
void deleteDataL(int position, list<string> &strList);
void deleteDataS(int position, set<string> &strSet);

void outputData(int64_t array[2][4][3]);

// Template Funtion Definitions
// Template definitions to allow timing of any inputted function with one parameter
template<typename P1, typename Func>
auto getTime(Func func, P1 param1)
{
    auto start = high_resolution_clock::now();

    func(param1);

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(end - start);
    return duration.count();

}

// Template definitions to allow timing of any inputted function with two parameters
template<typename P1, typename P2, typename Func>
auto getTime(Func func, P1 param1, P2 param2)
{
    auto start = high_resolution_clock::now();

    func(param1, param2);

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(end - start);
    return duration.count();

}

// Template definitions to allow timing of any inputted function with three parameters
template<typename Func, typename P1, typename P2, typename P3>
auto getTime(Func func, P1 param1, P2 param2, P3 param3)
{
    auto start = high_resolution_clock::now();

    func(param1, param2, param3);

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(end - start);
    return duration.count();
}


int main() 
{
    vector<string> strVec;
    list<string> strList;
    set<string> strSet;

    string readFile = "data.txt";

    // Slice 0 is the current race values
    // Slice 1 is the total race values
    int64_t data[2][ROW_CNT][COL_CNT];

    int idx = 0;
    while(idx < SIMULATION_CNT)
    {
        // Saves vector data
        data[0][0][0] = getTime(readDataV, readFile, strVec);
        data[0][1][0] = getTime(sortDataV, strVec);
        data[0][2][0] = getTime(insertDataV, DATASET_SIZE/2, "TESTDATA", strVec);
        data[0][3][0] = getTime(deleteDataV, DATASET_SIZE/2, strVec);

        // Saves list data
        data[0][0][1] = getTime(readDataL, readFile, strList);
        data[0][1][1] = getTime(sortDataL, strList);
        data[0][2][1] = getTime(insertDataL, DATASET_SIZE/2, "TESTDATA", strList);
        data[0][3][1] = getTime(deleteDataL, DATASET_SIZE/2, strList);

        // Saves set data
        data[0][0][2] = getTime(readDataS, readFile, strSet);
        data[0][1][2] = -1;
        data[0][2][2] = getTime(insertDataS, "TESTDATA", strSet);
        data[0][3][2] = getTime(deleteDataS, DATASET_SIZE/2, strList);

        // Adds slice 0 to slice 1
        for(int i = 0; i < ROW_CNT; i++)
        {
            for(int j = 0; j < COL_CNT; j++)
            {
                // If slice 1 is uninitialized
                if(idx == 0)
                {
                    // Zero out the data
                    data[1][i][j] = 0;
                }

                // Add slice 0 data to slice 1 data
                data[1][i][j] += data[0][i][j];
            }
        }
    };

    cout << endl << setw(SPACING_SIZE * 2 + 5) << "Data Structure Task Speed" << endl;
    cout << "Operation: " << setw(SPACING_SIZE - 5) << "Vector" << setw(SPACING_SIZE) << "List" << setw(SPACING_SIZE) << "Set" << endl;

    // Tests and outputs vector data
    cout << "Read: " << setw(SPACING_SIZE) << getTime(readDataV, readFile, strVec) << setw(SPACING_SIZE) 
    << getTime(readDataL, readFile, strList) << setw(SPACING_SIZE) 
    <<  getTime(readDataS, readFile, strSet) << endl;

    // Tests and outputs list data
    cout << "Sort: " << setw(SPACING_SIZE) << getTime(sortDataV, strVec) << setw(SPACING_SIZE) 
    << getTime(sortDataL, strList) << setw(SPACING_SIZE) 
    << -1 << endl;

    // Test and outputs set data
    cout << "Delete: " << setw(SPACING_SIZE - 2) << getTime(deleteDataV, DATASET_SIZE/2, strVec) << setw(SPACING_SIZE) 
    <<  getTime(deleteDataL, DATASET_SIZE/2, strList) << setw(SPACING_SIZE) 
    << getTime(deleteDataS, DATASET_SIZE/2, strSet) << endl;
    
    cout << "\n(Note: A negative one on the table means N/A)\n" << endl;

    return 0;
}

// Function Definitions
// All of these functions use a slightly different version of predfined library functions for reading, sorting, inserting, and deleting
// I didn't add too many notes because they are sort of self explanatory
void readDataV(string filename, vector<string> &strVec)
{
    ifstream readFile(filename);
    string tempStr;

    while(getline(readFile, tempStr))
    {
        strVec.push_back(tempStr);
    }

    readFile.close();
}

void readDataL(string filename, list<string> &strList)
{
    ifstream readFile(filename);
    string tempStr;

    while(getline(readFile, tempStr))
    {
        strList.push_back(tempStr);
    }
}

void readDataS(string filename, set<string> &strSet)
{
    ifstream readFile(filename);
    string tempStr;

    while(getline(readFile, tempStr))
    {
        strSet.insert(tempStr);
    }
}

void sortDataV(vector<string> &strVec) { sort(strVec.begin(), strVec.end()); }
void sortDataL(list<string> &strList) { strList.sort(); }

void insertDataV(int position, string item, vector<string> &strVec) {
    if(position < strVec.size())
    {
        strVec.insert(strVec.begin() + position, item);
    }
}

void insertDataL(int position, string item, list<string> &strList)
{  
    auto it = strList.begin();

    if(position < strList.size())
    {
        // Move to the position at that item and insert a new item there
        advance(it, position);
        strList.insert(it, item);
    }
}

void insertDataS(string item, set<string> &strSet) { strSet.insert(item); }

void deleteDataV(int position, vector<string> &strVec)
{
    if(position < strVec.size())
    {
        strVec.erase(strVec.begin() + position);
    }
}

void deleteDataL(int position, list<string> &strList)
{
    auto it = strList.begin();

    if(position < strList.size())
    {
        // Move to the position at that item and delete the item there
        advance(it, position);
        strList.erase(it);
    }
}

void deleteDataS(int position, set<string> &strSet)
{
    auto it = strSet.begin();

    if(position < strSet.size())
    {
        // Move to the position at that item and delete the item there
        advance(it, position);
        strSet.erase(it);
    }
}

void outputData(int64_t array[2][4][3])
{

}
/* syntax examples:
auto start = high_resolution_clock::now()
auto end = high_resolution_clock::now()
auto duration = duration_cast<milliseconds>(end - start)
duration.count() references elapsed milliseconds
*/