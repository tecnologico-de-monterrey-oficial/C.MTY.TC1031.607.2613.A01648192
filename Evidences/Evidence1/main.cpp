#include <iostream>
#include <vector>
#include <chrono>
#include <fstream>
#include <string>
#include "Logs.h"
#include "Sorts.h"
using namespace std;

void dataLogs(vector<Logs>& logs, const string& archivo){
    ifstream file(archivo);
    if (!file.is_open()){
        cout<<"No se pudo abrir archivo."<<archivo<<endl;
        return;
    }
    string line;
    while (getline(file, line)){ //puse "archivo" en vez de "file" por accidente y me pasé media hora haciendo research sobre esto. estoy cansada
        if (!line.empty()){
            logs.push_back(Logs(line));
        }
    }
    file.close();
}

void saveLogs(const vector<Logs>& logs, const string& archivo){
    ofstream file(archivo);
    for (int i=0; i<logs.size(); i++){
        file<<logs[i]<<endl;
    }
    file.close();
    cout<<"Archivo: "<<archivo<<endl;
}

int main(){
    cin.exceptions(ios::failbit | ios::badbit);

    vector<Logs> original;
    dataLogs(original, "log607-1.txt");

    cout<<"Numero de registro: "<<original.size()<<endl;

    int opcion= 0;
    long long comps= 0;
    long long swaps= 0;

    do{
        bool opcionValida= false;
        do{
            try{
                cout<<"\nElige uno para ordenar los logs"<<endl;
                cout<<"1. Swap Sort\n2. Bubble Sort\n3. Selection Sort\n4. Insertion Sort" << endl;
                cout<<"5. Merge Sort\n6. Quick Sort\n7. Shell Sort\n9. Salir\n> ";
                cin>>opcion;
                opcionValida= true;
            }catch(ios_base::failure& ex){
                cout<<"Error. Elige del 1 al 9"<<endl;
                cin.clear();
                cin.ignore(1000, '\n');
            }
        }while (!opcionValida);
        if (opcion>=1 && opcion<=7){
            //crear copia de los unsorted
            vector<Logs> logsSortear= original;
            string nombreAlgoritmo= "";
            
            cout <<"\nOrdenando los"<<logsSortear.size()<<"datos."<<endl;
            auto start= chrono::high_resolution_clock::now();

            switch (opcion) {
                case 1:
                    nombreAlgoritmo= "Swap_Sort";
                    swapS(logsSortear, comps, swaps); 
                    break;
                case 2:
                    nombreAlgoritmo= "Bubble_Sort";
                    bubbleS(logsSortear, comps, swaps); 
                    break;
                case 3:
                    nombreAlgoritmo= "Selection_Sort";
                    selectionS(logsSortear, comps, swaps); 
                    break;
                case 4:
                    nombreAlgoritmo= "Insertion_Sort";
                    insertS(logsSortear, comps, swaps); 
                    break;
                case 5:
                    nombreAlgoritmo= "Merge_Sort";
                    mergeSort(logsSortear); 
                    break;
                case 6:
                    nombreAlgoritmo= "Quick_Sort";
                    quickS(logsSortear); 
                    break;
                case 7:
                    nombreAlgoritmo= "Shell_Sort";
                    shellS(logsSortear); 
                    break;
            }

            auto end= chrono::high_resolution_clock::now();
            auto millis= chrono::duration_cast<chrono::milliseconds>(end-start).count();

            cout<<"Algoritmo: "<<nombreAlgoritmo<<endl;
            cout<<"Tiempo de ejecucion: "<<millis<<" ms\n";

            if (opcion <= 4) {
                cout<<"Comparaciones: "<<comps<<"\nIntercambios: "<<swaps<<"\n";
            }

            //gardar a archivo
            string outputFile= "ordenado_"+ nombreAlgoritmo+ ".txt";
            saveLogs(logsSortear, outputFile);

        } else if (opcion != 9) {
            cout<<"Opcion no valida."<<endl;
        }

    }while(opcion != 9);

    cout<<"Bye bye"<<endl;
    return 0;
}