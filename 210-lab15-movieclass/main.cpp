
// COMSC-210 | Lab 15 | Jonvianney Maglasang

// Started September 25, 2026 at 8:48pm
// Finished September 25, 2026 at 

#include <iostream>
#include <vector>
#include <string>

using namespace std;

const int CurrentYear = 2026;

class Movie
{
    private:
        string title;
        int yearReleased;
        string screenWriter;

    private:
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
            
        }
};

int main()
{

    return 0;
}