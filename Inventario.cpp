#include "Inventario.h"

Inventario::Inventario(ListaPalabras* _lista,Personaje* _jugador):Comando("si",""){
    jugador = _jugador;
    validas = _lista;
    
}

void Inventario::ejecuta(){
    std::cout<<"inventario"<<std::endl;
    jugador->muestraInventario();
}
