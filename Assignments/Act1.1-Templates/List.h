#ifndef LIST_H
#define LIST_H
#include <vector>
//using namespace std;

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

//no me gusta poner código extra en el archivo h, entonces moví las cosas que pusimos en clase al archivo de Actividad1.1...
/*
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
void List<T>::print(){
    std::cout<<"[  ";
    for(int i=0;i<size;i++){
        std::cout<<list[i]<<"  ";
    }
    std::cout<<"]"<<std::endl;
}
*/
#endif