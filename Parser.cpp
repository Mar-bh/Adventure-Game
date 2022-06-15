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
    std::string instruccion, primera, segunda;
    std::cout << ">>>>";
    std::getline(std::cin, instruccion);
    std::stringstream sstr(instruccion);
    sstr >> primera;
    sstr >> segunda;
    sstr.ignore();
    //try {}
    //throw en getComando Invalid Argument con el mensaje "Comando ingresado no es valido"
    while(true){
        try{
        Comando* com=comandos->getComando(primera); 
        com->setSegPalabra(segunda);
        return com;
        } catch(std::invalid_argument& ia){
        std::cerr << "Ocurrio una excepcion: " << ia.what() << std::endl; 
        }
    }
}
   
