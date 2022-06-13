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
    plazaPrincipal = new Lugar("Plaza principal del Parque",0);
    zonaJuegos = new Lugar("Zona de Juegos, muchos lugares para jugar",0);
    lago = new Lugar("Lago de agua azul",0);
    zonaPicnic = new Lugar("Aquí vienen a un picnic",0);
    areneros = new Lugar("Zona para jugar con la arena",0);
    arbolCaido = new Lugar("Uy, un arbol caido. Zona final",4);
    //posiciones
    jugador -> setPosicion(plazaPrincipal); 
    pollo1 -> setPosicion (areneros);
    pollo2 -> setPosicion(lago);
    pollo3 -> setPosicion(zonaJuegos);
    pollo4 -> setPosicion(zonaPicnic);
    // rival1 -> setPosicion(areneros);
    // rival2 -> setPosicion(lago);
    //rival3 -> setPosicion(zonaJuegos)

     //salidas de cada lugar
    plazaPrincipal ->setSalida(areneros,lago,zonaJuegos,zonaPicnic);
    areneros -> setSalida(nullptr,plazaPrincipal,zonaJuegos,nullptr );
    zonaJuegos -> setSalida(nullptr,arbolCaido,nullptr,areneros);
    lago -> setSalida(plazaPrincipal,nullptr,zonaPicnic,nullptr);
    zonaPicnic -> setSalida(nullptr,nullptr,nullptr,plazaPrincipal);

}