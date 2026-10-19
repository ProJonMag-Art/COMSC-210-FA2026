
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

auto getTime();

void readData(string filename, vector<string> &strVec);
void readData(string filename, list<string> &strList);
void readData(string filename, set<string> &strSet);

void insertItem(int position, string item, vector<string> &strVec);
void insertItem(int position, string item, list<string> &strList);
void insertItem(int position, string item, set<string> &strSet);

void deleteItem(int position, vector<string> &strVec);
void deleteItem(int position, list<string> &strList);
void deleteItem(int position, set<string> &strSet);

int main() 
{
    

    return 0;
}

void readData(string filename, vector<string> &strVec)
{
    ifstream readFile(filename);
    string tempStr;

    while(getline(readFile, tempStr))
    {
        strVec.push_back(tempStr);
    }

    readFile.close();
}

void readData(string filename, list<string> &strList)
{
    ifstream readFile(filename);
    string tempStr;

    auto it = strList.begin();
    while(getline(readFile, tempStr))
    {
        strList.insert(it, tempStr);
        it++;
    }
}

void readData(string filename, set<string> &strSet)
{
    ifstream readFile(filename);
    string tempStr;

    while(getline(readFile, tempStr))
    {
        strSet.insert(tempStr);
    }
}

void insertItem(int position, string item, vector<string> &strVec) { strVec.insert(strVec.begin() + position, item); }

void insertItem(int position, string item, list<string> &strList)
{  
    auto it = strList.begin();

    if(position <= strList.size())
    {
        // Move to the position at that item and insert a new item there
        advance(it, position);
        strList.insert(it, item);
    }
}

void insertItem(string item, set<string> &strSet) { strSet.insert(item); }

void deleteItem(int position, vector<string> &strVec)
{
    if(position <= strVec.size())
    {
        strVec.erase(strVec.begin() + position);
    }
}

void deleteItem(int position, list<string> &strList)
{
    auto it = strList.begin();

    if(position <= strList.size())
    {
        // Move to the position at that item and delete the item there
        advance(it, position);
        strList.erase(it);
    }
}

void deleteItem(int position, set<string> &strSet)
{
    auto it = strSet.begin();

    if(position <= strSet.size())
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