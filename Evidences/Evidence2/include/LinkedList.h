#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>  
#include <stdexcept>
#include "Node.h"

template <typename T>
class LinkedList{
private:
    Node<T>* head;
    Node<T>* tail;
    int size;
public:
    LinkedList() : head(nullptr), tail(nullptr), size(0) {}
    ~LinkedList();
    void addFirst(T data);
    void addLast(T data);
    T removeFirst();
    int getSize();
    Node<T>* getData(int index);
    void print(); 
};

template <typename T>
LinkedList<T>::~LinkedList(){
    while(head!=nullptr){
        Node<T>* aux= head;
        head= head->next;
        delete aux;
    }
}

template <typename T>
void LinkedList<T>::addFirst(T data){
    Node<T>* node= new Node<T>(data);
    node->next= head;
    head= node;
    if(size==0){
        tail= head;
    }
    size++;
}

template <typename T>
void LinkedList<T>::addLast(T data){
    if(head!=nullptr){
        tail->next= new Node<T>(data);
        tail= tail->next;
    }else{
        head= new Node<T>(data);
        tail= head;
    }
    size++;
}

template <typename T>
T LinkedList<T>::removeFirst(){
    if(head!=nullptr){
        T data= head->data;
        Node<T>* aux= head;
        head= head->next;
        if(head==nullptr){
            tail= nullptr;
        }
        delete aux;
        size--;
        return data;
    }
    throw std::out_of_range("La lista esta vacia");
}

template <typename T>
int LinkedList<T>::getSize(){
    return size;
}

template <typename T>
Node<T>* LinkedList<T>::getData(int index){
    if(index<0 || index>=size || head==nullptr){
        return nullptr; 
    }
    Node<T>* aux= head;
    for(int i=0; i<index; i++){
        aux= aux->next;
    }
    return aux;
}

template <typename T>
void LinkedList<T>::print(){
    Node<T>* aux= head;
    while(aux!=nullptr){
        std::cout<<aux->data<<" ";
        aux= aux->next;
    }
    std::cout<<std::endl;
}
#endif