#include "Juego.h"

Juego::Juego(){
    creaElementos();
    creaComandos();
}

void Juego::creaComandos(){
    ListaPalabras* comandos=parser.getComandos();
    comandos->agregaComando("movimiento", new MovimientoComando(jugador));
    comandos->agregaComando("pelea", new PeleaComando(jugador, rivales[0]));
    comandos->agregaComando("ayuda", new AyudaComando(comandos));
}

void Juego::creaElementos(){
    std::cout << "Creamos lugares" << std::endl;
   // lugares
    zonas[0] = new Lugar("Plaza principal del Parque",0); //Plaza principal
    zonas[1] = new Lugar("Zona de Juegos, muchos lugares para jugar",0); //zonaJuegos
    zonas[2] = new Lugar("Lago de agua azul",0); //lago
    zonas[3]= new Lugar("Aquí vienen a un picnic",0); //zonaPicnic 
    zonas[4]= new Lugar("Zona para jugar con la arena",0); //areneros
    zonas[5]= new Lugar("Uy, un arbol caido. Zona final",4); //arbol caido

    std::cout << "Creamos personaje" << std::endl;
    //personaje
    jugador = new Personaje("Nico",0,zonas[0]);

    //pollitos
    // pollitos[0] = new Pollos();
    // pollitos[1] = new Pollos();
    // pollitos[2] = new Pollos();
    // pollitos[3] = new Pollos();

    //posiciones y llaves 
    jugador -> setPosicion(zonas[0]); 
    std::cout << "pilin c" << std::endl;


    for(int i=0;i<4;i++){

        std::cout << "pilin" << i << std::endl;
        pollitos[i] = new Pollos("Pollito"+std::to_string(i),20,zonas[i+1],2,"rosa");
        //pollitos[i] ->setPosicion(zonas[i+1]);
        std::cout << "pilin" << i << std::endl;
        llaves[i] = new Item(100,"Llave","Pedazo para abrir puerta final");
        std::cout << "pilin" << i << std::endl;
        zonas[i+1] -> setRecompensa(llaves[i]);
        std::cout << "pilin" << i << std::endl;
    }

    for(int i=0;i<5;i++){
        std::cout << "pilin" << i << std::endl;
        rivales[i] = new Enemigo("X",10,zonas[i+1],5*i);
    }

     //salidas de cada lugar
    zonas[0] -> setSalida(zonas[4],zonas[2],zonas[1],zonas[3]);
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
    bool fin = false;
    while (!fin){
        while(true){
            Comando* comando = parser.generaComando();
            fin = procesaComando(comando);
            break;
        }
    }
    imprimeFin();

}

bool Juego::procesaComando(Comando* instruccion){
    bool vencio = false;
    instruccion ->ejecuta();

    if(jugador->getPosicion()==zonas[4]){
            if(jugador->getPuntaje() == 500){
                 vencio = true;
            } else {
                jugador -> setPosicion(zonas[5]);
            }
        }
    return vencio;
}