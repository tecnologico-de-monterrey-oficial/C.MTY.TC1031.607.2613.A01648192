#ifndef ACT23QUEUE_H
#define ACT23QUEUE_H
#include <string>
#include <iostream>
#include <stdexcept>

using namespace std;

struct Cliente{
    string nombre;
    int boletos;
};

template <typename T>
class Queue{
    private:
        Node<T>* head;
        Node<T>* tail;
        int length;
    public:
        Queue() : head(nullptr), tail(nullptr), length(0) {}
        T pop();
        void push(T data);
        T front();
        int getSize();
};

template <typename T>
T Queue<T>::pop(){ //Gemini me hizo la sugerencia de pop tipo T
    if(head != nullptr){
        T data= head->data;
        if(head==tail){
            Node<T>* aux= head;
            delete aux;
            head= nullptr;
            tail= nullptr;
        }else{
            Node<T>* aux= head;
            head= head->next;
            delete aux; 
        }
        length--;
        return data;
    }
    throw out_of_range("El Queue esta vacio. No hay clientes por atender.");
}

template <typename T>
void Queue<T>::push(T data){
    if(head != nullptr){
        tail->next= new Node<T>(data);
        tail= tail->next;
    }else{
        head= new Node<T>(data);
        tail= head;
    }
    length++;
}

template <typename T>
T Queue<T>::front(){
    if(head != nullptr){
        return head->data;
    }
    throw out_of_range("El Queue esta vacia");
}

template <typename T>
int Queue<T>::getSize(){
    return length;
}

#endif