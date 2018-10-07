#include <iostream>
#include <cmath>

using namespace std;

int main(){
	double a, b, c, solucion1, solucion2;
	
	cout << "Introduzca el valor de a: ";
	cin >> a;
	cout << "Introduzca el valor de b: ";
	cin >> b;
	cout << "Introduzca el valor de c: ";
	cin >> c;
	
	solucion1 = ((-b) + sqrt(pow(b,2) - (4*a*c))) / (2*a);
	solucion2 = ((-b) - sqrt(pow(b,2) - (4*a*c))) / (2*a);
	
	cout << "\nLas dos soluciones posibles son " << solucion1 << " y " << solucion2 << "\n\n";
	
	system("pause");
	return 0;
}
