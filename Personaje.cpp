#include "Personaje.h"   
#include <vector>

Personaje::Personaje(){
    nombre = "Nico"; 
    puntaje = 100;
    inventario.clear();
    posicion = Lugar("donde estas?");
}

Personaje::~Personaje(){}

Personaje::Personaje(std::string _nombre,int _puntaje,Lugar _posicion,std::vector <Item*> _inventario) 
{
    nombre = _nombre;
    puntaje = _puntaje;
    inventario = _inventario;
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
Lugar Personaje::getPosicion(){
    return posicion;
}

void Personaje::setPersonaje(std::string _nombre){
    nombre = _nombre;
}

void Personaje::setPuntos(int _puntaje){
    puntaje = _puntaje;
}

//duda sobre la composicion, queremos obtener la posicion del personaje por medio
// del metodo descripcion de Lugar; solo queremos desplegar un metodo de lugar en nuestro cpp de personaje,
// y llamarlo posicion, para consultarlo despues en el metodo de consulta del personaje.
void Personaje::setPosicion(Lugar _posicion){
    posicion = _posicion;
}

//metodo inventario, para por medio de un vector ver todos los items que tenemos y por otro metodo agregar
void Personaje::setInventario(std::vector <Item*> _inventario){
    inventario = _inventario;
}

std::string Personaje::mostrarLugar(){
    return posicion.getDescripcion();
}

//ver como funciona el vector y desplegar los items que poseemos
//void Personaje::muestraInventario(inventario); //para mostrar el inventario necesitamos acceder al vector
// inventario y observar todos los items que tenemos, es un vector porque podemos agregar mas items.

//Agregar items al vector inventario
//void Personaje::agregaItems(Item);// agregamos mas items al inventario
void Personaje::pelea(int golpe,Enemigo nombreEnemigo){// opciones de pelea
        switch(golpe){
            case 1:
                std::cout<<"---------------------------------------------------------------------"<<std::endl;
                //std::cout<<nombreEnemigo.getNombre()<<" ha sido herido de una patada y arañazo"<<std::endl;
                std::cout<<"---------------------------------------------------------------------"<<std::endl; 
                break;
            case 2:
                std::cout<<"---------------------------------------------------------------------"<<std::endl;
                //std::cout<<"Haz utilizado tus items en "<<nombreEnemigo.getNombre()<<std::endl;
                std::cout<<"---------------------------------------------------------------------"<<std::endl; 
                break;
            case 3:
                std::cout<<"---------------------------------------------------------------------"<<std::endl;
                //std::cout<<"Has mordido con rabia a "<<nombreEnemigo<<std::endl;
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
    std::cout << "Posicion:"  << posicion.getDescripcion() << std::endl;
    std::cout << "---------------------------------" << std::endl;
}