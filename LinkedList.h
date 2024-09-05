/*
A linked list consists of multiple nodes connected to each other 
each node carries 2 parameters:
value, address for next node
in some cases there maybe a two way connection where you can go to next node or previous if there was any

Tasks:
1- make a simple uni-directional implementation\
2- start implementing two directional nodes
*/

#include <iostream>

//Node class
template<typename T>
class node {
    public:
    T data;
    node<T>* next;  //a node pointer for the next node

    node(T value): data(value),next(nullptr){}
};


template<typename T> class LinkedList {
    node<T>* head;
    node<T>* tail;

    public:
    LinkedList():head(nullptr),tail(nullptr){}

    void add_head(const T& value) {
        node<T>* temp = new node<T>(value);
        temp->next = head;
        head = temp;
    }

    void remove_head() {
        if(head == nullptr) {
            std::cout<<"List is empty!\n";
            return;
        }
        node<T>* temp = head;
        if(head->next != nullptr ) {
            head = head->next;
        }else {
            head = tail = nullptr;
        }
        
        delete temp;
    }

    void add_to_list(const T& value) {
        node<T>* TempNode = new node<T>(value);
        if(head == nullptr) {
            head = tail = TempNode;
        } else {
            tail->next = TempNode;
            tail = TempNode;
        }
    }

    void remove_from_list(const T& value) {
        node<T>* current = head;
        node<T>* before = nullptr;
        while(current != nullptr) {
            if(current->data == value) {
                if(before != nullptr) {
                    before->next = current->next;
                } else {
                    head = current->next;
                }
                delete current;
                return;
            }
            before = current;
            current = current->next;
        }
    }

    void display_list(){
        if(head == nullptr) {
            throw("List is empty!");
        }
        node<T>* temp = head;
        std::cout<<"Your List:\n";
        while(temp != nullptr) {
            std::cout<<temp->data<<" ";
            temp = temp->next;
        }
        std::cout<<"Null\n";
    }
};