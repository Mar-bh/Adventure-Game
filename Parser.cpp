#include <string>
#include <sstream>
#include "Parser.h"


Parser::Parser(){
    comandos=new ListaPalabras;
}

ListaPalabras* Parser::getComandos(){
    return comandos;
}

Comando* Parser::generaComando(){
    fflush(stdin);
    std::string instruccion, primera, segunda;
    bool correct = true;
    std::cout << ">>>>";
    while (correct){
    std::getline(std::cin, instruccion);
    std::stringstream sstr(instruccion);
    sstr >> primera;
    sstr >> segunda;
    sstr.ignore();
    Comando* com=comandos->getComando(primera);
    try{
        Comando*  com = comandos->getComando(primera);
        if(com){
            com -> setSegPalabra(segunda);
            correct = false;
            return com;
        }
        else{

            throw com;
        }
    } catch(Comando* error){
        std::cout<<"El comando que ingresaste no es valido!\nIntenta de nuevo :)\n";
    }
  }
}