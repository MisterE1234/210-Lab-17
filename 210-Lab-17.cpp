//COMSC-210|Lab-17|Ethan Aylard
//IDE used: Visual Studio Code
//This program demonstrates linked lists with functions.

#include <iostream>
using namespace std;

const int SIZE = 7;  

struct Node {
    float value;
    Node *next;
};

int menu();
void output(Node *);
void addFront(Node *, int);
void addEnd(Node *, int);
void deleteNode(Node *, int);
void insertNode(Node *, int, int);
void deleteList(Node *);


int main() {
    Node *head = nullptr;
    int count = 0;
    int choice = -1;

    // create a linked list of size SIZE with random numbers 0-99
    for (int i = 0; i < SIZE; i++) {
        int tmp_val = rand() % 100;
        Node *newVal = new Node;
        
        // adds node at head
        if (!head) { // if this is the first node, it's the new head
            head = newVal;
            newVal->next = nullptr;
            newVal->value = tmp_val;
        }
        else { // its a second or subsequent node; place at the head
            newVal->next = head;
            newVal->value = tmp_val;
            head = newVal;
        }
    }
    output(head);
    
    while(choice != 0){

        choice = menu();
        switch(choice){
            case 1: {
                int val;
                cout << "Enter a value to add to the front of the list: ";
                cin >> val;
                addFront(head, val);
                output(head);
                break;
            }
            case 2: {
                int val;
                cout << "Enter a value to add to the end of the list: ";
                cin >> val;
                addEnd(head, val);
                output(head);
                break;
            }
            case 3: {
                int val;
                cout << "Enter a value to delete from the list: ";
                cin >> val;
                deleteNode(head, val);
                output(head);
                break;
            }
            case 4: {
                int afterVal, newVal;
                cout << "Enter a value to insert after: ";
                cin >> afterVal;
                cout << "Enter a new value to insert: ";
                cin >> newVal;
                insertNode(head, afterVal, newVal);
                output(head);
                break;
            }
            case 5: {
                deleteList(head);
                head = nullptr; // reset head to nullptr after deletion
                output(head);
                break;
            }

            case 7: {
                // option to display the list 
                output(head);
                break;
            }
            case 0:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
    
    
    Node * current = head;
    current = head;
    while (current) {
        head = current->next;
        delete current;
        current = head;
    }
    head = nullptr;
    output(head);

    delete head;

    return 0;
}

void output(Node * hd) {
    if (!hd) {
        cout << "Empty list.\n";
        return;
    }
    int count = 1;
    Node * current = hd;
    while (current) {
        cout << "[" << count++ << "] " << current->value << endl;
        current = current->next;
    }
    cout << endl;
}

int menu(){
    int choice;
    cout << "Menu Options:\n"
         << "1. Add a node to the front of the list\n"
         << "2. Add a node to the end of the list\n"
         << "3. Delete a node from the list\n"
         << "4. Insert a node after a specific value\n"
         << "5. Delete the entire list\n"
         << "7. Display the list\n"
         << "0. Exit\n"
         << "Enter your choice: ";
    cin >> choice;
    return choice;
}

void addFront(Node * hd, int val) {
    Node * newNode = new Node;
    newNode->value = val;
    newNode->next = hd;
    hd = newNode;
}

void addEnd(Node * hd, int val) {
    Node * newNode = new Node;
    newNode->value = val;
    newNode->next = nullptr;

    if (!hd) {
        hd = newNode;
        return;
    }

    Node * current = hd;
    while (current->next) {
        current = current->next;
    }
    current->next = newNode;
}

void deleteNode(Node * head, int val) {

    if (!head) return;

    if (head->value == val) {
        Node * temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node * current = head;
    Node * prev = nullptr;
    for (int i = 0; i < (val-1); i++)
        if (i == 0)
            prev = current;
            current = current->next;
        else {
            current = current->next;
            prev = prev->next;
        }
     // at this point, delete current and reroute pointers
    if (current) {  // checks for current to be valid before deleting the node
        prev->next = current->next;
        delete current;
        current = nullptr;
    }
}
