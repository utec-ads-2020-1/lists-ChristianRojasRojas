
#ifndef STACK_H
#define STACK_H

using namespace std;

#define MAX 1000

// TODO: Implement all methods
template <typename T>
class stack{
    T* data;
    int top;
    int capacity;

public:
    stack(int size = MAX);
    ~stack();

    void push(T);
    void pop();
    T peak();

    int size();
    bool empty();
};

template <typename T>
stack<T>::stack(int size) {
    capacity = size;
    data = new T[capacity];
    top = 0;
}

template <typename T>
void stack<T>::push(T data) {
    if (top == capacity){
        capacity *= 2;
        T* newArray = new T[capacity];
        for (int i=0;i < top; i++){
            newArray[i] = this->data[i];
        }
        this->data = newArray;
    }
    this->data[top] = data;
    top++;
}

template <typename T>
void stack<T>::pop() {
    if (!empty()){
        this->data[top-1] = 0;
        top--;
    }
}

template <typename T>
T stack<T>::peak() {
    if (!empty()){
        return this->data[top-1];
    }
    else{
        throw "there are not data in this list";
    }
}

template <typename T>
int stack<T>::size() {
    return this->top;
}

template <typename T>
bool stack<T>::empty() {
    return this->top==0;
}

template <typename T>
stack<T>::~stack() {
    delete this->data;
}

#endif