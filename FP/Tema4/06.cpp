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
		cout << "Introduzca un numero para la primera tabla ("<< i+1 <<"): ";
		cin >> tab1[i];
	}
	cout << "\n";
	for(int i = 0; i < 10; i++){
		cout << "Introduzca un numero para la segunda tabla ("<< i+1 <<"): ";
		cin >> tab2[i];
	}
	cout << "\n";
}

int vector::comparar(){
	int i = 0;
	bool identicas = false;

	while(!identicas && i < 10){
		if(tab1[i] != tab2[i])
			identicas = true;
		i++;
	}

	return identicas?1:0;
}

int main(void){
	vector v;

	v.cargar();
	cout << "Las tablas son " << (v.comparar()?"diferentes":"identicas") << ".\n\n";

	system("pause");
	return 0;
}
