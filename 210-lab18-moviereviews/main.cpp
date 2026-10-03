
// COMSC-210 | Lab 18 | Jonvianney Maglasang

// Started October 2, 2026 at 9:30pm
// Finished October 3, 2026 at 

#include <iostream>
#include <random>
#include <fstream>
#include <vector>
#include <string>
#include <ctime>
#include <cmath>

using namespace std;

struct ReviewNode
{
    double value;
    string review;
    ReviewNode* next;

    // Default Constructor and Normal Constructor
    ReviewNode(double inputVal = 0, string inputRev = "", ReviewNode* inputNode = nullptr)
    {
        this->value = inputVal;
        this->review = inputRev;
        this->next = inputNode;
    }
};

class Movie
{
    private:
        string title;
        ReviewNode* head;

    public:
        // Default and also regular constructor
        // allows you to create a new default node and set it as the first linked list node, or set the head ptr to a copy of a pointer to an already existing node object
        Movie(string inputTitle = "", ReviewNode* inputNode = new ReviewNode())
        {
            title = inputTitle;
            head = inputNode;
        }

        // Destructor
        ~Movie()
        {
            ReviewNode* prev = nullptr;

            // While head is not empty
            while(head != nullptr)
            {
                // Point previous ptr to head node and head ptr to next node
                prev = head;
                head = head->next;

                // Point prev, the previous head to null and free memory
                prev->review = "";
                prev->value = 0;
                prev = nullptr;
                delete prev;
            }
        }

        string getTitle() { return title; }
        ReviewNode* getHead() { return head; }
        void setTitle(string inputTitle) { title = inputTitle; }

        void addReview(ReviewNode* inputNode = new ReviewNode())
        {
            // If list is empty
            if(head == nullptr)
            {
                head = inputNode;
            } else
            {
                // New node points to head of list which points to other nodes
                inputNode->next = head;

                // Head points to appended node
                head = inputNode;
            }
        }
};

// Define Constants
const int Min = 100;
const int Max = 500;
const int MovieCnt = 4;
const int ReviewCnt = 3;
const string TitleData = "data/titles.txt";
const string ReviewData = "data/reviews.txt";

// Declare Functions
double getRevNum(int min, int max);
vector<string> readData(string filename);

int main()
{
    srand(time(0));
    vector<Movie> movieArr;
    vector<string> titleStrs = readData(TitleData);
    vector<string> reviewStrs = readData(ReviewData);

    for(int i = 0; i < MovieCnt; i++)
    {
        Movie tempMov(titleStrs[i]);

        for(int j = i * ReviewCnt; j % ReviewCnt != 0; j++)
        {
            tempMov.addReview(new ReviewNode(getRevNum(Min, Max), reviewStrs[j]));
        }
    }
    return 0;
}

// Define Functions
double getRevNum(int min, int max)
{
    int num = rand() % (max - min + 1) + min;
    
    // Casts num into into double, divides by ten, and then rounds to get rid of the excess decimal, then divides by ten again to give the new rounded num
    return round(static_cast<double>(num)/10)/10;
}

// Saves read string data into a string vector
vector<string> readData(string filename)
{
    vector<string> strArr;
    ifstream readFile(filename);
    string tempStr = "";

    // Saves readlines into a sting vector
    while(getline(readFile, tempStr))
    {
        strArr.push_back(tempStr);
    }

    readFile.close();
    return strArr;
}