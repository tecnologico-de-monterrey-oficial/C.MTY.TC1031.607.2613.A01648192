// ACT23Queue.h
#ifndef QUEUE_H
#define QUEUE_H
#include "ACT21LinkedList.h"
#include <stdexcept>

template <typename T>
class Queue{
    private:
        LinkedList<T> lista;
    public:
        T dequeue(); 
        void enqueue(T data);
        T front();
        int size();
        bool isEmpty();
};

template <typename T>
T Queue<T>::dequeue(){
    if(lista.getSize()>0){
        return lista.removeFirst();
    }
    throw std::out_of_range("El Queue esta vacio. No se puede hacer dequeue.");
}

template <typename T>
void Queue<T>::enqueue(T data){
    lista.addLast(data);
}

template <typename T>
T Queue<T>::front(){
    if(lista.getSize()>0){
        return lista.getData(0)->data;
    }
    throw std::out_of_range("El Queue esta vacio.");
}

template <typename T>
int Queue<T>::size(){
    return lista.getSize();
}

template <typename T>
bool Queue<T>::isEmpty(){
    return lista.getSize()==0;
}
#endif