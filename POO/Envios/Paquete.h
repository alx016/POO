#ifndef PAQUETE_H
#define PAQUETE_H

#include "Envio.h"
#include "Persona.h"

class Paquete:public Envio{
public:
  Paquete();
  Paquete(Persona, Persona,double, double, double);
  double getPesoPaquete()const;
  double getCostoKilogramo()const;
  void setPesoPaquete(double);
  void setCostoKilogramo(double);
  //double datosMiembros();
  double calculaCosto();
private:
  double pesoPaquete;
  double costoKilogramo;
};

Paquete::Paquete(){
  pesoPaquete=0;
  costoKilogramo=0;
}

Paquete::Paquete(Persona datosRemitente_, Persona datosDestinatario_,double costoEstandar_, double pesoPaquete_,double costoKilogramo_):Envio(datosRemitente_,datosDestinatario_,costoEstandar_){
    if (pesoPaquete<0){
      pesoPaquete=0;
    }
    else{
      pesoPaquete=pesoPaquete_;
    }
    if (costoKilogramo<0){
      costoKilogramo=0;
    }
    else{
      costoKilogramo=costoKilogramo_;
    }

        }
double Paquete::getPesoPaquete()const{return pesoPaquete;}
double Paquete::getCostoKilogramo()const{return costoKilogramo;}

void Paquete::setPesoPaquete(double pesoPaquete_){pesoPaquete=pesoPaquete_;}
void Paquete::setCostoKilogramo(double costoKilogramo_){costoKilogramo=costoKilogramo_;}

//double Paquete::datosMiembros()
double Paquete::calculaCosto(){
  double resultado;
  resultado=pesoPaquete*costoKilogramo+ getCostoEstandar();
  return resultado;
}
#endif
