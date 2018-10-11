#include <iostream>
#include <cstdlib>

using namespace std;

class Fibonacci{
	private:
		int n;
	public:
		void PedirNoElementos();
		float MostrarElementos();
};

void Fibonacci::PedirNoElementos(){
	do{
		cout << "Introduzca el numero de elementos que desea mostrar: ";
		cin >> n;
	}while(n < 1);

	cout << "\n";
}

float Fibonacci::MostrarElementos(){
	float media = 0;
	int a, b, tmp;
	a = 1;
	b = 0;

	cout << "Los" << n << " primeros elementos de la sucesion de Fibonacci: ";

	int i = 0;
	while(i < n){
		cout << b << ", ";
		media += b;

		tmp = b;
		b += a;
		a = tmp;

		i++;
	}

	cout << "\n";
	return media/n;
}

int main(){
	Fibonacci f;

	f.PedirNoElementos();
	cout << "La media de los elementos listados es " << f.MostrarElementos() << "\n\n";

	system("pause");
	return 0;
}
