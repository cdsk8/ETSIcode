#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

class Juego{
	private:
		int numero, n_intento, intento;
		int pedir_numero();
	public:
		void generar_numero();
		void jugada();
};

int Juego::pedir_numero(){
	int resultado;
	
	cout << "Intente adivinar el numero: ";
	cin >> resultado;
	
	return resultado;
}
void Juego::generar_numero(){
	srand(time(NULL));
	numero = 1 + rand() % (999-1);
}

void Juego::jugada(){
	n_intento = 0;
	
	while(n_intento < 10){
		intento = pedir_numero();
		n_intento++;
		
		if(numero == intento){
			cout << "Has acertado.\n\n";
			
			n_intento = 20;
		}else{
			if(n_intento == 10){
				cout << "No te quedan intentos, has perdido. El numero era " << numero << " \n\n";
			}else{
				if(intento >= numero){
					cout << "El numero introducido es mayor que el numero generado. Te queda" << (n_intento<9?"n":"") <<" " << (10-n_intento) << " inteto" << (n_intento<9?"s":"") <<".\n\n";
				}else{
					cout << "El numero introducido es menor que el numero generado. Te queda" << (n_intento<9?"n":"") <<" " << (10-n_intento) << " inteto" << (n_intento<9?"s":"") <<".\n\n";
				}
			}
		} 
	}
}

int main(){
	Juego j;
	string continuar;
	
	do{
		system("cls");
		
		j.generar_numero();
		j.jugada();
		
		cout << "\n¿Desea jugar otra vez? (si, no): ";
		cin >> continuar;
	}while(continuar == "si");

	system("pause");
	return 0;
}
