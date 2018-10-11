#include <iostream>
#include <cstdlib>

using namespace std;

int main(){
	int a, b;
	char opcion;
	bool continuar = true;

	cout << "Introduzca el primer numero: ";
	cin >> a;
	cout << "Introduzca el segundo numero: ";
	cin >> b;

	do{
		cout << "\n\tMENU\n  A. Sumar\n  B. Restar\n  C. Multiplicar\n  D. Dividir\n  E. Salir\nElija opcion: ";
		cin >> opcion;

		switch(opcion){
			case 'a':
			case 'A':
				cout << "\n " << a << " + " << b << " = " << (a+b) <<"\n\n";
				break;
			case 'b':
			case 'B':
				cout << "\n " << a << " - " << b << " = " << (a-b) <<"\n\n";
				break;
			case 'c':
			case 'C':
				cout << "\n " << a << " * " << b << " = " << (a*b) <<"\n\n";
				break;
			case 'd':
			case 'D':
				cout << "\n " << a << " / " << b << " = " << ((double)a/b) <<"\n\n";
				break;
			case 'e':
			case 'E':
				continuar = false;
				break;
			default:
				cout << "\nOpcion invaldia\n\n";
		}
	}while(continuar);

	system("pause");
	return 0;
}
