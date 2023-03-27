#ifndef Habitacion_h
#define Habitacion_h
#include <iostream>
#include <fstream>
using namespace std;

#include "Item.h"
class Habitacion{
  public:
    Habitacion();
    Habitacion(string,Item, string);
    Item getItem ();
    void setItem(Item);
    char getSalidas()const;
    void setSalidas(string, string);
    string getDescripcion();
    void setDescripcion(string descripcion_);
  private:
    string descripcion;
    Item items[5];
    char salidas;
};

Habitacion::Habitacion(){
  descripcion ="";
  items[5];
  //salidas=;
}
Habitacion::Habitacion(string descripcion_, Item items_, string salidas_ ){
  descripcion=descripcion_;
  items[5]=items_;
  salidas=salidas_;
}

Item Habitacion::getItem(){
  return items[5];
}

void Habitacion::setItem(Item items_){
  items[5]=items_;
}

char Habitacion::getSalidas()const{
  return salidas;
}
void Habitacion::setSalidas(string descr, string sal){
  descripcion=descr;
  salidas=sal;
}
string Habitacion::getDescripcion(){
  return descripcion;
}
void Habitacion::setDescripcion(string descripcion_){
  descripcion=descripcion_;
}

#endif
