#ifndef PELEACOMANDO_H
#define PELEACOMANDO_H
#include <iostream>
#include "Personaje.h"
#include "Enemigo.h"
#include "Comando.h"

class PeleaComando:public Comando{
    public:
        PeleaComando(Personaje*, Enemigo*);
        void ejecuta();
    private:
        Personaje* jugador;
        Enemigo* rival;
};

#endif
