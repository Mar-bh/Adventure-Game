#include "Personaje.h"   
#include <vector>

Personaje::Personaje(){
    nombre = "Nico"; 
    puntaje = 100;
    inventario = vector <Item*>;
    posicion = Lugar("donde estas?");
}

Personaje::~Personaje(){}

Personaje::Personaje(std::string _nombre,int _puntaje,std::vector <Item*> _inventario,Lugar _posicion) 
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
std::string Personaje::getDescripcion(){
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
void Personaje::setDescipcion(std::string _posicion){
    posicion = _posicion
}

//metodo inventario, para por medio de un vector ver todos los items que tenemos y por otro metodo agregar
void Personaje::setInventario(std::vector <Item*> _inventario);
    inventario = _inventario;

//ver como funciona el vector y desplegar los items que poseemos
//void Personaje::muestraInventario(inventario); //para mostrar el inventario necesitamos acceder al vector
// inventario y observar todos los items que tenemos, es un vector porque podemos agregar mas items.

//Agregar items al vector inventario
//void Personaje::agregaItems(Item);// agregamos mas items al inventario

void Personaje::pelea();// opciones de pelea
    //aqui va mucho texto sobre las opciones de pelea, maybe un switch case


void Personaje::consulta(){
    std::cout << "------------ DESCRIPCION DEL Personaje ------------" << std::endl;
    std::cout << "Nombre del Personaje: " << nombre << std::endl;
    std::cout << "Inventario:"  << inventario << std::endl;
    std::cout << "Valor:"  << puntaje << " puntos" <<  std::endl;
    std::cout << "Posicion:"  << posicion << std::endl;
    std::cout << "---------------------------------" << std::endl;
}