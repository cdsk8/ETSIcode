#include <iostream>

using namespace std;

class empleado{
	private:
		int horasNormales, horasExtra;
	public:
		void cargar();
		float nomina();
};

void empleado::cargar(){
	cout << "Ingrese el numero de horas normales trabajadas: ";
	cin >> horasNormales;
	cout << "Ingrese el numero de horas extras trabajadas: ";
	cin >> horasExtra;
	cout << "\n";
}

float empleado::nomina(){
	return ((horasNormales*5)+(horasExtra*8))*0.85;
}

int main(){
	empleado e;

	e.cargar();
	cout << "El sueldo a cobrar es " << e.nomina() << " euros.\n\n";

	system("pause");
	return 0;
}
