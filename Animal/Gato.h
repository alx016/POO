// Declara e implementa aquí la clase Gato
#ifndef GATO_H
#define GATO_H

#include "Animal.h"

class Gato:public Animal{
    public:
    Gato(string, int);
    void habla();
    void muestra();
};

Gato::Gato(string nom, int aNac):Animal(nom, aNac){}

void Gato::habla(){
    cout<<"MIAU"<<endl;
}
void Gato::muestra(){
    cout<<"Soy el gato "<<getNombre()<<" tengo "<<calculaEdad()<<" años"<<endl;
    
}

#endif //GATO_H
