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
		cout << "Introduzca un numero entero (" << (i+1) << "): ";
		cin >> tabla[i];
	}
	cout << "\n";
}

int uno::maximo(){
	int max = tabla[0];
	for(int i = 1; i < M; i++)
		if(tabla[i] > max)
			max = tabla[i];
    return max;
}

int uno::minimo(){
	int min = tabla[0];
	for(int i = 1; i < M; i++)
		if(tabla[i] < min)
			min = tabla[i];
    return min;
}

int main(void){
	uno u;

	u.cargar();
    cout << "El maximo valor almacenado en la tabla es " << u.maximo() << "\n";
    cout << "El minimo valor almacenado en la tabla es " << u.minimo() << "\n";


	cout << "\n";
	system("pause");
	return 0;
}
