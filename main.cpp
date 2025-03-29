#include <iostream>
// #include "BST.h"
#include "Trie.h"

int main(){
    // BST<int> tree;
    // tree.Insert(50);
    // tree.Insert(30);
    // tree.Insert(70);
    // tree.Insert(20);
    // tree.Insert(40);
    // tree.Insert(60);
    // tree.Insert(80);

    // std::cout << "InOrder Traversal: ";
    // tree.DisplayTree(1); // Should print: 20 30 40 50 60 70 80

    // std::cout << "\nPreOrder Traversal: ";
    // tree.DisplayTree(2); // Should print: 50 30 20 40 70 60 80

    // std::cout << "\nPostOrder Traversal: ";
    // tree.DisplayTree(3); // Should print: 20 40 30 60 80 70 50
    
    // std::cout<< (tree.Search(50, tree.Root)?"50 is found":"50 is Not found") << '\n';
    // std::cout<< (tree.Search(90, tree.Root)?"90 is found":"90 is Not found") << '\n';
    // tree.Delete(tree.Root, 50);
    // tree.DisplayTree(2);
    Trie tri;
    tri.insertWord("cat");
    tri.insertWord("car");
    tri.insertWord("card");
    tri.insertWord("carton");
    tri.insertWord("cart");
    tri.insertWord("cardi");
    tri.insertWord("N");
    tri.insertWord("Ni");
    tri.insertWord("Nin");
    tri.insertWord("Ninj");
    tri.insertWord("Ninja");
    tri.insertWord("Ninjb");
    tri.insertWord("Ninjc");
    tri.displayTrie();
    return 0;
}
