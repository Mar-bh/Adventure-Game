#ifndef PERSONAJE_H
#define PERSONAJE_H
#include <iostream>
#include <vector>
#include "Lugar.h"

class Personaje
{
private:
    std::string nombre;
    int puntaje;
    //Personaje* inventario[1];
    std::vector <Item*> Inventario;
    Lugar descripcion;

public:
    Personaje();
    Personaje(std::string,int,Lugar,std::vector <Item*>);
    ~Personaje();//
    std::string getNombre() const; 
    int getPuntaje(); 
    Lugar getDescripcion();
    Item* getInventario();
    void setPersonaje(std::string);
    void setDescipcion(std::string);
    void setPuntos(int);
    void setInventario(std::vector <Item*>);
    void descripcion();
};

#endif 