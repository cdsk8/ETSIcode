#ifndef VENTAS_H_INCLUDED
#define VENTAS_H_INCLUDED
#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;
typedef char cadena[101];

struct Sfecha{
    int dia;
    int mes;
    int anno;
};
struct venta{
    Sfecha fecha;
    int unidades;
    int producto;
    float importe;
};


class ventas{
    fstream detalle;
    cadena fichero;         //Ventas.dat
    cadena ficheroresumen;  //resumen.dat
public:
    void anadirventa(int num);  //CHECK
    void mostrarventas();  //CHECK
    void resumirfichero();
    void estadisticas(int tipo,int annoini,int annofin);
    bool asignar(cadena Fichero,cadena FicheroResumen);  //CHECK
};

#endif // VENTAS_H_INCLUDED
