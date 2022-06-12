#ifndef PELEACOMANDO_H
#define PELEACOMANDO_H
#include <iostream>
#include "Personaje.h"
#include "Comando.h"

class PeleaComando:public Comando{
    public:
        PeleaComando(Personaje*, Personaje*);
        void ejecuta();
    private:
        Personaje* jugador;

};

#endif