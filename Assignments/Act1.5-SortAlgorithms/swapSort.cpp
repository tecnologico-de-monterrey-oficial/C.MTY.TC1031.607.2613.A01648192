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

template <typename T>
void selectionS(vector<T> &list){
    for (int i=0; i<list.size()-1; i++){
        int min=i;
        for(int j=i+1; j<list.size(); j++){
            if (list[j]< list[min]){
                min=j;
            }
        }
        swap(list[min], list[i]);
    }

}


template <typename T>
void insertS(vector<T> &list){
    for (int i=1; i<list.size(); i++){
        int j=i;
        while(j>0 && (list[j]< list[j-1])){
            swap(list[j], list[j-1]);
            j--;
        }
    }
}


//me trabe demasiado en la logica del quickSort. credito a GeeksforGeeks por ayudarme a encontrar mis fallas logicas https://www.geeksforgeeks.org/dsa/quick-sort-algorithm/
template <typename T>
int splitQS(vector<T> &list, int start, int end){
    int pivot= list[end];
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


template <typename T>
void printVec(vector<T> &list){
    for (int i=0;i<list.size();i++){
        cout<<list[i]<<", ";
    }
    cout<<endl;
}

int main(){
    /*vector<int> myList1={15, 7, 3, 9, 12, 5, 2, 11};
    swapS(myList1);

    vector<int> myList2={15, 7, 3, 9, 12, 5, 2, 11};
    bubbleS(myList2);

    vector<int> myList3={15, 7, 3, 9, 12, 5, 2, 11};
    insertS(myList3);*/

    vector<int> myList4={15, 7, 3, 9, 12, 5, 2, 11};
    selectionS(myList4);

    vector<int> myList5={15, 7, 3, 9, 12, 5, 2, 11};
    quickS(myList5);

    /*printVec(myList1);
    printVec(myList2);
    printVec(myList3);*/
    printVec(myList4);
    printVec(myList5);
    return 0;
}
//primer loop para hacer swap, segundo para checar el menor
//15, 7, 3, 9, 12, 5, 2 