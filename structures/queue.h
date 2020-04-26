#ifndef QUEUE_H
#define QUEUE_H

using namespace std;

#define MAX 1000

// TODO: Implement all methods
template <typename T>
class queue {
    T* data;
    int top;
    int capacity;

public:
    queue(int size = MAX);
    ~queue();

    void push(T);
    void pop();
    T front();
    T back();

    int size();
    bool empty();
};

template <typename T>
queue<T>::queue(int size) {
    capacity = size;
    data = new T[capacity];
    top = 0;
}

template <typename T>
void queue<T>::push(T data) {
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
void queue<T>::pop() {
    if (!empty()){
        if (top != 1) {
            T *newArray = new T[capacity];
            for (int i = 0; i < top - 1; i++) {
                newArray[i] = this->data[i + 1];
            }
            this->data = newArray;
        }
        else{
            data[0] = 0;
        }
        top--;
    }
}

template <typename T>
T queue<T>::front() {
    if (!empty()){
        return this->data[0];
    }
    else{
        throw "list empty";
    }
}

template <typename T>
T queue<T>::back() {
    if (!empty()){
        return this->data[top-1];
    }
    else{
        throw "list empty";
    }
}

template <typename T>
int queue<T>::size() {
    return this->top;
}

template <typename T>
bool queue<T>::empty() {
    return this->top==0;
}

template <typename T>
queue<T>::~queue() {
    delete this->data;
}

#endif
