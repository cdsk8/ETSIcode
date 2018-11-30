#include <iostream>
#include <cstdlib>
#include <conio.h>
#include "cdrawer.h"

typedef char cadena[30];

using namespace std;

class PalabraOculta{
	private:
		cadena palabraSecreta;
		int Puntos;
	public:
		void Iniciar();
		void Jugar();
		void MostrarSecreta();
};

void PalabraOculta::Iniciar(){
	char ch;
	int i = 0;
	Puntos = 9;

	cout << "Introduzca la palabra secreta: ";

	do{
		ch = getch();
		switch(ch){
			case '\b':
				if(i > 0){
					cout << "\b \b";
					i--;
				}
				break;
			case '\r':
				cout << '\n';
				palabraSecreta[i] = '\0';
				break;
			default:
				cout << "*";
				palabraSecreta[i] = toupper(ch);
				i++;
		}
	}while(ch != '\r');
}

void PalabraOculta::Jugar(){
	char ch;
	bool acertado;
	int estado = 0; //	0 = nada | 1 = ha fallado | 2 =  ha acertado | 3 = ha repetido letra
	int adivinado, cantidad, longitud;
	adivinado = cantidad = longitud = 0;


	do{
		ch = palabraSecreta[longitud];
		longitud++;
	}while(ch != '\0');
	longitud--;

	char palabra[longitud];
	for(int i = 0; i < longitud; i++){
		palabra[i] = '-';
	}

	do{
		system("cls");

		cout << "\t\t" << "--> ";
		for(int i = 0; i < longitud; i++)
			cout << palabra[i];

		switch(estado){
			case 0:
				cout << " <--\t\tPuntos: " << Puntos << "\n\n\nAdivine una letra de la palabra: ";
				break;
			case 1:
				cout << " <--\t\tPuntos: " << Puntos << "\n\nLa letra introducida no se encuentra en la palabra.\nAdivine una letra de la palabra: ";
				break;
			case 2:
				cout << " <--\t\tPuntos: " << Puntos << "\n\nHas acertado " << cantidad << " letra" << (cantidad==1?"":"s") << ".\nAdivine una letra de la palabra: ";
				break;
			case 3:
				cout << " <--\t\tPuntos: " << Puntos << "\n\nLa letra introducida ya fue adivinada.\nAdivine una letra de la palabra: ";
				break;
		}


		ch = toupper(getch());

		acertado = false;
		estado = cantidad = 0;
		for(int i = 0; i < longitud; i++){
			if (palabraSecreta[i] == ch){
				if(palabraSecreta[i] == palabra[i]){
					estado = 3;
				}else{
					adivinado++;
					cantidad++;
					acertado = true;
					palabra[i] = palabraSecreta[i];
				}
			}
		}
		if(acertado){
			estado = 2;
		}else{
			Puntos--;
			if(estado != 3)
				estado = 1;
		}
	}while(Puntos > 0 and adivinado != longitud);
}

void PalabraOculta::MostrarSecreta(){
	system("cls");

	if(Puntos > 0){
        cout << "\t\t" << "--> " << palabraSecreta << " <--\n\nEnhorabuena, has adivinado la palabra secreta.\n\tTu puntuacion es:\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
        dibujarN(Puntos,400,10);
	}
	else{
		cout << "\t\t" << "--> " << palabraSecreta << " <--\n\nLo siento, esa era la palabra secreta.\n\n";
	}
}

int main(void){
	PalabraOculta po;

	po.Iniciar();
	po.Jugar();
	po.MostrarSecreta();

	system("pause");
	return 0;
}
