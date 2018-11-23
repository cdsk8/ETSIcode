#include <iostream>
#include <cstdlib>
#include <cstdio>

#define M 2
#define N 4

typedef char cadena[30];

using namespace std;

struct persona{
	int dni;
	cadena nombre;
};

class matrices{
	private:
		persona tabla[M][N];
	public:
		void cargar();
		void encontrar();
};

void matrices::cargar(){
	for(int i = 0; i < M; i++){
		for(int j = 0; j < N; j++){
			cout << "Introduzca un DNI, sin letra ("<< i+1 <<","<< j+1 <<"): ";
			cin >> tabla[i][j].dni;
			cin.ignore();
			cout << "Introduzca el nombre correspondiente al DNI anterior ("<< i+1 <<","<< j+1 <<"): ";
			gets(tabla[i][j].nombre);
		}
	}
	cout << "\n";
}

void matrices::encontrar(){
	int buscado;
	int j, i = 0;
	bool encontrado = 0;

	cout << "Introduzca el DNI por el que quiere buscar: ";
	cin >> buscado;

	while(!encontrado && i < M){
		j = 0;
		while(!encontrado && j < N){
			if(tabla[i][j].dni == buscado)
				encontrado = true;
			j++;
		}
		i++;
	}

	if(encontrado)
		cout << "\nEl DNI introducido ha sido encontrado. Su nombre asociado es " << tabla[i-1][j-1].nombre << ".\n\n";
	else
		cout << "\nEl DNI introducido no esta en la tabla.\n\n";

}

int main(void){
	matrices m;

	m.cargar();
	m.encontrar();

	system("pause");
	return 0;
}
