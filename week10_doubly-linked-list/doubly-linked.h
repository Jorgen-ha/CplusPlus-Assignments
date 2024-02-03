#ifndef __dll__
#define __dll__

#include <iostream>

using namespace std;

// Basic structure to store elements of a list
struct Node {
    int val;       // Contains the value
    Node *next;    // Pointer to the next element in the list
    Node *prev;    // Pointer to the previous element in the list
};

// Class List
class List {
public:
    List(void);        // Constructor
    ~List(void);       // Destructor
    void insert(int n);     // This should insert n in the list, using recursion
    void reverse(void);     // This should reverse the list
    void print(void);       // This should print the list
    
private:
    Node *first;              // Pointer to the first (if any) element in the list
    void deallocate(Node *n); // Deallocate memory recursively (like live code)
    void deallocate();        // Deallocate memory recursively (like live code)
    unsigned int length();    // Returns the length of the list by recursion
    unsigned int length(Node *n); // Returns the length of the list by recursion
    void insert(int n, Node *first); // This should insert n at the end of the list, using recursion
    void reverse(Node **first); // This should reverse the list, recursively
    void print(Node *first);// This should print the list recursively, separated by spaces
    
};

#endif

