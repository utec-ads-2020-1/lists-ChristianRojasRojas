#ifndef LINKED_H
#define LINKED_H

#include "list.h"
#include "iterators/bidirectional_iterator.h"
using namespace std;

// TODO: Implement all methods
template <typename T>
class LinkedList : public List<T> {
    private:
        Node<T>* nodeNum(int);
        Node<T>* sentinel;
    public:
        LinkedList() : List<T>() {}
        ~LinkedList();
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

        BidirectionalIterator<T> begin();
	    BidirectionalIterator<T> end();

        string name() {
            return "Linked List";
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
        void merge(LinkedList<T>&);
};

template <typename T>
T LinkedList<T>::front(){
    if(!empty()){
        return this->head->data;
    }
    else{
        throw "this list is empty, cannot give back (front) any data";
    }
}

template <typename T>
T LinkedList<T>::back(){
    if(!empty()){
        return this->tail->data;
    }
    else{
        throw "this list is empty, cannot give back (back) any data";
    }
}

template <typename T>
void LinkedList<T>::push_front(T data){
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
        this->head = temp;
        this->head->data = data;
        cout << "se agrega 1 nodo a la lista con datos" << endl;
    }
    this->nodes++;
}

template <typename T>
void LinkedList<T>::push_back(T data){
    Node<T>* temp = new Node<T>();
    temp->data = data;
    if(empty()){
        this->head = this->tail = temp;
        this->tail->data = this->head->data = data;
        cout << "se agrega 1 nodo a la lista vacia" << endl;
    }
    else{
        temp->prev = this->tail;
        this->tail->next = temp;
        this->tail = temp;
        this->tail->data = data;
        cout << "se agrega 1 nodo a la lista con datos" << endl;
    }
    this->nodes++;
}

template <typename T>
void LinkedList<T>::pop_front(){
    if(empty()){
        cout << "this list is empty, cannot delete front" << endl;
    }
    else{
        Node<T>* temp;
        temp = this->head;
        this->head = this->head->next;
        this->head->prev = nullptr;
        temp->killSelf();
        delete temp;
        this->nodes--;
    }
}

template <typename T>
void LinkedList<T>::pop_back(){
    if(empty()){
        cout << "this list is empty, cannot delete back" << endl;
    }
    else{
        Node<T>* temp = this->tail;
        this->tail = this->tail->prev;
        this->tail->next = nullptr;
        temp->killSelf();
        delete temp;
        this->nodes--;
    }
}

template <typename T>
T LinkedList<T>::operator[](int position){
    if(position >= this->nodes || position < 0){
        throw "invalid position in position search data";
    }
    else{
        Node<T>* temp = nodeNum(position);
        return temp->data;
    }
}

template <typename T>
bool LinkedList<T>::empty(){
    return this->head==nullptr;
}

template <typename T>
int LinkedList<T>::size(){
    return this->nodes;
}

template <typename T>
void LinkedList<T>::clear(){
    while(this->head->next!=nullptr){
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
void LinkedList<T>::sort(){
    if(empty()){
        cout << "this list is empty, cannot be sort" << endl;
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
void LinkedList<T>::reverse(){
    if(empty()){
        cout << "this list is empty, cannot reverse this list" << endl;
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
        this->tail->next = nullptr;
        this->head->prev = nullptr;
    }
}

template <typename T>
void LinkedList<T>::merge(LinkedList<T>& addList) {
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
        addList.head->prev = this->tail;
        this->tail = addList.tail;
    }
    this->nodes+=addList.size();
}

template <typename T>
BidirectionalIterator<T> LinkedList<T>::begin() {
    if (empty()){
        throw "list empty, cannot return any ptr (begin)";
    }
    else {
        this->head->prev = this->sentinel;
        this->sentinel->next = this->head;
        this->sentinel->prev = this->tail;
        this->tail->next = this->sentinel;
        auto ptr = BidirectionalIterator<T>(this->sentinel->next); // o head: Está bien
        return ptr;
    }
}

template <typename T>
BidirectionalIterator<T> LinkedList<T>::end() {
    if (empty()){
        throw "list empty, cannot return any ptr (end)";
    }
    else {
        this->head->prev = this->sentinel;
        this->sentinel->next = this->head;
        this->sentinel->prev = this->tail;
        this->tail->next = this->sentinel;
        auto ptr = BidirectionalIterator<T>(this->tail->next); // o sentinel: sentinel
        return ptr;
    }
}

template <typename T>
Node<T>* LinkedList<T>::nodeNum(int position) {
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

template <typename T>
void LinkedList<T>::imprimir() {
    Node<T>* temp = this->head;
    while(temp!=nullptr) {
        cout << temp->data << "  ";
        temp = temp->next;
    }
    cout << endl;
}

template <typename T>
LinkedList<T>::~LinkedList(){
    clear();
    this->sentinel->killSelf();
    delete sentinel;
}
#endif