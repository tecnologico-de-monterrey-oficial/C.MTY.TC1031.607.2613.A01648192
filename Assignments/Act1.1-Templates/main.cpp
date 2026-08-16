#include "List.h"
#include <iostream>
#include <string>
using namespace std;

int main(){
    List<int> myList;

    cout<<"lista de #"<<endl;
    //insertar
    myList.insert(7);
    myList.insert(27);
    myList.insert(43);
    myList.print();

    cout<<"Size: "<<myList.getSize()<<endl;
    cout<<"El num mayor: "<<myList.getMax()<<endl;

    //15 insert
    cout<<"15 inserta en posicion 1"<<endl;
    myList.insertAt(1,15);
    myList.print();

    //pos 2, delete
    cout<<"eliminando posicion 2"<<endl;
    myList.removeAt(2);
    myList.print();

    //pop last
    cout << "\nEliminando ultima posicion" << endl;
    myList.removeLast();
    myList.print();

    //strings
    cout<<"\nlista de strings"<<endl;
    List<string> things;
    things.insert("Laptop");
    things.insert("Bottle");
    things.print();
    
    return 0;
    //en la retrospección comentar lo de los archivos cpp y mi dificultad con compilar
}