
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
void insertItem(int position, string item, list<string> &strVec);
void insertItem(int position, string item, set<string> &strVec);

void deleteItem(int position, vector<string> &strVec);
void deleteItem(int position, list<string> &strVec);
void deleteItem(int position, set<string> &strVec);

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

void insertItem(int position, string item, vector<string> &strVec)
{
    int size = strVec.size();

    if(position < size)
    {
        // Replace strVec[position] with inputted item and save strVec[position] in a temp to be moved
        string tempStr = strVec[position];
        strVec[position] = item;

        // Shift all other items down one position
        for(int i = position + 1; i < size - 1; i++)
        {
            strVec[i] = tempStr;
            tempStr = strVec[i];
        }
    }
}

void insertItem(int position, string item, list<string> &strVec);
void insertItem(int position, string item, set<string> &strVec);

void deleteItem(int position, vector<string> &strVec);
void deleteItem(int position, list<string> &strVec);
void deleteItem(int position, set<string> &strVec);
/* syntax examples:
auto start = high_resolution_clock::now()
auto end = high_resolution_clock::now()
auto duration = duration_cast<milliseconds>(end - start)
duration.count() references elapsed milliseconds
*/