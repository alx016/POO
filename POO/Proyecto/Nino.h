#ifndef NINO_H
#define NINO_H
#include <iostream>
#include <fstream>
using namespace std;

#include "Character.h"
#include "Room.h"

class Nino:public Character{
    public:
        Nino();
        Nino(string,int);
        bool camina(std::string);
        //bool buscaItem(std::string);
        Item* consultaItem(int pos) const;
        void imprime();
};

Nino::Nino(){
}

Nino::Nino(string name, int num_):Character(name,num_){
}



bool Nino::camina(string dir){
    Room* voyA=getPosicion()->getSalida(dir);
    if (voyA!=nullptr && !voyA->requiereLlave()){
        setPosicion(voyA);
        return true;
    }
    else if (voyA!=nullptr && voyA->requiereLlave()){
        if (buscaItem("Llave")){
            setPosicion(voyA);
            return true;
        }
    }
    return false;
}

void Nino::imprime(){
    std::cout << "Soy " << getNombre() <<std::endl;
    std::cout << "y llevo en mi bolsa "<< getNum() << "ingredientes recolectados." << std::endl;
}
#endif
