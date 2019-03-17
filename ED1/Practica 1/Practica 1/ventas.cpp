#include "ventas.h"
#include "productos.h"

using namespace std;

bool ventas::asignar(cadena Fichero,cadena FicheroResumen){
    strcpy(fichero, Fichero);
    strcpy(ficheroresumen, FicheroResumen);

    bool correcto = true;

    detalle.open(fichero, ios::in); //Intento abrirlo si existe
    if(detalle.fail()){ //Si no existe
        detalle.close();
        detalle.open(fichero, ios::out); //Lo abro en lectura para crearlo
        if(detalle.fail()){ //Si no se puede crear
            detalle.close();
            correcto = false; //La operación ha fallado
        }
    }
    detalle.close();
    detalle.clear();
    if(correcto){
        detalle.open(ficheroresumen, ios::in);
        if(detalle.fail()){
            detalle.close();
            detalle.open(ficheroresumen, ios::out);
            if(detalle.fail()){
                detalle.close();
                correcto = false;
            }
        }
    }
    detalle.close();
    detalle.clear();

    return correcto;
}

void ventas::mostrarventas(){
    venta *v = new venta;   //Reservo memoria para una venta y un producto temporal
    producto *p = new producto;
    int ventPos = 0;
    bool encontrado, acabado = false;

    cout << "-------------->LISTA DE VENTAS<--------------\n\n";
    while(!acabado){
        detalle.open(fichero, ios::in | ios::binary); //Abro el fichero en binario
        detalle.seekp(ventPos , ios::beg);  //Avanzo a la posicion
        detalle.read((char *) v, sizeof(venta)); //Leo la venta
        acabado = detalle.eof();
        ventPos += detalle.gcount();    //Mover el contador

        //Buscar un producto con la misma ID
        detalle.close();
        detalle.open(ficheroresumen, ios::in | ios::binary);    //Abro los productos
        encontrado = false;
        while(!encontrado && !detalle.eof()){
            detalle.read((char *) p, sizeof(producto)); //Leo el producto
            //cout << "Busqueda :" << p->producto << " con " << v->producto <<"\n";
            if(p->producto == v->producto)
                encontrado = true;
        }
        detalle.close();

        if(encontrado){
            cout << "Fecha de venta: " << v->fecha.dia <<"/"<< v->fecha.mes <<"/"<< v->fecha.anno <<"\n"
                 << "Producto: " << p->nombre <<"\n"   //El nombre del producto
                 << "Unidades: " << v->unidades <<"\n"
                 << "Importe: " << v->importe <<"\n";
        }else{
            cout << "El producto " << v->producto << " no fue encontrado.\n";
        }
        cout << "______________________________________________\n\n";


    }

    delete p;
    delete v;        //Libero memoria
    detalle.close(); //Cierro el archivo
}

void ventas::anadirventa(int num){
    Sfecha fecha;
    int unidades;
    float importe;

    cout << "Introduzca el dia, mes y anno de la venta: \n";
    cin >> fecha.dia >> fecha.mes >> fecha.anno;
    cout << "Introduzca el numero de unidades vendidas: \n";
    cin >> unidades;
}

void ventas::resumirfichero(){
}

void ventas::estadisticas(int tipo,int annoini,int annofin){
}

