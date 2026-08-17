#ifndef LIST_H
#define LIST_H
#include <vector>
#include <iostream>
using namespace std;

template <typename T>
class List{
    private:
        std::vector<T>list;
        int size;
    public:
        List();
        void insert(T data);
        void removeLast();
        T getData(int pos);
        int getSize();
        T getMax();
        void print();
        void insertAt(int pos, T data);;
        void removeAt(int pos);        
        
};

//FUNCS

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
        cout<<"["<<i<<"] - "<<list[i]<<endl;
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

#endif