#include <iostream>
#include <cstdlib>

using namespace std;

class Juego{
	private:
		int ValorMin, ValorMax, ValorMedio;
	public:
		void PedirExtremos();
		char AdivinarNumero();
		bool CompruebaEsMenor();
		bool CompruebaEsMayor();
};

void Juego::PedirExtremos(){
	bool error;

	do{
		cout << "Introduzca el extremo inferior: ";
		cin >> ValorMin;
		cout << "Introduzca el extremo superior: ";
		cin >> ValorMax;

		if(ValorMin >= ValorMax){
			cout << "Error, el extremo inferior no puede ser mayor que el superior.\n\n";
			error = true;
		}else{
			error = false;
		}
	}while(error);
}

char Juego::AdivinarNumero(){
	ValorMedio = (ValorMin+ValorMax)/2;
	char respuesta;
	bool error;

	do{
		cout << "\n¿Es " << ValorMedio << " tu numero?(=) En caso de que no lo sea, ¿Tu numero es mayor (>) o menor (<) que " << ValorMedio << " ? ";
		cin >> respuesta;

		if(respuesta != '=' and respuesta != '>' and respuesta != '<'){
			cout << "Error, el simbolo introducido no es valido.\n\n";
			error = true;
		}else{
			error = false;
		}
	}while(error);

	return respuesta;
}

bool Juego::CompruebaEsMenor(){
	ValorMax = ValorMedio;
	bool correcto = true;

	if(ValorMin >= ValorMax)
		correcto = false;
	return correcto;
}

bool Juego::CompruebaEsMayor(){
	ValorMin = ValorMedio;
	bool correcto = true;

	if(ValorMin >= ValorMax)
		correcto = false;
	return correcto;
}

int main(){
	Juego j;
	string continuar;
	char resultado;

	do{
		system("cls");
		j.PedirExtremos();

		do{
			resultado = j.AdivinarNumero();
			if(resultado == '>'){
				if(!j.CompruebaEsMayor()){
					cout << "\nError al definir el limite superior.\n";
					resultado = '"';
				}
			}else if(resultado == '<'){
				if(!j.CompruebaEsMenor()){
					cout << "\nError al definir el limite inferior.\n";
					resultado = '"';
				}
			}
		}while(resultado != '=' or resultado == '*');

		if(resultado == '=')
			cout << "\nHe conseguido adivinar el numero en el que estas pensando.\n";

		cout << "\n¿Desea jugar otra vez? (si, no): ";
		cin >> continuar;
	}while(continuar == "si");

	system("pause");
	return 0;
}
