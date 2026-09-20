#include "Logs.h"
#include <iostream>
#include <sstream> //SSTREAM
using namespace std;

Logs::Logs(): year(0), month(0), day(0), time(""), parip(""), error("") {};

Logs::Logs(string line){
    this->raw= line;
    stringstream ss(line);
    string mStr, raw;
    //month, day, year, hour:minute:second, ip, error
    ss>> mStr>> this->day>> this->year>> this->time>> raw;

    string restoLine;//resto de la linea, o sea, el error
    getline(ss, restoLine);

    if (!restoLine.empty() && restoLine[0]==' '){
        restoLine.erase(0, 1);
    }
    this->error= restoLine;

    this->month= mesToInt(mStr);
    this->parip= padIPfunc(raw);
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

string Logs::padIPfunc(const string& ip){
    stringstream ss(ip);
    string segment;
    string padded= "";

    //split the IP every period to pad
    while (getline(ss, segment, '.')){
        if(padded.length()>0){
            padded+= ".";
        }
        string zeros = "000";
        zeros= zeros.substr(0, 3-segment.length()) + segment;
        padded+= zeros;
    }
    return padded;
}

//sobreescribir
bool Logs::operator<(const Logs& other) const{
    if (this->year != other.year) return this->year < other.year;
    if (this->month != other.month) return this->month < other.month;
    if (this->day != other.day) return this->day < other.day;
    if (this->time != other.time) return this->time < other.time;
    if (this->parip != other.parip) return this->parip < other.parip;
    return this->error < other.error;
}

bool Logs::operator>(const Logs& other) const{
    if (this->year != other.year) return this->year > other.year;
    if (this->month != other.month) return this->month > other.month;
    if (this->day != other.day) return this->day > other.day;
    if (this->time != other.time) return this->time > other.time;
    if (this->parip != other.parip) return this->parip > other.parip;
    return this->error > other.error;
}

bool Logs::operator<=(const Logs& other) const{
    return!(*this>other);
}

ostream& operator<<(ostream& os, const Logs& log){
    os<<log.raw;
    return os;
}