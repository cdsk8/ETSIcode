#include <iostream>
#include <cstdlib>
#include <string.h>

#define M 3
#define N 4
typedef char cadena[30];

using namespace std;

class cuatro{
	private:
		cadena tabla[M][N];
	public:
		void cargar();
		void encontrar();
};

void cuatro::cargar(){
	for(int i = 0; i < M; i++){
		for(int j = 0; j < N; j++){
			cout << "Introduzca una palabra: ";
			cin >> tabla[i][j];
		}
	}
	cout << "\n";
}

void cuatro::encontrar(){
	cadena buscado;
	int j, i = 0;
	bool encontrado = 0;

	cout << "Introduzca la palabra que desea buscar: ";
	cin >> buscado;

	while(!encontrado and i < M){
		j = 0;
		while(!encontrado and j < N){
			if(strcmp(tabla[i][j], buscado) == 0)
				encontrado = true;
			j++;
		}
		i++;
	}

	if(encontrado)
		cout << "\nLa palabra que buscaba se encuentra en tabla[" << (i-1) << "][" << (j-1) << "]\nEn indice 1, esta en la fila " << i << " y columna " << j << "\n\n";
	else
		cout << "\nLa palabra que buscaba se encuentra en la tabla.\n\n";

}

int main(void){
	cuatro c;

	c.cargar();
	c.encontrar();

	system("pause");
	return 0;
}
