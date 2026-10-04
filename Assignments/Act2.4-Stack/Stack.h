#ifndef STACK_H
#define STACK_H

template <typename T>
class Stack{
    private:
        Node<T>* top;
        int size;
    public:
        Stack(): top(nullptr), size(0){}
        void remove();
        void add(T data);
        Node<T>* getFast();
        void print();
};

#endif