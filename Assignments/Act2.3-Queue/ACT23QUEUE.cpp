#include <iostream>
#include <string>
#include <limits>
#include "ACT23Queue.h" 

using namespace std;

int main(){
    cin.exceptions(ios::failbit | ios::badbit);
    Queue<Cliente> fila;
    int opcion= 0;

    do{
        bool opcionValida= false;
        do{
            try{
                cout<<"\n--- TAQUILLA: FILA DE CLIENTES ---"<<endl;
                cout<<"1. Llegada de un nuevo cliente"<<endl;
                cout<<"2. Atender al siguiente cliente"<<endl;
                cout<<"3. Ver al siguiente cliente sin atenderlo aun"<<endl;
                cout<<"4. Mostrar cuantas personas hay en la fila"<<endl;
                cout<<"5. Salir\n> ";
                cin>>opcion;
                opcionValida= true;
            }catch(ios_base::failure& ex){
                cout<<"Error. Introduce un numero valido."<<endl;
                cin.clear();
                cin.ignore(1000, '\n');
            }
        }while(!opcionValida);

        switch(opcion){
            case 1:{
                Cliente nuevo;
                cout<<"Ingresa el nombre del cliente: ";
                cin.ignore(1000, '\n'); // se me olvidó poner esto, Gemini lo sugirió
                getline(cin, nuevo.nombre);
                
                bool boletosValidos= false;
                do{
                    try{
                        cout<<"Cantidad de boletos que desea: ";
                        cin>>nuevo.boletos;
                        boletosValidos= true;
                    }catch(ios_base::failure& ex){
                        cout<<"Error. Ingresa un numero valido."<<endl;
                        cin.clear();
                        cin.ignore(1000, '\n');
                    }
                }while(!boletosValidos);
                
                fila.push(nuevo);
                cout<<"-> Cliente "<<nuevo.nombre<<" agregado a la fila."<<endl;
                break;
            }
            case 2:{
                try{
                    Cliente atendido= fila.pop(); 
                    cout<<"-> Atendiendo a: "<<atendido.nombre<<endl;
                    cout<<"-> Boletos vendidos: "<<atendido.boletos<<endl;
                }catch(const out_of_range& ex){
                    cout<<"-> Excepcion: "<<ex.what()<<endl;
                }
                break;
            }
            case 3:{
                try{
                    Cliente siguiente= fila.front();
                    cout<<"-> Siguiente en turno: "<<siguiente.nombre<<endl;
                    cout<<"-> Boletos solicitados: "<<siguiente.boletos<<endl;
                }catch(const out_of_range& ex){
                    cout<<"-> Excepcion: "<<ex.what()<<endl;
                }
                break;
            }
            case 4:{
                cout<<"-> Personas actualmente en la fila: "<<fila.getSize()<<endl;
                break;
            }
            case 5:{
                cout<<"Cerrando taquilla. Tenga un buen dia."<<endl;
                break;
            }
            default:
                cout<<"Opcion no valida."<<endl;
                break;
        }
    }while(opcion!=5);

    return 0;
}