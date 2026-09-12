#include <iostream>
#include <vector>
#include <chrono>
#include <cstdlib> //rand
#include <ctime>
using namespace std;

//esta función tuve que buscarla y la hice mal jaja, Gemini encontró eso
template <typename T>
vector<T> generarRandom(int size) {
    vector<T> vec(size);
    for(int i = 0; i < size; i++) {
        vec[i] = static_cast<T>(rand() % 1000); 
    }
    return vec;
}

template <typename T>
void swapS(vector<T> &list, long long &comps, long long &swaps){
    comps=0;
    swaps=0;
    for (int i=0;i<list.size()-1;i++){
        for(int j=i+1;j<(list.size());j++){
            comps++;
            if (list[i]>list[j]){
                swap(list[i],list[j]);
                swaps++;
            }
        }
    }
}

//Gemini hizo un cambio muy importante. Me dijo que necesitaba de ocupar long long para evitar printing valores inservibles
template <typename T>
void bubbleS(vector<T> &list, long long &comps, long long &swaps){
    comps=0;
    swaps=0;
    for (int i=0;i<list.size()-1;i++){
        for(int j=0;j<(list.size()-1);j++){
            comps++;
            if (list[j]>list[j+1]){
                swap(list[j],list[j+1]);
                swaps++;
            }
        }
    }
}

template <typename T>
void selectionS(vector<T> &list, long long &comps, long long &swaps){
    comps=0;
    swaps=0;
    for (int i=0; i<list.size()-1; i++){
        int min=i;
        for(int j=i+1; j<list.size(); j++){
            comps++;
            if (list[j]< list[min]){
                min=j;
                swaps++;
            }
        }
        swap(list[min], list[i]);
    }

}


template <typename T>
void insertS(vector<T> &list, long long &comps, long long &swaps){
    comps=0;
    swaps=0;
    for (int i=1; i<list.size(); i++){
        comps++;
        int j=i;
        while(j>0 && (list[j]< list[j-1])){
            swap(list[j], list[j-1]);
            j--;
            swaps++;
            if (j > 0) comps++;
        }
    }
}


//me trabe demasiado en la logica del quickSort. credito a GeeksforGeeks por ayudarme a encontrar mis fallas logicas https://www.geeksforgeeks.org/dsa/quick-sort-algorithm/
template <typename T>
int splitQS(vector<T> &list, int start, int end){
    T pivot= list[end];
    int aux = start- 1;
    for(int j=start; j<=(end-1); j++){
        if(pivot>list[j]){
            aux++;
            swap(list[aux],list[j]);
        }
    }
    swap(list[aux+1], list[end]);
    return aux+1;
}

template <typename T>
void quickS(vector<T> &list, int start= 0, int end =-1){
    if (end == -1) {
        end = list.size() - 1;
    }
    if (start < end) {
        int pi = splitQS(list, start, end);
        quickS(list, start, pi - 1);
        quickS(list, pi + 1, end);
    }
}


//el algoritmo que más tuvo que editar Gemini. De hecho, fue por este que me di cuenta que tenía que hacer cambios a otros.
//Los cambios que me dijo que hiciera eran pq el método que vimos en clase nunca funcionaría en listas tan grandes
//algunos cambios  incluyen: calcular el tamaño de las mitades primero y pre alocarlos
//me recomendó cambiar algunos nombres de variables para mejor lectura. entre otros.
template <typename T>
void merge(vector<T> &list, int left, int mid, int right) {
    int n1= mid-left+1;
    int n2= right-mid;
    vector<T> L(n1), R(n2);

    for (int i= 0; i<n1; i++) {
        L[i]= list[left+i];
    }
    for (int j = 0; j < n2; j++) {
        R[j]= list[mid+1+j];
    }
    int i= 0, j= 0, k= left;
 
    while (i<n1 && j<n2) {
        if (L[i]<=R[j]) { 
            list[k]= L[i]; 
            i++; 
        } else { 
            list[k]= R[j]; 
            j++; 
        }
        k++;
    }
    while (i<n1) {list[k]= L[i]; i++; k++;}
    while (j<n2) {list[k]= R[j]; j++; k++;}
}

template <typename T>
void mergeSort(vector<T> &list, int left= 0, int right= -1) {
    if (right== -1) {
        right= list.size()-1;
    }
    
    if (left< right) {
        int mid= left+(right-left)/2;
        
        mergeSort(list, left, mid);
        mergeSort(list, mid+1, right);
        merge(list, left, mid, right);
    }
}

template <typename T>
void shellS(vector<T> &list) {
    int n= list.size();
    for (int gap= n/2; gap>0; gap/= 2) {
        for (int i= gap; i<n; i++) {
            T temp = list[i];
            int j;
            for (j= i; j>=gap && list[j-gap]>temp; j-=gap) {
                list[j]= list[j-gap];
            }
            list[j]= temp;
        }
    }
}

template <typename T>
void printVec(vector<T> &list){
    for (int i=0;i<list.size();i++){
        cout<<list[i]<<", ";
    }
    cout<<endl;
}

