#ifndef ITEM_H
#define ITEM_H
#include <iostream>

class Item
{
private:
    std::string item;
    std::string caracteristica;
    int puntos;
public:
    Item();
    Item(int,std::string,std::string);
    ~Item();
    std::string getItem() const; 
    std::string getCaracteristica() const; 
    int getPuntos()const;
    void setItem(std::string);
    void setCaracteristica(std::string);
    void setPuntos(int);
    void descripcion();
    Item operator+(const Item&);
};

#endif 