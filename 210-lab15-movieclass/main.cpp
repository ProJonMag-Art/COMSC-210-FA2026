
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
            cout << "Movie: " << getTitle() << endl;
            cout << setw(spaceSize) << "Year Released: " << getYear() << endl;
            cout << setw(spaceSize) << "Screenwriter: " << getSWriter() << endl;
        }
};

// Function Declarations
void readData(string filename, vector<Movie>& movieArr);

int main()
{
    string filename = "input.txt";
    vector<Movie> movieData;

    readData(filename, movieData);

    cout << "Best Movie Data: " << endl;
    cout << "----------------" << endl;
    for(int i = 0; i < movieData.size(); i++)
    {
        movieData[i].printData();
        cout << endl;
    }

    return 0;
}

void readData(string filename, vector<Movie>& movieArr)
{
    ifstream readFile(filename);
    Movie tempMovie;
    int tempInt = 0;
    string tempStr;

    // While there is another line of data to save as a string
    while(getline(readFile, tempStr))
    {
        tempMovie.setTitle(tempStr);

        // Read the next piece of data into a tempInt
        readFile >> tempInt;
        tempMovie.setYear(tempInt);

        // Ignores the '/n' char that the >> operator leaves for some reason to allow getline() to read the right line
        readFile.ignore();

        // Reads next line into tempStr to use the same tempStr again
        getline(readFile, tempStr);
        tempMovie.setSWriter(tempStr);

        movieArr.push_back(tempMovie);
    }

    readFile.close();
}