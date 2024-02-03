#include "Fib-tree.h"
#include <cmath>


FibTree::FibTree(){ // Constructor
    root = nullptr;
}  

FibTree::~FibTree(){ // Destructor
    deallocate();
} 

void FibTree::deallocate(Leaf *node){ // Deallocate memory recursively (like live code)
    if (node != nullptr){
        deallocate(node->left);
        deallocate(node->right);
        delete node;
    }
}

void FibTree::deallocate(){ // Deallocate memory recursively (like live code)
    deallocate(root);
    root = nullptr;
}

unsigned int FibTree::size(){         // Returns the size (number of elements) of the tree by recursion
    return size(root);
}

unsigned int FibTree::size(Leaf *node){  // Returns the size of the list by recursion
    if (node == nullptr){
        return 0;
    }
    else{
        return 1+(size(node->left) + size(node->right));
    }
}

unsigned int FibTree::depth(){            // Returns the depth/height of the tree by recursion
    return depth(root);
}

unsigned int FibTree::depth(Leaf *node){     // Returns the depth of the tree by recursion
    if (node == nullptr){
        return 0;
    }
    else{
        return 1 + max(depth(node->left), depth(node->right));
    }
}

unsigned int FibTree::leafs(){            // Returns the leafs of the tree by recursion
    return leafs(root);
}

unsigned int FibTree::leafs(Leaf *node){     // Returns the leafs of the tree by recursion
    if (node == nullptr){
        return 0;
    }
    else if (node->left == nullptr && node->right == nullptr){
        return 1;
    }
    else{
        return leafs(node->left) + leafs(node->right);
    }
}

unsigned int FibTree::fibonacci(int n){
        if (n == 0){
            return 1;
        }else if (n == 1){
            return 1;
        }else{
            return fibonacci(n - 1) + fibonacci(n - 2);
        }
    }

void FibTree::insertFib(int n, Leaf *node){
    if (n == 0){
        node->val = 1;
        node->left = nullptr;
        node->right = nullptr;
    }else if (n == 1){
        node->val = 1;
        node->left = nullptr;
        node->right = nullptr;
    }else{
        node->val = fibonacci(n);
        node->left = new Leaf;
        node->right = new Leaf;
        insertFib(n - 1, node->left);
        insertFib(n - 2, node->right);
    }
}

void FibTree::buildTree(int n){
    root = new Leaf;
    root->val = n;
    root->left = nullptr;
    root->right = nullptr;
    insertFib(n, root);
}
    

void FibTree::printOrder(void){    // This should print the tree recursively, separated by spaces
    cout << "Call tree in pre-order: ";
    printOrder(root);
    cout << endl;
}

void FibTree::printOrder(Leaf *node){  // This should print the tree recursively, separated by spaces
    if (node != nullptr){
        cout << node->val << " ";
        printOrder(node->left);
        printOrder(node->right);
    }
}

void FibTree::printAll(){
    printOrder();
    cout << "Call tree size: " << size() << endl;
    cout << "Call tree depth: " << depth() << endl;
    cout << "Call tree leafs: " << leafs() << endl;
}