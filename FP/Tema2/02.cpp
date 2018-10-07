#include <iostream>

using namespace std;

int main(void){
	int numero;
	
	cout << "Introduzca un numero entero: ";
	cin >> numero;
	numero += 5;
	cout << "El numero introducido incrementado en 5 es " << numero << ".\n\n";
	
	system("pause");
	return 0;
}
