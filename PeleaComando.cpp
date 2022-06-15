#include <sstream>
#include "PeleaComando.h"

PeleaComando::PeleaComando(Personaje* _jugador, Enemigo* enemy){
    jugador = _jugador;
    rival = enemy;
}

void PeleaComando::ejecuta(){
    std::cout << "Pelea Comando prueba" << std::endl; //prueba

    //std::cout<<typeid(rival).name();
    std::cout<<"---------------------------------------------------------------------"<<std::endl;
    std::cout<<"Hola "<<jugador -> getNombre()<<" salva a los pollos"<<std::endl;
    std::cout<<"---------------------------------------------------------------------"<<std::endl;
    std::cout<<jugador ->getNombre()<<" tienes que pelear con el primer enemigo en "<< jugador -> getPosicion() <<std::endl;
    std:: cout<<"---------------------------------------------------------------------"<<std::endl;

    int golpes;
    std::string nombreEnemigo;
    std::stringstream temporal; //std::stringstream temporal;

    do{ 
        std::cout<<"---------------------------------------------------------------------"<<std::endl;
        std::cout<<"Opciones de pelea:"<< std::endl;
        std::cout<<"1. Patada y arañazo"<< std::endl;
        std::cout<<"2. Utilizacion de Items"<< std::endl;
        std::cout<<"3. Mordida con rabia >:["<< std::endl;
        std::cout<<"---------------------------------------------------------------------"<<std::endl;
        std::cout<<"Ingresa la accion que deseas realizar"<<std::endl;
        std::cin >> golpes;
        nombreEnemigo = rival -> getNombre();
        temporal << rival  -> getNombre();
        Enemigo rivalN = *rival;
        jugador -> pelea(golpes,rivalN);
    }
    while (golpes!=7);
    // Personaje personaje1("Nico",200,primerLugar,inventario);
    // Enemigo enemigo1("Juan",100,personaje1.getPosicion(),inventario,5); 
    // std::cout<<typeid(enemigo1).name();
    // std::cout<<"---------------------------------------------------------------------"<<std::endl;
    // std::cout<<"Hola "<<personaje1.getNombre()<<" salva a los pollos"<<std::endl;
    // std::cout<<"---------------------------------------------------------------------"<<std::endl;
    // std::cout<<personaje1.getNombre()<<" tienes que pelear con el primer enemigo en "<<primerLugar.getDescripcion()<<std::endl;
    // std::cout<<"---------------------------------------------------------------------"<<std::endl;


}