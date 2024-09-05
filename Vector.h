#include <iostream>

template <typename T> class Vector{
    
    protected:
        T* store;
        int capacity;
        int slots;

    public:
        Vector(int n = 1):store(nullptr),capacity(n),slots(0){
            store = new T [capacity];
        }

        Vector(std::initializer_list<T> elements):capacity(elements.size()),slots(0){
            store = new T [capacity];
            for( const auto& item : elements){
                store[slots++] = item;
            }
        }

        ~Vector(){
            delete [] store;
        }

        void push_into(const T& item) {
            if (slots == capacity) {
                resize(capacity);
            }
            store[slots++] = item;
        } 

        T& operator [](int index){
            if(index >= slots){
                std::cout<<"out of index"<<std::endl;
                exit(0);
            }
            return store[index];
        }

        /*used to copy elements from one vec to another*/
        Vector& operator=(const Vector& otherVec) {
            if (this != &otherVec) {
                delete[] store;  
                capacity = otherVec.capacity;
                slots = otherVec.slots;
                store = new T[capacity];
                for (int i = 0; i < slots; i++) {
                    store[i] = otherVec.store[i];
                }
            }
            return *this;
        }

        /*leaves the second vec in an unusable state and moves it's content to the Lvalue vec*/
        Vector& operator=(Vector&& other)noexcept{
            if(this != &other){
                delete[] store;

                capacity = other.capacity;
                slots = other.slots;
                store = other.store;

                //now we make other usable again :)
                other.capacity = 0;
                other.slots = 0;
                other.store = nullptr;
            }
            return *this;
        }

        /*resizes the vector to the specified size*/
        void resize(int new_size){
            T* temp = new T [new_size*2];
            for (int i = 0; i < (new_size < slots ? new_size : slots ); i++)
            {
                temp[i] = store[i];
            }
            delete[] store;
            store = temp;
            capacity = new_size*2;
            if(slots > new_size){
                slots = new_size;
            }
        }
        
        /*removes the last element and returns it*/
        T pop_last(){
            T to_return = store[slots-1];
            slots--;
            return to_return;
        }

        /*returns the number of elements stored*/
        int length(){
            return slots;
        }
        
        /*used to return first element in Vector*/
        T front(){
            if(slots == 0){
                throw std::invalid_argument("No elements to show");
            }
            return store[0];
        }

        /*used to return last element in Vector*/
        T last(){
            if(slots == 0){
                throw std::invalid_argument("No elements to show");
            }
            return store[slots-1];
        }
        
        /*used to remove an element at the specified 1-based index*/
        void remove_element(int index){
            if(index-1 == slots){
                throw std::invalid_argument("that index is out of range!");
            }
            for (int i = index-1; i < slots; i++)
            {
                store[i] = store[i+1];
            }
            slots--;
        }

        /*removes elements between start (inclusive) and end (exclusive) 1-based index*/
        void remove_range(const int start , const int end){
            if((end <= start) || (end > slots) || (start <= 0)){
                throw std::invalid_argument("Invalid Range!");
            }
            for (int i = 0; i < slots-(end-start); i++)
            {
                if(end+i-1 < slots){
                    store[start-1+i] = store[end-1+i];
                }
            }
            slots -= (end-start);
        }

        void clear(){
            slots = 0;
        }

        /*fill with the value specified in the range between start (inclusive) and end (exclusive)*/
        void fill(const int start , const int end , const T& value){
            if((end <= start) || (end > slots) || (start <= 0)){
                throw std::invalid_argument("Invalid Range!");
            }
            for (int i = start-1; i < end; i++)
            {
                store[i] = value;
            }
        }
};
