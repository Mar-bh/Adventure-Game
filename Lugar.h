#ifndef LUGAR_H
#define LUGAR_H
#include "Item.h"
#include <iostream>
#include <vector>
#include "Item.h"

class Lugar {
    public:
        Lugar(); //l
        Lugar(std::string,int); //listo
        Lugar* getSalida(char); //listo
        Item* getRecompensa(int); //listo
        void setRecompensa(Item*); //listo
        void setSalida(Lugar*,Lugar*,Lugar*,Lugar*); //listo
        void descripcionLarga(); //listo    
        void sacarRecompensa(int);
        void setDescripcion(std::string);
        std::string getDescripcion(); //listo
        int numSalida(char); //listo
        int cantidadLlaves();

    private:
        Lugar* salidas[4];
        std::string descripcion;
        std::vector <Item*> recompensa;
        int llaves;
}; 
#endif
