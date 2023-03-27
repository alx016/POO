#ifndef DARCOMANDO_H
#define DARCOMANDO_H
#include "Character.h"
#include "Nino.h"
#include "Mama.h"
#include "Item.h"
#include "Comando.h"
class DarComando :public Comando{
    public:
        DarComando(Nino*, Mama*);
        void ejecuta();
    private:
        Nino* personaje;
        Mama* mama;
};

DarComando::DarComando(Nino* nino_, Mama* mama_):Comando("Dar", ""){
    personaje=nino_;
    mama=mama_;
}

void DarComando::ejecuta(){
    if (!tieneSegPalabra()){
        std::cout<<"Que quieres dar de tu inventario?...\n" << "no puedo ayudarte si no me das toda la información..." << std::endl;
    }
    else{
        std::string cosa = getSegPalabra();
        Room* actual= personaje->getPosicion();
        Room* actual1= mama->getPosicion();
        if (actual != actual1){
          std::cout<<"No hay nadie en la habitacion que pueda recibir los ingredientes."<<std::endl;
        }
        else{

          Item* num=personaje->sacaItem(cosa); //veo si está en el cuarto (posicion dentro del vector)
          if (num!=nullptr){
              mama->agregaItem(num);
              std::cout << "Haz entregado: "<< std::endl;
              std::cout << num->getDescripcion() << std::endl;

              //std::cout<<num1<<std::endl;

          }
          else{
              std::cout<< "Ese objeto no se encuentra en tu inventario..."<<std::endl;
              std::cout << "Recuerda tu tienes esto: "<<&actual<< std::endl;
              actual->getDescripcion();
          }
          int num1=mama->getNum();
          if (num1==5){
            std::cout<<"Gracias por los ingredientes! La Llave esta en la recepcion."<<std::endl;
          }
          // int num1=mama->getNum();
          // if (num1=6){
          //   string cosa1="llave";
          //   Item* num2=mama->sacaItem(cosa1);
          //   personaje ->agregaItem(num2);
          // }
          // if (num1!=nullptr){
          //   actual-> agregaItem(num1);
          //   std::cout << "Ya tienes la llave"<< std::endl;
          // }
    }
  }
}


#endif //DARCOMANDO_H
