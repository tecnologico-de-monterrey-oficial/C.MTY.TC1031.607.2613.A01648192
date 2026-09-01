/*Realiza un programa de c++ que contenga 2 funciones, una para búsqueda secuencial y otra para la búsqueda binaria, en el main crea un vector con 10,000 números aleatorios, entre 1 y 1,000,000, ordénalos con la función sort de c++ con vectores, solicita al usuario un número entero entre 1 y 1,000,000 y muestra en pantalla si el número se encuentra en la lista o no.

Muestra el tiempo que se tardó en buscar el número en la lista con cada una de las funciones de búsqueda,

El programa deberá de seguir preguntando por números hasta que el usuario teclee 0.

Realiza otro programa en c++ para que haga lo siguiente:
Los strings de una aplicación contienen caracteres duplicados y continuos, excepto uno por
string, Se te pide una aplicación que para cada uno de los string identifique el carácter único
y diga la cantidad de comparaciones que se realizan en forma secuencia y cuantos en forma
binaria.

Entrada
En una línea vendrá n - la cantidad de strings, posteriormente vendrán n lineas de strings.

Salida
Por cada string despliegue en una línea el carácter único y la cantidad de comparaciones que
se llevo el realizarlo con una búsqueda secuencial, posteriormente desplegando el carácter
único y la cantidad de comparaciones que se llevo el realizarlo en una búsqueda binaria.

Ejemplo de entrada:
4
AACCZZTTVXX
AAB
CCAAXWWTT
XXYYZZAAC

Ejemplo de salida:
V 5 V 2
B 1 B 1
X 3 X 1
C 4 C 3*/


//para la parte de random ocupe: https://stackoverflow.com/questions/21516575/fill-a-vector-with-random-numbers-c
#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <chrono>

using namespace std;

// secuencial
template <typename T>
int secuencial(const vector<T> &list, T seek) {
    for (int i = 0; i < list.size(); i++) {
        if (list[i] == seek) {
            return i;
        }
    }
    return -1;
}

// binaria
template <typename T>
int binarySearch(const vector<T> &list, T seek) {
    int left = 0;
    int right = list.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (seek == list[mid]) {
            return mid;
        } else if (seek < list[mid]) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return -1;
}

int main() {
    random_device rnd_device;
    mt19937 mersenne_engine{rnd_device()};
    uniform_int_distribution<int> dist{1, 1000000};
    
    vector<int> vec(10000);
    generate(vec.begin(), vec.end(), [&](){ return dist(mersenne_engine); });
    
    sort(vec.begin(), vec.end());
    
    int seek;
    cout << "Teclea un numero a buscar entre 1 y 1,000,000 (0 para salir): ";
    
    while (cin >> seek && seek != 0) {
        auto start_seq = chrono::high_resolution_clock::now();
        int pos_seq = secuencial(vec, seek);
        auto end_seq = chrono::high_resolution_clock::now();
        chrono::duration<double, std::micro> time_seq = end_seq - start_seq;
        
        auto start_bin = chrono::high_resolution_clock::now();
        int pos_bin = binarySearch(vec, seek);
        auto end_bin = chrono::high_resolution_clock::now();
        chrono::duration<double, std::micro> time_bin = end_bin - start_bin;
        
        if (pos_bin != -1) {
            cout << "SÍ está el num buscado" << endl;
        } else {
            cout << "No está el num buscado" << endl;
        }
        
        cout << "Tiempo para secuencial: " << time_seq.count() << " microsegundos." << endl;
        cout << "Tiempo para binario: " << time_bin.count() << " microsegundos.\n" << endl;
        
        cout << "num a buscar (0 para salir): ";
    }
    
    return 0;
}