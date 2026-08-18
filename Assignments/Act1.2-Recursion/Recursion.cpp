#include <iostream>
using namespace std;

int factorial(int n){
    if(n<=1){
        return 1;
    }
    return n*factorial(n-1);
}

int main(){
    cout<<"El factorial de 4 es: "<<factorial(4)<<endl;
    return 0;
}