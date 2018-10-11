#include <iostream>
#include <cstdlib>
#include <cmath>

#define k 9e9

using namespace std;

class Cargas{
	private:
		double q1, q2, r;
	public:
		void Leer();
		double Fuerza();
};

void Cargas::Leer(){
	cout << "Ingrese el valor de la primera carga (micro C): ";
	cin >> q1;
	cout << "Ingrese el valor de la segunda carga (micro C): ";
	cin >> q2;
	cout << "Ingrese la distancia entre las cargas (m): ";
	cin >> r;
	cout << "\n ";
}

double Cargas::Fuerza(){
	return k*(q1*1e-6*q2*1e-6)/pow(r,2);
}

int main(){
	Cargas q;
	string respuesta;

	do{
		system("cls");
		q.Leer();
		double fuerza = q.Fuerza();
		cout << "La fuerza entre de " << (fuerza>0?"repulsion":"atraccion") << " entre la dos cargas tiene un valor de " << fuerza << " N.\n\n";
		cout << "¿Desea ejecutar de nuevo con otros datos? (si, no): ";
		cin >> respuesta;
	}while(respuesta == "si");

	system("cls");
	cout << "Gracias por usar software B0vE.\n\n";

	system("pause");
	return 0;
}
