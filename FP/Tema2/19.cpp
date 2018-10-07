#include <iostream>

using namespace std;

class rectangulo{
	private:
		int largo, ancho;
	public:
		void iniciar();
		void cargar();
		int area();
		void cambiar();
};

void rectangulo::iniciar(){
	largo = 4;
	ancho = 2;
}

void rectangulo::cargar(){
	cout << "Ingrese el largo del rectangulo: ";
	cin >> largo;
	cout << "Ingrese el ancho del rectangulo: ";
	cin >> ancho;
	cout << "\n";
}

int rectangulo::area(){
	return largo * ancho;
}

void rectangulo::cambiar(){
	int tmp = largo;
	largo = ancho;
	ancho = tmp;
}

int main(){
	rectangulo r;

	r.iniciar();

	cout << "El area del rectangulo de largo 4 y ancho 2 es de " << r.area() << " unidades.\n\n";
	cout << "Modifica sus dimensiones.\n";
	r.cargar();
	cout << "El nuevo area del rectangulo es de " << r.area() << " unidades.\n";
	r.cambiar();
	cout << "Si invertimos el valor de largo y ancho, el area sigue sindo  de " << r.area() << " unidades.\n\n";

	system("pause");
	return 0;
}
