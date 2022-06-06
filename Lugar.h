#ifndef LUGAR_H
#define LUGAR_H

#include <iostream>
#include <vector>
#include "Item.h"

class Lugar {
    public:
        Lugar();
        Lugar(std::string);
        Item* getItem(int);
        void setItem(int, Item);
        Lugar* getSalida(char);
        Item getRecompensa(int);
        void setRecompensa(int, Item);
        void setSalida(Lugar*,Lugar*,Lugar*,Lugar*);
        std::string getDescripcion();
        int numSalida(char);

    private:
        Lugar* salidas[4];
        std::string descripcion;
        std::vector <Item*> recompensa;
        int llaves;

}; 
#endif
