#ifndef DOUBLELINKEDLIST_H
#define DOUBLELINKEDLIST_H
#include "Node.h"
#include <stdexcept>
#include <iostream>

using namespace std;

template <typename T>
class DoubleLinkedList{
private:
    NodeD<T>* head;
    NodeD<T>* tail;
    int size;

    NodeD<T>* split(NodeD<T>* headRef){
        NodeD<T>* fast= headRef;
        NodeD<T>* slow= headRef;
        while(fast->next!=nullptr && fast->next->next!=nullptr){
            fast= fast->next->next;
            slow= slow->next;
        }
        NodeD<T>* temp= slow->next;
        slow->next= nullptr;
        return temp;
    }

    NodeD<T>* merge(NodeD<T>* first, NodeD<T>* second, int& comparaciones, int& profMax, int profActual){
        if(profActual>profMax) profMax= profActual;
        if(first==nullptr) return second;
        if(second==nullptr) return first;

        comparaciones++;
        if(first->data <= second->data){
            first->next= merge(first->next, second, comparaciones, profMax, profActual+1);
            first->next->prev= first;
            first->prev= nullptr;
            return first;
        }else{
            second->next= merge(first, second->next, comparaciones, profMax, profActual+1);
            second->next->prev= second;
            second->prev= nullptr;
            return second;
        }
    }

    NodeD<T>* mergeSort(NodeD<T>* headRef, int& comparaciones, int& profMax, int profActual){
        if(headRef==nullptr || headRef->next==nullptr) return headRef;
        NodeD<T>* second= split(headRef);
        headRef= mergeSort(headRef, comparaciones, profMax, profActual+1);
        second= mergeSort(second, comparaciones, profMax, profActual+1);
        return merge(headRef, second, comparaciones, profMax, profActual);
    }

public:
    DoubleLinkedList(): head(nullptr), tail(nullptr), size(0) {}
    ~DoubleLinkedList(){ clear(); }
    
    void addLast(T data);
    void clear();
    void sort(int& comparaciones, int& profMax);
    NodeD<T>* getHead() const;
    int getSize() const;
};

template <typename T>
void DoubleLinkedList<T>::addLast(T data){
    if(head==nullptr){
        head= new NodeD<T>(data);
        tail= head;
        size++;
    }else{
        NodeD<T>* aux= new NodeD<T>(data);
        aux->prev= tail;
        tail->next= aux;
        tail= aux;
        size++;
    }
}

template <typename T>
void DoubleLinkedList<T>::clear(){
    while(head!=nullptr){
        NodeD<T>* aux= head;
        head= head->next;
        delete aux;
    }
    tail= nullptr;
    size= 0;
}

template <typename T>
void DoubleLinkedList<T>::sort(int& comparaciones, int& profMax){
    if(size<2) return;
    comparaciones= 0;
    profMax= 0;
    head= mergeSort(head, comparaciones, profMax, 0);
    NodeD<T>* temp= head;
    while(temp!=nullptr && temp->next!=nullptr){
        temp= temp->next;
    }
    tail= temp;
}

template <typename T>
NodeD<T>* DoubleLinkedList<T>::getHead() const{
    return head;
}

template <typename T>
int DoubleLinkedList<T>::getSize() const{
    return size;
}
#endif