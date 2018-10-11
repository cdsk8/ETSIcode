#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

#define PI 3.1415

int main(){
	double R, longitud, superficie, volumen;

	cout << "Introduzca el radio: ";
	cin >> R;

	longitud = 2 * PI * R;
	superficie = PI * pow(R,2);
	volumen = (4 * PI * pow(R,3)) / 3;

	cout << "\nLongitud: " << longitud << " unidades.";
	cout << "\nSuperficie: " << superficie << " unidades^2.";
	cout << "\nVolumen: " << volumen << " unidades^3.\n\n";

	system("pause");
	return 0;
}
