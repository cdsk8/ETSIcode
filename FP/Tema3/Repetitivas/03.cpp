#include <iostream>
#include <cstdlib>

using namespace std;

class Estadistica{
	private:
		int susp, apr, notab, sob;
	public:
		void elaborarEstadistica();
		void resultado();
};

void Estadistica::elaborarEstadistica(){
	int cantidad;
	double nota;
	susp = apr = notab = sob = 0;

	cout << "Introduzca el numero de alumnos: ";
	cin >> cantidad;
	for(int i = 0; i < cantidad; i++){
		do{
            cout << "Introduzca la nota: ";
            cin >> nota;
            if(nota < 0 || nota > 10){
                cout << "Error al introducir la nota, pruebe otra vez. ";
                system("color 4");
            }
		}while(nota < 0 || nota > 10);
		cout << "\n";
		system("color 7");

		if(nota >= 9){
			sob ++;
		}else if(nota >= 7){
			notab ++;
		}else if(nota >= 5){
			apr ++;
		}else if(nota >= 0){
			susp ++;
		}
	}
}

void Estadistica::resultado(){
	cout << "\nCantidad de suspensos: " << susp << "\nCantidad de aprobados: " << apr << "\nCantidad de notable: " << notab << "\nCantidad de sobresalientes: " << sob << "\n\n";
}

int main(){
	Estadistica e;

	e.elaborarEstadistica();
	e.resultado();

	system("pause");
	return 0;
}
