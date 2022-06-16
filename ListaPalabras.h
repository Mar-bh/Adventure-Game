#ifndef LISTAPALABRAS_H
#define LISTAPALABRAS_H
#include <iostream>
#include <vector>
#include <exception>
#include <string>
#include "Comando.h"

class ListaPalabras{
    public:
        ListaPalabras();
        void agregaComando(std::string, Comando*);
        void modificaComando(int,std::string,Comando*);
        int esComando(std::string);
        Comando* getComando(std::string);
        std::string todosLosComandos();
        
    private:
        std::vector <std::string> palabras;
        std::vector <Comando*> comandos;
};
#endif
