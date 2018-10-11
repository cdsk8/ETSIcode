#include <iostream>
#include <cstdlib>

using namespace std;

int main(){
	int segundos, minutos, horas;

	cout << "Introduzca una cantidad positiva de segundos: ";
	cin >> segundos;

	horas = segundos / 3600;
	segundos -= horas * 3600;
	minutos = segundos / 60;
	segundos -= minutos * 60;

	cout << "\nEquivale a " << horas << " horas,  " << minutos << " minutos y " << segundos << " segundos.\n\n";

	system("pause");
	return 0;
}
