#include "MovimientoComando.h"
#include <string>

MovimientoComando::MovimientoComando(Personaje* _jugador):Comando("movimiento",""){
    jugador = _jugador;
}

void MovimientoComando::ejecuta(){
    if (!tieneSegPalabra()){
        std::cout<<"A donde quieres ir?... necesitamos una direccion ..." << std::endl;
        std::cout << "Puede ser n para norte, s para sur, e para este y o para oeste" << std::endl;
    }
    else{
        std::string direc = getSegPalabra(); 
        char direccion = direc[0];
        if (jugador-> camina(direccion)){
            Lugar* actual= jugador->getPosicion(); //necesitamos metodo para saber si la persona se va a moverr
            std::cout << "Te has movido hacia el " << direc << std::endl;
            std::cout << "Ahora estas en: " << actual->getDescripcion() << std::endl;
        }
        else{
            std::cout << "No hay salida en esa direccion o no tienes la llave para abrir, busca otra salida... o la llave..." << std::endl;
        }
    } 
}