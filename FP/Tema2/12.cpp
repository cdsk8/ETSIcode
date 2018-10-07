#include <iostream>

using namespace std;

int main(){
	double celsius, fahrenheit;
	
	cout << "Introduzca una temperatura en grados Celsius: ";
	cin >> celsius;
	
	fahrenheit = celsius * (9.0/5.0) + 32;
	
	cout << "\n" << celsius << " grados Celsius equivalen a " << fahrenheit << " grados Fahrenheit.\n\n";
	
	system("pause");
	return 0;
}
