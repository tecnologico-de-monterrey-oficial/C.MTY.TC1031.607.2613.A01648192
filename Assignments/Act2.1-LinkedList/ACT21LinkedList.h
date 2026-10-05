#ifndef ACT21LINKEDLIST_H
#define ACT21LINKEDLIST_H
#include <iostream>  
#include <stdexcept>
#include "Node.h"

template <typename T>
class LinkedList {
private:
    Node<T>* head;
    int size;
public:
    LinkedList() : head(nullptr), size(0) {}
    void addFirst(T data);
    void addLast(T data);
    void insert(int index, T data);
    bool deleteData(T data);
    bool deleteAt(int index);
    Node<T>* getData(int index);
    void updateData(T seek, T data);
    void updateAt(int index, T data);
    int findData(T data);
    void print();

    T& operator[](int index);//gemini me ayudó a figurar cómo se hacía ponía la sobrecarga
    LinkedList<T>& operator=(const LinkedList<T>& other); //gemini me dijo, con razón, que le quitara el const final que le había puesto
};

template <typename T>
void LinkedList<T>::addFirst(T data) {
    Node<T>* node = new Node<T>(data);
    node->next = head;
    head = node;
    size++;
}

template <typename T>
void LinkedList<T>::addLast(T data) {
    if (head != nullptr) {
        Node<T>* aux = head;
        while (aux->next != nullptr) {
            aux = aux->next;
        }
        aux->next = new Node<T>(data);
    } else {
        head = new Node<T>(data);    
    }
    size++;
}

template <typename T>
void LinkedList<T>::insert(int index, T data) {
    if (index >= 0 && index < size) {
        int auxIndex = 0;
        Node<T>* aux = head;
        while (auxIndex < index) {
            aux = aux->next;
            auxIndex++;
        }
        aux->next = new Node<T>(data, aux->next);
        size++;
    } else {
        throw std::out_of_range("la posición no existe en la lista");
    }

}

template <typename T>
bool LinkedList<T>::deleteData(T data) {
    if (head != nullptr) {
        if (head->data == data) {
            Node<T>* aux = head;
            head = head->next;
            delete aux;
            size--;
            return true;
        } else {
            Node<T>* auxPrev = head;
            Node<T>* aux = head->next;
            while (aux != nullptr) {
                if (aux->data == data) {
                    auxPrev->next = aux->next;
                    delete aux;
                    size--;
                }
                auxPrev = aux;
                aux = aux->next;
                return true;
            }
            //throw out_of_range("no se encontró el dato a borrar")
            return false;
        }
    } else {
        //throw out_of_range("La lista esta vacía")
        return false;
    }
}

template <typename T>
bool LinkedList<T>::deleteAt(int index){
    if(index<0 || index >=size || head==nullptr){ //gemini me ayudó a resumir las excepciones de un solo en vez de ir poniendo cada excepción separada en diferentes partes de la función
        return false;
    }
    if(index== 0){
        Node<T>* aux= head;
        head= head->next;
        delete aux;
        size--;
        return true;
    }
    Node<T>* auxprev= head;
    for (int i= 0; i < index - 1; i++) {
        auxprev= auxprev->next;
    }
    Node<T>* aux = auxprev->next; 
    auxprev->next = aux->next;
    delete aux;
    size--;

    return true;
}

template <typename T>
Node<T>* LinkedList<T>::getData(int index){
    if (index< 0 || index >=size || head== nullptr) {
        return nullptr; 
    }
    Node<T>* aux = head;
    for (int i= 0; i< index; i++) {
        aux=aux->next;
    }
    return aux;
}

template <typename T>
void LinkedList<T>::updateData(T seek, T data){
    Node<T>* aux = head;
    while (aux != nullptr) {
        if (aux->data == seek) {
            aux->data = data;
            return;
        }
        aux = aux->next;
    }
    throw std::out_of_range("dato no encontrado");
}

template <typename T>
void LinkedList<T>::updateAt(int index, T data) {
    if (index < 0 || index >= size || head == nullptr) {
        throw std::out_of_range("index fuera de rango");
    }
    Node<T>* aux = head;
    for (int i = 0; i < index; i++) {
        aux = aux->next;
    }
    aux->data = data;
}

template <typename T>
int LinkedList<T>::findData(T data) {
    Node<T>* aux= head;
    int index= 0;
    while (aux != nullptr) {
        if (aux->data== data) {
            return index;
        }
        aux= aux->next;
        index++;
    }
    return -1; 
}

template <typename T>
T& LinkedList<T>::operator[](int index) {
    if (index < 0 || index >= size || head== nullptr) {
        throw std::out_of_range("posicion invalida");
    }
    
    Node<T>* aux = head;
    for (int i = 0; i < index; i++) {
        aux = aux->next;
    }
    
    //la recomendación que me dio gemini, con un ejemplo, fue poner la referena
    //T& para poder leer comandos y acualizzar como decía la rúbrica
    return aux->data;
}

//no comprendí bien para qué era esta función entonces gemini 
//verdaderamente me explicó y mostró cómo hacerla
template <typename T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& other) {
    if (this== &other) {
        return *this; // no auto asignación
    }
    // vaciar la lista para evitar figas de memoria
    while (head != nullptr) {
        Node<T>* aux= head;
        head= head->next;
        delete aux;
    }
    size = 0;
    //se copian los nodos de la otra lista
    Node<T>* aux= other.head;
    while (aux != nullptr) {
        this->addLast(aux->data); 
        aux= aux->next;
    }
    return *this;
}

template <typename T>
void LinkedList<T>::print(){
    Node<T>* aux= head;
    while(aux != nullptr){
        std::cout<<aux->data;
        aux= aux->next;
        if(aux != nullptr){
            std::cout<<"-";
        }
    }
    std::cout<<std::endl;
}

#endif