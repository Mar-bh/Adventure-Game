#ifndef POLLOS_H
#define POLLOS_H
#include <iostream>

class Pollos
{
private:
    std::string pollos;
    std::string caracteristica;
    int puntos;
public:
    Pollos();
    Pollos(int,std::string,std::string);
    ~Pollos();
    std::string getPollos() const; 
    std::string getCaracteristica() const; 
    int getPuntos()const;
    void setPollos(std::string);
    void setCaracteristica(std::string);
    void setPuntos(int);
    void descripcion();
};

#endif 