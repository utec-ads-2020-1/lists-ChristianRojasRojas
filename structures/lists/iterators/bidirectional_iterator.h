#ifndef BIDIRECTIONAL_ITERATOR_H
#define BIDIRECTIONAL_ITERATOR_H

#include "../node.h"

// TODO: Implement all methods
template <typename T> 
class BidirectionalIterator {
    private:
        Node<T> *current;

    public:
        BidirectionalIterator(){
            this->current = nullptr;
        };

        BidirectionalIterator(Node<T>* ptr){
            this->current = ptr;
        };

        BidirectionalIterator<T> operator=(BidirectionalIterator<T> other){
            this->current = other;
            return this->current;
        };

        bool operator!=(BidirectionalIterator<T> other){
            return this->current!= other.current;
        };

        BidirectionalIterator<T> operator++(){
            this->current = this->current->next;
            return this->current;
        };

        BidirectionalIterator<T> operator--(){
            this->current = this->current->prev;
            return this->current;
        };

        T operator*(){
            return this->current->data;
        };
};

#endif