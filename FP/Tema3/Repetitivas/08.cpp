#include <iostream>
#include <cstdlib>

using namespace std;

class Factorizar{
	private:
		int n;
	public:
		void informacion();
		long factorial();
};

void Factorizar::informacion(){
	do{
		cout << "Introduzca un numero entero positivo menor que 20: ";
		cin >> n;
		cout << "\n";
	}while(n < 0 or n >= 20);
}

long Factorizar::factorial(){
	long factorial = 1;

	for(int i = 1; i <= n; i++)
		factorial *= i;

	return factorial;
}

int main(){
	Factorizar f;

	f.informacion();
	cout << "El factorial del numero introducido es " << f.factorial() << ".\n\n";

	system("pause");
	return 0;
}
