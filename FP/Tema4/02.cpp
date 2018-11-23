#include <iostream>
#include <cstdlib>

#define M 10

using namespace std;

class matrices{
	private:
		int tabla[M];
	public:
		void cargar();
		bool encontrar();
};

void matrices::cargar(){
	for(int i = 0; i < M; i++){
		//cout << "Introduzca un numero entero (" << i+1 << "): ";
		//cin >> tabla[i];
		tabla[i] = i;   //Creo que este ejercicio ha cambiado.
	}
	//cout << "\n";
}

bool matrices::encontrar(){
	int buscado, i = 0;
	bool encontrado = false;

	cout << "Introduzca el numero que desea buscar: ";
	cin >> buscado;

	while(!encontrado && i < M){
		if(tabla[i] == buscado)
			encontrado = true;
		i++;
	}

	return encontrado;
}

int main(void){
	matrices m;

	m.cargar();
	cout << "\nEl numero que buscaba " << (m.encontrar()?"si":"no") << " se encuentra en la tabla.\n\n";

	system("pause");
	return 0;
}
