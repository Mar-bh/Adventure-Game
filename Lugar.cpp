#include "Lugar.h"

Lugar::Lugar(){ 
    descripcion = "Espacio del parque ";
    for(int i=0; i<4; i++){
        salidas[i]=nullptr;
    }
    llaves = 0;
}

Lugar::Lugar(std::string desc, int _llave){
    descripcion = desc;
    for(int i=0; i<4; i++){
        salidas[i]=nullptr;
    }
    llaves = _llave;
}

Lugar* Lugar::getSalida(char dir){ 
    int num=numSalida(dir);
    if(num>=0){
        return salidas[num];
    }
    return nullptr;
}

void Lugar::setSalida(Lugar* n, Lugar* s, Lugar* e, Lugar* o){ 
    salidas[0]=n;
    salidas[1]=s;
    salidas[2]=e;
    salidas[3]=o;
}

int Lugar::numSalida(char dir){
    switch(dir){
        case 'n':
            return 0;
        case 's':
            return 1;
        case 'e':
            return 2;
        case 'o':
            return 3;
        default:
            return -1;
    }

}

void Lugar::setDescripcion(std::string _desc){
    descripcion = _desc;
}
std::string Lugar::getDescripcion(){
    return descripcion;
}

void Lugar::setRecompensa(Item* premio){ //un arreglo para hacerle pushback 
    recompensa.push_back(premio);
}

void Lugar::sacarRecompensa(int premio){
    recompensa.erase(recompensa.begin()+premio);
}

Item* Lugar::getRecompensa(int num){
    if (num>=0 && num<recompensa.size()){
        return recompensa[num];
    }
    return nullptr;

}

void Lugar::descripcionLarga(){
    std::cout << descripcion << std::endl;
    std::cout << "En esta zona del parque tenemos: " << std::endl;
    std::cout << "Un enemigo /nUn pollo. /nAl rescatar al pollo podrás obtener lo siguiente:" << std::endl;
    for (int i=0; i<recompensa.size(); i++){
        std::cout <<"/t" << recompensa[i]->getItem() << std::endl;
    }

}

int Lugar::cantidadLlaves(){
    return llaves;
}