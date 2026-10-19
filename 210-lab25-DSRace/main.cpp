
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
    strVec.push_back(item);

    if(position < size)
    {
        // Shift all other items down one position by swapping with the element at the end
        // At i = position the end element is the inputted string because of push_back
        // At i = position + 1, the end element is the element at position
        for(int i = position; i < size; i++)
        {
            strVec[i].swap(strVec[strVec.size()]);
        }
    }
}

void insertItem(int position, string item, list<string> &strList)
{  
    auto it = strList.begin();

    advance(it, position - 1);
    strList.insert(it, item);
}

void insertItem(string item, set<string> &strSet) { strSet.insert(item); }

void deleteItem(int position, vector<string> &strVec);
void deleteItem(int position, list<string> &strVec);
void deleteItem(int position, set<string> &strVec);
/* syntax examples:
auto start = high_resolution_clock::now()
auto end = high_resolution_clock::now()
auto duration = duration_cast<milliseconds>(end - start)
duration.count() references elapsed milliseconds
*/