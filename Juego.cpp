#include "Juego.h"

Juego::Juego(){
    creaElementos();
    creaComandos();
}

void Juego::creaElementos(){
    ListaPalabras* comandos=parser.getComandos();
    comandos->agregaComando("movimiento", new MovimientoComando(jugador));
    comandos->agregaComando("pelea", new PeleaComando(jugador, rival1));
    //comandos->agregaComando("peea", new PeleaComando(jugador, rival2));
    // comandos->agregaComando("pelea", new PeleaComando(jugador, rival3));
    // comandos->agregaComando("pelea", new PeleaComando(jugador, rival4));
    // comandos->agregaComando("pelea", new PeleaComando(jugador, rivalFinal));
  
    comandos->agregaComando("ayuda", new AyudaComando(comandos));
}

void Juego::creaElementos(){
    jugador = new Personaje();
    zonas[0] = new Lugar("Plaza principal del Parque",0); //Plaza principal
    zonas[1] = new Lugar("Zona de Juegos, muchos lugares para jugar",0); //zonaJuegos
    zonas[2] = new Lugar("Lago de agua azul",0); //lago
    zonas[3]= new Lugar("Aquí vienen a un picnic",0); //zonaPicnic 
    zonas[4]= new Lugar("Zona para jugar con la arena",0); //areneros
    zonas[5]= new Lugar("Uy, un arbol caido. Zona final",4); //arbol caido
    //posiciones
    jugador -> setPosicion(zonas[0]); 
    for(int i=0;i<4;i++){
        pollitos[i] ->setPosicion(zonas[i+1]);
    }
    for(int i=0;i<5;i++){
        rivales[i] ->setPosicion(zonas[i+1]);
    }
    // rival1 -> setPosicion(zonas[4]);
    // rival2 -> setPosicion(lago);
    //rival3 -> setPosicion(zonaJuegos)

     //salidas de cada lugar
    zonas[0] ->setSalida(zonas[4],zonas[2],zonas[1],zonas[3]);
    zonas[4] -> setSalida(nullptr,zonas[0],zonas[1],nullptr );
    zonas[1] -> setSalida(nullptr,zonas[5],nullptr,zonas[4]);
    zonas[2] -> setSalida(zonas[0],nullptr,zonas[3],nullptr);
    zonas[3] -> setSalida(nullptr,nullptr,nullptr,zonas[0]);

}

void Juego::imprimeInicio(){
    std::cout << "Te encuentras en un parque" << std::endl;
    std::cout << "Tienes una mision especial " << std::endl;
    std::cout <<"Recorre el parque y recuperalos..." << std::endl;
    std::cout << "Si necesitas ayuda teclea la palabra: ayuda" << std::endl;
}

void Juego::imprimeFin(){
    std::cout << "Gracias por jugar" << std::endl;
    std::cout << "Estatus final -----" << std::endl;
    jugador ->consulta();
    std::cout << "FIN" << std::endl;
}

void Juego::play(){
    imprimeInicio();

}