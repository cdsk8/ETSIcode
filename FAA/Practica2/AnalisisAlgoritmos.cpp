#include "TestOrdenacion.h"
#include "Constantes.h"
#include <iostream>
using namespace std;


int menuAlgoritmos() {
	char c;

	system("cls");
	do {
		cout << "\n\n"
			<< "-----        Seleccione un algoritmo de ordenacion           -----\n\n"
			<< "                 1.- Algoritmo burbuja\n"
			<< "                 2.- Algoritmo interseccion\n"
			<< "                 3.- Algoritmo seleccion\n"
			<< "  -------------------\n"
			<< "   Elija una opcion: ";

		c = cin.get();
		system("cls");
	} while (c != '1' && c != '2' && c != '3');

	switch (c) {
	case '1':
		c = 1;
		break;
	case '2':
		c = 2;
		break;
	case '3':
		c = 3;
		break;
	}

	return c;
}
int menu() {
	/********************  OPERACIONES  *************************
	**** 0. Salir                   1. Probar los metodos    ****
	**** 2. Medir burbuja			3. Medir insercion       ****
	**** 4. Medir seleccion 		                         ****
	****       XY. X metodo 1, Y metodo 2 : (1, 2, 3)        ****
	*************************************************************/
	char c;
	system("cls");

	do {
		cout << " FAA. Practica 2. Curso 18/19 \n"
			<< "                                                           Borja Lopez Pineda \n"
			<< "-----                           MENU PRINCIPAL                          -----\n"
			<< "-----         ANALISIS EXPERIMENTAL DE ALGORITMOS DE ORDENACION         -----\n\n"
			<< "                         1.- Probar los metodos de ordenacion\n"
			<< "                         2.- Obtener el caso medio de un metodo de ordenacion\n"
			<< "                         3.- Comparar metodos\n"
			<< "                         0.- Salir\n"
			<< "                  ---------------------------------\n"
			<< "                       Elija una opcion: ";

		c = cin.get();
		system("cls");
	} while (c != '1' && c != '2' && c != '3' && c != '0');


	switch (c) {
	case '1':
		c = 1;
		break;
	case '2':
		c = menuAlgoritmos() + 1;
		break;
	case '3':
		c = (menuAlgoritmos() * 10) + menuAlgoritmos();
		break;
	case '0':
		c = 0;
		break;
	}

	cout << "\n\n";
	return c;
}

int getConstante(int numero) {
	switch (numero) {
	case 1: return BURBUJA;
	case 2: return INSERCION;
	case 3: return SELECCION;
	}
}

/** Programa principal **/
int main()
{
	TestOrdenacion test;

	int opt;

	do {
		opt = menu();
		if (opt > 10) {
			test.comparar(getConstante(opt / 10), getConstante(opt % 10));
		} else {
			switch(opt) {
				case 1:	//Probar los algoritmos
					test.comprobarMetodosOrdenacion();
				break;
				case 2:
				case 3:
				case 4:	//Medir burbuja
					test.casoMedio(getConstante(opt-1));
				break;
			}
		}
	} while (opt != 0);
	return 0;
};