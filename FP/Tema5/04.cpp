#include <iostream>
#include <cstdlib>
#include <string.h>
#include <conio.h>

#define MAX_CUENTAS 10
#define MAX_CLIENTES 100

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


class Cliente{
	private:
		Cadena Nombre;
		Cadena Direccion;
		Cuenta Cuentas[MAX_CUENTAS];
		int NoCuentas;
	public:
		Cliente();
		void ActualizarCliente(Cadena pNomb, Cadena pDir);
		void DameNombre(Cadena pNom);
		void DameDireccion(Cadena pDir);
		int BuscarCuenta(int pNoCuenta);
		bool CrearCuenta(Cuenta pCu);
		bool ActualizarCuenta(Cuenta pCu);
		bool BorrarCuenta(int pNoCuenta);
		int DameNoCuentas();
		Cuenta DameCuenta(int pos);
		void Mostrar(char Campo);
};

Cliente::Cliente(){
	Nombre[0] = '\0';
	Direccion[0] = '\0';
	NoCuentas = 0;
}

void Cliente::ActualizarCliente(Cadena pNomb, Cadena pDir){
	strcpy(Nombre, pNomb);
	strcpy(Direccion, pDir);
	NoCuentas = 0;
}

void Cliente::DameNombre(Cadena pNom){
	strcpy(pNom, Nombre);
}

void Cliente::DameDireccion(Cadena pDir){
	strcpy(pDir, Direccion);
}

int Cliente::BuscarCuenta(int pNoCuenta){
	int i, pos;
	i = pos = -1;

	while(i < NoCuentas and pos == -1){
		i++;
		if(Cuentas[i].DameNoCuenta() == pNoCuenta)
			pos = i;
	}

	return pos;
}

bool Cliente::CrearCuenta(Cuenta pCu){
	if(NoCuentas < MAX_CUENTAS and BuscarCuenta(pCu.DameNoCuenta()) == -1){
		Cuentas[NoCuentas] = pCu;
		NoCuentas++;
		return true;
	}else{
		return false;
	}
}

bool Cliente::ActualizarCuenta(Cuenta pCu){
	int pos = BuscarCuenta(pCu.DameNoCuenta());
	if(pos == -1){
		return false;
	}else{
		Cuentas[pos] = pCu;
		return true;
	}
}

bool Cliente::BorrarCuenta(int pNoCuenta){
	int pos = BuscarCuenta(pNoCuenta);
	if(pos == -1){
		return false;
	}else{
		NoCuentas--;
		for(int i = pos; i < NoCuentas; i++){
			Cuentas[i] = Cuentas[i+1];
		}
		return true;
	}
}

int Cliente::DameNoCuentas(){
	return NoCuentas;
}

Cuenta Cliente::DameCuenta(int pos){
	return Cuentas[pos];
}

void Cliente::Mostrar(char Campo){
	if(Campo == 's' or Campo == 't'){
		cout << "Nombre: " << Nombre << "\n";
		cout << "Direccion: " << Direccion << "\n";
	}
	if(Campo == 'c' or Campo == 't'){
		for(int i = 0; i < NoCuentas; i++){
			cout << "Numero: " << Cuentas[i].DameNoCuenta() << "\n";
			cout << "Saldo: " << Cuentas[i].DameSaldo() << "\n";
			cout << "Estado: " << (Cuentas[i].EstaBloqueada()?"Bloqueada":"No bloqueada") << "\n\n";
		}
	}
}


int BuscarCliente(Cliente Ctes[MAX_CLIENTES], int NCtes, Cadena Nombre){
	int i, pos;
	i = pos = -1;
	Cadena busqueda;

	while(i < NCtes and pos == -1){
		i++;
		Ctes[i].DameNombre(busqueda);
		if(strcmp(busqueda, Nombre) == 0)
			pos = i;
	}

	return pos;
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

	system("cls");
	cout << "    Menu Gestion de Cuentas\n"
			"1 Anadir una cuenta al cliente\n"
			"2 Mostrar las cuetnas del cliente\n"
			"3 Borrar una cuenta del cliente\n"
			"4 Modificar saldo de una cuenta\n"
			"5 Modificar estado de una cuenta\n"
			"6 Salir\n"
			"Elige opcion: ";
	cin >> respuesta;
	return respuesta;
}

