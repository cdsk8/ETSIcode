#ifndef PRODUCTOS_H_INCLUDED
#define PRODUCTOS_H_INCLUDED
#include <fstream>
#include "ventas.h"

using namespace std;

struct producto{
    Sfecha ultimaventa;
    int unidades;   //Unidades vendidas
    int producto;
    float importe;  //Total de las ventas de ese producto
    int tipo;
    char nombre[20];
};

class productos{
    int numproductos;
    int maxcatalogo;
    fstream resumen;
    cadena fichero;
    ventas ven;
public:
    productos(cadena Fichero, cadena FicheroVentas);
    ~productos();
    int getmaxcatalogo();
    void setmaxcatalogo(int num);
    int getnumproductos();
    void setnumproductos(int num);
    void mostrarproductos();
    void mostrarventas();
    bool anadirventa();
    void actualizarresumen();
    void obtenerestadisticas(int tipo,int annoini,int annofin);
    void obtenerestadisticas2(int tipo,int annoini,int annofin);
};

#endif // PRODUCTOS_H_INCLUDED
