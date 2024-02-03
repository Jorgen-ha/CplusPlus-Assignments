#ifndef __fibtree__
#define __fibtree__

#include <iostream>

using namespace std;

struct Leaf {
    int val;       // Contains the numeric value
    Leaf *left;    // Pointer to the left subtree
    Leaf *right;   // Pointer to the right subtree
};


// Class Fibonacci tre
class FibTree {
public:
    FibTree(void);         // Constructor
    ~FibTree(void);        // Destructor
    void buildTree(int n); // This should insert n in the tree
    void printAll(void); // This should print the tree
    
private:
    Leaf *root;                        // Pointer to the root (if any) element in the list
    void deallocate(Leaf *n);          // Deallocate memory recursively (like live code)
    void deallocate();                 // Deallocate memory recursively (like live code)
    unsigned int size();               // Returns the size of the list by recursion
    unsigned int size(Leaf *n);        // Returns the size of the list by recursion
    unsigned int depth();            // Returns the depth of the tree by recursion
    unsigned int depth(Leaf *n);     // Returns the depth of the tree by recursion
    unsigned int leafs();            // Returns the leafs of the tree by recursion
    unsigned int leafs(Leaf *n);     // Returns the leafs of the tree by recursion
    unsigned int fibonnaci(int n);   // Returns the n-th fibonacci number
    void insertFib(int n, Leaf *node); // This should insert n in the tree, using recursion
    void printOrder(Leaf *node);       // This should print the tree recursively, separated by spaces
    void printOrder(void);             // This should print the tree recursively, separated by spaces
    
};

#endif
