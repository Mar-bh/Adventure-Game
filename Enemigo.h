#ifndef ENEMIGO_H
#define ENEMIGO_H
#include "Personaje.h"

class Enemigo:public Personaje{
private:
    int nivelPeligro;
public:
    Enemigo();
    Enemigo(std::string,int,Lugar*,int );
    int getnivelPeligro() const; 
    void setnivelPeligro(int);    
    void dialogo(); 
    void quitaPuntaje();
};

#endif 