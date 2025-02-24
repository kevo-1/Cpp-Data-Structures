#include <iostream>
#include "BST.h"

int main(){
    BST<int> tree;

    tree.Insert(50);
    tree.Insert(30);
    tree.Insert(70);
    tree.Insert(20);
    tree.Insert(40);
    tree.Insert(60);
    tree.Insert(80);

    std::cout << "InOrder Traversal: ";
    tree.DisplayTree(1); // Should print: 20 30 40 50 60 70 80

    std::cout << "\nPreOrder Traversal: ";
    tree.DisplayTree(2); // Should print: 50 30 20 40 70 60 80

    std::cout << "\nPostOrder Traversal: ";
    tree.DisplayTree(3); // Should print: 20 40 30 60 80 70 50

    return 0;
}