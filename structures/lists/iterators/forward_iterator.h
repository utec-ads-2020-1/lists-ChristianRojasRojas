#ifndef FORWARD_ITERATOR_H
#define FORWARD_ITERATOR_H

#include "../node.h"

// TODO: Implement all methods
template <typename T> 
class ForwardIterator {
    private:
        Node<T> *current;

    public:
        ForwardIterator(){
            this->current = nullptr;
        };

        ForwardIterator(Node<T>* ptr){
            this->current = ptr;
        };

        ForwardIterator<T> operator=(ForwardIterator<T> other){
            this->current = other;
            return this->current;
        };

        bool operator!=(ForwardIterator<T> other){
            return this->current!= other.current;
        };

        ForwardIterator<T> operator++(){
            this->current = this->current->next;
            return this->current;
        };

        T operator*(){
            return this->current->data;
        };
};

#endif