#include <iostream>

#define MAX_CUENTAS 100

typedef char Cadena[50];

using namespace std;

class Cuenta{
	private:
		float Saldo;
		int NoCuenta;
		bool Bloqueada;
	public:
		Cuenta();
		Cuenta(int pNo, float pSal);
		bool ActualizarSaldo(int pSal);
		void ActualizarBloqueo(bool pBloq);
		float DameSaldo();
		int DameNoCuenta();
		bool EstaBloqueada();
};

Cuenta::Cuenta(){
	Saldo = 0;
	NoCuenta = 0;
	Bloqueada = false;
}

Cuenta::Cuenta(int pNo, float pSal){
	Saldo = pSal;
	NoCuenta = pNo;
	Bloqueada = false;
}

bool Cuenta::ActualizarSaldo(int pSal){
	if(!Bloqueada)
		Saldo = pSal;
	return !Bloqueada;
}

void Cuenta::ActualizarBloqueo(bool pBloq){
	Bloqueada = pBloq;
}

float Cuenta::DameSaldo(){
	return Saldo;
}

int Cuenta::DameNoCuenta(){
	return NoCuenta;
}

bool Cuenta::EstaBloqueada(){
	return Bloqueada;
}


int BuscarCuenta(Cuenta Ctas[MAX_CUENTAS], int NCuentas, int NoCuenta){
	int i, pos;
	i = pos = -1;
	
	while(i < NCuentas and pos == -1){
		i++;
		if(Ctas[i].DameNoCuenta() == NoCuenta)
			pos = i;
	}
	
	return pos;
}

int MenuCuentas(){
	int respuesta;
	cout << "    Menu Gestion de Cuentas\n"
			"1 Anadir una cuenta a un cliente\n"
			"2 Mostrar las cuetnas del cliente\n"
			"3 Borrar una cuenta del cliente\n"
			"4 Modificar saldo de una cuenta\n"
			"5 Modificar estado de una cuenta\n"
			"6 Salir\n"
			"Elige opcion: ";
	cin >> respuesta;
	return respuesta;
}


int main(void){
	Cuenta DatosCuentas[MAX_CUENTAS];
	bool continuar = true;
	int numero, pos;
	char ch;
	float saldo;
	int nCuentas = 0;
	
	do{
		ch = MenuCuentas();
		system("cls");
		switch(ch){
			case 1:
				if(nCuentas < MAX_CUENTAS){
					cout << "Introduzca el numero de cuenta: ";
					cin >> numero;
					if(BuscarCuenta(DatosCuentas, nCuentas,numero) == -1){
						cout << "Introduzca el saldo de la cuenta: ";
						cin >> saldo;
						DatosCuentas[nCuentas] = Cuenta(numero, saldo);
						nCuentas++;
						cout << "\nCuenta creada correctamente.\n\n";
					}else{
						cout << "\nError, ya existe una cuenta guardada con ese numero.\n\n";
					}
				}else{
					cout << "\nError, se ha superado el maximo de cuentas guardadas permitidas.\n\n";
				}
				break;
			case 2:
				if(nCuentas == 0){
					cout << "No se han encontrado cuentas guardadas.\n\n";
				}else{
					for(int i = 0; i < nCuentas; i++){
						cout << "Numero: " << DatosCuentas[i].DameNoCuenta() << "\n";
						cout << "Saldo: " << DatosCuentas[i].DameSaldo() << "\n";
						cout << "Estado: " << (DatosCuentas[i].EstaBloqueada()?"Bloqueada":"No bloqueada") << "\n\n";
					}
				}
				break;
			case 3:
				cout << "Introduzca el numero de cuenta que desea eliminar: ";
				cin >> numero;
				
				pos = BuscarCuenta(DatosCuentas, nCuentas,numero);
				if(pos == -1){
					cout << "Error, no existe ningunacuenta guardada con el numero introducido.\n\n";
				}else{
					nCuentas--;
					for(int i = pos; i < nCuentas; i++){
						DatosCuentas[i] = DatosCuentas[i+1];
					}
					cout << "Cuenta eliminada con exito.\n\n";
				}
				break;
			case 4:
				cout << "Introduzca el numero de cuenta que desea modificar: ";
				cin >> numero;
				
				pos = BuscarCuenta(DatosCuentas, nCuentas,numero);
				if(pos == -1){
					cout << "Error, no existe ningunacuenta guardada con el numero introducido.\n\n";
				}else{
					cout << "Introduzca el nuevo saldo: ";
					cin >> saldo;
					if(DatosCuentas[pos].ActualizarSaldo(saldo)){
						cout << "Cuenta modificada con exito.\n\n";
					}else{
						cout << "Cuenta bloqueada. La operacion no pudo ser realizada.\n\n";
					}
				}
				break;
			case 5:
				cout << "Introduzca el numero de cuenta que desea modificar: ";
				cin >> numero;
				
				pos = BuscarCuenta(DatosCuentas, nCuentas,numero);
				if(pos == -1){
					cout << "Error, no existe ningunacuenta guardada con el numero introducido.\n\n";
				}else{
					cout << "Introduzca 's' para bloquear la cuenta o 'n' para no bloquearla: ";
					cin >> ch;
					if(ch == 's'){
						DatosCuentas[pos].ActualizarBloqueo(true);
						cout << "Cuenta bloqueada con exito.\n\n";
					}else if(ch == 'n'){
						DatosCuentas[pos].ActualizarBloqueo(false);
						cout << "Cuenta desbloqueada con exito.\n\n";
					}else{
						cout << "Error al introducir el caracter requerido.\n\n";
					}
				}
				break;
			case 6:
				continuar = false;
				break;
		}
		if(continuar){
			cout << "Pulse una tecla para regresar al menu.";
			cin.ignore();
			cin.ignore();
			system("cls");
		}
	}while(continuar);
	
	
	return 0;
}
