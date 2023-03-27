#ifndef Servivo_h
#define Servivo_h
#include <iostream>
#include <fstream>
using namespace std;
#include "Item.h"
#include "Habitacion.h"

class SerVivo{
    public:
        SerVivo();
        SerVivo(string, Habitacion);
        void setEspecie(string);
        string getEspecie()const;
        virtual string muestra() = 0;
    private:
        string especie;
        Habitacion habitacionActual;
};

SerVivo::SerVivo(){
    especie="";
    //habitacionActual="Recepcion";
}

SerVivo::SerVivo(string esp, Habitacion hab){
    especie=esp;
    habitacionActual=hab;
}

void SerVivo::setEspecie(string especie_){
    especie=especie_;
}

string SerVivo::getEspecie()const{
    return especie;
}
string SerVivo::muestra(){
  return "Yo soy ";
}

#endif //Servivo_h
