#include "Logs.h"
#include <iostream>
using namespace std;

Logs::Logs() : year(0), month(0), day(0), time(""), parip(""), error("") {};

Logs::Logs(string line){
    this-> raw= line;
    //regreso
}

//Si hay una manera más linda, disculpe
int Logs::mesToInt(const string& m){
    if (m== "Jan") return 1;
    if (m== "Feb") return 2;
    if (m== "Mar") return 3;
    if (m== "Apr") return 4;
    if (m== "May") return 5;
    if (m== "Jun") return 6;
    if (m== "Jul") return 7;
    if (m== "Aug") return 8;
    if (m== "Sep") return 9;
    if (m== "Oct") return 10;
    if (m== "Nov") return 11;
    if (m== "Dec") return 12;
    return 0;
}

string Logs::padIP(const string& ip){
//hacer split con cada punto. agh ya veo mañana
}

//después de esto, el bombazo de overloads.