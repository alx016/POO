#ifndef TERRITORIO_H
#define TERRITORIO_H

#include <string>

class Territorio {
public:
  Territorio();
  Territorio(string, double);
  string getNombre()const;
  double getSuperficie()const;
  void setNombre(string);
  void setSuperficie(double);

  virtual string obtenerDatos();

  friend ostream& operator << (ostream& , Territorio*);

private:
  string nombre;
  double superficie;
};
Territorio::Territorio(){
  nombre='-';
  superficie=0;
}
Territorio::Territorio(string nombre_, double superficie_){
  nombre=nombre_;
  superficie=superficie_;
}
string Territorio::getNombre()const{return nombre;}
double Territorio::getSuperficie()const{return superficie;}
void Territorio::setNombre(string nombre_){nombre=nombre_;}
void Territorio::setSuperficie(double superficie_){superficie=superficie_;}

 ostream& operator << (ostream& datos, Territorio* terri){
   datos << terri;
   return datos;
}
string Territorio::obtenerDatos(){
  string datos= nombre<<' '<<'-'<<' '<<to_string(superficie)<<' '<<"m^2"<<' ';
  return datos;
}


#endif
