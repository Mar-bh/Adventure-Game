#include "Pollos.h"   

Pollos::Pollos(int _valor, std::string _color,Personaje _nombre) 
{
    valor = _valor;
    color = _color;
    nombre = _nombre
}

int Pollos::getValor()const{
    return valor;
}

std::string Pollos::getColor()const{
    return color;
}

Personaje Pollos::getNombre()const{
    return nombre;
}

void Pollos::setValor(int _valor){
    valor = _valor;
}

void Pollos::setColor(std::string _color){
    color = _color;
}

void Pollos::setNombre(Personaje _nombre){
    nombre = _nombre
}

void Pollos::caracteristicas(){
    std::cout << "------------ DESCRIPCION DEL POLLO ------------" << std::endl;
    std::cout << "Nombre del Pollo: " << nombre << std::endl;
    std::cout << "Color del pollo:"  << color << std::endl;
    std::cout << "Valor:"  << valor << " puntos" <<  std::endl;
    std::cout << "---------------------------------" << std::endl;
}