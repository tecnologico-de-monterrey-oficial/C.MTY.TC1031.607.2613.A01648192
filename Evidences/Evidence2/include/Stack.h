#ifndef STACK_H
#define STACK_H
#include "ACT21LinkedList.h"
#include <stdexcept>

template <typename T>
class Stack{
    private:
        LinkedList<T> lista;
    public:
        T pop();
        void push(T data);
        T peek();
        int size();
        bool isEmpty();
};

template <typename T>
T Stack<T>::pop(){
    if(lista.getSize()>0){
        return lista.removeFirst();
    }
    throw std::out_of_range("El Stack esta vacio. No se puede hacer pop.");
}

template <typename T>
void Stack<T>::push(T data){
    lista.addFirst(data);
}

template <typename T>
T Stack<T>::peek(){
    if(lista.getSize()>0){
        return lista.getData(0)->data;
    }
    throw std::out_of_range("El Stack esta vacio.");
}

template <typename T>
int Stack<T>::size(){
    return lista.getSize();
}

template <typename T>
bool Stack<T>::isEmpty(){
    return lista.getSize()==0;
}
#endif