#ifndef PAIS_H
#define PAIS_H

#include "Territorio.h"

class Pais:public Territorio{
public:
  Pais();
  Pais(string, double, string, string);
  string getIdioma()const;
  string getMoneda()const;
  void setIdioma(string);
  void setMoneda(string);

  string obtenerDatos();
private:
  string idioma, moneda;
};
Pais::Pais(){
  idioma='-';
  moneda='-';
}
Pais(string nombre_, double superficie_, string idioma_, string moneda_):Territorio(nombre_,superficie_){
  idioma=idioma_;
  moneda=moneda_;
}
string getIdioma()const{return idioma;}
string getMoneda()const{return moneda;}
void setIdioma(string){idioma=idioma_;}
void setMoneda(string){moneda=moneda_;}

string Pais::obtenerDatos(){
  string datos= "País " + Territorio::obtenerDatos() + "idioma: "<<idioma<<" moneda:"<<moneda;
  return datos;
}

#endif