int Menu(){
	int respuesta;
	cout << "    Menu Principal\n"
			"1 Anadir un cliente\n"
			"2 Actualizar direccion del cliente\n"
			"3 Mostrar un cliente\n"
			"4 Mostrar todos los clientes\n"
			"5 Submenu Gestion de Cuentas\n"
			"6 Regresar\n"
			"Elige opcion: ";
	cin >> respuesta;
	return respuesta;
}


int main(void){
	Cliente Datos[MAX_CLIENTES];
	int nClientes;

	char ch;
	bool continuar = true;
	Cadena nombre, direccion;
	int i, pos;


	do{
		ch = Menu();
		system("cls");
		switch(ch){
			case 1:
				if(nClientes < MAX_CLIENTES){
					cout << "Introduzca el nombre del cliente: ";
					i = 0;
					do{
						ch = getch();
						switch(ch){
							case '\b':
								if(i > 0){
									cout << "\b \b";
									i--;
								}
								break;
							case '\r':
								cout << '\n';
								nombre[i] = '\0';
								break;
							default:
								cout << ch;
								nombre[i] = ch;
								i++;
						}
					}while(ch != '\r');

					cout << "Introduzca la direccion del cliente: ";
					i = 0;
					do{
						ch = getch();
						switch(ch){
							case '\b':
								if(i > 0){
									cout << "\b \b";
									i--;
								}
								break;
							case '\r':
								cout << '\n';
								direccion[i] = '\0';
								break;
							default:
								cout << ch;
								direccion[i] = ch;
								i++;
						}
					}while(ch != '\r');

					Datos[nClientes].ActualizarCliente(nombre, direccion);
					nClientes++;

					cout << "Cliente creado correctamente.\n\n";
				}else{
					cout << "Error, limite de clietnes almacenados alcanzado.\n\n";
				}
				break;
			case 2:
				cout << "Introduzca el nombre del cliente: ";
				i = 0;
				do{
					ch = getch();
					switch(ch){
						case '\b':
							if(i > 0){
								cout << "\b \b";
								i--;
							}
							break;
						case '\r':
							cout << '\n';
							nombre[i] = '\0';
							break;
						default:
							cout << ch;
							nombre[i] = ch;
							i++;
					}
				}while(ch != '\r');

				pos = BuscarCliente(Datos, nClientes, nombre);
				if(pos == -1){
					cout << "Error, cliente no encontrado.\n\n";
				}else{
					cout << "Introduzca la direccion del cliente: ";
					i = 0;
					do{
						ch = getch();
						switch(ch){
							case '\b':
								if(i > 0){
									cout << "\b \b";
									i--;
								}
								break;
							case '\r':
								cout << '\n';
								direccion[i] = '\0';
								break;
							default:
								cout << ch;
								direccion[i] = ch;
								i++;
						}
					}while(ch != '\r');

					Datos[pos].ActualizarCliente(nombre, direccion);

					cout << "Cliente actualizado correctamente.\n\n";
				}
				break;
			case 3:
				cout << "Introduzca el nombre del cliente: ";
				i = 0;
				do{
					ch = getch();
					switch(ch){
						case '\b':
							if(i > 0){
								cout << "\b \b";
								i--;
							}
							break;
						case '\r':
							cout << '\n';
							nombre[i] = '\0';
							break;
						default:
							cout << ch;
							nombre[i] = ch;
							i++;
					}
				}while(ch != '\r');

				pos = BuscarCliente(Datos, nClientes, nombre);
				if(pos == -1){
					cout << "Error, cliente no encontrado.\n\n";
				}else{
					Datos[pos].Mostrar('t');
				}
				break;
			case 4:
				for(int i = 0; i < nClientes; i++){
					Datos[i].Mostrar('t');
				}
				break;
			case 5:
				cout << "Introduzca el nombre del cliente: ";
				i = 0;
				do{
					ch = getch();
					switch(ch){
						case '\b':
							if(i > 0){
								cout << "\b \b";
								i--;
							}
							break;
						case '\r':
							cout << '\n';
							nombre[i] = '\0';
							break;
						default:
							cout << ch;
							nombre[i] = ch;
							i++;
					}
				}while(ch != '\r');

				pos = BuscarCliente(Datos, nClientes, nombre);
				if(pos == -1){
					cout << "Error, cliente no encontrado.\n\n";
				}else{

					int supos = pos;
					bool submenu = true;
					int numero;
					float saldo;
					Cuenta cuenta;
					int nCuentas = Datos[pos].DameNoCuentas();

					do{
						ch = MenuCuentas();
						system("cls");
						switch(ch){
							case 1:
								if(nCuentas < MAX_CUENTAS){
									cout << "Introduzca el numero de cuenta: ";
									cin >> numero;
									if(Datos[supos].BuscarCuenta(numero) == -1){
										cout << "Introduzca el saldo de la cuenta: ";
										cin >> saldo;
										Datos[supos].CrearCuenta(Cuenta(numero, saldo));
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
									cout << "No se han encontrado cuentas guardadas. \n\n";
								}else{
									for(int i = 0; i < nCuentas; i++){
										cuenta = Datos[supos].DameCuenta(i);
										cout << "Numero: " << cuenta.DameNoCuenta() << "\n";
										cout << "Saldo: " << cuenta.DameSaldo() << "\n";
										cout << "Estado: " << (cuenta.EstaBloqueada()?"Bloqueada":"No bloqueada") << "\n\n";
									}
								}
								break;
							case 3:
								cout << "Introduzca el numero de cuenta que desea eliminar: ";
								cin >> numero;

								pos = Datos[supos].BuscarCuenta(numero);
								if(pos == -1){
									cout << "Error, no existe ningunacuenta guardada con el numero introducido.\n\n";
								}else{
									nCuentas--;
									for(int i = pos; i < nCuentas; i++){
										Datos[supos].ActualizarCuenta(Datos[supos].DameCuenta(i+1));
									}
									cout << "Cuenta eliminada con exito.\n\n";
								}
								break;
							case 4:
								cout << "Introduzca el numero de cuenta que desea modificar: ";
								cin >> numero;

								pos = Datos[supos].BuscarCuenta(numero);
								if(pos == -1){
									cout << "Error, no existe ningunacuenta guardada con el numero introducido.\n\n";
								}else{
									cout << "Introduzca el nuevo saldo: ";
									cin >> saldo;
									cuenta = Datos[supos].DameCuenta(pos);
									if(cuenta.ActualizarSaldo(saldo)){
										Datos[supos].ActualizarCuenta(cuenta);
										cout << "Cuenta modificada con exito.\n\n";
									}else{
										cout << "Cuenta bloqueada. La operacion no pudo ser realizada.\n\n";
									}
								}
								break;
							case 5:
								cout << "Introduzca el numero de cuenta que desea modificar: ";
								cin >> numero;

								pos = Datos[supos].BuscarCuenta(numero);
								if(pos == -1){
									cout << "Error, no existe ningunacuenta guardada con el numero introducido.\n\n";
								}else{
									cout << "Introduzca 's' para bloquear la cuenta o 'n' para no bloquearla: ";
									cin >> ch;
									cuenta = Datos[supos].DameCuenta(pos);
									if(ch == 's'){
										cuenta.ActualizarBloqueo(true);
										cout << "Cuenta bloqueada con exito.\n\n";
										Datos[supos].ActualizarCuenta(cuenta);
									}else if(ch == 'n'){
										cuenta.ActualizarBloqueo(false);
										cout << "Cuenta desbloqueada con exito.\n\n";
										Datos[supos].ActualizarCuenta(cuenta);
									}else{
										cout << "Error al introducir el caracter requerido.\n\n";
									}
								}
								break;
							case 6:
								submenu = false;
								break;
						}
						if(submenu){
							cout << "Pulse una tecla para regresar al menu.";
							cin.ignore();
							cin.ignore();
							system("cls");
						}
					}while(submenu);
					system("cls");
				}
				break;
			case 6:
				continuar = false;
				break;
		}
		if(continuar and ch != 6){
			cout << "\nPulse una tecla para regresar al menu.";
			cin.ignore();
			cin.ignore();
			system("cls");
		}
	}while(continuar);


	return 0;
}
