#include "ACT21LinkedList.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
using namespace std;

template <typename T>
void probarLista(LinkedList<T>& lista){
    int opcion= -1;
    do{
        cout<<"\n[ Lista: ";
        lista.print();
        cout<<"]\n";
        
        cout<<"1. Agregar al principio\n2. Agregar al final\n3. Insertar despues de un index\n";
        cout<<"4. Borrar un elemento\n5. Borrar en una posicion\n6. Obtener elemento\n7. Actualizar un elemento\n8. Actualizar por posicion\n";
        cout<<"9. Encuentra un elemento\n10. Obtener elemento ([])\n11. Actualizar por posicion ([])\n12. Duplicar lista (=)\n0. Salir\n> ";
        
        try{
            cin>>opcion;
            if(opcion==0) break;
            T dato, buscar;
            int index;

            switch(opcion){
                case 1:
                    cout<<"Dato al principio: "; cin>>dato;
                    lista.addFirst(dato);
                    break;
                case 2:
                    cout<<"Dato al final: "; cin>>dato;
                    lista.addLast(dato);
                    break;
                case 3:
                    cout<<"Indice: "; cin>>index;
                    cout<<"Dato: "; cin>>dato;
                    lista.insert(index, dato);
                    break;
                case 4:
                    cout<<"Dato a borrar: "; cin>>dato;
                    if(lista.deleteData(dato)) cout<<"Borrado.\n";
                    else cout<<"No existe.\n";
                    break;
                case 5:
                    cout<<"Indice a borrar: "; cin>>index;
                    if(lista.deleteAt(index)) cout<<"Borrado.\n";
                    else cout<<"Posicion invalida.\n";
                    break;
                case 6:
                    cout<<"Indice: "; cin>>index;
                    if(lista.getData(index)!=nullptr) 
                        cout<<"Dato: "<<lista.getData(index)->data<<"\n";
                    else 
                        cout<<"Posicion invalida.\n";
                    break;
                case 7:
                    cout<<"Dato a reemplazar: "; cin>>buscar;
                    cout<<"Nuevo valor: "; cin>>dato;
                    lista.updateData(buscar, dato);
                    break;
                case 8:
                    cout<<"Indice a actualizar: "; cin>>index;
                    cout<<"Nuevo valor: "; cin>>dato;
                    lista.updateAt(index, dato);
                    break;
                case 9:
                    cout<<"Dato a buscar: "; cin>>dato;
                    index= lista.findData(dato);
                    if(index!=-1) cout<<"Encontrado en indice: "<<index<<"\n";
                    else cout<<"No existe.\n";
                    break;
                case 10:
                    cout<<"Indice []: "; cin>>index;
                    cout<<"Dato: "<<lista[index]<<"\n";
                    break;
                case 11:
                    cout<<"Indice []: "; cin>>index;
                    cout<<"Nuevo valor: "; cin>>dato;
                    lista[index]= dato;
                    break;
                case 12: {
                    LinkedList<T> duplicada;
                    duplicada= lista; 
                    cout<<"Lista duplicada: ";
                    duplicada.print();
                    break;
                }
                default:
                    cout<<"Opcion no valida.\n";
            }
        }catch(ios_base::failure& ex){
            cout<<"Error de formato."<<endl;
            cin.clear();
            cin.ignore(1000, '\n');
        }catch(const out_of_range& ex){
            cout<<"Excepcion: "<<ex.what()<<endl;
        }
    }while(opcion!=0);
}

int main(){
    srand(time(0));
    cin.exceptions(ios::failbit | ios::badbit);

    int tipoDato= 0, tipoCarga= 0;
    bool configurado= false;

    do{
        try{
            cout<<"Selecciona tipo de dato:\n1. int\n2. string\n> ";
            cin>>tipoDato;
            if(tipoDato!=1 && tipoDato!=2) throw invalid_argument("");

            cout<<"\nLlenar la lista:\n1. Aleatorios o predeterminados\n2. Input de usuario\n> ";
            cin>>tipoCarga;
            if(tipoCarga!=1 && tipoCarga!=2) throw invalid_argument("");
            
            configurado= true;
        }catch(...){
            cout<<"Invalido. Intenta de nuevo.\n";
            cin.clear(); cin.ignore(1000, '\n');
        }
    }while(!configurado);

    if(tipoDato== 1){
        LinkedList<int> miListaInt;
        if(tipoCarga== 1){
            for(int i=0; i<5; i++) miListaInt.addLast(rand() % 100);
        }else{
            int n, valor;
            cout<<"Cuantos numeros? "; cin>>n;
            for(int i=0; i<n; i++){ cout<<"Valor "<<i<<": "; cin>>valor; miListaInt.addLast(valor); }
        }
        probarLista(miListaInt);
    }else{
        LinkedList<string> miListaStr;
        if(tipoCarga==1){
            miListaStr.addLast("Luis"); miListaStr.addLast("Alberto"); miListaStr.addLast("Spinetta");
        }else{
            int n; string valor;
            cout<<"Cuantas palabras? "; cin>>n;
            for(int i=0; i<n; i++){ cout<<"Palabra "<<i<<": "; cin>>valor; miListaStr.addLast(valor); }
        }
        probarLista(miListaStr);
    }

    cout<<"Bye bye"<<endl;
    return 0;
}