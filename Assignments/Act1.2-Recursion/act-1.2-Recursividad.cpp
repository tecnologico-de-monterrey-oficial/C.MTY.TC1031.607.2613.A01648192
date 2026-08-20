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

int fibonacciRecursive(int n){
    if(n<=2){
        return 1;
    }
    return fibonacciRecursive(n-1)+fibonacciRecursive(n-2);
}

int bacteriaIterative(int n) {
    double born = 3.78;
    double died = 2.34;
    int sum = 1;
    for (int i=1; i<=n; i++) {
        int bacBorn = sum * born;
        int bacDied = sum * died; 
        sum += bacBorn - bacDied; 
    }
    return sum;

}

int bacteriaRecursive(int n) {
    if (n==0) {
        return 1;
    }
    int bacteria = bacteriaRecursive(n-1);
    int born = bacteria * 3.78;
    int died = bacteria * 2.34;
    return bacteria + born - died;
}

double investmentIterative(int n, int m){
    double invest=m;
    for(int i=1;i<=n;i++){
        float rate=1.1875;
        invest= invest*rate;
    }
    return invest;
}

double investmentRecursive(int n, int m){
    if (n==0){
        return m;
    }
    double invest=investmentRecursive(n-1, m);
    return invest*1.1875;
}

int powIterative(int n, int y){
    int power=1;
    for(int i=1;i<=y;i++){
        power*=n;
    }
    return power;
}

int powRecursive(int n, int y){
    if(y==0){
        return 1;
    }
    int power=powRecursive(n,y-1);
    return (power*n);
}

int main(){
    cout<<"La suma iterativa de 5 es: "<<sumIterative(5)<<endl; 
    cout<<"La suma recursica de 5 es: "<<sumRecursive(5)<<endl;
    cout<<"La suma con formula de 5 es: "<<sumFormula(5)<<endl;
    cout<<"La secuencia fibonacci iterativa de 5 es: "<<fibonacciIterative(5)<<endl;
    cout<<"La secuencia fibonacci recursiva de 5 es: "<<fibonacciRecursive(5)<<endl;
    cout << "La bacteraia iterativa de 5 es: " << bacteriaIterative(5) << endl;
    cout << "La bacteria recursiva de 5 es: " << bacteriaRecursive(5) << endl;
    cout << "La inversión iterativa de 100 dolares en 5 meses es: " << investmentIterative(5,100) << endl;
    cout << "La inversión recursiva de 100 dolares en 5 meses es: " << investmentRecursive(5,100) << endl;
    cout << "La exponencial iterativa de 5 a la 10 es: " << powIterative(5,10) << endl;
    cout << "La exponencial recursiva de 5 a las 10 es: " << powRecursive(5,10) << endl;
    return 0;
   
}