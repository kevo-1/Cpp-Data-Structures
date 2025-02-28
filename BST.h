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
    public:
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
    
    Node<T>* Successor(Node<T>* node) {
        while (node != nullptr && node->Left != nullptr)
        {
            node = node->Left;
        }
        return node;
    }

    void Delete(Node<T>*& Root,T elem) {
        if(Root == nullptr) return;

        if(elem < Root->element) {
            Delete(Root->Left, elem);
        } else if(elem > Root->element) {
            Delete(Root->Right, elem);
        } else {
            if(Root->Left == nullptr) {
                Node<T>* temp = Root->Right;
                delete Root;
                Root = temp;
            } else if (Root->Right == nullptr) {
                Node<T>* temp = Root->Left;
                delete Root;
                Root = temp;
            } else {
                Node<T>* succ = Successor(Root->Right);
                Root->element = succ->element;
                Delete(Root->Right,succ->element);
            }
        }
    }

    bool Search(T elem, Node<T>* Root) {
        if(Root == nullptr) {
            return false;
        }
        if(Root->element == elem) {
            return true;
        }
        return elem < Root->element ? Search(elem, Root->Left) : Search(elem, Root->Right);
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
