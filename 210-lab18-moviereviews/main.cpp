
// COMSC-210 | Lab 18 | Jonvianney Maglasang

// Started October 2, 2026 at 9:30pm
// Finished October 2, 2026 at 

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
const int MIN = 100;
const int MAX = 500;

// Declare Functions
double getRandNum(int min, int max);


int main()
{
    srand(time(0));

    // Returns double between 1.0 and 5.0
    for(int i = 0; i < 5; i++)
    {
        cout << round(static_cast<double>(getRandNum(MIN, MAX))/10)/10 << endl;
    }
    return 0;
}

// Define Functions
double getRandNum(int min, int max)
{
    return rand() % (max - min + 1) + min;
}
