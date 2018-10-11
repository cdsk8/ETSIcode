#include <iostream>
#include <cstdlib>

using namespace std;

int main(){
	int a, b, tmp;

	cout << "Ingrese el primer numero entero: ";
	cin >> a;
	cout << "Ingrese el segundo numero entero: ";
	cin >> b;

	cout << "\nLos numeros introducidos son " << a << " y " << b << ".\n";

	tmp = a;
	a = b;
	b = tmp;

	cout << "Los numeros intercambiados son " << a << " y " << b << ".\n\n";

	system("pause");
	return 0;
}
