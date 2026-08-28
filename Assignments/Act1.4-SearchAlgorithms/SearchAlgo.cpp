/*
(right+left)/2

int mid = (right+left)/2

left or rihjt= mid +1 or mid - 1
right n-1
*/

#include <iostream>
#include <algorithm>
using namespace std;

int myList[]={36,11,6,27,12,5,16,3,13,8};

void searchAlgo(int n){
    int size= sizeof(myList)/sizeof(myList[0]);
    sort(myList, myList+size);

    bool found= false;

    int left=0;
    int right=(size)-1;
    while (left<=right){
        int mid=(right+left)/2;
        if(myList[mid]<n){
            left=mid+1;
        }else if(myList[mid]>n){
            right=mid-1;
        }else if(myList[mid]==n){
            cout<<"Numero encontrado"<<endl;
            found=true;
            break;
        }
    }

    if(!found){
            cout<<"numero no encontrado"<<endl;
        }
}

int main(){
    searchAlgo(40);
    return 0;
}