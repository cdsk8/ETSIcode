#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <conio.h>

#define MAX 5

typedef char cad[20];

using namespace std;

class tprod{
	private:
		cad nombre;
		float precio;
		int stock;
	public:
		tprod();
		void cambiarnombre(cad nom);
		void cambiarprecio(float prec);
		void cambiarstock(int stoc);
		void leenombre(cad nom);
		float leeprecio();
		void leestock(int &st);
		void vender(int cantidad);
};

tprod::tprod(){
	strcpy(nombre, "NO HAY PRODUCTO");
	precio = 0;
	stock = 0;
}

void tprod::cambiarnombre(cad nom){
	strcpy(nombre, nom);
}
void tprod::cambiarprecio(float prec){
	precio = prec;
}
void tprod::cambiarstock(int stoc){
	stock = stoc;
}

void tprod::leenombre(cad nom){
	strcpy(nom, nombre);
}
float tprod::leeprecio(){
	return precio;
}
void tprod::leestock(int &st){
	st = stock;
}

void tprod::vender(int cantidad){
	if(stock >= cantidad){
		stock -= cantidad;
		cout << "Total a pagar: " << (cantidad*precio) << "e.\n";
	}else{
		cout << "No se dispone de stock suficiente.\n";
	}
}


class almacen{
	private:
		tprod productos[MAX];
		int nprod;
	public:
		almacen();
		void vaciar();
		int existe(cad nom);
		void verprod(int pos, tprod &prod);
		int insertar(tprod P);
		void vertabla();
		void vender(int pos, int cant);
};

almacen::almacen(){
	vaciar();
}

void almacen::vaciar(){
	nprod = 0;
}

int almacen::existe(cad nom){
	int i, pos;
	cad original;
	pos = -1;
	i = 0;

	while(i < nprod and pos == -1){
		productos[i].leenombre(original);
		if(strcmp(original,nom) == 0)
			pos = i;
		i++;
	}

	return pos;
}

void almacen::verprod(int pos, tprod &prod){
	prod = productos[pos];
}

int almacen::insertar(tprod P){
    /*--------------------  Códigos de resultado  ---------------------
      ------ 0. Correcto ---- 1. Ya existe ---- 2. Almacen lleno ------
      -----------------------------------------------------------------*/
    int resultado;

	if(nprod == MAX)
		resultado = 2;
    else{
        cad nombre;
        P.leenombre(nombre);
        if(existe(nombre) != -1)
            resultado = 1;
        else{
            productos[nprod++] = P;
            resultado = 0;
        }
    }

	return resultado;
}

void almacen::vertabla(){
	if(nprod == 0){
		cout << "El almacen esta vacio.\n";
	}else{
		cad nombre;
		int stock;
		for(int i = 0; i < nprod; i++){
			productos[i].leenombre(nombre);
			productos[i].leestock(stock);
			cout << "Nombre: " << nombre << ".\n";
			cout << "Precio: " << productos[i].leeprecio() << "e.\n";
			cout << "Stock:  " << stock << ".\n\n";
		}
	}
}

void almacen::vender(int pos, int cant){
	int stock;
	float precio = productos[pos].leeprecio();
	productos[pos].leestock(stock);

	if(stock >= cant){
		productos[pos].cambiarstock(stock-cant);
		cout << "Total a pagar: " << (cant*precio) << "e.\n";
	}else{
		cout << "No se dispone de estock suficiente.\n";
	}
}


char menu(){
	system("cls");
	cout << "*************** MENU *****************\n"
			"******A.- Visualizar la tabla.\t******\n"
			"******B.- Insertar un producto.\t******\n"
			"******C.- Vender un producto.\t******\n"
			"******D.- Vaciar el almacen.\t******\n"
			"******E.- Salir.\t\t******\n"
			"**************************************\n"
			"Pon la opcion que deseas: ";
	char ch;
	cin >> ch;
	return ch;
}

int main(void){
	bool continuar = true;
	tprod prod_tmp;
	cad prodN_tmp;
	int prodS_tmp;
	float pordP_tmp;
	int i, pos;
	char ch;

	almacen a;

	do{
        system("cls");
		switch(menu()){
			case 'A':
			case 'a':
			    system("cls");
				a.vertabla();
				break;
			case 'B':
			case 'b':
			    system("cls");
				cout << "Introduzca el nombre: ";
				cin.ignore();
				gets(prodN_tmp);
				prod_tmp.cambiarnombre(prodN_tmp);

				cout << "Introduzca el precio: ";
				cin >> pordP_tmp;
				prod_tmp.cambiarprecio(pordP_tmp);

				cout << "Introduzca el stock: ";
				cin >> prodS_tmp;
				prod_tmp.cambiarstock(prodS_tmp);

				switch(a.insertar(prod_tmp)){
					case 2:
						cout << "\nEl almacen esta lleno.\n";
						break;
					case 1:
						cout << "\nYa existe un producto con ese nombre.\n";
						break;
					case 0:
						cout << "\nProducto Creado correctamente.\n";
						break;
				}
				break;
			case 'C':
			case 'c':
			    system("cls");
				cout << "\nIntroduzca el nombre del producto a vender: ";
				cin.ignore();
				gets(prodN_tmp);
				pos = a.existe(prodN_tmp);
				if(pos == -1){
					cout << "\nNo existe ningun producto con ese nombre.\n";
				}else{
					cout << "\nIntroduzca la cantidad de productos a vender: ";
					cin >> prodS_tmp;

					a.vender(pos, prodS_tmp);
				}
				break;
			case 'D':
			case 'd':
			    system("cls");
				a.vaciar();
				cout << "Almacen vaciado correctamente.\n";
				break;
			case 'E':
			case 'e':
			    system("cls");
				continuar = false;
				break;
		}

		if(continuar){
			cout << "\nPulse una tecla para regresar al menu.";
			cin.ignore();
			cin.ignore();
		}
	}while(continuar);

	return 0;
}
