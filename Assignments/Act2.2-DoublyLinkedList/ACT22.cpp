#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <stdexcept>
#include "DoubleLinkedList.h"

using namespace std;

template <typename T>
void menuLista(DoubleLinkedList<T>& lista){
    int opcion= -1;
    do{
        cout<<"\n[ Lista: ";
        lista.print();
        cout<<"]\n";
        cout<<"1. Agregar al principio\n2. Agregar al final\n3. Insertar despues de indice\n";
        cout<<"4. Borrar dato\n5. Borrar en posicion\n6. Obtener elemento (getData)\n";
        cout<<"7. Actualizar dato\n8. Actualizar por posicion\n9. Encontrar dato\n";
        cout<<"10. Obtener por []\n11. Actualizar por []\n12. Igualar a otra lista (=)\n";
        cout<<"13. Limpiar lista\n14. Ordenar lista\n15. Duplicar elementos\n16. Remover duplicados\n0. Salir\n> ";
        
        try{
            cin>>opcion;
            if(opcion==0){
                break;
            }
            
            T dato, buscar;
            int index;

            switch(opcion){
                case 1:
                    cout<<"Dato al principio: "; 
                    cin>>dato;
                    lista.addFirst(dato); 
                    break;
                case 2:
                    cout<<"Dato al final: "; 
                    cin>>dato;
                    lista.addLast(dato); 
                    break;
                case 3:
                    cout<<"Indice: "; 
                    cin>>index;
                    cout<<"Dato: "; 
                    cin>>dato;
                    lista.insert(index, dato); 
                    break;
                case 4:
                    cout<<"Dato a borrar: "; 
                    cin>>dato;
                    if(lista.deleteData(dato)){
                        cout<<"Borrado.\n";
                    }else{
                        cout<<"No se encontro.\n";
                    }
                    break;
                case 5:
                    cout<<"Indice a borrar: "; 
                    cin>>index;
                    if(lista.deleteAt(index)){
                        cout<<"Borrado.\n";
                    }else{
                        cout<<"Posicion invalida.\n";
                    }
                    break;
                case 6:
                    cout<<"Indice: "; 
                    cin>>index;
                    cout<<"Dato: "<<lista.getData(index)<<"\n"; 
                    break;
                case 7:
                    cout<<"Dato a reemplazar: "; 
                    cin>>buscar;
                    cout<<"Nuevo valor: "; 
                    cin>>dato;
                    lista.updateData(buscar, dato); 
                    break;
                case 8:
                    cout<<"Indice: "; 
                    cin>>index;
                    cout<<"Nuevo valor: "; 
                    cin>>dato;
                    lista.updateAt(index, dato); 
                    break;
                case 9:
                    cout<<"Dato a buscar: "; 
                    cin>>dato;
                    index= lista.findData(dato);
                    if(index != -1){
                        cout<<"Encontrado en indice: "<<index<<"\n";
                    }else{
                        cout<<"No se encontro.\n";
                    }
                    break;
                case 10:
                    cout<<"Indice []: "; 
                    cin>>index;
                    cout<<"Dato: "<<lista[index]<<"\n"; 
                    break;
                case 11:
                    cout<<"Indice []: "; 
                    cin>>index;
                    cout<<"Nuevo valor: "; 
                    cin>>dato;
                    lista[index]= dato; 
                    break;
                case 12: 
                    {
                        DoubleLinkedList<T> copia;
                        copia= lista; 
                        cout<<"Copia exacta creada:\n";
                        copia.print(); 
                        break;
                    }
                case 13:
                    lista.clear(); 
                    cout<<"Lista limpiada.\n"; 
                    break;
                case 14:
                    lista.sort(); 
                    cout<<"Lista ordenada.\n"; 
                    break;
                case 15:
                    lista.duplicate(); 
                    cout<<"Elementos duplicados.\n"; 
                    break;
                case 16:
                    lista.removeDuplicates(); 
                    cout<<"Duplicados removidos.\n"; 
                    break;
                default:
                    cout<<"Opcion no valida.\n";
                    break;
            }
        }catch(ios_base::failure& ex){
            cout<<"Error de formato.\n";
            cin.clear(); 
            cin.ignore(1000, '\n');
        }catch(const out_of_range& ex){
            cout<<"Excepcion atrapada: "<<ex.what()<<"\n";
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
            cout<<"Elige el tipo de dato:\n1. Enteros (int)\n2. Textos (string)\n> ";
            cin>>tipoDato;
            if(tipoDato!=1 && tipoDato!=2){
                throw invalid_argument("");
            }

            cout<<"Como poblar la lista?\n1. Aleatorios/Predefinidos\n2. Manual\n> ";
            cin>>tipoCarga;
            if(tipoCarga!=1 && tipoCarga!=2){
                throw invalid_argument("");
            }
            
            configurado= true;
        }catch(...){
            cout<<"Seleccion invalida.\n";
            cin.clear(); 
            cin.ignore(1000, '\n');
        }
    }while(!configurado);

    if(tipoDato==1){
        DoubleLinkedList<int> miListaInt;
        if(tipoCarga==1){
            for(int i=0; i<6; i++){
                miListaInt.addLast(rand() % 100);
            }
        }else{
            int n, valor;
            cout<<"Cuantos numeros? "; 
            cin>>n;
            for(int i=0; i<n; i++){ 
                cout<<"Valor "<<i<<": "; 
                cin>>valor; 
                miListaInt.addLast(valor); 
            }
        }
        menuLista(miListaInt);
    }else{
        DoubleLinkedList<string> miListaStr;
        if(tipoCarga==1){
            miListaStr.addLast("Zeta"); 
            miListaStr.addLast("Alfa"); 
            miListaStr.addLast("Beta");
        }else{
            int n; 
            string valor;
            cout<<"Cuantas palabras? "; 
            cin>>n;
            for(int i=0; i<n; i++){ 
                cout<<"Palabra "<<i<<": "; 
                cin>>valor; 
                miListaStr.addLast(valor); 
            }
        }
        menuLista(miListaStr);
    }

    cout<<"Bye bye"<<endl;
    return 0;
}