int main() {
    srand(time(0));
    int opcion = 0;
    long long comps = 0, swaps = 0;
    
    //saqué mucho código de mi proyecto en el curso pasado, con Salinas. todo lo de menú y exceptions viene de ahí
    cin.exceptions(ios::failbit | ios::badbit);
    do {
        bool opcionValida= false;
        do {
            try {
                cout<<"\nSorting algortimps- elige uno de los siguientes"<<endl;
                cout<<"1. Swap Sort\n2. Bubble Sort\n3. Selection Sort\n4. Insertion Sort"<<endl;
                cout<<"5. Merge Sort\n6. Quick Sort\n7. Shell Sort\n9. Salir\n";
                cin>>opcion;
                opcionValida= true;
            } catch(ios_base::failure& ex){
                cout<<"Error. Introduce un numero valido."<<endl;
                cin.clear();
                cin.ignore(1000, '\n');
            }
        }while (!opcionValida);
        if (opcion>=1 && opcion<=7) {
            cout<<"Creando las listas aleatorias.\n";
            vector<int> list1k= generarRandom<int>(1000);
            vector<int> list10k= generarRandom<int>(10000);
            vector<int> list100k= generarRandom<int>(100000);
            
            auto start1= chrono::high_resolution_clock::now();
            auto end1= start1;
            auto start2= start1, end2= start1;
            auto start3= start1, end3= start1;

            string nombreAlgoritmo= "";

            switch (opcion) {
                case 1:
                    nombreAlgoritmo= "swapSort";
                    start1= chrono::high_resolution_clock::now(); swapS(list1k, comps, swaps); end1= chrono::high_resolution_clock::now();
                    start2= chrono::high_resolution_clock::now(); swapS(list10k, comps, swaps); end2= chrono::high_resolution_clock::now();
                    start3= chrono::high_resolution_clock::now(); swapS(list100k, comps, swaps); end3= chrono::high_resolution_clock::now();
                    break;
                case 2:
                    nombreAlgoritmo= "bubbleSort";
                    start1= chrono::high_resolution_clock::now(); bubbleS(list1k, comps, swaps); end1= chrono::high_resolution_clock::now();
                    start2= chrono::high_resolution_clock::now(); bubbleS(list10k, comps, swaps); end2= chrono::high_resolution_clock::now();
                    start3= chrono::high_resolution_clock::now(); bubbleS(list100k, comps, swaps); end3= chrono::high_resolution_clock::now();
                    break;
                case 3:
                    nombreAlgoritmo= "selectionSort";
                    start1= chrono::high_resolution_clock::now(); selectionS(list1k, comps, swaps); end1= chrono::high_resolution_clock::now();
                    start2= chrono::high_resolution_clock::now(); selectionS(list10k, comps, swaps); end2= chrono::high_resolution_clock::now();
                    start3= chrono::high_resolution_clock::now(); selectionS(list100k, comps, swaps); end3= chrono::high_resolution_clock::now();
                    break;
                case 4:
                    nombreAlgoritmo= "insertionSort";
                    start1= chrono::high_resolution_clock::now(); insertS(list1k, comps, swaps); end1= chrono::high_resolution_clock::now();
                    start2= chrono::high_resolution_clock::now(); insertS(list10k, comps, swaps); end2= chrono::high_resolution_clock::now();
                    start3= chrono::high_resolution_clock::now(); insertS(list100k, comps, swaps); end3= chrono::high_resolution_clock::now();
                    break;
                case 5:
                    nombreAlgoritmo= "mergeSort";
                    start1= chrono::high_resolution_clock::now(); mergeSort(list1k); end1= chrono::high_resolution_clock::now();
                    start2= chrono::high_resolution_clock::now(); mergeSort(list10k); end2= chrono::high_resolution_clock::now();
                    start3= chrono::high_resolution_clock::now(); mergeSort(list100k); end3= chrono::high_resolution_clock::now();
                    break;
                case 6:
                    nombreAlgoritmo= "quickSort";
                    start1= chrono::high_resolution_clock::now(); quickS(list1k); end1= chrono::high_resolution_clock::now();
                    start2= chrono::high_resolution_clock::now(); quickS(list10k); end2= chrono::high_resolution_clock::now();
                    start3= chrono::high_resolution_clock::now(); quickS(list100k); end3= chrono::high_resolution_clock::now();
                    break;
                case 7:
                    nombreAlgoritmo= "shellSort";
                    start1= chrono::high_resolution_clock::now(); shellS(list1k); end1= chrono::high_resolution_clock::now();
                    start2= chrono::high_resolution_clock::now(); shellS(list10k); end2= chrono::high_resolution_clock::now();
                    start3= chrono::high_resolution_clock::now(); shellS(list100k); end3= chrono::high_resolution_clock::now();
                    break;
            }

            auto time1k= chrono::duration_cast<chrono::nanoseconds>(end1-start1).count();
            auto time10k= chrono::duration_cast<chrono::nanoseconds>(end2-start2).count();
            auto time100k= chrono::duration_cast<chrono::nanoseconds>(end3-start3).count();

            // 1000 nada mas pq quiero mucho a mi laptopt
            cout << "\nLista ordenada: \n";
            for(int i = 0; i < list1k.size(); i++) {
                cout << list1k[i] << " ";
            }
            cout << "\n\n"; 
            
            
            if (opcion <= 4) {
                cout<<"Comparaciones sobre las de 100,000\n";
                cout<<"Comparaciones: "<<comps<<"\nIntercambios: "<<swaps<<"\n\n";
            }

            cout << "algoritmo, tipo de dato, tiempo1000, tiempo10000, tiempo100000\n";
            cout << nombreAlgoritmo << ", int, " << time1k << ", " << time10k << ", " << time100k << "\n";
        } else if (opcion!=9) {
            cout<<"Opcion no valida."<<endl;
        }

    }while(opcion != 9);

    cout<<"Bye bye"<<endl;
    return 0;
}
//primer loop para hacer swap, segundo para checar el menor
//15, 7, 3, 9, 12, 5, 2 