#include "ListaPalabras.h"

ListaPalabras::ListaPalabras(){}

void ListaPalabras::agregaComando(std::string pal, Comando* com){
    palabras.push_back(pal);
    comandos.push_back(com);
}

int ListaPalabras::esComando(std::string pal){
    for(int i=0; i<palabras.size(); i++){
        if (palabras[i]==pal){
            return i;
        }
    }
    return -1;
}

void ListaPalabras::modificaComando(int pos, std::string pal, Comando* com){
    palabras[pos] = pal;
    comandos[pos] = com;
}

Comando* ListaPalabras::getComando(std::string pal){
    int pos=esComando(pal);
    if(pos>=0){
        return comandos[pos];
     } //else {
    //     throw std::invalid_argument("Comando ingresado no es valido" );
    // }
    return nullptr;
}

std::string ListaPalabras::todosLosComandos(){
    std::string todos="Los comandos que puedes usar son:\n";
    for(std::string &pal:palabras){
        todos += "\t"+ pal + "\n";
    }
    todos+= "\t-> El comando de ayuda consiste en una sola palabra. \n\t-> Los otros comandos van seguido de una segunda palabra.";
    return todos;
}