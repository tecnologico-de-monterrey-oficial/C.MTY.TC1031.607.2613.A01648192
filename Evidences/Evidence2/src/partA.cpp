// partA.cpp
#include <iostream>
#include <string>
#include "LinkedList.h"
#include "Queue.h"
#include "Stack.h"
#include "DoubleLinkedList.h"

using namespace std;

int main(){
    cout<<"\nPARTE A"<<endl;

    cout<<"\n1. LINKED LIST"<<endl;
    LinkedList<int> list;
    cout<<"Remover en lista vacia: ";
    try{
        list.removeFirst();
    }catch(const out_of_range& e){
        cout<<"Excepcion: "<<e.what()<<endl;
    }
    list.addFirst(10);
    cout<<"Un elemento (addFirst 10): "; list.print();
    list.addLast(20);
    list.addFirst(5);
    cout<<"Varios elementos (addLast 20, addFirst 5): "; list.print();
    cout<<"Tamano: "<<list.getSize()<<endl;
    cout<<"Remover primero ("<<list.removeFirst()<<"): "; list.print();

    cout<<"\n2. STACK"<<endl;
    Stack<int> stack;
    cout<<"Pop en pila vacia: ";
    try{
        stack.pop();
    }catch(const out_of_range& e){
        cout<<"Excepcion: "<<e.what()<<endl;
    }
    cout<<"Pila vacia? "<<(stack.isEmpty() ? "Si" : "No")<<endl;
    stack.push(100);
    cout<<"Push(100) -> Peek: "<<stack.peek()<<", Size: "<<stack.size()<<endl;
    stack.push(200);
    cout<<"Push(200) -> Pop: "<<stack.pop()<<endl;
    cout<<"Peek actual: "<<stack.peek()<<endl;

    cout<<"\n3. QUEUE"<<endl;
    Queue<int> queue;
    cout<<"Dequeue en fila vacia: ";
    try{
        queue.dequeue();
    }catch(const out_of_range& e){
        cout<<"Excepcion: "<<e.what()<<endl;
    }
    cout<<"Fila vacia? "<<(queue.isEmpty() ? "Si" : "No")<<endl;
    queue.enqueue(1);
    cout<<"Enqueue(1) -> Front: "<<queue.front()<<", Size: "<<queue.size()<<endl;
    queue.enqueue(2);
    cout<<"Enqueue(2) -> Dequeue: "<<queue.dequeue()<<endl;
    cout<<"Front actual: "<<queue.front()<<endl;

    cout<<"\n4. DOUBLE LINKED LIST"<<endl;
    DoubleLinkedList<int> dlist;
    cout<<"Lista vacia forward: "; dlist.printForward();
    dlist.addFirst(50);
    cout<<"AddFirst(50): "; dlist.printForward();
    dlist.addLast(150);
    cout<<"AddLast(150): "; dlist.printForward();
    
    NodeD<int>* headNode= dlist.getHead();
    cout<<"Insertar 100 despues del head: ";
    dlist.insertAfter(headNode, 100);
    dlist.printForward();
    
    cout<<"Backward (tail a head): ";
    dlist.printBackward();
    
    cout<<"Eliminar nodo 100: ";
    dlist.deleteNode(headNode->next);
    dlist.printForward();
    cout<<"Tamano final: "<<dlist.getSize()<<endl;

    cout<<"\nBye bye."<<endl;
    return 0;
}