#include "AyudaComando.h"

AyudaComando::AyudaComando(ListaPalabras* _lista):Comando("Ayuda",""){
    validas = _lista;
}

void AyudaComando::ejecuta(){
    std::cout<< "Te encuentras en un parque y tu mision es recuperar a los pollitos perdidos en este." << std::endl;
    std::cout << "Recuerda que para recuperarlos tendras que vencer a tus enemigos en el camino" << std::endl;
    std::cout << validas ->todosLosComandos() << std::endl;
}