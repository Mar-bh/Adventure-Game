#ifndef LUGAR_H
#define LUGAR_H
#include "Item.h"
#include <iostream>
#include <vector>

class Lugar {
    public:
        Lugar();
        Lugar(std::string, bool);
        Lugar* getSalida(std::string);
        Item getRecompensa(int);
        void setRecompensa(int, Item);
        void setSalida(char, Lugar);
        std::string getDescripcion();

    private:
        Lugar* salidas[4];
        std::string descripcion;
        Item* recompensa[];

}; 
#endif
