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

        BidirectionalIterator(Node<T>* ptr){ // Intenta hacerlo explicit para ver problemas
            this->current = ptr;
        };

        BidirectionalIterator<T> operator=(BidirectionalIterator<T> other){
            // Current es tipo Node y other es tipo iterator
            this->current = other;
            return this->current; // Estás retornando nuevos iteradores
        };

        bool operator!=(BidirectionalIterator<T> other){
            return this->current!= other.current;
        };

        BidirectionalIterator<T> operator++(){ // No verificas que current sea null
            this->current = this->current->next;
            return this->current;
        };

        BidirectionalIterator<T> operator--(){ // No verificas que current sea null
            this->current = this->current->prev;
            return this->current;
        };

        T operator*(){ // No verificas que current sea null
            return this->current->data;
        };
};

#endif