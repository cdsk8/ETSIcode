#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <cstring>
#include "ventas.h"
#include "productos.h"

using namespace std;


char menu(){
    cout << "\n\tPractica 1\n"
         << "\t\t\t\t\t\t Borja Lopez Pineda \n\n\n"
         << "\t1. Ver fichero detalle ventas\n"
         << "\t2. Ver fichero productos\n"
         << "\t3. A"<<char(164)<<"adir venta\n"
         << "\t4. Crear resumen ventas\n"
         << "\t5. Obtener estadisticas (tipo producto y periodo)\n"
         << "\t0. Salir\n";
    return getch();
}

int main(void){
    productos prods("resumen.dat", "Ventas.dat");

    char c;
    do{
        c = menu();
        system("cls");
        cout <<"\n\n";
        switch(c){
            case '0':
            break;
            case '1'://Ver fichero vebtas
                prods.mostrarventas();
            break;
            case '2'://Ver fichero productos
                prods.mostrarproductos();
            break;
            case '3'://Agregar una venta
                prods.anadirventa();
            break;
            case '4'://Crear resumen de ventas
                prods.actualizarresumen();
                cout << "Resumen actualizado.\n";
            break;
            case '5'://Mostrar estadisticas
                int tipo, annoInicio, annoFin;
                cout << "Introduzca el tipo del producto (1. Electronica | 2. Papeleria | 3. Otros): ";
                cin >> tipo;
                cout << "Introduzca el anno de inicio y fin: ";
                cin >> annoInicio >> annoFin;
                cout << "\n\n";
<<<<<<< HEAD
                prods.obtenerestadisticas2(tipo, annoInicio, annoFin);
=======
                prods.obtenerestadisticas(tipo, annoInicio, annoFin);
>>>>>>> 606276cfaefa2170c3de792ac8e17e40001ffc30
            break;
            default:
                cout << "\n\tIntroduzca una opcion valida.";
        }
        if(c != '0'){
            cout << "\n\tPulse una tecla para regresar al menu.";
            getch();
            system("cls");
        }
    }while(c != '0');

    return 0;
}
