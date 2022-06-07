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
    std::vector <Item*> inventario;
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
    void setDescripcion(std::string);
    void setPuntos(int);
    void setInventario(std::vector <Item*>);
    void muestraInventario(); //para mostrar el inventario necesitamos acceder al vector inventario y observar todos los items que tenemos, es un vector porque podemos agregar mas items.
    void agregaItems(Item);// agregamos mas items al inventario
    void consulta();/* consulta para poder ver el lugar en el que se encuentra por medio de posicion, consulta(posicion)?*/
    void pelea();// opciones de pelea
};

#endif 