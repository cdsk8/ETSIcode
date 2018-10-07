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
	cout << "Ingrese el valor de la carga (micro C): ";
	cin >> q;
	cout << "Ingrese la distancia a la cargas (m): ";
	cin >> r;
	cout << "\n ";
}

double CampoElec::Intensidad(){
	return (q*1e-6)/(4*pi*e0*pow(r,2));
}

int main(){
	CampoElec ce;

	ce.Leer();
	cout << "La intensidad es de " << ce.Intensidad() << " N/C.\n\n";

	system("pause");
	return 0;
}
