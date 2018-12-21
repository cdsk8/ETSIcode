#include <iostream>
#include <cstdlib>
#include <string.h>
#include <conio.h>
#include <stdio.h>
#include "cdrawer.h"

#define MAX 5
//TODO: El menu de elementos bonito
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

void tprod::vender(int cantidad){ //Deprecated
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
		//cout << "Total a pagar: " << (cant*precio) << "e.\n";
		cad nombre;
		productos[pos].leenombre(nombre);
		if(strcmp(nombre,"Muskas")==0)
            dibujarVideo("sources/NYAN/NYAN_",24,24,168,25,100,100);
		cout << "Total a pagar:\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
		Sleep(100);
		//dibujarN(cant*precio,50,150,6);
		dibujar("sources/euro.bmp",400,300,RGB(255,0,255),6);
		dibujarNanim(cant*precio,50,150,3,125,5);
	}else{
		cout << "No se dispone de estock suficiente.\n";
	}
}

void printFor(int ch, int veces = 1){
    // 0 CRLF 13+10
    // 1 ╔ 201
    // 2 ╗ 187
    // 3 ╚ 200
    // 4 ╝ 188
    // 5 ╠ 204
    // 6 ╣ 185
    // 7 ╦ 203
    // 8 ╩ 202
    // 9 ═ 205
    //10 ║ 186
    //11 ╬ 206
    char chars[12] = {'\n',201,187,200,188,204,185,203,202,205,186,206};
    for(int i = 0; i < veces; i++){
        cout << chars[ch];
    }
}
void printFor(char *cadena, int veces = 1){
    for(int i = 0; i < veces; i++){
        cout << cadena;
    }
}
char menu(){
	system("cls");
	cout << "\n";

    printFor("    ");    printFor(1);    printFor(9,15); printFor(" MENU "); printFor(9,15); printFor(2);    printFor(0);
    printFor("    ");    printFor(10);   printFor(" ",36);   printFor(10);   printFor(0);
    printFor("    ");    printFor(10);   printFor(" ",5); printFor("A.- Visualizar la tabla.");  printFor(" ",7);    printFor(10);    printFor(0);
    printFor("    ");    printFor(10);   printFor(" ",5); printFor("B.- Insertar un producto.");  printFor(" ",6);    printFor(10);    printFor(0);
    printFor("    ");    printFor(10);   printFor(" ",5); printFor("C.- Vender un producto.");  printFor(" ",8);    printFor(10);    printFor(0);
    printFor("    ");    printFor(10);   printFor(" ",5); printFor("D.- Vaciar el almacen.");  printFor(" ",9);    printFor(10);    printFor(0);
    printFor("    ");    printFor(10);   printFor(" ",5); printFor("E.- Salir.");  printFor(" ",21);    printFor(10);    printFor(0);
    printFor("    ");    printFor(10);   printFor(" ",36);   printFor(10);   printFor(0);
    printFor("    ");    printFor(3);    printFor(9,36); printFor(4);    printFor(0);

	cout << "\tPon la opcion que deseas: ";
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
