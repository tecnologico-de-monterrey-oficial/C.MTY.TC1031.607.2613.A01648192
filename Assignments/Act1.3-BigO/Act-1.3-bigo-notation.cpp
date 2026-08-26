/*Además realiza lo siguiente en un program de c++:
    Escribe una función iterativa que dado un vector que contiene enteros positivos, regrese la suma de los enteros impares contenidos en el vector. 
    Escribe una función recursiva que dado un vector que contiene enteros positivos, regrese la suma de los enteros impares contenidos en el vector.
    Agrega a cada una de las funciones el orden en base a la notación sintónica de cada función.
*/
#include <iostream>
#include <vector>
using namespace std;

vector<int> numeros = {1, 2, 3, 4, 5, 6, 7, 8, 9};

int oddsIterative(vector<int> n){
    int sum=0;
    for(int i=0; i<n.size(); i++){
        if((n[i]%2)!=0){
            sum+=n[i];
        }
    }
    return sum;
}//el orden de complejidad es de O(n)

int oddsRecursive(vector<int> n){
    if(n.size()==0){
        return 0;
    }
    int ultimo=n.back();
    n.pop_back();
    int num = 0;
    if((ultimo % 2) != 0){
        num = ultimo;
    }
    return num + oddsRecursive(n);
}//el orden de complejidad es de O(n)

int main(){
    cout << "Suma Iterativa: " << oddsIterative(numeros) << endl;
    cout << "Suma Recursiva: " << oddsRecursive(numeros) << endl;
    return 0;
    return 0;
}