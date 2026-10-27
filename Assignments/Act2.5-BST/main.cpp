#include <iostream>
#include "BST.h"

using namespace std;

int main(){
    cin.exceptions(ios::failbit | ios::badbit);
    
    BST<int> bst;
    int opcion= -1;

    do{
        cout<<"\n=== MENU BST ==="<<endl;
        cout<<"1. Insertar valor\n2. Borrar (delete) valor\n3. Imprimir arbol\n4. Buscar (find) valor\n";
        cout<<"5. Recorridos (visit)\n6. Altura (height) del arbol\n7. Ancestros de un nodo\n";
        cout<<"8. Nivel (whatLevelAmI) de un nodo\n0. Salir\n> ";
        
        try{
            cin>>opcion;
            if(opcion == 0) break;

            int valor, metodo, res;

            switch(opcion){
                case 1:
                    cout<<"Valor a insertar: "; 
                    cin>>valor;
                    bst.insert(valor);
                    break;
                case 2:
                    cout<<"Valor a borrar: "; 
                    cin>>valor;
                    bst.remove(valor);
                    break;
                case 3:
                    bst.print();
                    break;
                case 4:
                    cout<<"Valor a buscar: "; 
                    cin>>valor;
                    if(bst.find(valor)){
                        cout<<"El valor "<<valor<<" si se encuentra en el arbol.\n";
                    }else{
                        cout<<"El valor no existe.\n";
                    }
                    break;
                case 5:
                    cout<<"Recorrido (1=Preorder, 2=Inorder, 3=Postorder, 4=LevelByLevel): "; 
                    cin>>metodo;
                    bst.visit(metodo);
                    break;
                case 6:
                    cout<<"Altura del arbol: "<<bst.height()<<"\n";
                    break;
                case 7:
                    cout<<"Ingresa el nodo para buscar sus ancestros: "; 
                    cin>>valor;
                    bst.ancestors(valor);
                    break;
                case 8:
                    cout<<"Ingresa el nodo para consultar su nivel: "; 
                    cin>>valor;
                    res= bst.whatLevelAmI(valor);
                    if(res != -1){
                        cout<<"El nodo esta en el nivel: "<<res<<"\n";
                    }else{
                        cout<<"Resultado: "<<res<<" (No existe)\n";
                    }
                    break;
                default:
                    cout<<"Opcion no valida.\n";
            }
        }catch(ios_base::failure& ex){
            cout<<"Error de formato. Por favor introduce un numero entero.\n";
            cin.clear(); 
            cin.ignore(1000, '\n');
        }catch(const out_of_range& ex){
            cout<<"Excepcion: "<<ex.what()<<"\n";
        }
    }while(opcion != 0);

    return 0;
}