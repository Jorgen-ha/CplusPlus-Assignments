#include "doubly-linked.h"
#include <cmath>

List::List(){ // Constructor
    first = nullptr;
}  

List::~List(){ // Destructor
    deallocate();
} 

void List::deallocate(Node *node){ // Deallocate memory recursively (like live code)
    if (node != nullptr){
        deallocate(node->next);
        delete node;
    }
}

void List::deallocate(){ // Deallocate memory recursively (like live code)
    deallocate(first);
    first = nullptr;
}

unsigned int List::length(){         // Returns the length of the list by recursion
    return length(first);
}

unsigned int List::length(Node *node){  // Returns the length of the list by recursion
    if (node == nullptr){
        return 0;
    }
    else{
        return 1 + length(node->next);
    }
}

void List::insert(int n){  // This should insert n at the end of the list, using recursion
    if (length() == 0){ // List is empty, assign value to first
        first = new Node;
        first->val = n;
        first->next = nullptr;
        first->prev = nullptr;
    }
    else{
        insert(n, first);
    }
} 

void List::insert(int n, Node *node){  // This should insert n at the end of the list, using recursion
    if (node->next == nullptr){       // Arrived at the end or empty list
        Node *newNode = new Node;
        newNode->val = n;
        newNode->next = nullptr;
        newNode->prev = node;
        node->next = newNode;
        return;
    }
    // if not at the end, go to next node
    insert(n, node->next);
}

void List::reverse(void){  // This should reverse the list, recursively
    if (length() == 0){
        return;     // Nothing to reverse
    }else{
        reverse(&first);
    }
}
/// @brief Recursively reverses the list, using a double pointer
/// @param node 
/// double pointer necessary in order to update the first pointer
void List::reverse(Node **node){  // This should reverse the list, recursively
    Node* first;
    Node* rest;

    if (*node == nullptr){
        return;     // end or empty list
    }

    first = *node;
    rest = first->next;

    if (rest == nullptr){
        return;     // only one element in list
    }

    reverse(&rest);
    first->next->next = first;
    first->next = nullptr;
    *node = rest;
}

void List::print(void){    // This should print the list recursively, separated by spaces
    print(first);
}

void List::print(Node *node){  // This should print the list recursively, separated by spaces
    if (node != nullptr){
        cout << node->val << " ";
        print(node->next);
    }else {
        cout << endl;
    }
}