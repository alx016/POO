#ifndef Mama_h
#define Mama_h
#include <iostream>
#include <fstream>
using namespace std;

#include "SerVivo.h"
class Mama:public SerVivo{
    public:
        Mama();
        Mama(string, Habitacion, Item);
        void recibe();
        string muestra();
    private:
        Item inventario[5];
};

Mama::Mama(){
    inventario[5];
}

Mama::Mama(string espe, Habitacion habactual, Item inv):SerVivo(espe, habactual){
    inventario[5]=inv;
}

void Mama::recibe(){

}
string Mama::muestra(){
  string resultado = SerVivo::muestra()+"una mama."
  return resultado;
}
#endif //Mama_h
