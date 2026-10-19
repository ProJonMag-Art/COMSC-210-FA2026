
// COMSC-210 | Lab 25 | Jonvianney Maglasang

// Started October 18, 2026 at 4:45 PM
// Finished October 18, 2026 at 

#include <iostream>
#include <fstream>
#include <chrono>
#include <algorithm>
#include <list>
#include <set>
#include <vector>
#include <string>

using namespace std;
using namespace std::chrono;

const int DATASET_SIZE = 20000;

void readDataV(string filename, vector<string> &strVec);
void readDataL(string filename, list<string> &strList);
void readDataS(string filename, set<string> &strSet);

void sortDataV(vector<string> &strVec);
void sortDataL(list<string> &strList);
void sortDataS(set<string> &strSet);

void insertItemV(int position, string item, vector<string> &strVec);
void insertItemL(int position, string item, list<string> &strList);
void insertItemS(string item, set<string> &strSet);

void deleteItemV(int position, vector<string> &strVec);
void deleteItemL(int position, list<string> &strList);
void deleteItemS(int position, set<string> &strSet);

// Template definitions to allow timing of any inputted function with one parameter
template<typename P1, typename Func>
nanoseconds getTime(Func func, P1 param1)
{
    auto start = high_resolution_clock::now();

    func(param1, param2);

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(end - start);
    return duration.count();

}

// Template definitions to allow timing of any inputted function with two parameters
template<typename P1, typename P2, typename Func>
nanoseconds getTime(Func func, P1 param1, P2 param2)
{
    auto start = high_resolution_clock::now();

    func(param1, param2);

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(end - start);
    return duration.count();

}

// Template definitions to allow timing of any inputted function with three parameters
template<typename Func, typename P1, typename P2, typename P3>
nanoseconds getTime(Func func, P1 param1, P2 param2, P3 param3)
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

    nanoseconds timing;

    timing = getTime(readDataV, readFile, strVec);
    //timing = getTime(sort, readFile, strVec);
    timing = getTime(readDataL, readFile, strVec);

    cout << "READ | SORT | INSERT | DELETE";


    timing = getTime(readDataL, readFile, strVec);

    return 0;
}

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

void insertItemV(int position, string item, vector<string> &strVec) {
    if(position < strVec.size())
    {
        strVec.insert(strVec.begin() + position, item);
    }
}

void insertItemL(int position, string item, list<string> &strList)
{  
    auto it = strList.begin();

    if(position < strList.size())
    {
        // Move to the position at that item and insert a new item there
        advance(it, position);
        strList.insert(it, item);
    }
}

void insertItemS(string item, set<string> &strSet) { strSet.insert(item); }

void deleteItemV(int position, vector<string> &strVec)
{
    if(position < strVec.size())
    {
        strVec.erase(strVec.begin() + position);
    }
}

void deleteItemL(int position, list<string> &strList)
{
    auto it = strList.begin();

    if(position < strList.size())
    {
        // Move to the position at that item and delete the item there
        advance(it, position);
        strList.erase(it);
    }
}

void deleteItemS(int position, set<string> &strSet)
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