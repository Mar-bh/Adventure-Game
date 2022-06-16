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
    std::cout << ">>>>";
    std::getline(std::cin, instruccion);
    std::stringstream sstr(instruccion);
    sstr >> primera;
    sstr >> segunda;
    sstr.ignore();
    
    try{
        Comando*  com = comandos->getComando(primera);
        if(com){
            com -> setSegPalabra(segunda);
            return com;
        }
        else{
            //fflush(stdin);
            //generaComando();
            //throw std::invalid_argument("Comando ingresado no es valido" );
            throw com;
        }
    } catch(Comando* error){
        std::cout<<"El comando que ingresaste no es valido!\nIntenta de nuevo :)\n";
        fflush(stdin);
        generaComando()->ejecuta(); // si el comando es incompleto ejecutamos ejecuta()
        generaComando(); // si el comando no es valido en ningun sentido volvemos a generaComando() para evaluar desde 0
        
        //procesaComando()->generaComando();
    //    std::cerr << "Ocurrio una excepcion: " << ia.what() << std::endl; 
    }
    //}
    
    // try{
    //         Comando* com = comandos->getComando(primera);
    //         com -> setSegPalabra(segunda);
    //         return com;
    // }catch(std::invalid_argument& ia){
    //      std::cerr << "Ocurrio una excepcion: " << ia.what() << std::endl; 
    // }

    //try {}
    //throw en getComando Invalid Argument con el mensaje "Comando ingresado no es valido"
   // Comando* com;
    // while(true){
    //     try{
    //         com=comandos->getComando(primera); 
    //         com->setSegPalabra(segunda);
    //         return com;
    //     } 
    //     return com;catch(std::invalid_argument& ia){
    //      std::cerr << "Ocurrio una excepcion: " << ia.what() << std::endl; 
    // }
    // }
}
   
