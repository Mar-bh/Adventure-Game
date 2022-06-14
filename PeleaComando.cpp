#include "PeleaComando.h"

PeleaComando::PeleaComando(Personaje* _jugador, Enemigo* enemy){
    jugador = _jugador;
    rival = enemy;
}

void PeleaComando::ejecuta(){
    std::cout << "Pelea Comando prueba" << std::endl; //prueba
}