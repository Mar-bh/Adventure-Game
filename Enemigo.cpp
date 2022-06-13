#include "Enemigo.h"   

Enemigo::Enemigo(std::string _nombre,int _puntaje,Lugar* _posicion,std::vector <Item*> _inventario,int _nivelPeligro):Personaje(_nombre,_puntaje,_posicion,_inventario){
    nivelPeligro = _nivelPeligro;
}

int Enemigo::getnivelPeligro()const{
    return nivelPeligro;
}


void Enemigo::setnivelPeligro(int _nivelPeligro){
    nivelPeligro = _nivelPeligro;
}

void Enemigo::dialogo(){
    std::cout << "------------ ENEMIGO ------------" << std::endl;
    std::cout << "Estas en: " << getPosicion << std::endl;    
    std::cout << "Nivel de peligro del enemigo: " << nivelPeligro << std::endl;
    std::cout << "Hola Nico, soy: " << getNombre << std::endl;
    std::cout << "Como veras, mi puntaje es de:"  << getPuntaje << std::endl;
    std::cout << "---------------------------------" << std::endl;
}

void Enemigo::quitaPuntaje(){
    
}