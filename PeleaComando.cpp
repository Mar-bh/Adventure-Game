#include <sstream>
#include "PeleaComando.h"

PeleaComando::PeleaComando(Personaje* _jugador, Enemigo* enemy, Personaje* _pollos):Comando("pelea",""){
    jugador = _jugador;
    rival = enemy;
    pollo = _pollos;
}

void PeleaComando::ejecuta(){

    std::cout<<"--------------------------------PELEA--------------------------------"<<std::endl;
    std::cout<<"Hola "<<jugador -> getNombre()<<" salva a los pollos"<<std::endl;
    std::cout<<"---------------------------------------------------------------------"<<std::endl;
    std::cout<<jugador ->getNombre()<<" si derrotas al enemigo, el pollo te dara un Item especial, si fallas tus golpes te bajaran puntos "<< jugador -> getPosicion()->getDescripcion() <<std::endl;
    rival -> dialogo();
    std:: cout<<"---------------------------------------------------------------------"<<std::endl;

    int golpes;
    std::string nombreEnemigo;
    std::stringstream temporal; 
    int golpesTotal = 0, contador = 0, damage = 10;

    do{ 
        int opcion;
        std::cout<<"---------------------------------------------------------------------"<<std::endl;
        std::cout<<"Opciones de pelea:"<< std::endl;
        std::cout<<"1. Patada y aranazo"<< std::endl;
        std::cout<<"2. Utilizacion de Items"<< std::endl;
        std::cout<<"3. Mordida con rabia >:["<< std::endl;
        std::cout<<"---------------------------------------------------------------------"<<std::endl;
        std::cout<<"Ingresa la accion que deseas realizar"<<std::endl;
        std::cin >> opcion;

        nombreEnemigo = rival -> getNombre();
        temporal << rival  -> getNombre();
        Enemigo rivalN = *rival;
        jugador -> pelea(opcion,rivalN);
        golpesTotal += opcion;
        std::cout << "Golpes " << golpesTotal <<std::endl;
        contador ++;
        damage =+ 10;

        if (contador==3 && golpesTotal >= 6) {
            std::cout<<"Has derrotado a "<<nombreEnemigo<<"!!!!"<<std::endl;
            int puntos = jugador -> getPuntaje();
            jugador -> setPuntos(puntos+100);
            std::cout<<"Tu puntaje ahora es de "<< jugador -> getPuntaje() <<std::endl;
            std::cout << "Haz recuperado al pollito " << pollo ->getNombre() <<std::endl;
            std::cout << "Como agradecimieno el pollito te ha dado: " << pollo ->getItem(0) ->getItem() <<std::endl;
            Item* inicial = jugador ->getPosicion() ->getRecompensa(0);
            Item* temporal = jugador ->getItem(0);
            Item suma = *inicial + *temporal;
            jugador -> getItem(0)-> setPuntos(suma.getPuntos());
            // std::cout << "Prueba " << std::endl;
            // std::cout << jugador -> getPosicion()->getRecompensa(0) -> getItem() << std::endl;
            // std::cout << jugador -> getPosicion()->getRecompensa(0) -> getPuntos() << std::endl;
            std::cout <<"Por derrotar al enemigo ahora tienes una llave de: " << jugador ->getItem(0)->getPuntos() << " puntos" << std::endl;
            jugador -> agregaItems(pollo ->getItem(0));
            jugador ->getPosicion() ->sacarRecompensa(0);
            golpes = 4;
        }
        else if (contador==3 && golpesTotal <= 6){
            std::cout<<"El enemigo es demasiado fuerte y te bajo 10 puntos"<<std::endl;
            std::cout <<"Sigue la batalla" << std::endl;
            jugador->quitarPuntaje(damage);
            std::cout<<jugador -> getPuntaje()<<std::endl;
            contador = 0;
            golpesTotal = 0;
        }
    }
    while (golpes!=4);
}