
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
stack<T>::stack() {

}

template <typename T>
void stack<T>::push(T) {

}

template <typename T>
void stack<T>::pop() {

}

template <typename T>
T stack<T>::peak() {

}

template <typename T>
int stack<T>::size() {

}

template <typename T>
bool stack<T>::empty() {

}

template <typename T>
stack<T>::~stack() {
    delete this->data;
}

#endif