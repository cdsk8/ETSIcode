#include <iostream>

using namespace std;

class Fracciones{
	private:
		int a, b, c, d;
	public:
		void cargar();
		void sumar();
		void restar();
		void multiplicacion();
		void division();
};

void Fracciones::cargar(){
	cout << "Ingrese el valor de a: ";
	cin >> a;
	cout << "Ingrese el valor de b: ";
	cin >> b;
	cout << "Ingrese el valor de c: ";
	cin >> c;
	cout << "Ingrese el valor de d: ";
	cin >> d;
	cout << "\n ";
}

void Fracciones::sumar(){
	cout << a << "/" << b << " + " << c << "/" << d << " = " << (a*d + b*c) << "/" << (b*d) << "\n";
}

void Fracciones::restar(){
	cout << a << "/" << b << " - " << c << "/" << d << " = " << (a*d - b*c) << "/" << (b*d) << "\n";
}

void Fracciones::multiplicacion(){
	cout << a << "/" << b << " * " << c << "/" << d << " = " << (a*c) << "/" << (b*d) << "\n";
}

void Fracciones::division(){
	cout << a << "/" << b << " / " << c << "/" << d << " = " << (a*d) << "/" << (b*c) << "\n";
}

int main(){
	Fracciones f;

	f.cargar();
	f.sumar();
	f.restar();
	f.multiplicacion();
	f.division();

	cout << "\n";

	system("pause");
	return 0;
}
