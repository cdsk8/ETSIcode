#include <iostream>
#include <cmath>

using namespace std;

class Movimiento{
	private:
		double velocidad_inicial, posicion_inicial, aceleracion, tiempo;
	public:
		void cargar();
		float velocidad();
		float posicion();
};

void Movimiento::cargar(){
	cout << "Ingrese la velocidad inicial (m/s): ";
	cin >> velocidad_inicial;
	cout << "Ingrese la posicion inicial (m): ";
	cin >> posicion_inicial;
	cout << "Ingrese la aceleracion (m/s^2): ";
	cin >> aceleracion;
	cout << "Ingrese el tiempo (s): ";
	cin >> tiempo;
}

float Movimiento::velocidad(){
	return velocidad_inicial + aceleracion * tiempo;
}

float Movimiento::posicion(){
	return posicion_inicial + (velocidad_inicial * tiempo) + (aceleracion * pow(tiempo,2) / 2);
}

int main(){
	Movimiento m;

	m.cargar();
	cout << "La velocidad final es de " << m.velocidad() << "m/s.\n";
	cout << "La posicion final es de " << m.posicion() << "m.\n\n";

	system("pause");
	return 0;
}
