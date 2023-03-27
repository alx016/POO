#include <iostream>
using namespace std;
/* Este programa no requiere que completes nada, no lo modifiques, pero si revisa
   qué está haciendo para que cuando pruebes tu programa verifiques que si está
   haciendo lo que debe hacer y que tu clase está correcta o qué método no se está
   comportando como debiera*/

#include "Tiempo.h"

int main() {
    int t1h, t1m, t2h, t2m, t4h, t4m, t5h, t5m;
    char opcion;
    Tiempo t3, t6, t7(15, 59), t8(0,0), t9;

    // teclear los valores para tiempo 1, tiempo2, tiempo4 y tiempo5
    cin >> t1h >> t1m >> t2h >> t2m >> t4h >> t4m >> t5h >> t5m;
    Tiempo t1(t1h, t1m), t2(t2h, t2m);
    Tiempo t4(t4h, t4m), t5(t5h, t5m);

    cin >> opcion;

    switch (opcion) {
        case 'a':
            // + SUMA tiempo con tiempo miembro
            t3 = t1 + t2;
            cout << t1 << endl;
            cout << t2 << endl;
            cout << t3 << endl;

            t6 = t4 + t5;
            cout << t4 << endl;
            cout << t5 << endl;
            cout << t6 << endl;


            break;

        case 'b':
            // + SUMA tiempo con minutos miembro
            t3 = t2 + 10;
            cout << t2 << endl;
            cout << t3 << endl;

            t3 = t2 + 190;
            cout << t2 << endl;
            cout << t3 << endl;
            break;

        case 'c':
            // + SUMA minutos con tiempo friend
            t3 = 45 + t2;
            cout << t2 << endl;
            cout << t3 << endl;


            t3 = 90 + t2;
            cout << t2 << endl;
            cout << t3 << endl;
            break;

        case 'd':
            // ++ Incrementa 1 minuto   miembro
            t3 = ++t2;
            cout << t2 << endl;;
            cout << t3 << endl;

            t3 = ++t7;
            cout << t7 << endl;
            cout << t3 << endl;
            break;

        case 'e':
            // -- Decrementa 1 minuto   friend
            t3 = --t2;
            cout << t2 << endl;
            cout << t3 << endl;

            t3 = --t8;
            cout << t3 << endl;
            cout << t8 << endl;
            break;

        case 'f':
            // += SUMA tiempo con tiempo  friend
            t2 += t4;
            cout << t2 << endl;
            cout << t4 << endl;

            t7 += t5;
            cout << t5 << endl;
            cout << t7 << endl;
            break;

        case 'g':
            // > Regresa true si el primer tiempo es mayor que el segundo  miembro
            if (t1 > t2)
                cout << "mayor" << endl;
            else
                cout << "no mayor" << endl;

            if (t4 > t2)
                cout << "mayor" << endl;
            else
                cout << "no mayor" << endl;
            break;
    }
    return 0;
}
