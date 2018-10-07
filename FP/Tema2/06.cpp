#include <iostream>

using namespace std;

int main(){
	double teoria, practica, final;
		
	cout << "Ingrese la nota de teoria: ";
	cin >> teoria;
	cout << "Ingrese la nota de practicas: ";
	cin >> practica;
	
	final = teoria*0.7 + practica*0.3;
	
	cout << "La nota final es un " << final << ".\n\n";
	
	system("pause");
	return 0;
}
