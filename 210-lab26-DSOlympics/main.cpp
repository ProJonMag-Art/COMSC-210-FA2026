
// COMSC-210 | Lab 26 | Jonvianney Maglasang

// Started October 23, 2026 at  PM
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

    string readFile = "codes.txt";

    cout << endl << setw(55) << "Data Structure Task Speed" << endl;
    cout << "Table [ms]: " << setw(16) << "READ" << setw(SPACING_SIZE) << "SORT" << setw(SPACING_SIZE) << "INSERT" << setw(SPACING_SIZE) << "DELETE" << endl;

    // Tests and outputs vector data
    cout << "Vector: " << setw(SPACING_SIZE) << getTime(readDataV, readFile, strVec) << setw(SPACING_SIZE) 
    << getTime(sortDataV, strVec) << setw(SPACING_SIZE) 
    <<  getTime(insertDataV, DATASET_SIZE/2, "TESTCODE", strVec) << setw(SPACING_SIZE) 
    << getTime(deleteDataV, DATASET_SIZE/2, strVec) << endl;

    // Tests and outputs list data
    cout << "List: " << setw(SPACING_SIZE + 2) << getTime(readDataL, readFile, strList) << setw(SPACING_SIZE) 
    << getTime(sortDataL, strList) << setw(SPACING_SIZE) 
    <<  getTime(insertDataL, DATASET_SIZE/2, "TESTCODE", strList) << setw(SPACING_SIZE) 
    << getTime(deleteDataL, DATASET_SIZE/2, strList) << endl;

    // Test and outputs set data
    cout << "Set: " << setw(SPACING_SIZE + 3) << getTime(readDataS, readFile, strSet) << setw(SPACING_SIZE) 
    << -1 << setw(SPACING_SIZE) 
    <<  getTime(insertDataS, "TESTCODE", strSet) << setw(SPACING_SIZE) 
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
/* syntax examples:
auto start = high_resolution_clock::now()
auto end = high_resolution_clock::now()
auto duration = duration_cast<milliseconds>(end - start)
duration.count() references elapsed milliseconds
*/