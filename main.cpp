#include <string>
#include <vector>
//#include <sstream>
//#include <fstream>
#include <iostream>
#include "Personaje.h"
#include "Enemigo.h"
#include "Pollos.h"
#include "Personaje.h"
#include "Comado.h"

using namespace std;

int main(){
    vector <Item*> inventario;
    
    inventario.push_back(new Item(20,"hacha","afilada"));

    /*
    Item pilin(300,"pilin","pilin");
    item.push_back(new Item(100,"palito","grande"));
    item.push_back(new Item(200,"rata tiesa","rata con Thiner"));
    item.push_back(new Item(40,"piedra","chiquita"));
    item.push_back(new Item(300,"pilin","pilin"));*/

    Lugar primerLugar("Plaza Principal");
    


    Personaje personaje1("Nico",200,primerLugar,inventario);
    Enemigo enemigo1("Juan",100,personaje1.getPosicion(),inventario,5); 
    cout<<typeid(enemigo1).name();
    cout<<"---------------------------------------------------------------------"<<endl;
    cout<<"Hola "<<personaje1.getNombre()<<" salva a los pollos"<<endl;
    cout<<"---------------------------------------------------------------------"<<endl;
    cout<<personaje1.getNombre()<<" tienes que pelear con el primer enemigo en "<<primerLugar.getDescripcion()<<endl;
    cout<<"---------------------------------------------------------------------"<<endl;

    int golpes;
    //string nombreEnemigo;
    //stringstream temporal;

    do{ 
        cout<<"---------------------------------------------------------------------"<<endl;
        cout<<"Opciones de pelea:"<< endl;
        cout<<"1. Patada y arañazo"<< endl;
        cout<<"2. Utilizacion de Items"<< endl;
        cout<<"3. Mordida con rabia >:["<< endl;
        cout<<"---------------------------------------------------------------------"<<endl;
        cout<<"Ingresa la accion que deseas realizar"<<endl;
        cin >> golpes;
        //nombreEnemigo = to_string(enemigo1.getNombre());
        //temporal << enemigo1.getNombre();
        personaje1.pelea(golpes,enemigo1);
    }
    while (golpes!=7);
}