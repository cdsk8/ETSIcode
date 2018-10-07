#include <iostream>
#include <cmath>

#define pi 3.1415
#define e0 8.85e-12

using namespace std;

class CampoElec{
	private:
		double q, r;
	public:
		void Leer();
		double Intensidad();
};

void CampoElec::Leer(){
	char opcion;
	
	cout << "Seleccione la unidad en la que quiere introducir la carga.\n  a) Miliculombios \n  b)Microculombios\n  c)Nanoculombios\n";
	cout << "Ingrese su opcion (a, b, c): ";
	cin >> opcion;
	cout << "Ingrese el valor de la carga: ";
	cin >> q;
	switch(opcion){
		case 'a':
			q *= 1e-3;
			break;
		case 'b':
			q *= 1e-6;
			break;
		case 'c':
			q *= 1e-9;
			break;
		default:
			cout << "Error en la seleccion de unidades.\n";
	}
	
	cout << "\nSeleccione la unidad en la que quiere introducir la carga.\n  a)Decimetros\n  b)Centimetros\n  c)Milimetros\n";
	cout << "Ingrese su opcion (a, b, c): ";
	cin >> opcion;
	cout << "Ingrese la distancia a la cargas: ";
	cin >> r;
	switch(opcion){
		case 'a':
			r *= 1e-1;
			break;
		case 'b':
			r *= 1e-2;
			break;
		case 'c':
			r *= 1e-3;
			break;
		default:
			cout << "Error en la seleccion de unidades.\n";
	}
	
	cout << "\n ";
}

double CampoElec::Intensidad(){
	return (q)/(4*pi*e0*pow(r,2));
}

int main(){
	CampoElec ce;

	ce.Leer();
	cout << "La intensidad es de " << ce.Intensidad() << " N/C.\n\n";

	system("pause");
	return 0;
}
