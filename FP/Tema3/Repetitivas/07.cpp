#include <iostream>
#include <cstdlib>

using namespace std;

class Primo{
	private:
		int n;
	public:
		void cargar();
		bool esPrimo();
		void ListaPrimos();
};

void Primo::cargar(){
	cout << "Introduzca un numero: ";
	cin >> n;
}

bool Primo::esPrimo(){
	bool primo = true;

	int i = 2;
	do{
		if(i != n and n%i == 0)
			primo = false;
		i++;
	}while(i <= n/2 and primo);

	return primo;
}

void Primo::ListaPrimos(){
	cout << "Lista de primos entre 2 y 1000:\n";
	for(int i = 2; i < 1000; i++){
		n = i;
		if(esPrimo()){
			cout << i << ", ";
		}
	}
}

int main(){
	Primo p;

	p.ListaPrimos();
	cout << "\n\n";

	system("pause");
	return 0;
}
