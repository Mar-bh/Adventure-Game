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
    Pollos(std::string,int,Lugar,std::vector <Item*>,int,std::string);
    std::string getColor() const; 
    int getValor() const; 
    void setNombre(Personaje);
    void setColor(std::string);
    void setValor(int);
    void caracteristicas();
};

#endif 
