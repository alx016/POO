#include "Shape.h"

class Polygon:public Shape{
public:
  Polygon();
  Polygon(double, double, double);
  double getNumeroLados() const;
  void setNumeroLados(double);

private:
  double numeroLados;
};

Polygon::Polygon(){
  numeroLados=0;
}
Polygon::Polygon(double _x, double _y, double _numeroLados):Shape(_x, _y){
  alto=_numeroLados;
}

double Polygon::getNumeroLados() const{
  return numeroLados;
}

void Rectangle::setNumeroLados(double _numeroLados){
  numeroLados=_numeroLados;
}
#endif //Polygon h
