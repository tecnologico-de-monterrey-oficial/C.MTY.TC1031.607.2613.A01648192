#include "List.h"
#include <iostream>
#include <string>
using namespace std;
/*
int sum(int a, int b){
    return a+b;
}

double sum(double a, double b){
    return a+b;
}

string sum(string a, string b){
    return a+b;
}
*/
template <typename T>
List<T>::List(){
    size=0;
}

template <typename T>
void List<T>::insert(T data){
    list.push_back(data);
    size++;
}

template <typename T>
void List<T>::removeLast(){
    if(size==0){
        cout<<"NO HAY ELEMENTOS"<<endl;
    }else{
        cout<<list[size-1]<<endl;
        list.pop_back();
        size--;
    }
}

template <typename T>
T List<T>::getData(int pos){
    return list[pos];
}

template <typename T>
int List<T>::getSize(){
    return size;
}

template <typename T>
T List<T>::getMax(){
    if(size==0){
        return T();//vació para que regrese
    }
    T maxVal=list[0];
    for(int i=1;i<size;i++){
        if (list[i]>maxVal){
            maxVal=list[i];
        }
    }
    return maxVal;
}

template <typename T>
void List<T>::print(){
    for(int i=0;i<size;i++){
        cout<<"["<<i<<"], "<<list[i]<<endl;
    }
}

template <typename T>
void List<T>::insertAt(int pos, T data){
    if(pos<0 || pos>size){
        cout<<"POSICIÓN INVÁLIDA"<<endl; //le pongo tilde pq así decía en canvas pero quizás no salgan bien
    }else{
        list.insert(list.begin()+pos, data);
        size++;
    }
}

template <typename T>
void List<T>::removeAt(int pos){
    if(size==0){
        cout<<"NO HAY ELEMENTOS"<<endl;
    }else if(pos<0 || pos>= size){
        cout<<"POSICIÓN INVÁLIDA"<<endl;
    }else{
        cout<<list[pos]<<endl;
        list.erase(list.begin()+pos);
        size--;
    }
}

/* sum no se usa según lo que pide el profe pero no borro nada por si las moscas
template<typename T> 
T sum(T a, T b){
    return a+b;
}*/


/*
int main(){
    string a="hola";
    string b="crayola";
    cout<<"Sum of "<<a<<" and "<<b<<" is "<<sum(a,b)<<endl;
    int c=5;
    int d=10;
    cout<<"Sum of "<<c<<" and "<<d<<" is "<<sum(c,d)<<endl;
    double e=5.5;
    double f=10.5;
    cout<<"Sum of "<<e<<" and "<<f<<" is "<<sum(e,f)<<endl;

    List<int> list;
    list.insert(5);
    list.insert(10);
    list.insert(15);
    cout<<"numeros int: "<<endl;
    list.print();

    List<string> dobles;
    dobles.insert("5.9");
    dobles.insert("8.9");
    cout<<"doubles: "<<endl;
    dobles.print();

    List<string> things;
    things.insert("Laptop");
    things.insert("Bottle");
    cout<<"strings: "<<endl;
    things.print();




    return 0;
}
*/