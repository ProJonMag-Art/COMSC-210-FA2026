
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

auto getTime();

void readData(string filename, vector<string> &strVec);
void readData(string filename, list<string> &strList);
void readData(string filename, set<string> &strSet);

void deleteItem();
void deleteItem();
void deleteItem();

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

/* syntax examples:
auto start = high_resolution_clock::now()
auto end = high_resolution_clock::now()
auto duration = duration_cast<milliseconds>(end - start)
duration.count() references elapsed milliseconds
*/