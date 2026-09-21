#ifndef LOGS_H
#define LOGS_H
#include <iostream>
#include <string>

class Logs{
    private:
        std::string raw; //la linea cruda
        int year;
        int month;
        int day;
        std::string time;
        std::string parip;//paddedIP. cambio el nombre mañana smh
        std::string error;

    public:
        Logs();
        Logs(std::string line);
        int mesToInt(const std::string& m);
        std::string padIPfunc(const std::string& ip);

        //sobreescribir
        bool operator<(const Logs& other) const;
        bool operator>(const Logs& other) const;
        bool operator<=(const Logs& other) const;
        bool operator==(const Logs& other) const;
        friend std::ostream& operator<<(std::ostream& os, const Logs& log);
};


#endif