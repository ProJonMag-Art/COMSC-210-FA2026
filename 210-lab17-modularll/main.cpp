
// COMSC-210 | Lab 16 | Jonvianney Maglasang

// Started October 10, 2026 at 11:16am
// Finished October 10, 2026 at

#include <iostream>

using namespace std;

// Struct/Constant Definition
const int SIZE = 7;

struct Node {
    float value;
    Node *next;
};

// Function Declaration
void output(Node* head);
void deleteNode(Node* head);
void insertAfter(Node* head);

int main()
{
    Node *head = nullptr;
    int count = 0;

    // create a linked list of size SIZE with random numbers 0-99
    for (int i = 0; i < SIZE; i++)
    {
        int tmp_val = rand() % 100;
        Node *newVal = new Node;

        // List is empty, adds node at head
        if (!head) {
            head = newVal;
            newVal->next = nullptr;
            newVal->value = tmp_val;
        } else 
        {
            newVal->next = head;
            newVal->value = tmp_val;
            head = newVal;
        }
    }

    output(head);
    deleteNode(head);
    output(head);

    return 0;
}

// deleting a node
void deleteNode(Node* head)
{
    cout << "Which node to delete? " << endl;
    output(head);
    int entry;
    cout << "Choice --> ";
    cin >> entry;

    // traverse that many times and delete that node
    Node *current = head;
    Node *prev = nullptr; // start prev as nullptr to detect head deletion
    for (int i = 0; i < (entry - 1); i++) 
    {
        prev = current;
        current = current->next;
    }
    // at this point, delete current and reroute pointers
    if (current) 
    {
        if (prev == nullptr) 
        {
            // deleting the head node
            head = current->next;
        } else 
        {
            prev->next = current->next;
        }
        delete current;
        current = nullptr;
    }
}

// insert a node
void insertAfter(Node* head, Node* current, Node* prev)
{
    cout << "After which node to insert 10000? " << endl;
    int count = 1;
    int entry;
    current = head;

    while (current) {
        cout << "[" << count++ << "] " << current->value << endl;
        current = current->next;
    }

    cout << "Choice --> ";
    cin >> entry;
    current = head;

    prev = nullptr; // reset prev to nullptr for same reason
    for (int i = 0; i < entry; i++) {
        prev = current;
        current = current->next;
    }
    // at this point, insert a node between prev and current
    Node *newnode = new Node;
    newnode->value = 10000;
    newnode->next = current;
    if (prev == nullptr) {
        // inserting before the head
        head = newnode;
    } else 
    {
        prev->next = newnode;
    }
    output(head);
    
    // deleting the linked list
    current = head;
    while (current) 
    {
        head = current->next;
        delete current;
        current = head;
    }
    head = nullptr;
    output(head);
}

void output(Node *head) 
{
    if (!head) {
        cout << "Empty list.\n";
        return;
    }
    int count = 1;
    Node *current = head;

    while (current) 
    {
        cout << "[" << count++ << "] " << current->value << endl;
        current = current->next;
    }
    cout << endl;
}
