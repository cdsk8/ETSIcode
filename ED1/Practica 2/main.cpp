#include <iostream>
#include "cola.h"

using namespace std;

int main(){
    Cola c;

    int act;
    while(true){
        c.dibujar();
        cout << "\n1. Agregar\n2. Leer\n3. Eliminar\nIntroduzca: ";
        cin >> act;
        switch(act){
        case 1:
            Elemento e;
            e.prioridad = 2;
            cout << "Elemento: ";
            cin >> e.comando;
            c.encolar(e);
            break;
        case 2:
            cout << "ATENDER: "<<c.primero().comando<<"\n";
            break;
        case 3:
            c.desencolar();
            break;
        default:
            return 1;
        }
        cout << "\n";
    }



    return 0;
}
