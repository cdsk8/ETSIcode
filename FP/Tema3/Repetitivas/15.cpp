#include <iostream>
#include <cstdlib>

using namespace std;

class Adivinar{
	private:
		int Nsecreto, Puntos;
	public:
		void Inicio();
		void Jugar();
};

void Adivinar::Inicio(){
	int semilla, tmp, divisores;

	cout << "Introduzca la semilla para este juego: ";
	cin >> semilla;

	tmp = (semilla%90)*123;
	divisores = 0;
	for(int i = 1; i < tmp/2; i++){
		if(tmp%i == 0)
			divisores += i;
	}
	if(divisores > tmp)
		Nsecreto = tmp%12459;
	else
		Nsecreto = tmp%5397;

	cout << "Introduzca el numero de puntos con los que inicia la partida: ";
	cin >> Puntos;
}

void Adivinar::Jugar(){
	int numero;

	do{
		cout << "\nAdivine el numero secreto: ";
		cin >> numero;

		if(numero == Nsecreto){
			Puntos = -5;
		}else{
			if(numero < Nsecreto){
				Puntos --;
				if(Puntos > 0)
					cout << "Te has quedado corto, pierdes un punto. Te quedan " << Puntos << " punto" << (Puntos>1?"s":"") << ".\n";
			}else{
				Puntos -= 2;
				if(Puntos > 0)
					cout << "Te has pasado pierdes dos puntos. Te quedan " << Puntos << "punto" << (Puntos>1?"s":"") << ".\n";
			}
		}
	}while(Puntos > 0);

	if(Puntos == -5){
		cout << "\nEnhorabuena, has adivinado el numero secreto.\n";
	}else{
		cout << "\nHas perdido, no te quedan puntos.\n";
	}
}

int main(){
	Adivinar a;
	string continuar;

	do{
		system("cls");

		a.Inicio();
		a.Jugar();

		cout << "\n\n¿Desea jugar otra vez? (si, no): ";
		cin >> continuar;
	}while(continuar == "si");

	system("pause");
	return 0;
}
