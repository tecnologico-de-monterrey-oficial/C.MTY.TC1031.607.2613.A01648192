#pragma once
#include <string>
#include <sstream>

using namespace std;

struct LogRecord{
    string month;
    int day;
    int year;
    string time;
    string ip;
    string event;
    string originalLine;

    int getMonthInt() const{
        if(month=="Jan") return 1; if(month=="Feb") return 2;
        if(month=="Mar") return 3; if(month=="Apr") return 4;
        if(month=="May") return 5; if(month=="Jun") return 6;
        if(month=="Jul") return 7; if(month=="Aug") return 8;
        if(month=="Sep") return 9; if(month=="Oct") return 10;
        if(month=="Nov") return 11; if(month=="Dec") return 12;
        return 0;
    }

    long long getTimestamp() const{
        int h, m, s;
        char colon;
        stringstream ss(time);
        ss>>h>>colon>>m>>colon>>s;
        long long ts= year;
        ts= ts * 100 + getMonthInt();
        ts= ts * 100 + day;
        ts= ts * 100 + h;
        ts= ts * 100 + m;
        ts= ts * 100 + s;
        return ts;
    }

    bool operator<=(const LogRecord& other) const{
        return this->getTimestamp() <= other.getTimestamp();
    }
    
    bool matchDate(string m, int d, int y) const{
        return month==m && day==d && year==y;
    }
};