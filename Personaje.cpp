#include "Personaje.h"   
#include <vector>

Personaje::Personaje(){
    nombre = "Nico"; 
    puntaje = 100;
    inventario.clear();
    posicion -> setDescripcion("");
}

Personaje::~Personaje(){}

Personaje::Personaje(std::string _nombre,int _puntaje,Lugar* _posicion) //,std::vector <Item*> _inventario vector vacio | metodo agregar item
{
    nombre = _nombre;
    puntaje = _puntaje;
    // inventario = _inventario; Evaluar
    posicion = _posicion;
}

std::string Personaje::getNombre()const{
    return nombre;
}

int Personaje::getPuntaje(){
    return puntaje;
}

//get Inventario

/*get posicion, Composicion de Lugar; obtener las caracteristicas
de Lugar y llamarlo posicion, posicion*/
Lugar* Personaje::getPosicion(){
    return posicion;
}

void Personaje::setPersonaje(std::string _nombre){
    nombre = _nombre;
}

void Personaje::setPuntos(int _puntaje){
    puntaje = _puntaje;
}

void Personaje::setPosicion(Lugar* _posicion){
    posicion = _posicion;
}

//metodo inventario, por medio de un vector ver todos los items que tenemos y por otro metodo agregar
void Personaje::setInventario(std::vector <Item*> _inventario){
    inventario = _inventario;
}

std::string Personaje::mostrarLugar(){
    return posicion -> getDescripcion();
}

//ver como funciona el vector y desplegar los items que poseemos
//void Personaje::muestraInventario(inventario); //para mostrar el inventario necesitamos acceder al vector
// inventario y observar todos los items que tenemos, es un vector porque podemos agregar mas items.

void Personaje::muestraInventario(){
    std::cout << "------------ INVENTARIO ------------" << std::endl;
    for(int i = 0; i < inventario.size(); i++){
        inventario[i] ->descripcion();
     }
    std::cout << "------------ FIN INVENTARIO ------------" << std::endl;
}

void Personaje::agregaItems(Item* nuevoItem){
    inventario.push_back(nuevoItem);
}

Item* Personaje::getItem(int pos){
    return inventario[pos];

}

void Personaje::pelea(int golpe,Personaje& nombreEnemigo){
        switch(golpe){
            case 1:
                std::cout<<"---------------------------------------------------------------------"<<std::endl;
                std::cout<<nombreEnemigo.getNombre()<<" ha sido herido de una patada y aranazo"<<std::endl;
                std::cout<<"---------------------------------------------------------------------"<<std::endl; 
                break;
            case 2:
                std::cout<<"---------------------------------------------------------------------"<<std::endl;
                std::cout<<"Haz utilizado tus items en "<<nombreEnemigo.getNombre()<<std::endl;
                std::cout<<"---------------------------------------------------------------------"<<std::endl; 
                break;
            case 3:
                std::cout<<"---------------------------------------------------------------------"<<std::endl;
                std::cout<<"Has mordido con rabia a "<<nombreEnemigo.getNombre()<<std::endl;
                std::cout<<"---------------------------------------------------------------------"<<std::endl; 
                break;
            default:
                break;
        }
    }
   
void Personaje::consulta(){
    std::cout << "------------ DESCRIPCION DEL Personaje ------------" << std::endl;
    std::cout << "Nombre del Personaje: " << nombre << std::endl;
    std::cout << "Cantidad en Inventario:"  << inventario.size() << std::endl;
    std::cout << "Valor:"  << puntaje << " puntos" <<  std::endl;
    std::cout << "Posicion:"  << posicion -> getDescripcion() << std::endl;
    std::cout << "---------------------------------" << std::endl;
}

int Personaje::buscaLLaves(){
    int cantidadLlaves = 0;
    for(int i=0; i < inventario.size(); i++){
        if(inventario[i] -> getItem() == "Llave"){
            cantidadLlaves += 1;
        }
    }
    return cantidadLlaves;
}

bool Personaje::camina(char dir){
    Lugar* nuevoLugar= posicion-> getSalida(dir);
    if (nuevoLugar!=nullptr && nuevoLugar -> cantidadLlaves() == 0){
        setPosicion(nuevoLugar);
        return true;    
    }
    else if (nuevoLugar!=nullptr && nuevoLugar-> cantidadLlaves() == 4){
        if (buscaLLaves() == 4){
            setPosicion(nuevoLugar);
            return true;
        }
    }
    return false;
}

void Personaje::quitarPuntaje(int damage){
    puntaje-=damage;
}