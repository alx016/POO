#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "Shape.h"

class Rectangle:public Shape{
public:
  Rectangle();
  Rectangle(double, double, double, double);
  double getAlto() const;
  double getAncho()const;
  void setAlto(double);
  void setAncho(double);
  string draw()override;
  double area();

private:
  double alto;
  double ancho;
};

Rectangle::Rectangle(){
  alto=0;
  ancho=0;
}
Rectangle::Rectangle(double _x, double _y, double _alto, double _ancho):Shape(_x, _y){
  alto=_alto;
  ancho=_ancho;
}

double Rectangle::getAlto() const{
  return alto;
}
double Rectangle::getAncho() const{
  return ancho;
}
void Rectangle::setAlto(double _alto){
  alto=_alto;
}
void Rectangle::setAncho(double _ancho){
  ancho=_ancho;
}
string Rectangle::draw(){
  string resultado = Shape::draw() + ": Rectangulo";
  return resultado;
}

double Rectangle::area(){
  return ancho*alto;
}
#endif //Rectangle h
