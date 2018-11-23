#include <iostream>
#include <cstdlib>


//Caracteres especiales del español.
#define Ea char(160)
#define Ee char(130)
#define Ei char(161)
#define Eo char(162)
#define Eu char(163)
#define Ex char(168)

#define M 10

using namespace std;

class uno{
	private:
		int tabla[M];
	public:
		void cargar();
		int maximo();
		int minimo();
};

void uno::cargar(){
	for(int i = 0; i < M; i++){
		cout << "Introduzca un numero entero (" << (i+1) << "): ";
		cin >> tabla[i];
	}
	cout << "\n";
}

int uno::maximo(){
	int max = tabla[0];
	for(int i = 1; i < M; i++)
		if(tabla[i] > max)
			max = tabla[i];
    return max;
}

int uno::minimo(){
	int min = tabla[0];
	for(int i = 1; i < M; i++)
		if(tabla[i] < min)
			min = tabla[i];
    return min;
}

int main(void){
	uno u;

	u.cargar();
    cout << "El m"<<Ea<<"ximo valor almacenado en la tabla es " << u.maximo() << "\n";
    cout << "El m"<<Ei<<"nimo valor almacenado en la tabla es " << u.minimo() << "\n";


	cout << "\n";
	system("pause");
	return 0;
}
