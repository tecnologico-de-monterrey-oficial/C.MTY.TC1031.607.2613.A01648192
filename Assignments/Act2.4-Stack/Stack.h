#ifndef STACK_H
#define STACK_H
#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

template <typename T>
class Stack{
    private:
        Node<T>* topNode; // Gemini sugirió renombrar para no chocar con la función top()
        int length;
    public:
        Stack() : topNode(nullptr), length(0) {}
        T pop();
        void push(T data);
        T top();
        int getSize();
};

template <typename T>
T Stack<T>::pop(){
    if(topNode != nullptr){
        T data= topNode->data;
        Node<T>* aux= topNode;
        topNode= topNode->next;
        delete aux;
        length--;
        return data;
    }
    throw out_of_range("El historial esta vacio. No se puede retroceder.");
}

template <typename T>
void Stack<T>::push(T data){
    Node<T>* newNode= new Node<T>(data);
    newNode->next= topNode;
    topNode= newNode;
    length++;
}

template <typename T>
T Stack<T>::top(){
    if(topNode != nullptr){
        return topNode->data;
    }
    throw out_of_range("El historial esta vacio.");
}

template <typename T>
int Stack<T>::getSize(){
    return length;
}

#endif