#include <iostream>
#include <cstdlib>
#include<stdlib.h>
#include<time.h>

#define TAMA 25

using namespace std;

class Analisis{
	private:
		int Datos[1000];
		int Ndatos;
		int Valores[TAMA];
	public:
		void PedirDatos();
		void AnalizarDatos();
		bool EstanTodos();
		int ValorRepetido();
		int ValorMasRepetido();
		void MostrarDatos();
		void MostrarAnalisis();
};

void Analisis::PedirDatos(){
	char respuesta;
	int entrada;
	bool error;

	cout << "¿Desea introducirlos manualmente (m) o automaticamente (a)? ";
	cin >> respuesta;

	Ndatos = 0;

	do{
		if(respuesta == 'm'){
			cout << "\nModo manual seleccionado, introduzca -1 para dejar de introducir valores.\n";

			do{
				cout << "Introduzca un valor [0,24]: ";
				cin >> entrada;
				if(entrada < 0 or entrada > 24 or entrada == -1){
					if(entrada != -1)
						cout << "Solo se admiten valores entre 0 y 24. ";
				}else{
					Datos[Ndatos] = entrada;
					Ndatos++;
				}
			}while(entrada != -1);

			error = false;
		}else if(respuesta == 'a'){
			srand(time(NULL));
			Ndatos = 1+rand()%(1001-1);
			for(int i = 0; i < Ndatos; i++){
				Datos[i] = rand()%25;
			}
			error = false;
		}else{
			error = true;
			cout << "Introduzca m, para usar la entrada manual, o introduzca a, para la entrada automatica.\n";
		}
	}while(error);
}

void Analisis::AnalizarDatos(){
	for(int i = 0; i < TAMA; i++){
		Valores[i] = 0;
	}

	for(int i = 0; i < Ndatos; i++){
		Valores[Datos[i]]++;
	}
}

bool Analisis::EstanTodos(){
	bool todos = true;
	int i = 0;

	while(i < TAMA and todos){
		if(Valores[i] == 0)
			todos = false;
		i++;
	}

	return todos;
}

int Analisis::ValorRepetido(){
	int numero;
	bool error;

	do{
		cout << "Introduzca el numero a comprobar [0,24]: ";
		cin >> numero;

		if(numero < 0 or numero > 24){
			error = true;
			cout << "El numero debe estar comprendido entre 0 y 24.\n";
		}else{
			error = false;
		}
	}while(error);

	return Valores[numero];
}

int Analisis::ValorMasRepetido(){
	int max_numero, max = 0;

	for(int i = 0; i < TAMA; i++){
		if(Valores[i] > max){
			max = Valores[i];
			max_numero = i+1;
		}
	}

	return max_numero;
}

void Analisis::MostrarDatos(){
	cout << "Datos: ";
	for(int i = 0; i < Ndatos; i++){
		cout << Datos[i] << ", ";
	}
}

void Analisis::MostrarAnalisis(){
	for(int i = 0; i < TAMA; i++){
		cout << "+--";
	}
	cout << "+\n";
	for(int i = 0; i < TAMA; i++){
		cout << (i<9?"| ":"|") << (i+1);
	}
	cout << "|\n";
	for(int i = 0; i < TAMA; i++){
		cout << "+--";
	}
	cout << "+\n";
	for(int i = 0; i < TAMA; i++){
		cout << (Valores[i]<10?"| ":"|") << Valores[i];
	}
	cout << "|\n";
	for(int i = 0; i < TAMA; i++){
		cout << "+--";
	}
	cout << "+\n\n";
}

int main(void){
	int entrada;
	Analisis a;
	bool introducido, analizado;
	introducido = analizado = false;

	do{
		cout << "---------------->Analisis<----------------\n"
				"1. Introducir/Generar datos.\n"
				"2. Analizar datos.\n"
				"3. Comprobar si estan todos los valores.\n"
				"4. Comrpobar repeticiones de un valor.\n"
				"5. Buscar el valor mas repetido.\n"
				"6. Mostrar todos los datos.\n"
				"7. Mostrar al analisis.\n\n"
				"8. Salir.\n"
				"---------------->Analisis<----------------\n"
				"Introduzca su accion: ";
		cin >> entrada;

		switch(entrada){
			case 1:
				system("cls");
				a.PedirDatos();
				cout << "\nDatos introducidos/generados correctamente.\nPulse una telca para volver al menu.\n";
				cin.ignore();
				cin.ignore();
				system("cls");
				introducido = true;
				break;
			case 2:
				system("cls");
				if(introducido){
					a.AnalizarDatos();
					cout << "Los datos fueron analizados correctamente.\nPulse una telca para volver al menu.\n";
					analizado = true;
				}else{
					cout << "Debes introducir los datos antes de analizarlos.\nPulse una telca para volver al menu.\n";
				}
				cin.ignore();
				cin.ignore();
				system("cls");
				break;
			case 3:
				system("cls");
				if(analizado){
					cout << (a.EstanTodos()?"Todos":"No todos") << " los valores posibles estan en los datos.\n\nPulse una telca para volver al menu.\n";
				}else{
					cout << "Debes analizar los datos antes de ejecutar esta funcion.\nPulse una telca para volver al menu.\n";
				}
				cin.ignore();
				cin.ignore();
				system("cls");
				break;
			case 4:
				system("cls");
				if(analizado){
					cout << "El valor que ha introducido se repite " << a.ValorRepetido() << " vez/veces.\n\nPulse una telca para volver al menu.\n";
				}else{
					cout << "Debes analizar los datos antes de ejecutar esta funcion.\nPulse una telca para volver al menu.\n";
				}
				cin.ignore();
				cin.ignore();
				system("cls");
				break;
			case 5:
				system("cls");
				if(analizado){
					cout << "El valor que mas se repite en los datos es el " << a.ValorMasRepetido() << ".\n\nPulse una telca para volver al menu.\n";
				}else{
					cout << "Debes analizar los datos antes de ejecutar esta funcion.\nPulse una telca para volver al menu.\n";
				}
				cin.ignore();
				cin.ignore();
				system("cls");
				break;
			case 6:
				system("cls");
				if(analizado){
					a.MostrarDatos();
					cout << "\nLos datos fueron mostrados correctamente.\nPulse una telca para volver al menu.\n";
				}else{
					cout << "Debes analizar los datos antes de ejecutar esta funcion.\nPulse una telca para volver al menu.\n";
				}
				cin.ignore();
				cin.ignore();
				system("cls");
				break;
			case 7:
				system("cls");
				if(analizado){
					a.MostrarAnalisis();
					cout << "\nEl analisis fue mostrado correctamente.\nPulse una telca para volver al menu.\n";
				}else{
					cout << "Debes analizar los datos antes de ejecutar esta funcion.\nPulse una telca para volver al menu.\n";
				}
				cin.ignore();
				cin.ignore();
				system("cls");
				break;
			case 8:
				break;
			default:
				cout << "\nNo se ha reconocido la orden, debe ser un valor entre 1 y 8.\nPulse una telca para volver al menu.\n";
				cin.ignore();
				cin.ignore();
				system("cls");
				break;
		}
	}while(entrada != 8);

	return 0;
}
