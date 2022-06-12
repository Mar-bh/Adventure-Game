#include <string>
#include <vector>
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
    cout<<"---------------------------------------------------------------------"<<endl;
    cout<<"Hola "<<personaje1.getNombre()<<" salva a los pollos"<<endl;
    cout<<"---------------------------------------------------------------------"<<endl;
    cout<<personaje1.getNombre()<<" tienes que pelear con el primer enemigo en "<<primerLugar.getDescripcion()<<endl;
    cout<<"---------------------------------------------------------------------"<<endl;
    int golpes;

    while (golpes!=7){
        cout<<"---------------------------------------------------------------------"<<endl;
        cout<<"Menu de opciones:"<< endl;
        cout<<"1. Suma          | 5. Comparacion"<< endl;
        cout<<"2. Resta         | 6. Imprimir Arreglo"<< endl;
        cout<<"3. Sumar 1       | 7. Salir"<< endl;
        cout<<"4. Restar 1      "<< endl;
        cout<<"---------------------------------------------------------------------"<<endl;

        cin >> menu;
}
}