
// COMSC-210 | Lab 18 | Jonvianney Maglasang

// Started October 2, 2026 at 9:30pm
// Finished October 2, 2026 at 

#include <iostream>
#include <random>
#include <fstream>
#include <vector>
#include <string>

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

        ~Movie()
        {
            ReviewNode* temp = head;

            // While head is not empty
            while(head != nullptr)
            {
                // Point head to the next node
                head = head->next;

                // Point temp, the previous head to null and free memory
                temp = nullptr;
                delete temp;

                // Reasign temp to the new head of list
                temp = head;
            }
        }

        string getTitle() { return title; }
        ReviewNode* getHead() { return head; }

        void addReview(ReviewNode* inputNode = new ReviewNode())
        {
            ReviewNode* head = getHead();

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

int main()
{

    return 0;
}
