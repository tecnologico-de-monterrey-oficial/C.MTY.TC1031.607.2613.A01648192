#include <iostream>
#include <vector>
using namespace std;

template <typename T>
void swapS(vector<T> &list){
    for (int i=0;i<list.size()-1;i++){
        for(int j=i+1;j<(list.size());j++){
            if (list[i]>list[j]){
                swap(list[i],list[j]);
            }
        }
    }
}


template <typename T>
void bubbleS(vector<T> &list){
    for (int i=0;i<list.size()-1;i++){
        for(int j=0;j<(list.size()-1);j++){
            if (list[j]>list[j+1]){
                swap(list[j],list[j+1]);
            }
        }
    }
}
/*
template <typename T>
void insertS(vector<T> &list){
    for (){
        for(){
            if (){
            
            }
        }
    }
}*/

template <typename T>
void insertS(vector<T> &list){
    for (int i=0;i<(list.size());i++){
        int j=i+1;
        int base=list[i];

        while(j>=1 && (list[j]>list[i])){
            list[j+1]=list[j];
            j-=j;
            }

        list[j+1]=base;
    }
}


template <typename T>
void printVec(vector<T> &list){
    for (int i=0;i<list.size();i++){
        cout<<list[i]<<", ";
    }
}

int main(){
    /*vector<int> myList1={15, 7, 3, 9, 12, 5, 2};
    swapS(myList1);

    vector<int> myList2={15, 7, 3, 9, 12, 5, 2};
    bubbleS(myList2);*/

    vector<int> myList3={15, 7, 3, 9, 12, 5, 2};
    insertS(myList3);

    /*printVec(myList1);
    printVec(myList2);*/
    printVec(myList3);
    return 0;
}
//primer loop para hacer swap, segundo para checar el menor
//15, 7, 3, 9, 12, 5, 2 