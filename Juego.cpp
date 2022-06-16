#include <string>
#include <iostream>
#include <sstream>
#include "Juego.h"

Juego::Juego(){
    creaElementos();
    creaComandos();
}

void Juego::creaElementos(){
    //lugares
    zonas[0] = new Lugar("Plaza principal del Parque",0); //Plaza principal
    zonas[1] = new Lugar("Zona de Juegos, muchos lugares para jugar",0); //zonaJuegos
    zonas[2] = new Lugar("Lago de agua azul",0); //lago
    zonas[3]= new Lugar("Aqui vienen a un picnic",0); //zonaPicnic 
    zonas[4]= new Lugar("Zona para jugar con la arena",0); //areneros
    zonas[5]= new Lugar("Uy, un arbol caido. Zona final",4); //arbol caido

    //personaje
    jugador = new Personaje("Nico",0,zonas[0]);

    //items
    std::string nombreItem[4] = {"pelota","hoja","pluma","peluche"};
    std::string descripciones[4] = {"objeto para diversion", "para jugar","premio","lo que te encuentras en un parque"};

    //Pollitos
    std::string colores[5] = {"Azul","Rosa","Rojo","Amarillo","Morado"};
    std::string nombres[5] = {"Juan","Marianas","Nolberto","Paola","Jukari"};

    for(int i=0;i<4;i++){
        pollitos[i] = new Pollos(nombres[i],20+i*2,zonas[0],10,colores[i]);
        objetos[i] = new Item(10*1,nombreItem[i],descripciones[i]);
        //Quiero desplegar el color del pollo :(
        //std::cout<<pollitos[i] -> getColor()<<std::endl;
        pollitos[i] ->setPosicion(zonas[i+1]);
        pollitos[i] ->agregaItems(objetos[i]);
        llaves[i] = new Item(100,"Llave","Pedazo para abrir puerta final");
        zonas[i+1] -> setRecompensa(llaves[i]);
    }
    //Enemigos
    std::string nombreEne[5] = {"Iker","Carlos","Javier","Israel","Alfonso"};
    for(int i=0;i<5;i++){
        rivales[i] = new Enemigo(nombreEne[i],10*i,zonas[0],i);
        rivales[i] ->setPosicion(zonas[i+1]);
    }
     //salidas de cada lugar
    zonas[0] -> setSalida(zonas[4],zonas[2],zonas[1],zonas[3]);
    zonas[4] -> setSalida(nullptr,zonas[0],zonas[1],nullptr );
    zonas[1] -> setSalida(nullptr,zonas[5],nullptr,zonas[4]);
    zonas[2] -> setSalida(zonas[0],nullptr,zonas[3],nullptr);
    zonas[3] -> setSalida(nullptr,nullptr,nullptr,zonas[0]);
}

void Juego::creaComandos(){ 
    ListaPalabras* comandos=parser.getComandos();
    comandos->agregaComando("movimiento", new MovimientoComando(jugador));
    comandos->agregaComando("pelea", new PeleaComando(jugador, rivales[0],pollitos[0]));
    comandos->agregaComando("ayuda", new AyudaComando(comandos));
    //comandos->agregaComando("si", new Inventario());//
    fflush(stdin);
}

void Juego::imprimeInicio(){
    std::cout << "Te encuentras en un parque" << std::endl;
    std::cout << "Tienes una mision especial " << std::endl;
    std::cout << "Recorre el parque y recuperalos..." << std::endl;
    std::cout << "Si necesitas ayuda teclea la palabra: ayuda" << std::endl;
}

void Juego::imprimeFin(){
    std::cout << "Gracias por jugar" << std::endl;
    std::cout << jugador->getNombre() << "Has rescatado a todos los pollos!!!"<<std::endl;
    std::cout << "Estatus final -----" << std::endl;
    jugador ->consulta();
    jugador -> muestraInventario();
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

//Proceso de los comandos segun se les llame; principalmente comandoPelea
bool Juego::procesaComando(Comando* instruccion){
    bool vencio = false, peleo = false;
    ListaPalabras* comandos=parser.getComandos();
    if(instruccion ->getComando()=="pelea" &jugador->getPosicion() == zonas[0]){
        std::cout << "No puedes pelear en este lugar" << std::endl;
    }else if (jugador->getPosicion() == zonas[1] )  {
        std::cout << "e" << std::endl;
        comandos ->modificaComando(1,"pelea",new PeleaComando(jugador, rivales[0],pollitos[0]));
        instruccion ->ejecuta();
        peleo = true;
    } else if (jugador->getPosicion() == zonas[2] )  {
        comandos ->modificaComando(1,"pelea",new PeleaComando(jugador, rivales[1],pollitos[1]));
        instruccion ->ejecuta();
        peleo = true;
    } else if (jugador->getPosicion() == zonas[3] )  {
        comandos ->modificaComando(1,"pelea",new PeleaComando(jugador, rivales[2],pollitos[2]));
        instruccion ->ejecuta();
        peleo = true;
    }  else if (jugador->getPosicion() == zonas[4] )  {
        comandos ->modificaComando(1,"pelea",new PeleaComando(jugador, rivales[3],pollitos[3]));
        instruccion ->ejecuta();
        peleo = true;
    } else if (jugador->getPosicion() == zonas[5] )  {
        comandos ->modificaComando(1,"pelea",new PeleaComando(jugador, rivales[4],new Pollos()));
       instruccion ->ejecuta();
       peleo = true;
    } else {
        std::cout<<"aaaaaaaa"<<std::endl;
        instruccion -> ejecuta();
        
    }


    if(peleo==true){
        jugador -> consulta(); //consulta del personaje cada que termina una pelea; puntaje, items, ubicacion
        std::cout<<"\n--------------------------------------------------\n"<<std::endl;
        std::cout<<"Sigue explorando!"<<std::endl;
        //Checar para inventario
        //std::cout<<"\nQuieres ver los Items de tu inventario?\nEscribe si o no\n"<<std::endl;
        //std::stringstream sstr(respuesta);
        //std::cout<<respuesta<<std::endl;
        //comandos ->modificaComando(new Inventario());
        //instruccion->ejecuta();
        /*
        if (respuesta=="si"){
            jugador->muestraInventario();
        }
        else {
            return vencio;
        }*/     
    }

//condicion para terminar el juego(principalmente en la zona final)
    if(jugador->getPosicion()==zonas[5]){
            if(jugador->getPuntaje() >= 400){
            } else {
                jugador -> setPosicion(zonas[0]);
            }
        }
    peleo =false;
    std::cout << "g" << std::endl;
    return vencio;
}

