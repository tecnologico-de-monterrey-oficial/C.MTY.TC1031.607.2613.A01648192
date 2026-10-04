#ifndef LinkedList_h
#define LinkedList_h

#include "Node.h"

template <typename T>
class LinkedList {
private:
    Node<T>* head;
    int size;
public:
    LinkedList() : head(nullptr), size(0) {}
    void push_front(T data);
    void push_back(T data);
    void print();
    void insert(int index, T data);
    void deleteData(T data)
};

template <typename T>
void LinkedList<T>::push_front(T data) {
    Node<T>* node = new Node<T>(data);
    node->next = head;
    head = node;
}

template <typename T>
void LinkedList<T>::push_back(T data) {
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
        throw out_of_range("la posición no existe en la lista")
    }

}

template <typename T>
void LinkedList<T>::deleteData(T data) {
    if (head != nullptr) {
        if (head->data == data) {
            Node<T>* aux = head;
            head = head->next;
            delete aux;
            size--;
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
            }
            throw out_of_range("no se encontró el dato a borrar")
        }
    } else {
        throw out_of_range("La lista esta vacía")
    }
}

template <typename T>
void LinkedList<T>::print() {
    Node<T>* aux = head;
    while (aux != nullptr) {
        cout << aux->data;
        aux = aux->next;
        if (aux != nullptr) {
            cout << "-";
        }
    }
    cout << endl;
}
#endif