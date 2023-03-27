#ifndef ENVIO_H
#define ENVIO_H
#include "Persona.h"

class Envio {
public:
  Envio();
  Envio(Persona,Persona,double);

  Persona getDatosRemitente();
  Persona getDatosDestinatario();

  void setDatosRemitente(Persona);
  void setDatosDestinatario(Persona);

  double getCostoEstandar()const;
  void setCostoEstandar(double);

  virtual double calculaCosto();//Polimorfismo

private:
  Persona datosRemitente; //Composicion 
  Persona datosDestinatario;

  double costoEstandar;
};

Envio::Envio(){
  costoEstandar=0;
}
  Envio::Envio(Persona datosRemitente_, Persona datosDestinatario_,double costoEstandar_){
    datosRemitente=datosRemitente_;
    datosDestinatario=datosDestinatario_;
    costoEstandar=costoEstandar_;
  }
  Persona Envio::getDatosRemitente(){return datosRemitente;}
  Persona Envio::getDatosDestinatario(){return datosDestinatario;}

  double Envio::getCostoEstandar()const{return costoEstandar;}
  void Envio::setCostoEstandar(double costoEstandar_){costoEstandar=costoEstandar_;}

  void Envio::setDatosRemitente(Persona datosRemitente_){datosRemitente=datosRemitente_;}
  void Envio::setDatosDestinatario(Persona datosDestinatario_){datosDestinatario=datosDestinatario_;}


  double Envio::calculaCosto(){
    return costoEstandar;
  }
#endif
