#ifndef LUGAR_H
#define LUGAR_H

#include <iostream>
#include <vector>
#include "Item.h"

class Lugar {
    public:
        Lugar();
        Lugar(std::string);
        Lugar* getSalida(std::string);
        Item getRecompensa(int);
        void setRecompensa(int, Item);
        void setSalida(Lugar*,Lugar*,Lugar*,Lugar*);
        std::string getDescripcion();
        int numSalida(std::string);

    private:
        Lugar* salidas[4];
        std::string descripcion;
        std::vector <Item*> recompensa;
        int llaves;

}; 
#endif
