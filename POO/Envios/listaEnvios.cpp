#include <iostream>
#include <fstream>
#include <string>
using namespace std;
/* RECUERDA antes de completar este archivo hay que hacer las clases Envio, Sobre y Paquete
   como te lo pide la actividad de CANVAS*/

#include "Paquete.h"
#include "Sobre.h"
// SIGUE LAS INSTRUCCIONES para completar el archivo, son 13 puntos a cubrir
int main() {

    //1. Declara un arreglo de apuntadores a objetos Envío de 20 localidades, llámalo listaEnvio
    Envio* listaEnvio[20];

    int cantEnvios;

    string nombreR, estadoR, ciudadR, cpR;
    string nombreD, estadoD, ciudadD, cpD;

    double costoEstandar, peso, costoKg;
    double largo, ancho, cargoAdicional;
    char tipoEnvio;
    ifstream archivo;

    //Abre el archivo, observa el ejemplo de archivo para que veas el formato
    archivo.open("datosEnvio.txt");

    cantEnvios = 0; //Esta variable lleva el control del número de elementos agregados
    while (archivo >> tipoEnvio) { //Mientras pueda encontrar un dato al inicio de cada renglón y lo pongo en tipoEnvio
      archivo>>nombreR>>estadoR>>ciudadR>>cpR;
      archivo>>nombreD>>estadoD>>ciudadD>>cpD>>costoEstandar;
        if (tipoEnvio == 'p' ) { // Si el tipo de envio es p  es un "paquete"

            //2. Lee el resto de los datos, usa las variables que ya están definidas.
            archivo>>peso>>costoKg;
            // 3. Crea dos objetos Persona una para el remitente y otra para el destinatario
            Persona remitente(nombreR, estadoR, ciudadR, cpR);
            Persona destinatario(nombreD, estadoD, ciudadD, cpD);

            // 4. Agrega un nuevo paquete al arreglo
            listaEnvio[cantEnvios]=new Paquete(remitente,destinatario, costoEstandar,peso,costoKg);
            cantEnvios++;
        }
        else { //Si no fue p, entonces es una s lo cual significa que es un "Sobre"

            // 5. Lee el resto de los datos del renglón, guárdalos en las variables que ya están declaradas
            archivo>>largo>>ancho>>cargoAdicional;


            // 6. Crea dos objetos Persona uno para el remitente y otro para el destinatario
            Persona remitente(nombreR, estadoR, ciudadR, cpR);
            Persona destinatario(nombreD, estadoD, ciudadD, cpD);

            // 7. Agrega un nuevo sobre al arreglo
              listaEnvio[cantEnvios]=new Sobre(remitente,destinatario, costoEstandar,largo,ancho, cargoAdicional);
              cantEnvios++;
        }
    }
    archivo.close();

    Persona rem, dest;
    double costoEnvio, totalEnvios;

    totalEnvios = 0; // Para ir acumulando el costo de los envíos
    for (int c = 0; c < cantEnvios; c++) {
        // 8. Obten el remitente del Envio
        Persona r=listaEnvio[c]->getDatosRemitente();
        cout << "---------- " << "Inician datos de Envio: " << c+1 << " ----------" << endl;
        cout << "REMITENTE: " << endl;
        // 9. Manda a imprimir los datos del remitente, usa el método adecuado que ya tienes definido en esa clase
        r.imprime();
        cout << endl;
        // 10. Obten el destinatario
        Persona dest=listaEnvio[c]->getDatosDestinatario(); //apuntadores
        cout << "\nDESTINATARIO: " << endl;
        // 11. Manda a imprimir los datos del destinatario, usa el método adecuado que ya tienes definido en esa clase;
        dest.imprime();
        // 12. Determina el costo del Envío guárdalo en la variable costoEnvio
        costoEnvio=listaEnvio[c]->calculaCosto();
        cout << "\n\tCOSTO: $" << costoEnvio << endl;
        // 13. Acumula el costo del Envio en la variable totalEnvios
        totalEnvios=totalEnvios+costoEnvio;
        cout << "---------- " << "Termina Datos de Envio: " << c+1 << " ----------\n" << endl;
    }
    cout << "\tTOTAL DE LOS ENVIOS: $" << totalEnvios << endl;

    return 0;
}

/*Este es un ejemplo de cómo se vería el despliegue de uno de los Envios
---------- Inician datos de Envio: 1 ----------
REMITENTE:
Nombre: Elsa_Torres
Dirección: NL Monterrey 64840

DESTINATARIO:
Nombre: Salvador_Leal
Dirección: Jalisco Guadalajara 44190

    COSTO: $270
---------- Termina Datos de Envio: 1 ----------*/
