#include "Lugar.h"

Lugar::Lugar(){
    descripcion = "Espacio del parque ";
    for(int i=0; i<4; i++){
        salidas[i]=nullptr;
    }
    llaves = 0;
}

Lugar::Lugar(std::string desc){
    descripcion = desc;
    for(int i=0; i<4; i++){
        salidas[i]=nullptr;
    }
    llaves = 0;
}

Lugar* Lugar::getSalida(std::string dir){

}

void Lugar::setSalida(Lugar* n, Lugar* s, Lugar* e, Lugar* o,){
    salidas[0]=n;
    salidas[1]=s;
    salidas[2]=e;
    salidas[3]=o;
}

int Lugar::numSalida(std::string dir){
    
}
