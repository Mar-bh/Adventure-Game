#ifndef ENEMIGO_H
#define ENEMIGO_H
#include "Personaje.h"

class Enemigo:public Personaje
{
private:
    int nivelPeligro;
public:
    Enemigo(std::string _nombre,int _puntaje,Lugar _posicion,std::vector <Item*> _inventario,
    int _nivelPeligro);
    int getnivelPeligro() const; 
    Personaje getNombre()const;
    Personaje getPuntaje()const;
    Personaje getPosicion();
    void setnivelPeligro(int);    
    void setNombre(Personaje);
    void setPuntaje(Personaje);
    void setPosicion(Personaje);
    void dialogo(); 
    void quitaPuntaje();
    void caracteristicas();
};

#endif 