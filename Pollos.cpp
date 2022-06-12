#include "Pollos.h"   

Pollos::Pollos(std::string _nombre,int _puntaje,Lugar _posicion,std::vector <Item*> _inventario,int _valor, std::string _color):Personaje(_nombre,_puntaje,_posicion,_inventario){
    valor = _valor;
    color = _color;
}

int Pollos::getValor()const{
    return valor;
}

std::string Pollos::getColor()const{
    return color;
}

void Pollos::setValor(int _valor){
    valor = _valor;
}

void Pollos::setColor(std::string _color){
    color = _color;
}

void Pollos::caracteristicas(){
    std::cout << "------------ DESCRIPCION DEL POLLO ------------" << std::endl;
    std::cout << "Nombre del Pollo: " << getNombre << std::endl;
    std::cout << "Color del pollo:"  << color << std::endl;
    std::cout << "Valor:"  << valor << " puntos" <<  std::endl;
    std::cout << "---------------------------------" << std::endl;
}