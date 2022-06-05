#ifndef COMANDO_H
#define COMANDO_H
#include <iostream>

class Commando {
    public:
        Comando();
        Comando(std::string, std::string);
        std::string getComando() const;
        void setSegPalabra(std::string);
        bool tieneSegPalabra();
        virtual void ejecuta() = 0;
    private: 
        std::string comando;
        std::string segPalabra;
};
#endif