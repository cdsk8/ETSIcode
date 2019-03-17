#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <cstring>
#include "ventas.h"
#include "productos.h"
//#include "vector.h"

using namespace std;





char menu(){
    cout << "\n\tPractica 1\n\n"
         << "\t\t1. Ver fichero detalle ventas\n"
         << "\t\t2. Ver fichero productos\n"
         << "\t\t3. A"<<char(164)<<"adir venta\n"
         << "\t\t4. Crear resumen ventas\n"
         << "\t\t5. Obtener estadisticas (tipo producto y periodo)\n"
         << "\t\t0. Salir\n";
    return getch();
}
int main(void){
    //productos prods("resumen.dat", "Ventas.dat");

    fstream archivo("Ventas.dat", ios::in | ios::binary);
    venta *vv = new venta;
    while(!archivo.eof()){
        archivo.read((char *) vv, sizeof(venta));
        cout << vv->producto << "\n";
    }

    ventas v;
    cout << "TAMA VENTA: " << sizeof(venta) << "\n";
    cout << "ASIGNAR: " << (v.asignar("Ventas.dat","resumen.dat")?"BIEN":"MAL") <<"\n";
    v.mostrarventas();



    /*
    fstream archivo("resumen.dat", ios::in | ios::binary);
    producto *p = new producto;
    while(!archivo.eof()){
        archivo.read((char *) p, sizeof(producto));
        cout << p->producto << "\n";
    }
    */


    getche();

    char c;
    do{
        c = menu();
        system("cls");
        switch(c){
            case '0':
            break;
            case '1'://Ver fichero detalle
                //prods.mostrarproductos();
            break;
            case '2'://Ver fichero productos
                //prods.mostrarventas();
            break;
            case '3'://Agregar una venta
                //prods.anadirventa();
            break;
            case '4'://Crear resumen de ventas
                //prods.actualizarresumen();
            break;
            case '5'://Mostrar estadisticas
                //prods.obtenerestadisticas();
            break;
            default:
                cout << "\n\tIntroduzca una opcion valida.\n\tPulse una tecla para regresar al menu.";
                getch();
        }
        system("cls");
    }while(c != '0');

    system("pause");
    return 0;
}
