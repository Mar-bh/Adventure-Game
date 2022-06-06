#ifndef LUGAR_H
#define LUGAR_H

#include <iostream>
#include <vector>
#include "Item.h"

class Lugar {
    public:
        Lugar(); //l
        Lugar(std::string); //listo
        Lugar* getSalida(char); //listo
        Item* getRecompensa(int);
        void setRecompensa(std::vector <Item*>); //listo
        void setSalida(Lugar*,Lugar*,Lugar*,Lugar*); //listo
        void descripcion(); //listo
        std::string getDescripcion(); //listo
        int numSalida(char); //listo

    private:
        Lugar* salidas[4];
        std::string descripcion;
        std::vector <Item*> recompensa;
        int llaves;

}; 
#endif
