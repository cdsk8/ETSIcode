#include "ventas.h"
#include "productos.h"

using namespace std;

bool compararFecha(Sfecha f1, Sfecha f2);
void intercambiar(producto *p1, producto *p2);
void Burbuja(producto **prods, int inicio, int fin);


bool ventas::asignar(cadena Fichero,cadena FicheroResumen){
    strcpy(fichero, Fichero);
    strcpy(ficheroresumen, FicheroResumen);

    bool correcto = true;

    detalle.open(fichero, ios::in); //Intento abrirlo si existe
    if(detalle.fail()){ //Si no existe
        detalle.clear();
        detalle.close();
        detalle.open(fichero, ios::out); //Lo abro en lectura para crearlo
        if(detalle.fail()){ //Si no se puede crear
            detalle.clear();
            correcto = false; //La operación ha fallado
        }
    }
    detalle.close();

    return correcto;
}

void ventas::mostrarventas(){
    venta v;
    producto p;
    bool encontrado;
    detalle.open(fichero, ios::in | ios::binary);
    ifstream prods(ficheroresumen, ios::binary);

    cout << "-------------->LISTA DE VENTAS<--------------\n\n";
    while(detalle.read((char *) &v, sizeof(venta)) && !detalle.eof()){  //Leer y comprobar que no se haya acabado el archivo
        prods.seekg(sizeof(producto)*(v.producto-1), ios::beg);
        prods.read((char *) &p, sizeof(producto));

        if(prods && p.tipo != -1){
            cout << "Fecha de venta: " << v.fecha.dia <<"/"<< v.fecha.mes <<"/"<< v.fecha.anno <<"\n"
                 << "Producto: " << p.nombre <<"\n"   //El nombre del producto
                 << "Unidades: " << v.unidades <<"\n"
                 << "Importe: " << v.importe <<"\n";
        }else{
            cout << "El producto vendido " << v.producto << " no fue encontrado en la lista de productos.\n";
        }
        cout << "______________________________________________\n\n";
        prods.clear();
    }

    prods.close();
    detalle.close(); //Cierro los archivos
}

void ventas::anadirventa(int num){
    venta v, tmp;

    detalle.open(fichero, ios::binary | ios::in | ios::out);   //Abro el archivo
    if(detalle){   //Lo leo dentro para que el usuario no introduzca los datos en vano
        v.producto = num;
        cout << "Introduzca el dia, mes y anno de la venta: ";
        cin >> v.fecha.dia >> v.fecha.mes >> v.fecha.anno;
        cout << "Introduzca el numero de unidades vendidas: ";
        cin >> v.unidades;
        cout << "Introduzca el importe: ";
        cin >> v.importe;


        bool encaja = false;
        detalle.seekg(0, ios::end);
        do{
            if(detalle.tellg() <= 0){
                encaja = true;  //Encaja porque no hay ventas anteriores
            }else{
                detalle.seekg((int) -sizeof(venta), ios::cur);  //Retrodece una posicion
                detalle.read((char *) &tmp, sizeof(venta));     //Lee la venta
                if(compararFecha(tmp.fecha, v.fecha)){    //Comparacion de fechas
                    detalle.write((char *) &tmp, sizeof(venta));    //Escrebe la venta una posicion más abajo
                    detalle.seekg((int) -sizeof(venta)*2, ios::cur);    //Sube las dos posiciones que se ha movido
                }else{
                    encaja = true;  //Encaja porque la venta leida es anterior
                }
            }
            if(encaja)
                detalle.write((char *) &v, sizeof(venta));
        }while(!encaja);
    }else{
        cout << "Error al abrir el fichero de ventas\n";
    }
    detalle.close();
}

