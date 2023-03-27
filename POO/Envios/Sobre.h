#ifndef SOBRE_H
#define SOBRE_H

#include "Envio.h"
#include "Persona.h"

class Sobre:public Envio{
public:
  Sobre();
  Sobre(Persona, Persona,double, double, double, double);
  double getLargo()const;
  double getAncho()const;
  double getCargaoAdicional()const;
  void setLargo(double);
  void setAncho(double);
  void setCargoAdicional(double);
  double calculaCosto();
private:
  double largo, ancho, cargaAdicional;
};
Sobre::Sobre(){
  largo=0;
  ancho=0;
  cargaAdicional=0;
}
Sobre::Sobre(Persona datosRemitente_, Persona datosDestinatario_,double costoEstandar_, double largo_, double ancho_, double cargaAdicional_):Envio(datosRemitente_,datosDestinatario_,costoEstandar_){
  largo=largo_;
  ancho=ancho_;
  cargaAdicional=cargaAdicional_;
}
double Sobre::getLargo()const{return largo;}
double Sobre::getAncho()const{return ancho;}
double Sobre::getCargaoAdicional()const{return cargaAdicional;}
void Sobre::setLargo(double largo_){largo=largo_;}
void Sobre::setAncho(double ancho_){ancho=ancho_;}
void Sobre::setCargoAdicional(double cargaAdicional_){cargaAdicional=cargaAdicional_;}

double Sobre::calculaCosto(){
  double resultado;
  if (largo>25 && ancho>30){
    resultado=cargaAdicional+getCostoEstandar();
  }
  else {
    resultado=getCostoEstandar();
  }

  return resultado;
}
#endif
