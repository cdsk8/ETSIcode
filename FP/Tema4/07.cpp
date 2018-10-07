#include <iostream>

using namespace std;

class merges{
	private:
		int uno[15], dos[15], fus[30];
		int numuno;
		int numdos;
	public:
		void cargar();
		void mezclar();
		void ver();
		void verfusion();
};

void merges::cargar(){
	bool error = false;
	
	do{
		cout << "Introduzca el numero de elementos que desea colocar en la primera tabla: ";
		cin >> numuno;
		if(numuno > 15){
			cout << "El numero introducido no puede ser mayor que 15.\n";
			error = true;
		}else{
			error = false;
		}
	}while(error);
	
	for(int i = 0; i < numuno; i++){
		do{
			cout << "Introduzca un numero para la primera tabla: ";
			cin >> uno[i];
			if(i != 0 and uno[i] < uno[i-1]){
				cout << "El numero introducido no puede ser menor que el anterior.\n";
				error = true;
			}else{
				error = false;
			}
		}while(error);
	}
	
	cout << "\n";
	
	do{
		cout << "Introduzca el numero de elementos que desea colocar en la segunda tabla: ";
		cin >> numdos;
		if(numdos > 15){
			cout << "El numero introducido no puede ser mayor que 15.\n";
			error = true;
		}else{
			error = false;
		}
	}while(error);
	
	for(int i = 0; i < numdos; i++){
		do{
			cout << "Introduzca un numero para la segunda tabla: ";
			cin >> dos[i];
			if(i != 0 and dos[i] < dos[i-1]){
				cout << "El numero introducido no puede ser menor que el anterior.\n";
				error = true;
			}else{
				error = false;
			}
		}while(error);
	}
	
	cout << "\n";
}

void merges::mezclar(){
	int i, j, k;
	i = j = k = 0;
	
	while(i < numuno or j < numdos){
		if((i != numuno and uno[i] < dos[j]) or j == numdos){
			fus[k] = uno[i];
			i++;
		}else{
			fus[k] = dos[j];
			j++;
		}
		k++;
	}
}

void merges::ver(){
	cout << "\n    Tabla uno\tTabla dos\n";
	for(int i = 0; i < (numuno>numdos?numuno:numdos); i++){
		cout << "\t";
		if(i < numuno)
			cout << uno[i];
		if(i < numdos)
			cout << "\t    " << dos[i] ;
		cout << "\n";
	}
}

void merges::verfusion(){
	cout << "\n       Tabla fusionada\n";
	for(int i = 0; i < numuno + numdos; i++){
		cout << "\t      " << fus[i] << "\n";
	}
	cout << "\n";
}

int main(void){
	merges m;
	
	m.cargar();
	m.mezclar();
	m.ver();
	m.verfusion();
	
	system("pause");
	return 0;
}
