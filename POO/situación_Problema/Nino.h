#ifndef Nino_h
#define Nino_h
#include <iostream>
#include <fstream>
using namespace std;

#include "SerVivo.h"
class Nino:public SerVivo{
    public:
        Nino();
        Nino(string, Habitacion, string, Item);
        void setNombre(string);
        string getNombre();
        Item getItem ();
        void setItem(Item);
        void agarrar();
        void entregarTodo();
        void entregarUno();
        string muestra();
    private:
        string nombre;
        Item inventario[2];
};

Nino::Nino(){
  nombre=' ';
  inventario[2];
}

Nino::Nino(string especie_, Habitacion habitacionActual_, string nombre_, Item inventario_):SerVivo(especie_,habitacionActual_){
  nombre=nombre_;
  inventario[2]=inventario_;
}

string Nino::getNombre(){
  return nombre;
}
void Nino::setNombre(string nombre_){
  nombre=nombre_;
}
Item Nino::getItem(){
  //item=item_;
}
void Nino::setItem(Item inventario_){
  inventario[2]=inventario_;
}

void Nino::agarrar(){

}
void Nino::entregarTodo(){

}
void Nino::entregarUno(){

}

string Nino::muestra(){
  string resultado = SerVivo::muestra()+"un niño."
  return resultado;
}
#endif
