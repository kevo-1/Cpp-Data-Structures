#include <iostream>

template <typename T> class Stack{
    protected:
    T* store;
    int ind = 0;
    int cap = 1;

    public:
    Stack():store(nullptr),ind(0),cap(1){
        store = new T [cap];
    };

    void push_ontop(const T& item){
        T* temp = new T [cap+1];
        for (int i = 0; i < cap; i++)
        {
            temp[i] = store[i];
        }
        temp[cap-1] = item;
        delete [] store;
        store = temp;
        cap+=1;
    }

    void pop_off(){
        if(cap <= 1){
            throw std::invalid_argument("stack is already empty");
        }
        T* temp = new T [cap-1];
        for (int i = 0; i < cap - 1; i++)
        {
            temp[i] = store[i];
        }
        delete [] store;
        store = temp;
        cap-=1;
    }

    T Top(){
        if(cap > 1)
            return store[cap-2];
        else
            throw std::invalid_argument("Stack is empty");
    }

    int Get_size(){
        return cap - 1;
    }

    bool Empty(){
        if(cap == 1){
            return true;
        }
        else{
            return false;
        }
    }
};