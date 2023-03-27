#include <iostream>
using namespace std;
#include <vector>
#include "Circle.h"
#include "Rectangle.h"

int* ejemplo(){
  static int x=88;
  int* ptrInt=&x;
  return ptrInt;
}

int main(){
  //Apuntador es una variable especial que lo que guarda son direcciones de memoria.
  cout<<"---------apuntadores----------"<<endl;
  int* ptrInt;//Apuntador de tipo entero
  int valor=5;
  ptrInt=&valor;// el & nos da la direccion de memoria en este caso de la variable valor
  cout<<ptrInt<<" - Es la dirección de memoria"<<endl;
  cout<<&valor<<" - Direccion de memoria de valor: "<<endl;
  cout<<*ptrInt<< " - Valor al cual apunta el apuntador"<<endl;//Imprime el valor 5

  //Las referencias es guardar una variable bajo otro nombre (alias)

  //memoria dinamica
  int* ptrInt2;
  ptrInt2=new int(10);//se guarda la dirección de memoria del valor entero 10
  cout<<ptrInt2<<" - Es la dirección de memoria"<<endl;
  cout<<*ptrInt2<< " - Valor al cual apunta el apuntador"<<endl;//Imprime el valor 10

  int* ptrInt3=ejemplo();
  cout<<ptrInt3<<endl;

  Circle c1(2,4,5);
  Circle* ptrC1=&c1;
  cout<<(*ptrC1).draw()<<endl;
  cout<<ptrC1->draw()<<endl;
  cout<<ptrC1<<endl;

  Circle* ptrCircle=new Circle(-1,1,4);//Creacion dinamica
  cout<<ptrCircle->draw()<<endl;

  ptrCircle=NULL;

  delete ptrCircle; //libera el espacio de memoria
  cout<<"---------polimorfismo----------"<<endl;
  Shape* figuras[5];
  figuras[0]= new Circle(1,1,2);
  figuras[1]= new Rectangle(0,0,4,2);
  figuras[2]= new Circle(1,2,2);
  figuras[3]= new Circle(3,3,4);
  figuras[4]= new Rectangle(-5,-5,5,6);
  for (int i=0;i<5;i++){
    cout<< figuras[i]->draw() <<endl;
    cout<< "El area es: "<<figuras[i]->area()<<endl;
    if (Circle* c=dynamic_cast<Circle*>(figuras[i])){//dynamic_cast= convierte la referencia "figuras[i]" a tipo circulo y se guarda en la variable "c"
      cout<<"Radio del circulo: "<< c->getRatio()<<endl;
    }//cast dinamico
  }

  vector<Shape*> figuras2;//entre <> esta el tipo de apuntador (tipo shape)
  figuras2.push_back(new Circle(2,2,8));
  figuras2.push_back(new Rectangle(1,1,4,6));
  figuras2.push_back(new Circle(1,1,1));
  cout<<"---------con vector----------"<<endl;
  for(int i=0;i<figuras2.size();i++){
    cout<< figuras2[i]->draw() <<endl;
  }
  //Puede ver todos los métodos de vector en:
  // https://www.tutorialspoint.com/cpp_standard_library/vector.htm

  return 0;
}
