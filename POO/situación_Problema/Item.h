#ifndef Item_h
#define Item_h
#include <iostream>
#include <fstream>
using namespace std;

class Item{
    public:
        Item();
        Item(string);
        string getDescripcion() const;
        void setDescripcion(string);

    private:
        string descripcion;

};

Item::Item(){
    descripcion="";
}

Item::Item(string desc){
    descripcion=desc;
}

string Item::getDescripcion()const{
    return descripcion;
}

void Item::setDescripcion(string D){
    descripcion=D;
}

#endif //Item_h