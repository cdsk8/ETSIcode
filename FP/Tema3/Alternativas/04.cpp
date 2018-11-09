#include <iostream>
#include <cstdlib>

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

int menu(){
    int opcion;
    cout << "\n\tMENU\n  1. Sumar\n  2. Restar\n  3. Multiplicar\n  4. Dividir\n\nElija opcion: ";
	cin >> opcion;
	return opcion;
}

int main(){
    numeros n;
	int opcion;

	n.cargar();

	switch(menu()){
		case 1:
			cout << "\n " << n.leeuno() << " + " << n.leedos() << " = " << (n.leeuno()+n.leedos()) <<"\n\n";
			break;
		case 2:
			cout << "\n " << n.leeuno() << " - " << n.leedos() << " = " << (n.leeuno()-n.leedos()) <<"\n\n";
			break;
		case 3:
			cout << "\n " << n.leeuno() << " * " << n.leedos() << " = " << (n.leeuno()*n.leedos()) <<"\n\n";
			break;
		case 4:
			cout << "\n " << n.leeuno() << " / " << n.leedos() << " = " << ((double)n.leeuno()/n.leedos()) <<"\n\n";
			break;
		default:
			cout << "\nOpcion invaldia\n\n";
	}


	system("pause");
	return 0;
}
