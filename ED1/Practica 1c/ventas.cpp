#include "ventas.h"
#include "productos.h"

#define SALTO 2

using namespace std;

bool compararFecha(Sfecha f1, Sfecha f2);
void intercambiar(producto **p1, producto **p2);
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

void ventas::anadirventa(int num) {

    venta fichero;
    venta vaux;
    int totalp=0;
    venta *tabla=new venta[101];
    if(tabla == NULL){
        cout << "Error, sin memoria.";
        return;
    }
    int elementos=0;
    int importe_temp;   //Realmente no necesitas estas variables, puedes guardarlo directamente en vaux.importe, vaux.unidades ...
    int unidades;
    int dia;
    int mes;
    int ano;
    bool encontrado=true;

    detalle.open("Ventas.dat", ios::in | ios::out | ios::binary);

    if(!detalle.fail()) {

        cout << "Introduce las unidades vendidas del producto: " << endl;
        cin >> unidades;
        cout << "Introduce el importe: " << endl;
        cin >> importe_temp;
        cout << "Introduce el dia de la venta: " << endl;
        cin >> dia;
        cout << "Introduce el mes de la venta: " << endl;
        cin >> mes;
        cout << "Introduce el año de la venta: " << endl;
        cin >> ano;
        cout << "Datos introducidos correctamente" << endl;


        vaux.unidades=unidades;
        vaux.importe=importe_temp;
        vaux.producto=num;
        vaux.fecha.anno=ano;
        vaux.fecha.mes=mes;
        vaux.fecha.dia=dia;


        detalle.seekg(0,ios::end);

        totalp=detalle.tellg();
        totalp=totalp/sizeof(venta);

        detalle.seekg((sizeof(venta))*(totalp-1),ios::beg);
        detalle.read((char *) &fichero, sizeof(venta));

        if ((fichero.fecha.anno*365+fichero.fecha.mes*30+fichero.fecha.dia)<=(ano*365+mes*30+dia)) {

            detalle.seekp(0,ios::end);
            detalle.write((char *) &vaux, sizeof(venta));

        } else {

            int i=0;
            while ((fichero.fecha.anno*365+fichero.fecha.mes*30+fichero.fecha.dia)>(ano*365+mes*30+dia)) {

                i++;
                detalle.seekg((sizeof(venta))*(totalp-i),ios::beg);
                detalle.read((char *) &fichero, sizeof(venta));
                tabla[i-1] = fichero;

            }
            i--; //Le quito una porque la ultima lectura ya esta por detras

            detalle.seekp((sizeof(venta))*(totalp-i),ios::beg);
            detalle.write((char *) &vaux, sizeof(venta));
            i--; //Le quito otra porque ya he escrito la nueva


            for (; i>=0; i--) { //Restaurar las leidas

                detalle.seekp((sizeof(venta))*(totalp-i),ios::beg);
                detalle.write((char *) &tabla[i], sizeof(venta));

            }


        }

    }

    detalle.close();

}

void ventas::resumirfichero() {
}
void ventas::estadisticas(int tipo,int annoini,int annofin){
    resumirfichero();   //Actualizar resumen

    ifstream prods(ficheroresumen, ios::binary);    //Abrir el resumen
    prods.seekg(0, ios::end);   //ir al final

    int Ntabla = SALTO;
    producto **tabla = new producto*[Ntabla];   //Crear tabla dinamica de punteros a producto con el tamaño de la cantidad de productos totales

    if(tabla == NULL){
        cout << "ERROR al reservar memoria.\n";
    }else{
        prods.seekg(0, ios::beg);   //Volver al principio del archivo
        int i = 0;  //Variable de contador
        do{
            tabla[i] = new producto;
            prods.read((char *) tabla[i], sizeof(producto));    //Cargar los datos
            if(!prods.eof()){
                if((*tabla[i]).tipo == tipo &&
                  annoini <= (*tabla[i]).ultimaventa.anno &&   //Si cumple las condiciones avanza el contador, para que no sea remplazada
                  annofin >= (*tabla[i]).ultimaventa.anno){
                    i++;

                    if(i == Ntabla){ //Ampliar SALTO Elementos
                        producto **tablaNueva = new producto*[Ntabla+SALTO];
                        if(tablaNueva == NULL){
                            cout << "ERROR al reservar memoria.\n";
                            //Aqui podría ir al final del fichero para evitar que el bucle continue
                        }else{
                            for(int j = 0; j < Ntabla; j++)
                                tablaNueva[j] = tabla[j];
                            delete [] tabla;
                            tabla = tablaNueva;
                            Ntabla += SALTO;
                        }
                    }
                }
                else
                    delete tabla[i];
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
        }
        delete [] tabla;
    }

    prods.close();
}
void Burbuja(producto **prods, int inicio, int fin){
    int pos,ele;
    for (pos=inicio; pos<fin; pos++)
        for (ele=fin; ele>pos; ele--)
            if((*prods[ele-1]).importe > (*prods[ele]).importe){
                cout << "antes: " <<prods[ele-1]->importe<<"\n";
                intercambiar(&prods[ele-1], &prods[ele]);//Función genérica que tendrá que ser implementada
                cout << "despues: " <<prods[ele-1]->importe<<"\n";
            }

}
void intercambiar(producto **p1, producto **p2){
    producto *tmp;
    tmp = *p1;
    *p1 = *p2;
    *p2 = tmp;
}

bool compararFecha(Sfecha f1, Sfecha f2){
    return f1.anno >  f2.anno ||        //Devuelve True si f1 > f2
          (f1.anno == f2.anno && f1.mes >  f2.mes) ||
          (f1.anno == f2.anno && f1.mes == f2.mes && f1.dia > f2.dia);
}
