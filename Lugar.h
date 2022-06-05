#ifndef LUGAR_H
#define LUGAR_H

#include <iostream>
#include <vector>

class Lugar {
    public:
        Lugar();
        Lugar(std::string, bool);
        Lugar* getSalida(std::string);
        
    private:
        Lugar* salidas[4];
        bool abierto;


}; 
#endif
