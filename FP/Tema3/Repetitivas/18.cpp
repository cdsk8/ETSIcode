#include <iostream>
#include <cmath>

 #define pi 3.141592

using namespace std;

class young{
	private:
		float seccion, longitud, carga, deformacion;
	public:
		void leer_datos();
		float calcular_esfuerzo();
		float calcular_deformacion();
		float modulo_young();
};

void young::leer_datos(){
	int unidad;
	
	cout <<"Elija la unidad en la que introducira la carga: \n\t1. Newtons\n\t2. KiloNewtons\nSeleccion: ";
	cin >> unidad;
	cout << "Introduzca la carga (" << (unidad==1?"N":"KN") <<"): ";
	cin >> carga;
	carga *= unidad==1?1:1e-3;
	
	cout <<"\nElija la unidad en la que introducira la seccion: \n\t1. Metros\n\t2. Milimetros\nSeleccion: ";
	cin >> unidad;
	cout << "Introduzca la seccion (" << (unidad==1?"m":"mm") <<"): ";
	cin >> seccion;
	seccion *= unidad==1?1:1e-3;
	
	cout <<"\nElija la unidad en la que introducira la longitud inicial: \n\t1. Metros\n\t2. Milimetros\nSeleccion: ";
	cin >> unidad;
	cout << "Introduzca la longitud inicial (" << (unidad==1?"m":"mm") <<"): ";
	cin >> longitud;
	longitud *= unidad==1?1:1e-3;
	
	cout <<"\nElija la unidad en la que introducira el incremento de la longitud: \n\t1. Metros\n\t2. Milimetros\nSeleccion: ";
	cin >> unidad;
	cout << "Introduzca el incremento en la longitud (" << (unidad==1?"m":"mm") <<"): ";
	cin >> deformacion;
	deformacion *= unidad==1?1:1e-3;
	
	cout << "\n\n";
}

float young::calcular_esfuerzo(){
	return roundf(carga/(pi*pow(seccion/2,2))*100)/100;
}

float young::calcular_deformacion(){
	return roundf((deformacion/longitud) * 10000)/10000;
}

float young::modulo_young(){
	return calcular_esfuerzo()/calcular_deformacion();
}

int main(){
	young y;
	
	y.leer_datos();
	cout << "El esfuerzo actuante es de " << y.calcular_esfuerzo() << " MPa\n";
	cout << "La deformacion del material es de " << y.calcular_deformacion() << "\n";
	cout << "El modulo de young es de " << y.modulo_young() << " MPa\n\n";

	system("pause");
	return 0;
}
