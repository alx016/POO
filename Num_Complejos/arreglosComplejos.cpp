#include <iostream>
#include <fstream>
using namespace std;

#include "Complejo.h"

void pruebaOperaciones(){
    //Prueba de los métodos de operaciones
    //Creo dos complejos con datos que reciba del usuario
    double re, im, re2, im2;
    cin>>re>>im;
    cin>>re2>>im2;
    //1. Escribe las instrucciones para crear los dos complejos c1 y c2 con los datos que te proporcionó el usuario
    Complejo c1(re,im);
    Complejo c2(re2,im2);
    //Creo un tercer complejo con 1 real e imaginario
    Complejo c3(1,1);

    //2. Imprimo c1 y c2, escribe las instrucciones para realizar el despliegue a pantalla
    c1.imprimir();
    c2.imprimir();
    //Pruebo el agregar, voy a agregar a c1 el complejo c3
    cout<<"Agregar: ";
    //3. Agrega las instrucciones para agregar a c1 el complejo c3
    c1.agregar(c3);
    //Imprimo c1 para ver el cambio
    c1.imprimir();
    //Pruebo la suma de c1 con c2, imprimo el resultado
    cout<< "Suma: ";
    //4. Crea el complejo llamado suma y asignale el valor resultante de la suma de c1 con c2
    Complejo suma(c1.suma(c2));
    suma.imprimir();
    //Pruebo la multiplicación de c1 con c2, imprimo el resultado
    //5. Crea el complejo llamado multi y asignale el resultado de la multiplicación de c1 y c2
    Complejo multi(c1.multiplicacion(c2));
    cout<< "Mutiplicacion: ";
    multi.imprimir();
    //Pruebo la multiplicación escalar c1 con 3.5, imprimo el resultado
    Complejo escalar(c1.multiEscalar(3.5));
    cout<<"Multiplicacion escalar: ";
    escalar.imprimir();
}

void cargaDatosSuma(int num){
    //7. Crea un arreglo de num Complejos
    Complejo arreglo[num];
    //Cargar datos para Construir los complejos
    double re, im;
    for (int i=0; i<num; i++){
        //Teclear los datos
        cin>>re>>im;
       //8. En la posición i del arreglo de Complejos, asigna el Complejo creado con los datos re e im.
        arreglo[i]=Complejo(re,im);
    }
    // la siguiente variable resultado será nuestro acumulador para ir sumando todos los complejos del arreglo.
    Complejo resultado;
    for (int i=0; i<num; i++){
        /*9.Escribe la instrucción para que en resultado queda la suma de lo que llevábamos
            con el complejo de la posición que estamos recorriendo*/
          resultado = resultado.suma(arreglo[i]);
    }
    //imprimo el resultado ya cuando tengo la suma de todo
    resultado.imprimir();
}

void cargaArchivoMultiEscalar(double num){
    //10. Declaro el arreglo llamado arr de 20 Complejos
    Complejo arr[20];
    ifstream archivo;
    //11. Instrucción para abrir el archivo Datos.txt
    archivo.open("Datos.txt");
    int numDatos=0;
    double re, im;
    while (archivo >> re >> im ) {
         /*12. En la posición numDatos del arreglo arr, asigno un Complejo creado
               con los datos que acabas de leer del archivo*/
        arr[numDatos]=Complejo(re,im);
         numDatos++;
    }
    for(int i=0; i<numDatos; i++){
        arr[i].imprimir();
        /*13. Cambio lo que tengo en la posición i por el nuevo complejo que se forma con la multiplicación del complejo
               guardado en la posición i y num (usa el método que multiplica un Complejo por un escalar*/
        arr[i]= arr[i].multiEscalar(num);//Completa aquí lo que hace falta.
    }
    //Mostrar ya modificados
    cout<<"Ya multiplicados por "<<num << endl;
    //14. Escribe el for para imprimir todos los datos del arreglo ahora que se han modificado
    for (int i=0; i<numDatos; i++){
      arr[i].imprimir();
    }


}

//El main está completo, no necesitas hacer nada pero te recomiendo revisar el código para que veas qué hace.
int main() {
  int opc;
  while(opc!=4){
    //cout<<"1-Prueba operaciones, 2-Recibe 3 y suma, 3-Carga archivo y multiplica, 4-Salir"<<endl; Para calificar dejalo comentado
    cin>>opc;
    switch(opc){
        case 1:
        {
            pruebaOperaciones();
            break;
        }
        case 2:
        {
            //Carga datos para un arreglo de n complejos y suma
            int cuantos;
            cin>>cuantos;
            cargaDatosSuma(cuantos);
            break;
        }
        case 3:
        {
            //Carga un archivo datos y agrega un complejo a todos los datos
            //Recibe por cuánto quieres multiplicar los datos del arreglo
            double porCuanto;
            cin>>porCuanto;
            cargaArchivoMultiEscalar(porCuanto);
            break;
        }
        case 4:
        {
            cout<< "Saliendo del programa..."<<endl;
            break;
        }
        default:
        {
            cout<<"Opcion Incorrecta"<<endl;
        }
    }
 }
  return 0;
}
