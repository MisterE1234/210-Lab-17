//COMSC-210|Lab-17|Ethan Aylard
//IDE used: Visual Studio Code
//This program demonstrates linked lists with functions.

#include <iostream>
using namespace std;

 
// Define the Node structure
// Each node contains a float value and a pointer to the next node
struct Node {
    float value;
    Node *next;
};

// Function prototypes
int menu();
int choice;
void output(Node *);
void addFront(Node *, int);
void addEnd(Node *, int);
void deleteNode(Node *, int);
void insertNode(Node *, int, int);
void deleteList(Node *);


int main() {
    const int SIZE = 7; // initial size of the linked list
    Node *head = nullptr;
    int count = 0;
    int menuNum = -1;

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
    // Menu loop
    
    while(menuNum != 0){

        // display menu and get user choice
        menuNum = menu();
        switch(menuNum){
        
            case 1: {
                // option to add a node to the front of the list
                int val;
                cout << "Enter a value to add to the front of the list: ";
                val = choice();
                addFront(head, val);
                output(head);
                break;
            }
            case 2: {
                // option to add a node to the end of the list
                int val;
                cout << "Enter a value to add to the end of the list: ";
                val = choice();
                addEnd(head, val);
                output(head);
                break;
            }
            case 3: {
                // option to delete a node from the list
                int val;
                cout << "Enter a value to delete from the list: ";
                val = choice();
                deleteNode(head, val);
                output(head);
                break;
            }
            case 4: {
                // option to insert a node after a specific value
                Node * current = head;
                count = 1;
                int afterVal, newVal;
                cout << "Enter a value to insert after: ";
                afterVal = choice();
                 while (current) {
                cout << "[" << count++ << "] " << current->value << endl;
                current = current->next;
                }

                cout << "Enter a new value to insert: ";
                newVal = choice();
                insertNode(head, afterVal, newVal);
                output(head);
                break;
            }
            case 5: {
                // option to delete the entire list
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
            // exit the program
                cout << "Exiting program." << endl;
                break;
            default:
            // handle invalid menu choice
                cout << "Invalid choice. Please try again." << endl;
        }
    }
    
    // Clean up memory before exiting
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

// Function to output the linked list
//requires a pointer to the head node and returns nothing
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

// Function to display the menu and get user choice
// returns the user's menu choice as an integer
int menu(){
    int option;
    cout << "Menu Options:\n"
         << "1. Add a node to the front of the list\n"
         << "2. Add a node to the end of the list\n"
         << "3. Delete a node from the list\n"
         << "4. Insert a node after a specific value\n"
         << "5. Delete the entire list\n"
         << "7. Display the list\n"
         << "0. Exit\n"
         << "Enter your choice: ";
    cin >> option;
    return option;
}

// Function to add a node to the front of the list
// requires a pointer to the head node and the value to add
// returns nothing
void addFront(Node * head, int val) {
    Node * newNode = new Node;
    newNode->value = val;
    newNode->next = head;
    head = newNode;
}

// Function to add a node to the end of the list
// requires a pointer to the head node and the value to add
// returns nothing
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

// Function to delete a node with a specific value from the list
// requires a pointer to the head node and the value to delete
// returns nothing
void deleteNode(Node * head, int val) {

    if (!head) return;

    if (head->value == val) {
        Node * temp = head;
        head = head->next;
        delete temp;
        return;
    }

    // traverse the list to find the node to delete
    Node * current = head;
    Node * prev = head;
    for (int i = 0; i < (val-1); i++)
        if (i == 0)
            
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

// Function to insert a new node with a specific value after a node with a given value
// requires a pointer to the head node, the value after which to insert, and the new value
// returns nothing
void insertNode(Node * head, int afterVal, int newVal) {
    Node * current = head;
    Node * prev = head;

    for (int i = 0; i < (afterVal); i++)
        if (i == 0)
            current = current->next;
        else {
            current = current->next;
            prev = prev->next;
        }
    //at this point, insert a node between prev and current
    Node * newnode = new Node;
    newnode->value = newVal;
    newnode->next = current;
    prev->next = newnode;
    
}

// Function to delete the entire linked list
// requires a pointer to the head node
// returns nothing
void deleteList(Node * head) {
    Node * current = head;
    while (current) {
        head = current->next;
        delete current;
        current = head;
    }
    head = nullptr;
}

// Function to get a valid integer choice from the user
//requires no parameters
// returns the valid integer input
int choice(){
    int entry;
    bool valid = false;
    while (!valid){
        cout << "Enter your choice: ";
        cin >> entry;
        if (!cin.fail())
            valid = true;
        else
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid choice. Please try again." << endl;
    }
    return entry;
}
