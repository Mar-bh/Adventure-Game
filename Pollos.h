#ifndef POLLOS_H
#define POLLOS_H
#include "Personaje.h"

class Pollos:public Personaje
{
private:
    std::string color;
    int valor;
public:
    Pollos();
    Pollos(std::string _nombre,int _puntaje,Lugar _posicion,std::vector <Item*> _inventario,int _valor, std::string _color);
    std::string getColor() const; 
    int getValor() const; 
    std::string getNombre()const;
    void setNombre(Personaje);
    void setColor(std::string);
    void setValor(int);
    void caracteristicas();
};

#endif 
