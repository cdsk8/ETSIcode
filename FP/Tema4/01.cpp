#include <iostream>
#include <cstdlib>

#define M 10

using namespace std;

class uno{
	private:
		int tabla[M];
	public:
		void cargar();
		int maximo();
		int minimo();
};

void uno::cargar(){
	for(int i = 0; i < M; i++){
		cout << "Introduzca un numero entero: ";
		cin >> tabla[i];
	}
	cout << "\n";
}

int uno::maximo(){
	int max = -32767;
	for(int i = 0; i < M; i++)
		if(tabla[i] > max)
			max = tabla[i];
	cout << "El maximo valor almacenado en la tabla es " << max << "\n";
}

int uno::minimo(){
	int min = 32767;
	for(int i = 0; i < M; i++)
		if(tabla[i] < min)
			min = tabla[i];
	cout << "El minimo valor almacenado en la tabla es " << min << "\n";
}

int main(void){
	uno u;

	u.cargar();
	u.maximo();
	u.minimo();

	cout << "\n";
	system("pause");
	return 0;
}
