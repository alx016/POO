#ifndef Rata_h
#define Rata_h

#include "SerVivo.h"

class Rata:public SerVivo{
public:
  Rata();
  Rata(string, Habitacion, Item);
  void intercambia();
  string muestra();
private:
  Item item;
};
Rata::Rata(){

}

Rata::Rata(string especie_, Habitacion habitacionActual_,Item item_):SerVivo(especie_,habitacionActual_){

}

void Rata::intercambia(){

}
string Rata::muestra(){
  string resultado = SerVivo::muestra()+"una rata."
  return resultado;
}
#endif //Rata_h
