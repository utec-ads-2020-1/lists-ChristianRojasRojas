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
        void imprimir();

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
        throw "this list is empty, cannot give back (front) any data";
    }
}

template <typename T>
T ForwardList<T>::back() {
    if(!empty()){
        return this->tail->data;
    }
    else{
        throw "this list is empty, cannot give back (back) some data";
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
        throw "this list is empty, cannot delete front";
    }
    else{
        Node<T>* temp;
        temp = this->head;
        this->head = this->head->next;
        temp->killSelf();
        delete temp;
        this->nodes--;
    }
}

template <typename T>
void ForwardList<T>::pop_back(){
    if(empty()){
        throw "this list is empty, cannot delete back";
    }
    else{
        Node<T>* temp = this->tail;
        this->tail = nodeNum(this->nodes-2);
        this->tail->next = nullptr;
        temp->killSelf();
        delete temp;
        this->nodes--;
    }
}

template <typename T>
T ForwardList<T>::operator[](int position){
    if(position >= this->nodes || position < 0){
        throw "invalid position in position search data";
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
        this->nodes--;
    }
    this->head->killSelf();
    delete this->head;
    this->nodes--;
}

template <typename T>
void ForwardList<T>::sort(){
    if(empty()){
        throw "this list is empty, cannot be sort";
    }
    else{
        Node<T>* temp = this->head;
        Node<T>* temp2 = this->head->next;
        for (int i=0; i < this->nodes-1; i++){
            while(temp2!=nullptr){
                if(temp->data > temp2->data){
                    swapData(temp->data,temp2->data);
                }
                temp2 = temp2->next;
            }
            temp = temp->next;
            temp2 = temp->next;
        }
    }
}

template <typename T>
void ForwardList<T>::reverse(){
    if(empty()){
        throw "this list is empty, cannot reverse this list";
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
void ForwardList<T>::merge(ForwardList<T>& addList) {
    if (empty() && addList.empty()){
        cout <<  "both list empty" << endl;
    }
    else if (empty()){
        this->head = addList.head;
        this->tail = addList.tail;
    }
    else if(addList.empty()){
        cout << "nada por hacer lista de agregacion vacia" << endl;
    }
    else {
        this->tail->next = addList.head;
        this->tail = addList.tail;
    }
    this->nodes+=addList.size();
}



template <typename T>
Node<T>* ForwardList<T>::nodeNum(int position) {
    if (position >= this->nodes || position < 0){
        throw "invalid position in search position";
    }else{
        Node<T>* temp = this->head;
        for (int i=0; i<position;i++){
            temp = temp->next;
        }
        return temp;
    }
}

template <typename T>
void ForwardList<T>::imprimir() {
    Node<T>* temp = this->head;
    while(temp!=nullptr) {
        cout << temp->data << "  ";
        temp = temp->next;
    }
    cout << endl;
}

#endif