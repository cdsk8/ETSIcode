#include <iostream>
#include <cstdlib>

using namespace std;

class Fibonacci{
	private:
		int n;
	public:
		void PedirNoElementos();
		float MostrarElementos();
		int ComprobarElemento();
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

int Fibonacci::ComprobarElemento(){
	cout << "Introduzca el numero que quiera comprobar: ";
	cin >> n;

	int i, pos, a, b, tmp;
	i = 0;
	pos = -1;
	a = 1;
	b = 0;

	while(i <= n and pos == -1){
		if(b == n)
			pos = i;

		tmp = b;
		b += a;
		a = tmp;

		i++;
	}

	return pos+1;
}

int main(){
	Fibonacci f;

	int pos = f.ComprobarElemento();
	if(pos == -1){
		cout << "\nEl numero introducido no pertenece a la sucesion.\n\n";
	}else{
		cout << "\nEl numero introducido aparece en la sucesion en la posicion " << pos << ".\n\n";
	}

	system("pause");
	return 0;
}
