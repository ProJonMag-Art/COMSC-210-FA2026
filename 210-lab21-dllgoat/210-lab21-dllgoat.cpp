
// COMSC-210 | Lab 21 | Jonvianney Maglasang

// Started October 10, 2026 at 10:14am
// Finished October 9, 2026 at 

#include <iostream>
#include <random>
#include <ctime>
#include <string>

using namespace std;

const int MIN_NR = 10, MAX_NR = 99, MIN_LS = 5, MAX_LS = 20;

int getRandInt(int min, int max);

class Goat
{
    private:
        int age;
        string name;
        string color;
        string randNames[15];
        string randCols[15];
            
    public:
        Goat()
        {
            for(int i = 0; i < 15; i++)
            {
                age = getRandInt(0, 20);
                name = randNames[getRandInt(0, 14)];
                color = randCols[getRandInt(0, 14)];
            }
        }

        int getAge() { return age; } 
        string getName() { return name; }
        string getCol() { return color; }
};

class DoublyLinkedList 
{
private:
    struct Node 
    {
        Goat goat;
        Node* prev;
        Node* next;
        Node(Goat val, Node* p = nullptr, Node* n = nullptr) 
        {
            goat = val; 
            prev = p;
            next = n;
        }
    };

    Node* head;
    Node* tail;

public:
    // constructor
    DoublyLinkedList() { head = nullptr; tail = nullptr; }

    void push_back(Goat value) 
    {
        Node* newNode = new Node(value);
        if (!tail) // if there's no tail, the list is empty
        { 
            head = tail = newNode;
        } 
        else 
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void push_front(Goat value) 
    {
        Node* newNode = new Node(value);
        if (!head) // if there's no head, the list is empty
        {
            head = tail = newNode;
        }  
        else 
        {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void insert_after(Goat value, int position) 
    {
        if (position < 0) 
        {
            cout << "Position must be >= 0." << endl;
            return;
        }

        Node* newNode = new Node(value);
        if (!head) 
        {
            head = tail = newNode;
            return;
        }

        Node* temp = head;
        for (int i = 0; i < position && temp; ++i)
        {
            temp = temp->next;
        }

        if (!temp) {
            cout << "Position exceeds list size. Node not inserted.\n";
            delete newNode;
            return;
        }

        newNode->next = temp->next;
        newNode->prev = temp;

        if (temp->next)
        {
            temp->next->prev = newNode;
        }
        else
        {
            tail = newNode; // Inserting at the end
        }

        temp->next = newNode;
    }

    void delete_node(Goat value) 
    {
        if (!head) return; // Empty list

        Node* temp = head;
        /*
        while (temp && temp->data != value)
            temp = temp->next;
        */

        if (!temp) return; // Value not found

        if (temp->prev) {
            temp->prev->next = temp->next;
        } else {
            head = temp->next; // Deleting the head
        }

        if (temp->next) {
            temp->next->prev = temp->prev;
        } else {
            tail = temp->prev; // Deleting the tail
        }

        delete temp;
    }

    void print() 
    {
        Node* current = head;
        if (current == nullptr) 
        {
            cout << "List is empty!" << endl;
            return; 
        }
        
        while (current) 
        {
            cout << current->goat.getName() << " (" << current->goat.getCol() << ", " << current->goat.getAge() << ")";
            current = current->next;
        }
        cout << endl;
    }

    void print_reverse() 
    {
        Node* current = tail;
        if (!current) 
        {
            cout << "List is empty!" << endl;
            return; 
        }

        while (current) 
        {
            cout << current->goat.getName() << " (" << current->goat.getCol() << ", " << current->goat.getAge() << ")";
            current = current->prev;
        }
        cout << endl;
    }

    ~DoublyLinkedList() 
    {
        while (head) 
        {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

// Driver program
int main() {
    srand(time(0));

    DoublyLinkedList list;
    int size = getRandInt(MIN_LS, MAX_LS);

    for (int i = 0; i < size; ++i)
    {
        list.push_back(Goat());
    }
    cout << "List forward: ";
    list.print();

    cout << "List backward: ";
    list.print_reverse();

    cout << "Deleting list, then trying to print.\n";
    list.~DoublyLinkedList();
    cout << "List forward: ";
    list.print();

    return 0;
}

int getRandInt(int min, int max)
{
    return rand() % (max - min +1) + min;
}