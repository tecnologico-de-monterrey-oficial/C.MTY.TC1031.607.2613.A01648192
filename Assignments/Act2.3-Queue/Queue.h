#ifndef QUEUE_H
#define QUEUE_H

#include "Node.h"

template <typename T>
class Queue{
    private:
        Node<T>* tail,
            head;
        int size;
    public:
        Queue(): head(nullptr), size(0) {}
        void remove(T data);
        void add(T data);
        Node<T>* getFast();
        void print();
};

template <typename T>


#endif