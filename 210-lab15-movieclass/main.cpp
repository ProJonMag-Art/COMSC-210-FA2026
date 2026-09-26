
// COMSC-210 | Lab 15 | Jonvianney Maglasang

// Started September 25, 2026 at 8:48pm
// Finished September 25, 2026 at 

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

// Const vars
const int CurrentYear = 2026;

// Class Definition and Declaration
class Movie
{
    private:
        string title;
        int yearReleased;
        string screenWriter;

    public:
        // I'd normally add comments to these functions but these are relatively self-explanatory
        void setTitle(string inputTitle = "")
        {
            title = inputTitle;
        }

        int setYear(int inputYear = 0)
        {
            if(inputYear >= 0 && inputYear <= CurrentYear)
            {
                yearReleased = inputYear;
                return 1;
            } else
            {
                return -1;
            }
        }

        void setSWriter(string inputSWriter = "")
        {
            screenWriter = inputSWriter;
        }

        string getTitle()
        {
            return title;
        }

        int getYear()
        {
            return yearReleased;
        }

        string getSWriter()
        {
            return screenWriter;
        }

        void printData()
        {
            int spaceSize = 5;
            cout << "Movie: " << title << endl;
            cout << setw(5) << "Year Released: " << yearReleased << endl;
            cout << setw(5) << "Screenwriter: " << screenWriter << endl;
        }
};

// Function Declarations
void readData(string filename, vector<Movie>& movieArr)
{
    ifstream readFile(filename);
    Movie tempObj;
    int tempInt = 0;
    string tempStr;


    while(readFile >> tempStr >> tempInt)
    {
        tempObj.setTitle(tempStr);
        tempObj.setYear(tempInt);

        readFile >> tempStr;
        tempObj.setSWriter(tempStr);
    }

    readFile.close();
}

int main()
{

    return 0;
}