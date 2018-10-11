#include <iostream>
#include <cstdlib>
#include <cmath>

#define g 9.8

using namespace std;

class Energia{
	private:
		double m, v, h;
	public:
		void Leer();
		float ECinetica();
		float EPotencial();
};

void Energia::Leer(){
	cout << "Ingrese el valor de la masa (kg): ";
	cin >> m;
	cout << "Ingrese el valor de la velocidad (km/h): ";
	cin >> v;
	cout << "Ingrese el valor de la altura (km): ";
	cin >> h;
	cout << "\n ";
}

float Energia::ECinetica(){
	return (m*pow(v/3.6,2))/2;
}

float Energia::EPotencial(){
	return m*g*h*1e3;
}

int main(){
	Energia e;

	e.Leer();
	cout << "La energía cinetica es de " << e.ECinetica() << " J.\n";
	cout << "La energía potencial es de " << e.EPotencial() << " J.\n\n";
	cout << "La energía mecanica es de " << e.ECinetica()+e.EPotencial() << " J.\n\n";

	system("pause");
	return 0;
}
