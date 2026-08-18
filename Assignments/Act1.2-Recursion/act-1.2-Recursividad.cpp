//Michelle Lagos
//A01648192
#include <iostream>
using namespace std;

int sumIterative(int n){
    int suma =0;
    for (int i=1;i<=n;i++){
        suma +=i;
    }
    return suma;
}

int sumRecursive(int n){
    if(n==1){
        return 1;
    }
    return n+sumRecursive(n-1);
}

//formula n(n+1)/2
int sumFormula(int n){
    if(n==1){
        return 1;
    }
    return (n*(n+1)/2);
}

int fibonacciIterative(int n){
    int a =1;
    int b=1;
    int c;
    int suma=1;
    for (int i=3;i<=n;i++){
        c=a+b;
        a=b;
        b=c;
    }
    return b;


}


int main(){
    cout<<"La suma iterativa de 5 es: "<<sumIterative(5)<<endl; 
    cout<<"La suma recursica de 5 es: "<<sumRecursive(5)<<endl;
    cout<<"La suma con formula de 5 es: "<<sumFormula(5)<<endl;
    cout<<"La secuencia fibonacci de 5 es: "<<fibonacciIterative(5)<<endl;
    return 0;
   
}