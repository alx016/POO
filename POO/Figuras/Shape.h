#ifndef SHAPE_H
#define SHAPE_H

class Shape{
private:
  int x;
  int y;
public:
  Shape();
  Shape(double, double);
  double getX() const;
  double getY() const;
  void setX(double);
  void setY(double);
  virtual string draw();
  virtual double area() = 0; //Clase Abstracta: la clase se vuelve abstracta, tambien es un metodo virtual puro.esto lo hace abstracta.
};

Shape::Shape(){
  x=0;
  y=0;
}

Shape :: Shape(double _x, double _y){
  x=_x;
  y=_y;
}
double Shape::getX()const{
  return x;
}
double Shape::getY()const{
  return y;
}
void Shape::setX(double _x){
  x=_x;
}
void Shape::setY(double _y){
  y=_y;
}

string Shape::draw(){  //polimorfismo
  return "Soy una figura";
}

#endif //Shape H
