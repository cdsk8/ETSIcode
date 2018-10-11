#include <iostream>
#include <cstdlib>

using namespace std;

class Primo{
	private:
		int n;
	public:
		void cargar();
		bool esPrimo();
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

int main(){
	Primo p;

	p.cargar();
	cout << "El numero introducido " << (p.esPrimo()?"si":"no") << " es primo.\n\n";

	system("pause");
	return 0;
}
