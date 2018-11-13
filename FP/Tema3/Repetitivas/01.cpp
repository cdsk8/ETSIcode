#include <iostream>
#include <cstdlib>
#include <conio.h>

using namespace std;

class numeros{
    int uno, dos;
public:
    void cargar();
    int leeuno();
    int leedos();
};

void numeros::cargar(){
    cout << "Introduzca el primer numero: ";
	cin >> uno;
	cout << "Introduzca el segundo numero: ";
	cin >> dos;
}

int numeros::leeuno(){
    return uno;
}

int numeros::leedos(){
    return dos;
}

char menu(){
    cout << "\n\tMENU\n  A. Sumar\n  B. Restar\n  C. Multiplicar\n  D. Dividir\n  E. Salir\n\nElija opcion: ";
	return getch();
}

int main(){
	numeros n;
	bool continuar = true;

	n.cargar();

	do{
		switch(menu()){
			case 'a':
			case 'A':
				cout << "\n\n\n " << n.leeuno() << " + " << n.leedos() << " = " << (n.leeuno()+n.leedos()) <<"\n\n";
				break;
			case 'b':
			case 'B':
				cout << "\n\n\n " << n.leeuno() << " - " << n.leedos() << " = " << (n.leeuno()-n.leedos()) <<"\n\n";
				break;
			case 'c':
			case 'C':
				cout << "\n\n\n " << n.leeuno() << " * " << n.leedos() << " = " << (n.leeuno()*n.leedos()) <<"\n\n";
				break;
			case 'd':
			case 'D':
				cout << "\n\n\n " << n.leeuno() << " / " << n.leedos() << " = " << ((double)n.leeuno()/n.leedos()) <<"\n\n";
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
