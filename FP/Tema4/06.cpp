#include <iostream>
#include <cstdlib>

using namespace std;

class vector{
	private:
		int tab1[10], tab2[10];
	public:
		void cargar();
		int comparar();
};

void vector::cargar(){
	for(int i = 0; i < 10; i++){
		cout << "Introduzca un numero para la primera tabla: ";
		cin >> tab1[i];
	}
	for(int i = 0; i < 10; i++){
		cout << "Introduzca un numero para la segunda tabla: ";
		cin >> tab2[i];
	}
	cout << "\n";
}

int vector::comparar(){
	int i = 0;
	int identicas = 0;

	while(!identicas and i < 10){
		if(tab1[i] != tab2[i])
			identicas = 1;
		i++;
	}

	return identicas;
}

int main(void){
	vector v;

	v.cargar();
	cout << "Las tablas son " << (v.comparar()?"diferentes":"identicas") << ".\n\n";

	system("pause");
	return 0;
}
