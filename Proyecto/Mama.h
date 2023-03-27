#ifndef MAMA_H
#define MAMA_H
#include <iostream>
#include <fstream>
using namespace std;

#include "Character.h"
class Mama:public Character{
    public:
        Mama();
        Mama(string,int);
        void imprime();
};

Mama::Mama(){
}

Mama::Mama(string name,int num_):Character(name, num_){
}

void Mama::imprime(){
    std::cout << "Soy " << getNombre() <<std::endl;
}

#endif //Mama_h
