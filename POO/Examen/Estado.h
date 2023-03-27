#ifndef ESTADO_H
#define ESTADO_H

#include "Territorio.h"
#include <string>

class Estado:public Territorio {
public:
  Estado();
  Estado(string, double,double);
  double getPresupuesto()const;
  void setPresupuesto(double);

  string obtenerDatos();
private:
  double presupuesto;
};

Estado::Estado(){
  presupuesto=0;
}
Estado(string nombre_, double superficie_, double presupuesto_):Territorio(nombre_,superficie_){
  presupuesto=presupuesto_;
}
double getPresupuesto()const{return presupuesto;}
void setPresupuesto(double presupuesto_){presupuesto=presupuesto_;}

string Estado::obtenerDatos(){
  string datos="Estado" + Territorio::obtenerDatos() + "presupuesto:$"<<to_string(presupuesto)<<endl;
  return datos;
}

#endif
