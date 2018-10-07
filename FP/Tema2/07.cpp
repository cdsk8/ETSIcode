#include <iostream>
#include <cmath>

using namespace std;

int main(){
	double ax, ay, bx, by, distancia;
		
	cout << "Ingrese el eje x del primer punto: ";
	cin >> ax;
	cout << "Ingrese el eje y del primer punto: ";
	cin >> ay;
	cout << "Ingrese el eje x del segundo punto: ";
	cin >> bx;
	cout << "Ingrese el eje y del segundo punto: ";
	cin >> by;
	
	distancia = sqrt(pow(ax-bx,2)+pow(ay-by,2));
	
	cout << "\nLa distancia entre los dos puntos es: " << distancia << " unidades.\n\n";
	
	system("pause");
	return 0;
}
