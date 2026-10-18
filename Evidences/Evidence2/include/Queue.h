#ifndef ACT23QUEUE_H
#define ACT23QUEUE_H
#include "ACT21LinkedList.h"
#include <stdexcept>

template <typename T>
class Queue{
    private:
        LinkedList<T> lista;
    public:
        T pop();
        void push(T data);
        T front();
        int getSize();
        bool isEmpty();
};

template <typename T>
T Queue<T>::pop(){
    if(lista.getSize()>0){
        return lista.removeFirst();
    }
    throw std::out_of_range("El Queue esta vacio.");
}

template <typename T>
void Queue<T>::push(T data){
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
int Queue<T>::getSize(){
    return lista.getSize();
}

template <typename T>
bool Queue<T>::isEmpty(){
    return lista.getSize()==0;
}
#endif