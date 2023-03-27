// Declara e implementa aquí la clase Perro
#ifndef PERRO_H
#define PERRO_H

#include "Animal.h"

class Perro:public Animal{
    public:
    Perro(string, int);
    void habla();
    void muestra();
};

Perro::Perro(string nom, int aNac):Animal(nom, aNac){}

void Perro::habla(){
    cout<<"GUAU"<<endl;
}
void Perro::muestra(){
    cout<<"Soy el perro "<<getNombre()<<" tengo "<<calculaEdad()<<" años"<<endl;
}

#endif // PERRO_H
