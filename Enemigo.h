#ifndef ENEMIGO_H
#define ENEMIGO_H
#include "Personaje.h"

class Enemigo:public Personaje
{
private:
    int nivelPeligro;
public:
    Enemigo();
    Enemigo(std::string _nombre,int _puntaje,Lugar* _posicion,std::vector <Item*> _inventario,int _nivelPeligro);
    int getnivelPeligro() const; 
    void setnivelPeligro(int);    
    void dialogo(); 
    void quitaPuntaje();
};

#endif 