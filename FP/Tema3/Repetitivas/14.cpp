#include <iostream>
#include <cstdlib>
#include <windows.h>

using namespace std;

class Reloj{
	private:
		int Hi, Mi, Si, TiempoSimulacion;
	public:
		void Iniciar();
		void Simular();
};

void Reloj::Iniciar(){
	cout << "Introduzca la hora de inicio: ";
	cin >> Hi;
	cout << "Introduzca el minuto de inicio: ";
	cin >> Mi;
	Si = 0;
	TiempoSimulacion = 0;

	do{
		if(TiempoSimulacion < 0)
			cout << "El tiempo de simulacion no puede ser negativo.\n";
		cout << "Introduzca el tiempo que durara la simulacion (minutos): ";
		cin >> TiempoSimulacion;
		TiempoSimulacion *= 60;
	}while(TiempoSimulacion<0);
	cout << "\n";
}

void Reloj::Simular(){
	for(int i = 0; i < TiempoSimulacion; i++){
		cout << "\t" << (Hi<10?"0":"") << Hi << ":" << (Mi<10?"0":"") << Mi << ":" << (Si<10?"0":"") << Si << "\r";

		Si++;
		if(Si == 60){
			Si = 0;
			Mi++;
			if(Mi == 60){
				Mi = 0;
				Hi++;
				if(Hi == 24)
					Hi = 0;
			}
		}

		Sleep(500);
	}
}

int main(){
	Reloj r;

	r.Iniciar();
	r.Simular();

	system("pause");
	return 0;
}
