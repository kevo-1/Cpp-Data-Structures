template<typename T> class Node {
    public:
        T element;
        Node<T>* Left;
        Node<T>* Right;
        int height; //still not in use until the AVL tree is implemented.
        Node(T value, int height = 1):element(value),height(height),Left(nullptr),Right(nullptr){};
};

#include <iostream>

template <typename T> class BST {
    protected:
        Node<T>* Root;
    
    public:
    BST() {
        Root = nullptr;
    }

    ~BST() {
        DeleteNode(Root);
    }

    void Insert(T elem) {
        InsertHelper(elem, Root);
    }

    /*Display BST in 3 different ways (1-InOrder [left, root, right], 2-PreOrder [root, left, right], 3-PostOrder [left, right, root])*/
    void DisplayTree(int choice) {
        switch (choice) {
        case 1:
            InOrder(Root);
            break;
        case 2:
            PreOrder(Root);
            break;
        case 3:
            PostOrder(Root);
            break;
        default:
            throw std::invalid_argument("Not a valid display choice");
        }
    }

    private:
    void InsertHelper(T elem, Node<T>*& node) {
        if(node == nullptr) {
            node = new Node<T>(elem);
            return;
        }
        if(elem > node->element) {
            InsertHelper(elem, node->Right);
        } else {
            InsertHelper(elem, node->Left);
        }
    }

    void InOrder(Node<T>* node) {
        if(node == nullptr) return;
        InOrder(node->Left);
        std::cout<<node->element<<" ";
        InOrder(node->Right);
    }

    void PreOrder(Node<T>* node) {
        if(node == nullptr) return;
        std::cout<<node->element<<" ";
        PreOrder(node->Left);
        PreOrder(node->Right);
    }

    void PostOrder(Node<T>* node) {
        if(node == nullptr) return;
        PostOrder(node->Left);
        PostOrder(node->Right);
        std::cout<<node->element<<" ";
    }

    void DeleteNode(Node<T>* node) {
        if(node == nullptr) return;
        DeleteNode(node->Left);
        DeleteNode(node->Right);
        delete node;
    }
};