#ifndef ENEMIGO_H
#define ENEMIGO_H
#include "Personaje.h"

class Pollos:public Personaje
{
private:
    std::string color;
    int valor;
public:
    Pollos(int,std::string,Personaje);
    std::string getColor() const; 
    int getValor() const; 
    Personaje getNombre()const;
    void setNombre(Personaje);
    void setColor(std::string);
    void setValor(int);
    void caracteristicas();
};

#endif 