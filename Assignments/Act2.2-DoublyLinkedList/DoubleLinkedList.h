#ifndef DOUBLELINKEDLIST_H
#define DOUBLELINKEDLIST_H

#include "Node.h"
#include <iostream>
#include <stdexcept>

using namespace std;

template <typename T>
class DoubleLinkedList{
private:
    NodeD<T>* head;
    NodeD<T>* tail;
    int size;
public:
    DoubleLinkedList(): head(nullptr), tail(nullptr), size(0) {}
    ~DoubleLinkedList();
    
    void addFirst(T data);
    void addLast(T data);
    void insert(int index, T data);
    bool deleteData(T data);
    bool deleteAt(int index);
    T getData(int index);
    void updateData(T seek, T data);
    void updateAt(int index, T data);
    int findData(T data);
    void clear();
    void sort();
    void duplicate();
    void removeDuplicates();
    void print();

    T& operator[](int index);
    DoubleLinkedList<T>& operator=(const DoubleLinkedList<T>& other);
};

template <typename T>
DoubleLinkedList<T>::~DoubleLinkedList(){
    clear();
}

template <typename T>
void DoubleLinkedList<T>::addFirst(T data){
    if(head == nullptr){
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
    if(head == nullptr){
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
void DoubleLinkedList<T>::insert(int index, T data){
    if(index>=0 && index<size){
        if(index != size-1){
            int auxIndex= 0;
            NodeD<T>* aux= head;
            while(auxIndex<index){
                aux= aux->next;
                auxIndex++;
            }
            NodeD<T>* auxNew= new NodeD<T>(data);
            auxNew->prev= aux;
            auxNew->next= aux->next;
            aux->next->prev= auxNew;
            aux->next= auxNew;
            size++;
        }else{
            addLast(data);
        }
    }else{
        throw std::out_of_range("Indice invalido");
    }
}

template <typename T>
bool DoubleLinkedList<T>::deleteData(T data){
    NodeD<T>* aux= head;
    while(aux != nullptr){
        if(aux->data == data){
            if(aux == head){
                head= head->next;
                if(head != nullptr){
                    head->prev= nullptr;
                }else{
                    tail= nullptr;
                }
            }else if(aux == tail){
                tail= tail->prev;
                if(tail != nullptr){
                    tail->next= nullptr;
                }else{
                    head= nullptr;
                }
            }else{
                aux->prev->next= aux->next;
                aux->next->prev= aux->prev;
            }
            delete aux;
            size--;
            return true;
        }
        aux= aux->next;
    }
    return false;
}

template <typename T>
bool DoubleLinkedList<T>::deleteAt(int index){
    if(index<0 || index>=size || head==nullptr){
        return false;
    }
    NodeD<T>* aux= head;
    for(int i=0; i<index; i++){
        aux= aux->next;
    }
    if(aux == head){
        head= head->next;
        if(head != nullptr){
            head->prev= nullptr;
        }else{
            tail= nullptr;
        }
    }else if(aux == tail){
        tail= tail->prev;
        if(tail != nullptr){
            tail->next= nullptr;
        }else{
            head= nullptr;
        }
    }else{
        aux->prev->next= aux->next;
        aux->next->prev= aux->prev;
    }
    delete aux;
    size--;
    return true;
}

template <typename T>
T DoubleLinkedList<T>::getData(int index){
    if(index<0 || index>=size || head==nullptr){
        throw std::out_of_range("Posicion invalida");
    }
    NodeD<T>* aux= head;
    for(int i=0; i<index; i++){
        aux= aux->next;
    }
    return aux->data;
}

template <typename T>
void DoubleLinkedList<T>::updateData(T seek, T data){
    NodeD<T>* aux= head;
    while(aux != nullptr){
        if(aux->data == seek){
            aux->data= data;
            return;
        }
        aux= aux->next;
    }
    throw std::out_of_range("Dato no encontrado");
}

template <typename T>
void DoubleLinkedList<T>::updateAt(int index, T data){
    if(index<0 || index>=size || head==nullptr){
        throw std::out_of_range("Index fuera de rango");
    }
    NodeD<T>* aux= head;
    for(int i=0; i<index; i++){
        aux= aux->next;
    }
    aux->data= data;
}

template <typename T>
int DoubleLinkedList<T>::findData(T data){
    NodeD<T>* aux= head;
    int index= 0;
    while(aux != nullptr){
        if(aux->data == data){
            return index;
        }
        aux= aux->next;
        index++;
    }
    return -1;
}

template <typename T>
void DoubleLinkedList<T>::clear(){
    while(head != nullptr){
        NodeD<T>* aux= head;
        head= head->next;
        delete aux;
    }
    tail= nullptr;
    size= 0;
}

template <typename T>
void DoubleLinkedList<T>::sort(){
    if(size<2){
        return;
    }
    bool swapped;
    do{
        swapped= false;
        NodeD<T>* aux= head;
        while(aux->next != nullptr){
            if(aux->data > aux->next->data){
                T temp= aux->data;
                aux->data= aux->next->data;
                aux->next->data= temp;
                swapped= true;
            }
            aux= aux->next;
        }
    }while(swapped);
}

template <typename T>
void DoubleLinkedList<T>::duplicate(){
    NodeD<T>* aux= head;
    while(aux != nullptr){
        NodeD<T>* clon= new NodeD<T>(aux->data);
        clon->next= aux->next;
        clon->prev= aux;
        if(aux->next != nullptr){
            aux->next->prev= clon;
        }else{
            tail= clon;
        }
        aux->next= clon;
        aux= clon->next; 
        size++;
    }
}

template <typename T>
void DoubleLinkedList<T>::removeDuplicates(){
    sort(); 
    if(head==nullptr){
        return;
    }
    NodeD<T>* aux= head;
    while(aux->next != nullptr){
        if(aux->data == aux->next->data){
            NodeD<T>* aBorrar= aux->next;
            aux->next= aBorrar->next;
            if(aBorrar->next != nullptr){
                aBorrar->next->prev= aux;
            }else{
                tail= aux;
            }
            delete aBorrar;
            size--;
        }else{
            aux= aux->next;
        }
    }
}

template <typename T>
T& DoubleLinkedList<T>::operator[](int index){
    if(index<0 || index>=size || head==nullptr){
        throw std::out_of_range("Posicion invalida");
    }
    NodeD<T>* aux= head;
    for(int i=0; i<index; i++){
        aux= aux->next;
    }
    return aux->data;
}

template <typename T>
DoubleLinkedList<T>& DoubleLinkedList<T>::operator=(const DoubleLinkedList<T>& other){
    if(this== &other){
        return *this;
    }
    clear();
    NodeD<T>* aux= other.head;
    while(aux != nullptr){
        addLast(aux->data);
        aux= aux->next;
    }
    return *this;
}

template <typename T>
void DoubleLinkedList<T>::print(){
    NodeD<T>* aux= head;
    while(aux != nullptr){
        cout<<aux->data;
        aux= aux->next;
        if(aux != nullptr){
            cout<<"-";
        }
    }
    cout<<endl;
}

#endif