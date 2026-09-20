//prácticamente un copy paste de la tarea de la semana anterior
#ifndef SORTS_H
#define SORTS_H

#include <vector>
#include <algorithm> // For std::swap
#include <iostream>

using namespace std;

template <typename T>
void swapS(vector<T> &list, long long &comps, long long &swaps){
    comps=0;
    swaps=0;
    for (int i=0;i<list.size()-1;i++){
        for(int j=i+1;j<(list.size());j++){
            comps++;
            if (list[i]>list[j]){
                swap(list[i],list[j]);
                swaps++;
            }
        }
    }
}

//Gemini hizo un cambio muy importante. Me dijo que necesitaba de ocupar long long para evitar printing valores inservibles
template <typename T>
void bubbleS(vector<T> &list, long long &comps, long long &swaps){
    comps=0;
    swaps=0;
    for (int i=0;i<list.size()-1;i++){
        for(int j=0;j<(list.size()-1);j++){
            comps++;
            if (list[j]>list[j+1]){
                swap(list[j],list[j+1]);
                swaps++;
            }
        }
    }
}

template <typename T>
void selectionS(vector<T> &list, long long &comps, long long &swaps){
    comps=0;
    swaps=0;
    for (int i=0; i<list.size()-1; i++){
        int min=i;
        for(int j=i+1; j<list.size(); j++){
            comps++;
            if (list[j]< list[min]){
                min=j;
                swaps++;
            }
        }
        swap(list[min], list[i]);
    }

}


template <typename T>
void insertS(vector<T> &list, long long &comps, long long &swaps){
    comps=0;
    swaps=0;
    for (int i=1; i<list.size(); i++){
        comps++;
        int j=i;
        while(j>0 && (list[j]< list[j-1])){
            swap(list[j], list[j-1]);
            j--;
            swaps++;
            if (j > 0) comps++;
        }
    }
}


//me trabe demasiado en la logica del quickSort. credito a GeeksforGeeks por ayudarme a encontrar mis fallas logicas https://www.geeksforgeeks.org/dsa/quick-sort-algorithm/
template <typename T>
int splitQS(vector<T> &list, int start, int end){
    T pivot= list[end];
    int aux = start- 1;
    for(int j=start; j<=(end-1); j++){
        if(pivot>list[j]){
            aux++;
            swap(list[aux],list[j]);
        }
    }
    swap(list[aux+1], list[end]);
    return aux+1;
}

template <typename T>
void quickS(vector<T> &list, int start= 0, int end =-1){
    if (end == -1) {
        end = list.size() - 1;
    }
    if (start < end) {
        int pi = splitQS(list, start, end);
        quickS(list, start, pi - 1);
        quickS(list, pi + 1, end);
    }
}


//el algoritmo que más tuvo que editar Gemini. De hecho, fue por este que me di cuenta que tenía que hacer cambios a otros.
//Los cambios que me dijo que hiciera eran pq el método que vimos en clase nunca funcionaría en listas tan grandes
//algunos cambios  incluyen: calcular el tamaño de las mitades primero y pre alocarlos
//me recomendó cambiar algunos nombres de variables para mejor lectura. entre otros.
template <typename T>
void merge(vector<T> &list, int left, int mid, int right) {
    int n1= mid-left+1;
    int n2= right-mid;
    vector<T> L(n1), R(n2);

    for (int i= 0; i<n1; i++) {
        L[i]= list[left+i];
    }
    for (int j = 0; j < n2; j++) {
        R[j]= list[mid+1+j];
    }
    int i= 0, j= 0, k= left;
 
    while (i<n1 && j<n2) {
        if (L[i]<=R[j]) { 
            list[k]= L[i]; 
            i++; 
        } else { 
            list[k]= R[j]; 
            j++; 
        }
        k++;
    }
    while (i<n1) {list[k]= L[i]; i++; k++;}
    while (j<n2) {list[k]= R[j]; j++; k++;}
}

template <typename T>
void mergeSort(vector<T> &list, int left= 0, int right= -1) {
    if (right== -1) {
        right= list.size()-1;
    }
    
    if (left< right) {
        int mid= left+(right-left)/2;
        
        mergeSort(list, left, mid);
        mergeSort(list, mid+1, right);
        merge(list, left, mid, right);
    }
}

template <typename T>
void shellS(vector<T> &list) {
    int n= list.size();
    for (int gap= n/2; gap>0; gap/= 2) {
        for (int i= gap; i<n; i++) {
            T temp = list[i];
            int j;
            for (j= i; j>=gap && list[j-gap]>temp; j-=gap) {
                list[j]= list[j-gap];
            }
            list[j]= temp;
        }
    }
}

template <typename T>
void printVec(vector<T> &list){
    for (int i=0;i<list.size();i++){
        cout<<list[i]<<", ";
    }
    cout<<endl;
}

#endif