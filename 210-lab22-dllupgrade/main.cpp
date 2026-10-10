#include <iostream>
using namespace std;

const int MIN_NR = 10, MAX_NR = 99, MIN_LS = 5, MAX_LS = 20;

class DoublyLinkedList {
private:
    struct Node {
        int data;
        Node* prev;
        Node* next;
        Node(int val, Node* p = nullptr, Node* n = nullptr) {
            data = val; 
            prev = p;
            next = n;
        }
    };

    Node* head;
    Node* tail;

public:
    // constructor
    DoublyLinkedList() { head = nullptr; tail = nullptr; }

    void push_back(int value) {
        Node* newNode = new Node(value);
        if (!tail)  // if there's no tail, the list is empty
            head = tail = newNode;
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void push_front(int value) {
        Node* newNode = new Node(value);
        if (!head)  // if there's no head, the list is empty
            head = tail = newNode;
        else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void insert_after(int value, int position) {
        if (position < 0) {
            cout << "Position must be >= 0." << endl;
            return;
        }

        Node* newNode = new Node(value);
        if (!head) {
            head = tail = newNode;
            return;
        }

        Node* temp = head;
        for (int i = 0; i < position && temp; ++i)
            temp = temp->next;

        if (!temp) {
            cout << "Position exceeds list size. Node not inserted.\n";
            delete newNode;
            return;
        }

        newNode->next = temp->next;
        newNode->prev = temp;
        if (temp->next)
            temp->next->prev = newNode;
        else
            tail = newNode; // Inserting at the end
        temp->next = newNode;
    }

    void delete_val(int value) {
        if (!head) return; // Empty list

        Node* temp = head;
        while (temp && temp->data != value)
            temp = temp->next;

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

    void print() {
        Node* current = head;
        if (!current) return;
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    void print_reverse() {
        Node* current = tail;
        if (!current) return;
        while (current) {
            cout << current->data << " ";
            current = current->prev;
        }
        cout << endl;
    }

    void pop_front()
    {
        Node* current = head;

        // Empty list, do nothing
        if(current == nullptr) { return; };

        // One element list, removing head removes tail as well
        if(head == tail)
        {
            current->next = nullptr;
            delete head;
            return;
        }

        // Move the head forward, set the new head's previous to null, then remove the old head from the link and delete the old head
        head = current->next;
        head->prev = nullptr;
        current->next = nullptr;
        current->data = 0;
        delete current;
    }

    void pop_back()
    {
        Node* current = tail;

        // If tail is null, list is empty
        if(current = nullptr) { return; }

        // If head == tail, the list has one element and deleting the head will delete the tail
        if(head == tail)
        {
            current->prev = nullptr;
            delete current;
            return;
        }

        // Move the tail backward, set the new tail's next to null, then remove the old tail from the link and delete the old tail
        tail = current->prev;
        tail->next = nullptr;
        current->prev = nullptr;
        current->data = 0;
        delete current;
    }

    void delete_pos(int pos)
    {
        int currentPos = 0;
        Node* current = head;

        // Pos 0 means delete head
        if(pos == 0)
        {
            pop_front();
        }

        while(current != nullptr)
        {
            if(currentPos == pos)
            {
                // This delete_val method should already cover deleting the head or tail
                delete_val(current->data);
                break;
            }

            currentPos++;
        }
    }

    ~DoublyLinkedList() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

// Driver program
int main() {
    DoublyLinkedList list;
    int size = rand() % (MAX_LS-MIN_LS+1) + MIN_LS;

    for (int i = 0; i < size; ++i)
        list.push_back(rand() % (MAX_NR-MIN_NR+1) + MIN_NR);

    cout << "Original List forward: ";
    list.print();

    list.pop_front();

    cout << "Poopped Front List forward: ";
    list.print();

    list.pop_back();

    cout << "Popped Back List forward: ";
    list.print();

    list.delete_pos(MAX_NR/2);

    cout << "Middle Pos Deleted List forward: ";
    list.print();

    cout << "Deleting list, then trying to print.\n";
    list.~DoublyLinkedList();
    cout << "List forward: ";
    list.print();

    return 0;
}
