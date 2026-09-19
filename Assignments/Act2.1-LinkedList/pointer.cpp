#include <iostream>
#include "Fraction.h"
using namespace std;


int main(){
    int x=42;
    int* p= &x;
    cout<<x<<endl;
    cout<<&x<<endl;
    cout<<p<<endl;
    cout<<*p<<endl;

    cout<< "valores de q"<<endl;
    int* q = new int (5);
    cout<<q<<endl;
    cout<<*q<<endl;

    delete q;
    cout<<q<<endl;
    cout<<*q<<endl;

    Fraction* f= new Fraction(2,3);
    f->print();
    delete f;

    return 0;
}