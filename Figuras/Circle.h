#ifndef CIRCLE_H
#define CIRCLE_H

#include "Shape.h"

const double PI=3.14159;

class Circle:public Shape{
public:
  Circle();
  Circle(double, double, double);
  double getRatio() const;
  void setRatio(double);
  string draw() override;//poner el override es opcional
  //void coordenadas();
  double area(); //CLASE ABSTRACTA

private:
  double ratio;

};

Circle::Circle(){
  ratio=1;
}

Circle::Circle(double _x, double _y, double _ratio):Shape(_x, _y){
  ratio=_ratio;
}

double Circle::getRatio() const{
  return ratio;
}
void Circle::setRatio(double _ratio){
  ratio=_ratio;
}

string Circle::draw(){
  string resultado = Shape::draw() + ": Circulo";
  return resultado;
}

double Circle::area(){
return PI*ratio*ratio;
}
#endif //CIRCLE_H
