#include <iostream>

using namespace std;

int main(){
	int a, b, opcion;
	
	cout << "Introduzca el primer numero: ";
	cin >> a;
	cout << "Introduzca el segundo numero: ";
	cin >> b;
	
	cout << "\n\tMENU\n  1. Sumar\n  2. Restar\n  3. Multiplicar\n  4. Dividir\nElija opcion: ";
	cin >> opcion;
	
	switch(opcion){
		case 1:
			cout << "\n " << a << " + " << b << " = " << (a+b) <<"\n\n";
			break;
		case 2:
			cout << "\n " << a << " - " << b << " = " << (a-b) <<"\n\n";
			break;
		case 3:
			cout << "\n " << a << " * " << b << " = " << (a*b) <<"\n\n";
			break;
		case 4:
			cout << "\n " << a << " / " << b << " = " << ((double)a/b) <<"\n\n";
			break;
		default:
			cout << "\nOpcion invaldia\n\n";
	}
	
	
	system("pause");
	return 0;
}
