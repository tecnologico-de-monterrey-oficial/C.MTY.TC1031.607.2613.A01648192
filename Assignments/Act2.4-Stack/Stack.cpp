#include <iostream>
#include <string>
#include <limits>
#include "Stack.h"

using namespace std;

struct PaginaWeb{
    string titulo;
    string url;
};

int main(){
    cin.exceptions(ios::failbit | ios::badbit); // siempre se me olvida esto
    Stack<PaginaWeb> historial;
    int opcion= 0;

    do{
        bool opcionValida= false;
        do{
            try{
                cout<<"1. visitar otra pagina"<<endl;
                cout<<"2. Retroceder de pagina"<<endl;
                cout<<"3. Ver la pagina actual"<<endl;
                cout<<"4. Mostrar cantidad de paginas en historial"<<endl;
                cout<<"5. Salir\n> ";
                cin>>opcion;
                opcionValida= true;
            }catch(ios_base::failure& ex){
                cout<<"Error. INgresa un numero valido."<<endl;
                cin.clear();
                cin.ignore(1000, '\n');
            }
        }while(!opcionValida);

        switch(opcion){
            case 1:{
                PaginaWeb nuevaPagina;
                cout<<"Ingresa el titulo de pagina: ";
                cin.ignore(1000, '\n');
                getline(cin, nuevaPagina.titulo);
                
                cout<<"Ingresa el URL: ";
                getline(cin, nuevaPagina.url);
                
                historial.push(nuevaPagina);
                cout<<"exito: "<<nuevaPagina.titulo<<endl;
                break;
            }
            case 2:{
                try{
                    PaginaWeb cerrada= historial.pop();
                    cout<<"cerraste: "<<cerrada.titulo<<" ("<<cerrada.url<<")"<<endl;
                }catch(const out_of_range& ex){
                    cout<<ex.what()<<endl;
                }
                break;
            }
            case 3:{
                try{
                    PaginaWeb actual= historial.top();
                    cout<<"Pagina actual: "<<actual.titulo<<" ("<<actual.url<<")"<<endl;
                }catch(const out_of_range& ex){
                    cout<<ex.what()<<endl;
                }
                break;
            }
            case 4:{
                cout<<"Paginas en el historial: "<<historial.getSize()<<endl;
                break;
            }
            case 5:{
                cout<<"By bye."<<endl;
                break;
            }
            default:
                cout<<"Opcion no valida"<<endl;
                break;
        }
    }while(opcion!=5);

    return 0;
}