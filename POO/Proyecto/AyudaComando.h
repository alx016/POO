#ifndef AYUDACOMANDO_h
#define AYUDACOMANDO_H
#include "Comando.h"
#include "ListaPalabras.h"
class AyudaComando:public Comando{
    public:
        AyudaComando(ListaPalabras*);
        void ejecuta();
    private:
        ListaPalabras* validas;
};

AyudaComando::AyudaComando(ListaPalabras* palabras):Comando("Ayuda", ""){
    validas=palabras;
}

void AyudaComando::ejecuta(){
    std::cout<< "Estas en tu casa con hambre, busca los ingredientes." << std::endl;
    std::cout << "No sabes que hacer, pero no te preocupes, recuerda...." << std::endl;
    std::cout << validas->todosLosComandos() << std::endl;
}

#endif //AYUDACOMANDO_H
