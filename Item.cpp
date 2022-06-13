#include "Item.h"   

Item::Item(){
    puntos = 50; 
    item = "hacha";
    caracteristica = "objeto perron";
}

Item::~Item(){}

Item::Item(int _puntos, std::string _item,std::string _caracteristica) 
{
    puntos = _puntos;
    item = _item;
    caracteristica = _caracteristica;
}

int Item::getPuntos()const{
    return puntos;
}

std::string Item::getItem()const{
    return item;
}

std::string Item::getCaracteristica()const{
    return caracteristica;
}

void Item::setPuntos(int _puntos){
    puntos = _puntos;
}

void Item::setItem(std::string _item){
    item = _item;
}

void Item::setCaracteristica(std::string _caracteristica){
    caracteristica = _caracteristica;
}


void Item::descripcion(){
    std::cout << "------------ DESCRIPCION DEL ITEM ------------" << std::endl;
    std::cout << "Nombre del Item: " << item << std::endl;
    std::cout << "Caracteristicas:"  << caracteristica << std::endl;
    std::cout << "Valor:"  << puntos << " puntos" <<  std::endl;
    std::cout << "---------------------------------" << std::endl;
}

Item Item::operator+(const Item& otro){ //sobrecarga de operador para item, incrementamos puntos
    int puntajeFinal = puntos + otro.getPuntos();
    return Item(puntajeFinal, item, caracteristica);
}