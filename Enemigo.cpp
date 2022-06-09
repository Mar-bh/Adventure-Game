#include "Enemigo.h"   

Enemigo::Enemigo(std::string _nombre,int _puntaje,Lugar _posicion,std::vector <Item*> _inventario,int _valor, std::string _color):Personaje(_nombre,_puntaje,_posicion,_inventario){
    valor = _valor;
    color = _color;
}

int Enemigo::getValor()const{
    return valor;
}

std::string Enemigo::getColor()const{
    return color;
}


void Enemigo::setValor(int _valor){
    valor = _valor;
}

void Enemigo::setColor(std::string _color){
    color = _color;
}

void Enemigo::caracteristicas(){
    std::cout << "------------ DESCRIPCION DEL POLLO ------------" << std::endl;
    std::cout << "Nombre del Pollo: " << getNombre << std::endl;
    std::cout << "Color del pollo:"  << color << std::endl;
    std::cout << "Valor:"  << valor << " puntos" <<  std::endl;
    std::cout << "---------------------------------" << std::endl;
}