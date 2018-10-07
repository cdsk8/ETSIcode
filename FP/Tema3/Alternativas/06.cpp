#include <iostream>
#include <cmath>

using namespace std;

class Calculadora{
	private:
		int a, b;
	public:
		void informacion();
		void operacion();
};

void Calculadora::informacion(){
	cout << "Introduzca el primer numero: ";
	cin >> a;
	cout << "Introduzca el segundo numero: ";
	cin >> b;
}

void Calculadora::operacion(){
	char operacion;
	cout << "\nIntroduzca la operacion que desea realizar: ";
	cin >> operacion;
	
	if(operacion == '+' or operacion == 'S' or operacion == 's'){
		cout << "\n" << a << " + " << b << " = " << (a+b) << "\n\n";
	}else if(operacion == '-' or operacion == 'R' or operacion == 'r'){
		cout << "\n" << a << " - " << b << " = " << (a-b) << "\n\n";
	}else{
		cout << "\nLa opracion socilitada no es valida.\n\n";
	}
}

int main(){
	Calculadora c;
	
	c.informacion();
	c.operacion();
	
	system("pause");
	return 0;
}
