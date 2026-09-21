#include <iostream>
#include <vector>
#include <chrono>
#include <fstream>
#include <string>
#include "Logs.h"
#include "Sorts.h"
using namespace std;

int binarySearch(const vector<Logs>& list, const Logs& seek){
    int left= 0;
    int right= list.size()-1;
    int closest= left;

    while(left<=right){
        int mid= left+ (right - left)/2;

        if(list[mid]==seek){
            return mid; //fecha exacta
        }else if(list[mid]<seek){
            left= mid+1;
            closest= left;//por si no existe
        }else{
            right= mid - 1;
            closest= mid;
        }
    }
    if(closest>= list.size()){
        return list.size()-1;
    }
    return closest;
}


void dataLogs(vector<Logs>& logs, const string& archivo){
    logs.clear();//sugerencia de gemini para que el vector no duplique los datos en reruns
    ifstream file(archivo);
    if (!file.is_open()){
        cout<<"No se pudo abrir archivo "<<archivo<<endl;
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

//exportar el sorting más reciente al mismo archivo
void saveLogs(const vector<Logs>& logs){
    string archivo= "out/output608.txt";
    ofstream file(archivo);
    for (int i=0; i<logs.size(); i++){
        file<<logs[i]<<endl;
    }
    file.close();
    cout<<"Nuevo archivo ordenado: "<<archivo<<endl;
}

int main(){
    cin.exceptions(ios::failbit | ios::badbit);
    bool repetir= true;
    long long comps= 0;
    long long swaps= 0;
    while (repetir){
        int chooseArchivo= 0; 
        bool opcionValida= false;
        do{
            try{
                cout<<"Elige una base de datos"<<endl;
                cout<<"1. log607-1txt (database desordenada)"<<endl;
                cout<<"2. log607-2.txt (database casi ordenada)"<<endl;
                cin>>chooseArchivo;
                if (chooseArchivo==1 || chooseArchivo==2){
                    opcionValida= true;
                }else{
                    cout<<"Selecciona 1 o 2."<<endl;
                }
            }catch(ios_base::failure& ex){
                cout<<"Error, selecciona un valor valido"<<endl;
                cin.clear();
                cin.ignore(1000, '\n');
            }
        }while (!opcionValida); //no se porque pero no le agarrab a esta parte de la logica, gemini me ayudo con lo de opcionValida
        string nombreArchivo= (chooseArchivo== 1)?"data/log607-1.txt": "data/log607-2.txt";

        vector<Logs> logsSortear;
        cout<<"Sorting: "<<nombreArchivo<<endl;
        dataLogs(logsSortear, nombreArchivo);
        cout<<"Cantidad de logs: "<<logsSortear.size()<<endl;
        //segundo menu, algoritmos, lo que ya tenia
        int opcionAlgo= 0;
        opcionValida= false;
        do{
            try{
                cout<<"\nElige uno para ordenar los logs"<<endl;
                cout<<"1. Swap Sort\n2. Bubble Sort\n3. Selection Sort\n4. Insertion Sort" << endl;
                cout<<"5. Merge Sort\n6. Quick Sort\n7. Shell Sort\n8. Salir"<<endl;
                cin>>opcionAlgo;
                if (opcionAlgo>=1 && opcionAlgo<=8){
                    opcionValida=true;
                }else{
                    cout<<"opcion no valida, elige de 1 al 8."<<endl;
                }
            }catch(ios_base::failure& ex){
                cout<<"Error. Elige del 1 al 8"<<endl;
                cin.clear();
                cin.ignore(1000, '\n');
            }
        }while (!opcionValida);
        cin.ignore(1000, '\n'); //otra sugerencia de Gemini, para limpiar la basura del buffer en preparacion a los siguientes inputs
        
        if (opcionAlgo==8){
            break;
        }

        //siguiente menu, predicciones de usuario
        string prediccion;
        cout<<"Que tan rapido esperas que sea el sorting con las opciones elegidas?"<<endl;
        getline(cin, prediccion);//preguntar
        string nombreAlgoritmo= "";
        string complejidad= "";

        auto start= chrono::high_resolution_clock::now();

        //info de BigO sacada de https://www.bigocheatsheet.com/
        switch (opcionAlgo) {
                case 1:
                    nombreAlgoritmo= "Swap_Sort";
                    complejidad= "Mejor caso: O(n^2), peor caso: O(n^2)";
                    swapS(logsSortear, comps, swaps); 
                    break;
                case 2:
                    nombreAlgoritmo= "Bubble_Sort";
                    complejidad= "Mejor caso: O(n), peor caso: O(n^2)";
                    bubbleS(logsSortear, comps, swaps); 
                    break;
                case 3:
                    nombreAlgoritmo= "Selection_Sort";
                    complejidad= "Mejor caso: O(n^2), peor caso: O(n^2)";
                    selectionS(logsSortear, comps, swaps); 
                    break;
                case 4:
                    nombreAlgoritmo= "Insertion_Sort";
                    complejidad= "Mejor caso: O(n), peor caso: O(n^2)";
                    insertS(logsSortear, comps, swaps); 
                    break;
                case 5:
                    nombreAlgoritmo= "Merge_Sort";
                    complejidad= "Mejor caso: O(n log n), peor caso: O(n log n)";
                    mergeSort(logsSortear); 
                    break;
                case 6:
                    nombreAlgoritmo= "Quick_Sort";
                    complejidad= "Mejor caso: O(n log n), peor caso: O(n^2)";
                    quickS(logsSortear); 
                    break;
                case 7:
                    nombreAlgoritmo= "Shell_Sort";
                    complejidad= "Mejor caso: O(n log n), peor caso: O(n^2)";
                    shellS(logsSortear); 
                    break;
        }

        auto end= chrono::high_resolution_clock::now();
        auto millis= chrono::duration_cast<chrono::milliseconds>(end-start).count();

        //resultados
        cout<<"\nResultados del sorting:"<<endl;
        cout<<"Algoritmo: "<< nombreAlgoritmo<<endl;
        cout<<"Database usado: "<<nombreArchivo<<", de tama;o: "<<logsSortear.size()<<endl;
        cout<<"Tiempo de ejecucion: "<<millis<<" ms"<<endl;
        //comparacion?
        cout<<"Tu prediccion fue: '"<<prediccion<<"'"<<endl;

        if (opcionAlgo<=4){
            cout<<"Comparaciones: "<<comps<<"\nIntercambios: "<<swaps<<endl;
        }
        cout<<"complejidad: "<<complejidad<<endl;

        saveLogs(logsSortear);

        //rangos con binary search

        //Busqué en google sobre cómo buscar solo la mitad del string
        //me salió el pop-up de IA de Google que me dio la idea, entonces acredito la idea a Gemini
        string startDate;
        string endDate;
        cout<<"\nBusqueda por rango"<<endl;//binary search
        cout<<"Ingresa la fecha y hora de incio. formato ejemplo: Sep 29 2025 10:00:00"<<endl;
        getline(cin, startDate);

        cout<<"Ingresa la fecha y hora de fin. formato ejemplo: Sep 29 2025 10:00:00 "<<endl;
        getline(cin, endDate);

        //he aqui la idea que me dio gemini:
        Logs startLog(startDate+" 000.000.000.000 A");
        Logs endLog(endDate+" 999.999.999.999 Z");

        int startIndex= binarySearch(logsSortear, startLog);

        //buscar a los lados
        while (startIndex>0 && logsSortear[startIndex - 1]==logsSortear[startIndex]){
            startIndex--;
        }

        ofstream rangeFile("out/range607.txt");
        int count= 0;
        int encontrado= false;
        cout<<"\nRegistros encontrados: "<<endl;
        for(int i= startIndex; i<logsSortear.size(); i++){
            if(logsSortear[i] >  endLog){
                break;
            }
            if(!(logsSortear[i]< startLog)){
                cout<<logsSortear[i]<<endl;
                rangeFile<<logsSortear[i]<<endl;
                count++;   
                encontrado= true;
            }
        }
        if (encontrado){
            cout<<"\n"<<count<<" logs encontrados dentro del rango."<<endl;
        }else{
            cout<<"No se encontraron logs en el rengo"<<endl;
            rangeFile<<"No se encontraron logs en el rango"<<endl;
        }
        rangeFile.close();

        //repetir?
        int respuesta= 0;
        opcionValida= false;
        do{
            try{
                cout<<"Quieres volver a sortear? \n1= si, 2= no"<<endl;
                cin>>respuesta;
                if(respuesta== 1 || respuesta== 2){
                    opcionValida= true;
                }else{
                    cout<<"Error, elige 1 o 2"<<endl;
                    cin.clear();
                    cin.ignore(1000, '\n');
                }
            }catch(ios_base::failure& ex){
                cout<<"Error. Elige 1 o 2"<<endl;
                cin.clear();
                cin.ignore(1000, '\n');
            }
        }while(!opcionValida);
        if (respuesta== 2){
            repetir= false;
        }
    }
    cout<<"Bye bye"<<endl;
    return 0;
}

//no me queda completamente claro lo de comparar?