#ifndef CHARACTER_H
#define CHARACTER_H
#include <iostream>
#include <vector>
#include "Room.h"
#include "Item.h"

class Character {
    public:
        Character();
        Character(std::string, int);
        std::string getNombre() const;
        // int getHp() const;
        void setNombre(std::string);
        // void setHp(int);
        // void actualizaHp(int);
        Room* getPosicion() const;
        int getNum();
        void setNum(int);
        void setPosicion(Room*);
        void agregaItem(Item*);
        // Item* consultaItem(int pos) const;
        virtual void imprime()=0;
        // bool camina(std::string);
        bool buscaItem(std::string);
        Item* sacaItem(std::string);
        friend ostream& operator<< (ostream&, const Character&);
        //Character operator ++ ();
        //virtual void ataque(Personaje&);
    private:
        std::string nombre;
        //int hp;
        int num;
        Room* posicion;
        vector <Item*> inventario;
};

Character::Character(){
    posicion=nullptr;
    nombre="Personaje";
    num=inventario.size();
    // hp=100;
}

Character::Character(std::string name,int num_){
    posicion=nullptr;
    nombre=name;
    num=num_;
    // hp=pts;
}

std::string Character::getNombre() const{
    return nombre;
}

// int Character::getHp() const{
//     return hp;
// }

void Character::setNombre(std::string name){
    nombre=name;
}

// void Character::setHp(int pts){
//     hp=pts;
// }


// void Character::actualizaHp(int pts){
//     hp+=pts;
// }

Room* Character::getPosicion() const{
    return posicion;
}

void Character::setPosicion(Room* nuevo){
    posicion=nuevo;
}

int Character::getNum(){
  return num=inventario.size();
}
void Character::setNum(int num_){
  num=num_;
}

void Character::agregaItem(Item* item){
    inventario.push_back(item);
  }

ostream &operator<<(ostream& n, const Character& x){
    n << x.nombre << " con "<< x.num <<"ingredientes";
    return n;
}
void Character::imprime(){
    std::cout << "Hola, que tal! " << std::endl;
}

bool Character::buscaItem(string cosa){
    for(int i=0; i<inventario.size(); i++){
        if (inventario[i]->getDescripcion()==cosa){
            return true;
        }
    }
    return false;
}

Item* Character::sacaItem(string cosa){
  Item* eliminado;
  for(int i=0; i<inventario.size(); i++){
      if (inventario[i]->getDescripcion()==cosa){
          eliminado=inventario[i];
          inventario.erase(inventario.begin()+i);
          return eliminado;
      }
    }
  return nullptr;
}

#endif //CHARACTER_H
