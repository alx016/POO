
#include <iostream>
#include <string>
using namespace std;

#include "Perro.h"
#include "Gato.h"

int main()
{

//  ***Sigue los pasos de la sección "Instructions" para construir este programa***
//    Este sería el menú, si se desplegara, pero déjalo como comentario, es sólo guía para ti.
//    cout << "a) mostrar los 3 datos de ejemplo " << endl;
//    cout << "b) pedir al usuario los datos y mostrarlos " << endl;
//    cout << "opcion? " << endl;
    char opcion=' ';
    cin>>opcion;
    Animal* animales[3];
    switch(opcion){
        case 'a':
            animales[0]= new Gato("Silvestre",1947);
            animales[1]= new Perro("Fido",2008);
            animales[2]= new Gato("Tom",1940);
            break;
        case 'b':
          char tipo;
          string nom;
          int anio;
          cin>>tipo>>nom>>anio;
          for(int i=0;i>3;i++){
            if (tipo=='p'){
              animales[i] = new Perro(nom,anio);
            }
            else if(tipo=='g'){
              animales[i] = new Gato(nom,anio);
            }
            // switch(tipo){
            //   case 'p':
            //     animales[i] = new Perro(nom,anio);
            //     break;
            //   case 'g':
            //     animales[i] = new Gato(nom,anio);
            //     break;
            //   default:
            //     break;
            //   }
            }
          break;

    }
    for (int i=0;i<3;i++){
      animales[i] -> muestra();
      animales[i] -> habla();

    }


  return 0;
}
