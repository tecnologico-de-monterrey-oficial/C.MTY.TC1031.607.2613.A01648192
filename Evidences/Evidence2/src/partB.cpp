//Michelle Lagos A01648192
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <chrono>
#include <map>
#include "../include/Queue.h"
#include "../include/Stack.h"
#include "../include/DoubleLinkedList.h"
#include "../include/LogRecord.h"

using namespace std;

bool parseLine(const string& line, LogRecord& record){
    stringstream ss(line);
    string month, time, ip, eventWord, eventFull;
    int day, year;
    if(ss>>month>>day>>year>>time>>ip){
        while(ss>>eventWord){
            if(!eventFull.empty()) eventFull+= " ";
            eventFull+= eventWord;
        }
        if(eventFull.empty() || month.length()!=3) return false;
        record.month= month;
        record.day= day;
        record.year= year;
        record.time= time;
        record.ip= ip;
        record.event= eventFull;
        record.originalLine= line;
        return true;
    }
    return false;
}

int main(){
    cin.exceptions(ios::failbit | ios::badbit);
    Queue<string> readBuffer;
    DoubleLinkedList<LogRecord> database;
    string filename;
    ifstream file;
    
    while(true){
        cout<<"Archivo a cargar (log607-1.txt o log607-2.txt): ";
        cin>>filename;
        string fullPath= "../" + filename; 
        file.open(fullPath);
        
        if(file.is_open()){
            break;
        }else{
            cout<<"No se encontro el archivo. Intenta de nuevo.\n"<<endl;
        }
    }

    string line;
    while(getline(file, line)){
        if(!line.empty()) readBuffer.enqueue(line);
    }
    file.close();

    int lineNum= 1, omitted= 0, loaded= 0;
    while(!readBuffer.isEmpty()){
        string currentLine= readBuffer.dequeue();
        LogRecord record;
        if(parseLine(currentLine, record)){
            database.addLast(record);
            loaded++;
        }else{
            cout<<"Linea invalida omitida ("<<lineNum<<"): "<<currentLine<<endl;
            omitted++;
        }
        lineNum++;
    }
    cout<<"Cargados: "<<loaded<<" | Omitidos: "<<omitted<<endl;

    int opcion= 0;
    bool isSorted= false;
    
    do{
        bool opcionValida= false;
        do{
            try{
                cout<<"\nMENU\n";
                cout<<"1. Ordenar por fecha\n2. Buscar por dia\n3. Mostrar dia descendente\n4. Estadisticas\n5. Salir\n> ";
                cin>>opcion;
                opcionValida= true;
            }catch(ios_base::failure& ex){
                cout<<"Entrada no valida."<<endl;
                cin.clear();
                cin.ignore(1000, '\n');
            }
        }while(!opcionValida);

        if(opcion==1){
            if(isSorted){
                cout<<"Ya esta ordenado."<<endl;
            }else{
                string prediccion;
                cout<<"Prediccion de comparaciones: ";
                cin.ignore(1000, '\n');
                getline(cin, prediccion);
                
                int comparaciones= 0, profMax= 0;
                auto start= chrono::high_resolution_clock::now();
                database.sort(comparaciones, profMax);
                auto end= chrono::high_resolution_clock::now();
                chrono::duration<double, std::milli> duration= end - start;
                
                isSorted= true;
                cout<<"\nRESULTADOS MERGE SORT"<<endl;
                cout<<"Tiempo: "<<duration.count()<<" ms"<<endl;
                cout<<"Comparaciones: "<<comparaciones<<endl;
                cout<<"Profundidad recursion: "<<profMax<<endl;
                cout<<"Prediccion: "<<prediccion<<endl;
                
                ofstream out("output608.out");
                NodeD<LogRecord>* aux= database.getHead();
                while(aux!=nullptr){
                    out<<aux->data.originalLine<<"\n";
                    aux= aux->next;
                }
                out.close();
                cout<<"Archivo output608.out generado."<<endl;
            }
        }else if(opcion==2 || opcion==3){
            if(!isSorted){
                cout<<"Ordena los datos primero."<<endl;
                continue;
            }
            string sMonth;
            int sDay, sYear;
            try{
                cout<<"Mes (primer tres letras: Sep, Oct, etc.): "; cin>>sMonth;
                cout<<"Dia: "; cin>>sDay;
                cout<<"Year: "; cin>>sYear;
            }catch(...){
                cout<<"Datos invalidos."<<endl;
                cin.clear(); cin.ignore(1000, '\n');
                continue;
            }
            
            NodeD<LogRecord>* aux= database.getHead();
            int count= 0;
            
            if(opcion==2){
                while(aux!=nullptr){
                    if(aux->data.matchDate(sMonth, sDay, sYear)){
                        cout<<aux->data.originalLine<<endl;
                        count++;
                    }else if(count>0){
                        break; 
                    }
                    aux= aux->next;
                }
                cout<<"Total encontrados: "<<count<<endl;
            }else{
                Stack<LogRecord> invStack;
                while(aux!=nullptr){
                    if(aux->data.matchDate(sMonth, sDay, sYear)){
                        invStack.push(aux->data);
                        count++;
                    }else if(count>0){
                        break;
                    }
                    aux= aux->next;
                }
                while(!invStack.isEmpty()){
                    cout<<invStack.pop().originalLine<<endl;
                }
                cout<<"Total encontrados: "<<count<<endl;
            }
        }else if(opcion==4){
            map<string, int> dayCounts, eventCounts, ipCounts;
            NodeD<LogRecord>* aux= database.getHead();
            while(aux!=nullptr){
                string dateStr= aux->data.month + " " + to_string(aux->data.day) + " " + to_string(aux->data.year);
                dayCounts[dateStr]++;
                eventCounts[aux->data.event]++;
                ipCounts[aux->data.ip]++;
                aux= aux->next;
            }
            
            int maxDays= 0, maxEvents= 0, maxIPs= 0;
            for(auto const& [key, val] : dayCounts) if(val>maxDays) maxDays= val;
            for(auto const& [key, val] : eventCounts) if(val>maxEvents) maxEvents= val;
            for(auto const& [key, val] : ipCounts) if(val>maxIPs) maxIPs= val;
            
            cout<<"\nESTADISTICAS"<<endl;
            cout<<"Total validos: "<<database.getSize()<<endl;
            cout<<"Dias con mas incidentes ("<<maxDays<<"):"<<endl;
            for(auto const& [key, val] : dayCounts) if(val==maxDays) cout<<key<<endl;
            cout<<"Eventos mas frecuentes ("<<maxEvents<<"):"<<endl;
            for(auto const& [key, val] : eventCounts) if(val==maxEvents) cout<<key<<endl;
            cout<<"IPs mas frecuentes ("<<maxIPs<<"):"<<endl;
            for(auto const& [key, val] : ipCounts) if(val==maxIPs) cout<<key<<endl;
        }
    }while(opcion!=5);

    cout<<"Bye bye"<<endl;
    return 0;
}