void ventas::resumirfichero(){
    producto p;
    venta v;

    fstream prods(ficheroresumen, ios::binary | ios::in | ios::out);
    detalle.open(fichero, ios::binary | ios::in);

    if(detalle && prods){
        while(prods.read((char *) &p, sizeof(producto)) && !prods.eof()){  //Leer y comprobar que no se haya acabado el archivo de productos
            detalle.seekg(0, ios::beg);
            while(detalle.read((char *) &v, sizeof(venta)) && !detalle.eof()){  //Buscar en ventas
                if(v.producto == p.producto && compararFecha(v.fecha, p.ultimaventa)){   //La venta del producto actual
                    p.ultimaventa = v.fecha;
                    p.unidades += v.unidades;   //Actualizar datos
                    p.importe += v.importe;
                }

            }
            if(detalle.fail()) detalle.clear(); //Parece que esto no es necesario, pero hace mucho


            prods.seekp((int) -sizeof(producto), ios::cur); //Volver a la posicion de inicio del producto actual
            prods.write((char *) &p, sizeof(producto));     //Reescribir el productos actual
        }
    }

    prods.close();
    detalle.close();    //Cerrar los archivos
}

void ventas::estadisticas(int tipo,int annoini,int annofin){
    resumirfichero();   //Actualizar resumen

    ifstream prods(ficheroresumen, ios::binary);    //Abrir el resumen
    prods.seekg(0, ios::end);   //ir al final
    producto **tabla = new producto*[prods.tellg()/sizeof(producto)];   //Crear tabla dinamica de punteros a producto con el tamaño de la cantidad de productos totales

    if(tabla == NULL){
        cout << "ERROR al reservar memoria.\n";
    }else{
        prods.seekg(0, ios::beg);   //Volver al principio del archivo
        int i = 0;  //Variable de contador
        do{
            tabla[i] = new producto; //Reservar para el nuevo producto
            if(tabla[i] == NULL){
                cout << "ERROR al reservar memoria.\n";
            }else{
                prods.read((char *) tabla[i], sizeof(producto));    //Cargar los datos
                if(!prods.eof()){
                    if((*tabla[i]).tipo == tipo &&
                       annoini <= (*tabla[i]).ultimaventa.anno &&   //Si cumple las condiciones avanza el contador, para que no sea remplazada
                       annofin >= (*tabla[i]).ultimaventa.anno)
                        i++;
                }
            }
        }while(!prods.eof());
        i--;    //La ultima lectura no fue remplazada o está vacia

        Burbuja(tabla, 0, i);   //Ordena de menor a mayor, porque la voy a leer al reves

        cout << "-------------->Mejores productos<--------------\n\n";
        for(;i >= 0; i--){
            cout << "Fecha de venta: " << (*tabla[i]).ultimaventa.dia <<"/"<< (*tabla[i]).ultimaventa.mes <<"/"<< (*tabla[i]).ultimaventa.anno <<"\n"
                 << "Producto: " << (*tabla[i]).nombre <<"\n"   //El nombre del producto
                 << "Unidades: " << (*tabla[i]).unidades <<"\n"
                 << "Importe: " << (*tabla[i]).importe <<"\n";
            cout << "______________________________________________\n\n";
            delete tabla[i];    //Ir eliminando conforme se lee
        }
        delete [] tabla;
    }

    prods.close();
}

bool compararFecha(Sfecha f1, Sfecha f2){
    return f1.anno >  f2.anno ||        //Devuelve True si f1 > f2
          (f1.anno == f2.anno && f1.mes >  f2.mes) ||
          (f1.anno == f2.anno && f1.mes == f2.mes && f1.dia > f2.dia);
}

void intercambiar(producto *p1, producto *p2){
    producto tmp;

    tmp = *p1;
    *p1 = *p2;
    *p2 = tmp;
}
void Burbuja(producto **prods, int inicio, int fin){
    int pos,ele;
    for (pos=inicio; pos<fin; pos++)
        for (ele=fin; ele>pos; ele--)
            if((*prods[ele-1]).importe > (*prods[ele]).importe)
                intercambiar(prods[ele-1], prods[ele]);//Funciín genérica que tendrá que ser implementada
}

