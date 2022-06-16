#ifndef MOVIMIENTOCOMANDO_H
#define MOVIMIENTOCOMANDO_H
#include <iostream>
#include "Personaje.h"
#include "Comando.h"

class MovimientoComando:public Comando{
    public:
        MovimientoComando(Personaje*);
        void ejecuta();
    private:
        Personaje* jugador;
}; 

#endif