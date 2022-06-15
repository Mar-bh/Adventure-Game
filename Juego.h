#ifndef JUEGO_H
#define JUEGO_H
#include <iostream>

#include"Lugar.h"
#include "Comando.h"
#include "ListaPalabras.h"
#include "Item.h"
#include "MovimientoComando.h"
#include "AyudaComando.h"
#include "PeleaComando.h"
#include "Personaje.h"
#include "Pollos.h"
#include "Enemigo.h"
#include "Parser.h"

class Juego{
    public:
        Juego();
        void creaElementos();
        void creaComandos();
        void play();
        void imprimeInicio();
        bool procesaComando(Comando*);
        void imprimeFin();

    private:
        Parser parser;
        Personaje* jugador;
        Pollos*  pollitos[4]; //*pollo1,*pollo2,*pollo3,*pollo4;
        Enemigo* rivales[5];//        *rival1, *rival2,*rival3,*rival4,*rivalFinal;
        Lugar* zonas[6];  //*plazaPrincipal, *zonaJuegos, *lago, *zonaPicnic, *areneros, *arbolCaido;
        Item* llaves[4];
        Item* objetos[4];

};
#endif 