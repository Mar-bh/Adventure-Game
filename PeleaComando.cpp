#include <sstream>
#include "PeleaComando.h"

PeleaComando::PeleaComando(Personaje* _jugador, Enemigo* enemy):Comando("pelea",""){
    jugador = _jugador;
    rival = enemy;
}

void PeleaComando::ejecuta(){

    std::cout<<"--------------------------------PELEA--------------------------------"<<std::endl;
    std::cout<<"Hola "<<jugador -> getNombre()<<" salva a los pollos"<<std::endl;
    std::cout<<"---------------------------------------------------------------------"<<std::endl;
    std::cout<<jugador ->getNombre()<<" tienes que pelear con el primer enemigo en "<< jugador -> getPosicion()->getDescripcion() <<std::endl;
    rival -> dialogo();
    std:: cout<<"---------------------------------------------------------------------"<<std::endl;

    int golpes;
    std::string nombreEnemigo;
    std::stringstream temporal; 
    int golpesTotal = 0, contador = 0, damage = 10;

    do{ 
        int golpes;
        std::cout<<"---------------------------------------------------------------------"<<std::endl;
        std::cout<<"Opciones de pelea:"<< std::endl;
        std::cout<<"1. Patada y aranazo"<< std::endl;
        std::cout<<"2. Utilizacion de Items"<< std::endl;
        std::cout<<"3. Mordida con rabia >:["<< std::endl;
        std::cout<<"---------------------------------------------------------------------"<<std::endl;
        std::cout<<"Ingresa la accion que deseas realizar"<<std::endl;
        std::cin >> golpes;
        nombreEnemigo = rival -> getNombre();
        temporal << rival  -> getNombre();
        Enemigo rivalN = *rival;
        jugador -> pelea(golpes,rivalN);
        golpesTotal += golpes;
        contador ++;
        damage =+ 10;

        if (contador==3 && golpesTotal == 6) {
            std::cout<<"Has matado al enemigo"<<std::endl;
            golpes = 4;
        }
        else if (contador==3 && golpesTotal != 6){
            std::cout<<"El enemigo es chingon y te bajo 10 puntos"<<std::endl;
            std::cout <<"Sigue la batalla" << std::endl;
            jugador->quitarPuntaje(damage);
            std::cout<<jugador -> getPuntaje()<<std::endl;
            contador = 0;
            golpesTotal = 0;
        }
    }
    while (golpes!=4);
}