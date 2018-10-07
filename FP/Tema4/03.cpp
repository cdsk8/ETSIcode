#include <iostream>

#define M 10
#define N 15

using namespace std;

class tres{
	private:
		int tabla[M][N];
	public:
		void cargar();
		int encontrar();
};

void tres::cargar(){
	for(int i = 0; i < M; i++){
		for(int j = 0; j < N; j++){
			tabla[i][j] = i*j;
		}
	}
}

int tres::encontrar(){
	int buscado, j, i = 0;
	int encontrado = 0;
	
	cout << "Introduzca el numero que desea buscar: ";
	cin >> buscado;
	
	while(!encontrado and i < M){
		j = 0;
		while(!encontrado and j < N){
			if(tabla[i][j] == buscado)
				encontrado = 1;
			j++;
		}
		i++;
	}
	
	return encontrado;
}

int main(void){
	tres t;
	
	t.cargar();
	cout << "\nEl numero que buscaba " << (t.encontrar()?"si":"no") << " se encuentra en la tabla.\n\n";
	
	system("pause");
	return 0;
}
