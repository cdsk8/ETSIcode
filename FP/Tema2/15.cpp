#include <iostream>
#include <cstdlib>

using namespace std;

int main(){
	double a, b, c, d, e, f, x, y;

	cout << "Introduzca el valor de a: ";
	cin >> a;
	cout << "Introduzca el valor de b: ";
	cin >> b;
	cout << "Introduzca el valor de c: ";
	cin >> c;
	cout << "Introduzca el valor de d: ";
	cin >> d;
	cout << "Introduzca el valor de e: ";
	cin >> e;
	cout << "Introduzca el valor de f: ";
	cin >> f;

	x =  (c*e - b*f) / (a*e - b*d);
	y =  (a*f - c*d) / (a*e - b*d);

	cout << "\nEl valor de x es " << x << " y el valor de y es " << y << "\n\n";

	system("pause");
	return 0;
}
