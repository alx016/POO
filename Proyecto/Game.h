#ifndef GAME_H
#define GAME_H
#include <iostream>

#include "Room.h"
#include "DesplazaComando.h"
#include "AyudaComando.h"
#include "TomaComando.h"
#include "DarComando.h"
#include "Parser.h"
#include "Item.h"
#include "Nino.h"
#include "Mama.h"

class Game {
    public:
        Game();
        void creaElementos();
        void creaComandos();
        void play();
        bool procesaComando(Comando*);
        void imprimeBienvenida();
    private:
        Parser parser;
        Nino* personaje;
        Mama* mom;
        Room *recepcionCasa, *comedor, *cocina, *habitacion, *afuera;
        Item *pan, *queso, *jamon, *lechuga, *tomate, *monedas, *llave;
};

Game::Game(){
    creaElementos();
    creaComandos();
}

void Game::creaComandos(){
    ListaPalabras* comandos=parser.getComandos();
    comandos->agregaComando("desplaza", new DesplazaComando(personaje));
    comandos->agregaComando("toma", new TomaComando(personaje));
    comandos->agregaComando("dar", new DarComando(personaje,mom));
    comandos->agregaComando("ayuda", new AyudaComando(comandos));
}

/*crea todos los elementos que están presentes en el juego
y los configura (cuartos sus salidas y que objetos hay en cada room)*/
void Game::creaElementos(){
    personaje=new Nino("Fabi con hambre y lista para salir a jugar",0);
    mom=new Mama();

    recepcionCasa=new Room("Recepcion de la casa, totalmente amueblada. A lado de la puerta \n esta el pan en un mesa.", false);
    comedor=new Room("Comedor con mesa para 6 personas y un florero al centro.\n En una de las esquinas se encuentra un pedazo de queso", false);
    cocina=new Room("Estas en la cocina. Aqui se encuentra tu mama. \n A lado del microondas hay unas rebanadas de jamón.\n Y encima del horno esta la lechuga. ", false);
    habitacion=new Room("tu cuarto. En una de las repisas hay monedas. \n Y por alguna extrania razon hay un tomate en tu buro.", false);
    afuera=new Room("la calle!!! Ya puedes ir a jugar con tus amigos!", true);

    pan=new Item("pan");
    queso=new Item("queso");
    jamon=new Item("jamon");
    lechuga=new Item("lechuga");
    tomate=new Item("tomate");
    monedas=new Item("monedas");
    llave=new Item("Llave");

    personaje->setPosicion(recepcionCasa);
    mom->setPosicion(cocina);
    recepcionCasa->agregaItem(pan);
    comedor -> agregaItem(queso);
    cocina->agregaItem(jamon);
    cocina->agregaItem(lechuga);
    habitacion->agregaItem(monedas);
    habitacion->agregaItem(tomate);
    recepcionCasa->agregaItem(llave);
    //mom->agregaItem(llave);
    //cocina->agregaItem(llave);
    // int num1=mom->getNum();
    // if (num1==6){
    //   cocina->agregaItem(llave);
    // }
    recepcionCasa->setSalidas(habitacion, afuera, nullptr, cocina);
    comedor->setSalidas(nullptr, cocina, habitacion, nullptr);
    cocina->setSalidas(comedor, nullptr, recepcionCasa, nullptr);
    habitacion->setSalidas(nullptr, recepcionCasa, nullptr, comedor);
    afuera->setSalidas(recepcionCasa,nullptr,nullptr,nullptr);
}

void Game::imprimeBienvenida(){
    std::cout<<"Estas en la recepcion de la casa y con ganas de salir a jugar."<<std::endl;
    std::cout <<"Tu eres solo un niño. Un niño olvidadizo y desordenado,\n que quiere salir a jugar con sus amigos"<<std::endl;
    std::cout <<"Pero antes necesitas comer. Encuentra los ingredientes necesarios "<<std::endl;
    std::cout <<"para un sandwich y entregaselos a tu mama. A cambio ella te dara la Llave"<<std::endl;
    std::cout <<"de la casa para que puedas salir a jugar con tus amigos."<<std::endl;
    std::cout << "Si necesitas ayuda teclea la palabra: ayuda" << std::endl;
}

 void Game::play()
    {
        imprimeBienvenida();
        bool finished = false;
        while (!finished) {
            Comando* comando = parser.generaComando();
            finished = procesaComando(comando);
        }

        std::cout << "Gracias por jugar este juego de aventura" << std::endl;
    }

    bool Game::procesaComando(Comando* instr){
        bool salio = false;
        instr->ejecuta(); // se esta ejecutando polimorfismo

        if(personaje->getPosicion()==afuera){
            if(personaje->buscaItem("Llave")){
                salio = true;
            }
            else{
                personaje->setPosicion(recepcionCasa);
            }
        }
     return salio;
    }

#endif //GAME_H
