#ifndef PELEACOMANDO_H
#define PELEACOMANDO_H
#include <iostream>
#include "Personaje.h"
#include "Enemigo.h"
#include "Comando.h"
#include "Pollos.h"

class PeleaComando:public Comando{
    public:
        PeleaComando(Personaje*, Enemigo*,Personaje*);
        void ejecuta();
    private:
        Personaje* jugador;
        Enemigo* rival;
        Personaje* pollo;

};

#endif
