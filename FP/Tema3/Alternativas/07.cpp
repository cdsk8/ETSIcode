#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

class Billete{
	private:
		int distancia, dias, edad;
	public:
		void informacion();
		float operacion();
};

void Billete::informacion(){
	cout << "Introduzca la distancia del viaje: ";
	cin >> distancia;
	cout << "Introduzca el numero de dias que dura: ";
	cin >> dias;
	cout << "Introduzca la edad del turista: ";
	cin >> edad;
}

float Billete::operacion(){
	float precio = distancia * 2 * 0.5;
	if((dias >= 7 and distancia >= 800) or edad >= 55){
		precio *= 0.75;
	}
	return precio;
}

int main(){
	Billete b;

	b.informacion();
	cout << "\nEl precio del billete de ida y vuelta es " << b.operacion() << " euros.\n\n" ;

	system("pause");
	return 0;
}
