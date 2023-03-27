#ifnd//#ifndef COMPLEJO_H
#define COMPLEJO_H
#include <iostream>
#include <string>



class Complejo{
    private:
      double real;
      double imaginario;
    public:
      Complejo();
      Complejo(double, double);
      double getReal();
      double getImaginario();
      void setReal(double);
      void setImaginario(double);
      void agregar(Complejo&);
      Complejo conjugado();
      Complejo suma(Complejo&);
      Complejo multiplicacion(Complejo&);
      Complejo multiEscalar(double);
      void imprimir();
};
//Constructor
Complejo::Complejo(){
  imaginario=0;
  real=0;
}
Complejo::Complejo(double _imag, double _real){
  imaginario =_imag;
  real =_real;
}
void Complejo::setReal(double _real){
  real = _real;
}
void Complejo::setImaginario(double _imag){
  imaginario =_imag;
}
void Complejo::agregar(Complejo& _c1){
  real=real+_c1.getReal();
  imaginario=imaginario+_c1.getImaginario();
}
Complejo Complejo::conjugado(){
  real = real;
  imaginario = imaginario *-1;
  Complejo res (real,imaginario);
  return res;
}
Complejo Complejo::suma(Complejo& c1){
  //suma_r=real + c1.getReal();
  //suma_i=imaginario+c1.getImaginario();
  Complejo res(real + c1.getReal(),imaginario+c1.getImaginario());
  return res;
}
Complejo Complejo::multiplicacion(Complejo& c1){
  //multi_r=real * c1.getReal() - imaginario*c1.getImaginario();
  //multi_i=real*c1.getImaginario() + imaginario*c1.getReal();
  Complejo res(real * c1.getReal() - imaginario*c1.getImaginario(),real*c1.getImaginario() + imaginario*c1.getReal());
  return res;
}
Complejo Complejo::multiEscalar(double escalar){
  real = real *escalar;
  imaginario = imaginario*escalar;
  Complejo res(real,imaginario);
  return res;
}
void Complejo::imprimir(){
  if (imaginario<0){
    cout<<"("<<real <<"-"<<imaginario<<"i"<<")"<<endl;
  }
  else{
    cout<<"("<<real <<"+"<<imaginario<<"i"<<")"<<endl;
  }
}

double Complejo::getReal(){
  return real;
}
double Complejo::getImaginario(){
  return imaginario;
}

class MatrizComplejos{
  private:
    int n;
    int arreglo[20][20]; //arreglo bidimensional de 20 x 20
  public:
    MatrizComplejos();
    MatrizComplejos(int, int);
    int getN();
    void setN();
    int getPos(int, int);
    void setPos(int, int, Complejo&);
    MatrizComplejos suma(MatrizComplejos&);
    MatrizComplejos agrega(MatrizComplejos&);
};
