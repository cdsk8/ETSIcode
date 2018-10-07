#include <iostream>

using namespace std;

const double equivalenciaDolares = 1.16;
const double equivalenciaLibras = 0.89;

int main(){
	double euros, dolares, libras;
	
	cout << "Introduzca una cantidad de euros: ";
	cin >> euros;
	
	dolares = euros * equivalenciaDolares;
	libras = euros * equivalenciaLibras;
	
	cout << "\n" << euros << " euros equivale a " << dolares << " dolares.";
	cout << "\n" << euros << " euros equivale a " << libras << " dolares.\n\n";
	
	system("pause");
	return 0;
}
