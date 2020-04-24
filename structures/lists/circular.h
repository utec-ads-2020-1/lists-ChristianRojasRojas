#ifndef CIRCULAR_H
#define CIRCULAR_H

#include "list.h"
#include "iterators/bidirectional_iterator.h"
using namespace std;

// TODO: Implement all methods
template <typename T>
class CircularLinkedList : public List<T> {
    private:
        Node<T>* nodeNum(int);
    public:
        CircularLinkedList() : List<T>() {}

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

        BidirectionalIterator<T> begin();
	    BidirectionalIterator<T> end();

        string name() {
            return "Circular Linked List";
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
        void merge(CircularLinkedList<T>&);
};



template <typename T>
T CircularLinkedList<T>::front(){
    if(!empty()){
        return this->head->data;
    }
    else{
        throw "this list is empty, can't give back (front) any data";
    }
}

template <typename T>
T CircularLinkedList<T>::back(){
    if(!empty()){
        return this->tail->data;
    }
    else{
        throw "this list is empty, can't give back (back) any data";
    }
}

template <typename T>
void CircularLinkedList<T>::push_front(T data){
    Node<T>* temp = new Node<T>();
    temp->data = data;
    if(empty()){
        this->head = this->tail = temp;
        this->tail->data = this->head->data = data;
        cout << "se agrega 1 nodo a la lista vacia" << endl;
    }
    else{
        temp->next = this->head;
        this->head->prev = temp;
        temp->prev = this->tail;
        this->tail->next = temp;
        this->head = temp;
        this->head->data = data;
        cout << "se agrega 1 nodo a la lista con datos" << endl;
    }
    this->nodes++;
}

template <typename T>
void CircularLinkedList<T>::push_back(T data){
    Node<T>* temp = new Node<T>();
    temp->data = data;
    if(empty()){
        this->head = this->tail = temp;
        this->tail->data = this->head->data = data;
        cout << "se agrega 1 nodo a la lista vacia" << endl;
    }
    else{
        temp->prev = this->tail;
        temp->next = this->head;
        this->head->prev = temp;
        this->tail->next = temp;
        this->tail = temp;
        this->tail->data = data;
        cout << "se agrega 1 nodo a la lista con datos" << endl;
    }
    this->nodes++;
}

template <typename T>
void CircularLinkedList<T>::pop_front(){
    if(empty()){
        throw "this list is empty, can't delete front";
    }
    else{
        Node<T>* temp;
        temp = this->head;
        this->head = this->head->next;
        this->head->prev = this->tail;
        this->tail->next = this->head;
        temp->killSelf();
        delete temp;
        this->nodes--;
    }
}

template <typename T>
void CircularLinkedList<T>::pop_back(){
    if(empty()){
        throw "this list is empty, can't delete back";
    }
    else{
        Node<T>* temp = this->tail;
        this->tail = this->tail->prev;
        this->tail->next = this->head;
        this->head->prev = this->tail;
        temp->killSelf();
        delete temp;
        this->nodes--;
    }
}

template <typename T>
T CircularLinkedList<T>::operator[](int position){
    if(position >= this->nodes || position < 0){
        throw "invalid position in position search data";
    }
    else{
        Node<T>* temp = nodeNum(position);
        return temp->data;
    }
}

template <typename T>
bool CircularLinkedList<T>::empty(){
    if(this->head==nullptr){
        return true;
    }
    else{
        return false;
    }
}

template <typename T>
int CircularLinkedList<T>::size(){
    return this->nodes;
}

template <typename T>
void CircularLinkedList<T>::clear(){ //falta solucionar el clear -> tengo que solucionar el node->keillself();
    while(this->head!=this->tail){
        Node<T>* temp = this->head;
        this->head = this->head->next;
        temp->killSelf();
        delete temp;
        this->nodes--;
    }
    this->head->killSelf();
    this->tail->killSelf();
    delete this->head;
    this->nodes--;
}

template <typename T>
void CircularLinkedList<T>::sort(){
    //falta
}

template <typename T>
void CircularLinkedList<T>::reverse(){
    if(empty()){
        throw "this list is empty, can't reverse this list";
    }
    else {
        Node<T>* temp = this->tail;
        Node<T>* temp2 = this->tail;
        Node<T>* tempBack = this->tail->prev;
        this->tail = this->head;
        this->head = temp;
        this->head->next = this->head->prev;
        while(temp!=this->tail){
            temp->next = tempBack;
            temp = temp->next;
            tempBack = tempBack->prev;
            temp->prev = temp2;
            temp2 = temp2->next;
        }
        this->tail->next = this->head;
        this->head->prev = this->tail;
    }
}



template <typename T>
Node<T>* CircularLinkedList<T>::nodeNum(int position) {
    if (position >= this->nodes || position < 0){
        throw "invalid position in search position";
    }else{
        int direccion = 0;
        if (this->size()/2 < position){
            direccion=1;
        }
        Node<T>* temp;
        if (direccion == 0){
            temp = this->head;
            for (int i=0; i<position;i++){
                temp = temp->next;
            }
            return temp;
        }else{
            temp = this->tail;
            for (int i=this->size()-1; i>position;i--){
                temp = temp->prev;
            }
            return temp;
        }
    }
}

#endif