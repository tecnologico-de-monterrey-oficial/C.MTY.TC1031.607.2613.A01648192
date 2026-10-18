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
    
    void addFirst(T data);
    void addLast(T data);
    void insertAfter(NodeD<T>* node, T data);
    void deleteNode(NodeD<T>* node);
    void clear();
    void sort(int& comparaciones, int& profMax);
    NodeD<T>* getHead() const;
    int getSize() const;
    void printForward();
    void printBackward();
};

template <typename T>
void DoubleLinkedList<T>::addFirst(T data){
    if(head==nullptr){
        head= new NodeD<T>(data);
        tail= head;
        size++;
    }else{
        NodeD<T>* aux= new NodeD<T>(data);
        aux->next= head;
        head->prev= aux;
        head= aux;
        size++;
    }
}

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
void DoubleLinkedList<T>::insertAfter(NodeD<T>* node, T data){
    if(node==nullptr) return;
    NodeD<T>* newNode= new NodeD<T>(data);
    newNode->next= node->next;
    newNode->prev= node;
    node->next= newNode;
    if(newNode->next!=nullptr){
        newNode->next->prev= newNode;
    }else{
        tail= newNode;
    }
    size++;
}

template <typename T>
void DoubleLinkedList<T>::deleteNode(NodeD<T>* node){
    if(head==nullptr || node==nullptr) return;
    if(head==node) head= node->next;
    if(node->next!=nullptr) node->next->prev= node->prev;
    if(node->prev!=nullptr) node->prev->next= node->next;
    if(node==tail) tail= node->prev;
    delete node;
    size--;
}

template <typename T>
void DoubleLinkedList<T>::printForward(){
    NodeD<T>* aux= head;
    while(aux!=nullptr){
        cout<<aux->data<<" ";
        aux= aux->next;
    }
    cout<<endl;
}

template <typename T>
void DoubleLinkedList<T>::printBackward(){
    NodeD<T>* aux= tail;
    while(aux!=nullptr){
        cout<<aux->data<<" ";
        aux= aux->prev;
    }
    cout<<endl;
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