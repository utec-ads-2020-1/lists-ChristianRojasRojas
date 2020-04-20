#ifndef FORWARD_H
#define FORWARD_H

#include <stdlib.h>
#include "list.h"
#include "iterators/forward_iterator.h"

// TODO: Implement all methods
template <typename T>
class ForwardList : public List<T> {
    private:
        Node<T>* nodeNum(int);
    public:
        ForwardList() : List<T>() {}

        T front();
        T back();
        void push_front(T);
        void push_back(T);
        void pop_front();
        void pop_back();
        T operator[](int);
        bool empty();
        int size();
        void clear();
        void sort();
        void reverse();

        ForwardIterator<T> begin();
	    ForwardIterator<T> end();

        string name() {
            return "Forward List";
        }

        /**
         * Merges x into the list by transferring all of its elements at their respective 
         * ordered positions into the container (both containers shall already be ordered).
         * 
         * This effectively removes all the elements in x (which becomes empty), and inserts 
         * them into their ordered position within container (which expands in size by the number 
         * of elements transferred). The operation is performed without constructing nor destroying
         * any element: they are transferred, no matter whether x is an lvalue or an rvalue, 
         * or whether the value_type supports move-construction or not.
        */
        void merge(ForwardList<T>&);
};

template <typename T>
T ForwardList<T>::front(){
    if(!empty()){
        return this->head->data;
    }
    else{
        cout << "esta vacio -> trow excep" << endl;
    }
}

template <typename T>
T ForwardList<T>::back() {
    if(!empty()){
        return this->tail->data;
    }
    else{
        cout << "esta vacio -> trow excep" << endl;
    }
}

template <typename T>
void ForwardList<T>::push_front(T data){
    Node<T>* temp = new Node<T>();
    temp->data = data;
    if(empty()){
        this->head = this->tail = temp;
        this->tail->data = this->head->data = data;
        cout << "se agrega 1 nodo a la lista vacia" << endl;
    }
    else{
        temp->next = this->head;
        this->head = temp;
        this->head->data = data;
        cout << "se agrega 1 nodo a la lista con datos" << endl;
    }
    this->nodes++;
}

template <typename T>
void ForwardList<T>::push_back(T data){
    Node<T>* temp = new Node<T>();
    temp->data = data;
    if(empty()){
        this->head = this->tail = temp;
        this->tail->data = this->head->data = data;
        cout << "se agrega 1 nodo a la lista vacia" << endl;
    }
    else{
        this->tail->next = temp;
        this->tail = temp;
        this->tail->data = data;
        this->tail->next = nullptr;
    }
    this->nodes++;
}

template <typename T>
void ForwardList<T>::pop_front(){
    if(empty()){
        cout << "esta vacio nada que borrar -> excep" << endl;
    }
    else{
        Node<T>* temp;
        temp = this->head;
        this->head = this->head->next;
        //temp->killSelf();
        delete temp;
        this->nodes--;
    }
}

template <typename T>
void ForwardList<T>::pop_back(){
    if(empty()){
        cout << "esta vacio nada que borrar -> excep" << endl;
    }
    else{
        Node<T>* temp = this->tail;
        this->tail = nodeNum(this->nodes-2);
        //temp->killSelf();
        delete temp;
        this->nodes--;
    }
}

template <typename T>
T ForwardList<T>::operator[](int position){
    if(position >= this->nodes || position < 0){
        cout << "error -> excep" << endl;
        return this->head->data; // hasta implementar except
    }
    else{
        Node<T>* temp = nodeNum(position);
        return temp->data;
    }
}

template <typename T>
bool ForwardList<T>::empty(){
    if(this->head==nullptr){
        return true;
    }
    else{
        return false;
    }
}

template <typename T>
int ForwardList<T>::size(){
    return this->nodes;
}

template <typename T>
void ForwardList<T>::clear(){
    while(this->head->next!=nullptr){
        Node<T>* temp = this->head;
        this->head = this->head->next;
        temp->killSelf();
        delete temp;
    }
    this->head->killSelf();
    this->tail->killSelf();
    delete this->head;
    delete this->tail;
}

template <typename T>
void ForwardList<T>::sort(){
    //quickSort
}

template <typename T>
void ForwardList<T>::reverse(){
    if(empty()){
        cout << "excep vacio" << endl;
    }
    else {
        Node<T>* temp = this->tail;
        for (int i = this->nodes - 1; i > 0; i--) {
            temp->next = nodeNum(i - 1);
            temp = temp->next;
        }
        temp = this->head;
        this->head = this->tail;
        this->tail = temp;
        this->tail->next = nullptr;
    }
}



template <typename T>
Node<T>* ForwardList<T>::nodeNum(int position) {
    if (position >= this->nodes || position < 0){
        cout << "except --" << position << endl;
        return this->head;
    }else{
        Node<T>* temp = this->head;
        for (int i=0; i<position;i++){
            temp = temp->next;
        }
        return temp;
    }
}

#endif