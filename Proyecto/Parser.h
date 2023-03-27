#ifndef PARSER_H
#define PARSER_H

#include <iostream>
#include "ListaPalabras.h"

class Parser {//traducir lo escrito a un comando valido para el proyecto
    public:
        Parser();
        Parser(ListaPalabras*);
        ListaPalabras* getComandos();
        Comando* generaComando();
    private:
        ListaPalabras* comandos;
};

Parser::Parser(){
    comandos=new ListaPalabras;
}


ListaPalabras* Parser::getComandos(){
    return comandos;
}

Comando* Parser::generaComando(){
  std::string instruccion, primera, segunda;
    while (true)
    {
       std::cout << ">>>>";
        std::getline(std::cin, instruccion);//toma toda la linea hasta un entero
        std::stringstream sstr(instruccion);//lo divide en strings
        sstr >> primera;
        sstr >> segunda;
        sstr.ignore();
        try{
            Comando* com=comandos->getComando(primera);
            if (com==nullptr){
                throw invalid_argument("Comando inválido, introduzca de nuevo");
            }
            com->setSegPalabra(segunda);
            return com;
        }
        catch(invalid_argument &er){
            cerr<<er.what()<<endl;
        }
    }

}

#endif //PARSER_H
