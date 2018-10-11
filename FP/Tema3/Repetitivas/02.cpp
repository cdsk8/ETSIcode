#include <iostream>
#include <cstdlib>

using namespace std;

class Numeros{
	private:
		int maximo, minimo;
		float media;
	public:
		void estadistica();
		int mostrarmax();
		int mostrarmin();
		float mostrarmedia();
};

void Numeros::estadistica(){
	int cantidad, tmp;
	media = 0;

	cout << "Introduzca la cantidad de numeros que quieres poner: ";
	cin >> cantidad;

	for(int i = 0; i < cantidad; i++){
		cout << "Introduzca un numero entero: ";
		cin >> tmp;
		if(i == 0){
			maximo = minimo = tmp;
		}else{
			if(tmp < minimo)
				minimo = tmp;
			if(tmp > maximo)
				maximo = tmp;
		}
		media += tmp;
	}

	media /= cantidad;
	cout << "\n";
}

int Numeros::mostrarmax(){
	return maximo;
}

int Numeros::mostrarmin(){
	return minimo;
}

float Numeros::mostrarmedia(){
	return media;
}

int main(){
	Numeros n;

	n.estadistica();
	cout << "La maxima es " << n.mostrarmax() << "\nLa minima es " << n.mostrarmin() << "\nLa media es " << n.mostrarmedia() << "\n\n";

	system("pause");
	return 0;
}
