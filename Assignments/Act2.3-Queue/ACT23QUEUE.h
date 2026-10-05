#ifndef ACT23QUEUE_H
#define ACT23QUEUE_H
#include <string>
#include "Node.h"

struct Cliente{
    std::string nombre;
    int boletos;
};

template <typename T>
class Queue{
    private:
        Node<T>* head;
         Node<T>* tail;
    public:
    Queue();
    Queue(head, tail);
    void pop();
    void push(T data);
    void front();
};

#endif