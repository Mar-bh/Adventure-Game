#ifndef AYUDACOMANDO_H
#define AYUDACOMANDO_H
#include "Comando.h"
#include "ListaPalabras.h"
#include "Personaje.h"

class Inventario:public Comando{
    public:
        Inventario(ListaPalabras*,Personaje*);
        void ejecuta();
    private:
        ListaPalabras* validas;
        Personaje* jugador;
}; 
#endif