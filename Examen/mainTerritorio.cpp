#include <iostream>
using namespace std;
#include "Territorio.h"
#include "Pais.h"
#include "Estado.h"

int main(){
  Territorio* territorios[5];
  Circle* territorios=new Territorio("Mio",21353153);
  Circle* territorios=new Pais("México","español","peso");
  Circle* territorios=new Pais("Alemania","aleman","euro");
  Circle* territorios=new Estado("Jalisco",12345678.50);
  Circle* territorios=new Estado("Veracruz",12345678.50);

  for (int i=0;i<5;i++){
    cout<<territorios[i]->obtenerDatos()<<endl;
  }
  return 0;
}
