#include <iostream>
#include <cstdlib>
#include <string.h>
#include <conio.h>
#include <stdio.h>

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

	while(i < NoCuentas && pos == -1){
		i++;
		if(Cuentas[i].DameNoCuenta() == pNoCuenta)
			pos = i;
	}

	return pos;
}
bool Cliente::CrearCuenta(Cuenta pCu){
	if(NoCuentas < MAX_CUENTAS && BuscarCuenta(pCu.DameNoCuenta()) == -1){
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
		for(int i = pos; i < NoCuentas; i++)
			Cuentas[i] = Cuentas[i+1];
        NoCuentas--;
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
	if(Campo == 's' || Campo == 't'){
		cout <<"\t\t\t\t  "<< "Nombre: " << Nombre << "\n";
		cout <<"\t\t\t\t  "<< "Direccion: " << Direccion << "\n\n";
	}
	if(Campo == 'c' || Campo == 't'){
		for(int i = 0; i < NoCuentas; i++){
			cout <<"\t\t\t\t  "<< "Numero: " << Cuentas[i].DameNoCuenta() << "\n";
			cout <<"\t\t\t\t  "<< "Saldo: " << Cuentas[i].DameSaldo() << "\n";
			cout <<"\t\t\t\t  "<< "Estado: " << (Cuentas[i].EstaBloqueada()?"Bloqueada":"No bloqueada") << "\n\n";
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
    cout << "\n\n\t\t"<<char(201); for(int i = 0; i < 42; i++) cout << char(205); cout << char(187)<<"\n";
    cout << "\t\t"<< char(186)<<"  ADMINISTRADOR DE BANCO           _|[]|X " <<char(186)<<"\n";
    cout << "\t\t"<<char(204); for(int i = 0; i < 42; i++) cout << char(205); cout << char(185)<<"\n";
    cout << "\t\t"<<char(186)<<char(201); for(int i = 0; i < 40; i++) cout<< char(205); cout << char(187)<<char(186)<<"\n";
    cout << "\t\t"<< char(186)<<char(186)<<"         Menu Gestion de Cuentas        " <<char(186)<<char(186)<<"\n";
    cout << "\t\t"<< char(186)<<char(204); for(int i = 0; i < 40; i++) cout << char(205); cout << char(185)<<char(186)<<"\n";
    cout << "\t\t"<< char(186)<<char(186)<<"  1. Anadir una cuenta al cliente       " <<char(186)<<char(186)<<"\n";
    cout << "\t\t"<< char(186)<<char(186)<<"  2. Mostrar las cuetnas del cliente    "<<char(186)<<char(186)<<"\n";
    cout << "\t\t"<< char(186)<<char(186)<<"  3. Borrar una cuenta del cliente      "<<char(186)<<char(186)<<"\n";
    cout << "\t\t"<< char(186)<<char(186)<<"  4. Modificar saldo de una cuenta      "<<char(186)<<char(186)<<"\n";
    cout << "\t\t"<< char(186)<<char(186)<<"  5. Modificar estado de una cuenta     "<<char(186)<<char(186)<<"\n";
    cout << "\t\t"<< char(186)<<char(186)<<"  6. Salir                              "<<char(186)<<char(186)<<"\n";
    cout << "\t\t"<<char(186)<<char(200); for(int i = 0; i < 40; i++) cout<< char(205); cout << char(188)<<char(186)<<"\n";
    cout << "\t\t"<<char(200); for(int i = 0; i < 42; i++) cout << char(205); cout << char(188)<<"\n";
    cout << "\n\t\t"<<"	   Elige opcion: ";
	cin >> respuesta;
	return respuesta;
}
int Menu(){
	int respuesta;
    cout << "\n\n\t\t"<<char(201); for(int i = 0; i < 42; i++) cout << char(205); cout << char(187)<<"\n";
    cout << "\t\t"<< char(186)<<"  ADMINISTRADOR DE BANCO           _|[]|X " <<char(186)<<"\n";
    cout << "\t\t"<<char(204); for(int i = 0; i < 42; i++) cout << char(205); cout << char(185)<<"\n";
    cout << "\t\t"<<char(186)<<char(201); for(int i = 0; i < 40; i++) cout<< char(205); cout << char(187)<<char(186)<<"\n";
    cout << "\t\t"<< char(186)<<char(186)<<"             Menu Principal             " <<char(186)<<char(186)<<"\n";
    cout << "\t\t"<< char(186)<<char(204); for(int i = 0; i < 40; i++) cout << char(205); cout << char(185)<<char(186)<<"\n";
    cout << "\t\t"<< char(186)<<char(186)<<"  1. Anadir un cliente                  " <<char(186)<<char(186)<<"\n";
    cout << "\t\t"<< char(186)<<char(186)<<"  2. Actualizar direccion del cliente   "<<char(186)<<char(186)<<"\n";
    cout << "\t\t"<< char(186)<<char(186)<<"  3. Mostrar un cliente                 "<<char(186)<<char(186)<<"\n";
    cout << "\t\t"<< char(186)<<char(186)<<"  4. Mostrar todos los clientes         "<<char(186)<<char(186)<<"\n";
    cout << "\t\t"<< char(186)<<char(186)<<"  5. Submenu Gestion de Cuentas         "<<char(186)<<char(186)<<"\n";
    cout << "\t\t"<< char(186)<<char(186)<<"  6. Regresar                           "<<char(186)<<char(186)<<"\n";
    cout << "\t\t"<<char(186)<<char(200); for(int i = 0; i < 40; i++) cout<< char(205); cout << char(188)<<char(186)<<"\n";
    cout << "\t\t"<<char(200); for(int i = 0; i < 42; i++) cout << char(205); cout << char(188)<<"\n";
    cout << "\n\t\t"<<"	   Elige opcion: ";

	cin >> respuesta;
	return respuesta;
}


int main(void){
	Cliente Datos[MAX_CLIENTES];
	int nClientes = 0;

	char ch;
	bool continuar = true, error;
	Cadena nombre, direccion;
	int i, pos;


	do{
		ch = Menu();
		system("cls");
		switch(ch){
			case 1:                                                //Añadir un cliente
                cout << "\n\n\t\t"<<char(201); for(int i = 0; i < 60; i++) cout << char(205); cout << char(187)<<"\n";
                cout << "\t\t"<< char(186)<<"                       Agregar un cliente                   " <<char(186)<<"\n";
                cout << "\t\t"<< char(200); for(int i = 0; i < 60; i++) cout << char(205); cout << char(188)<<"\n\n";

				if(nClientes < MAX_CLIENTES){
					cout <<"\t\t  "<< "Introduzca el nombre del cliente: ";
					do{
                        cin.ignore();
                        gets(nombre);
                        error = (BuscarCliente(Datos,nClientes,nombre) != -1);
                        if(error)
                            cout <<"\t\t  "<< "Ya existe un cliente con ese nombre."<<"\t\t  "<<"Introduzca otro nombre: ";
					}while(error);

					cout <<"\t\t  "<< "Introduzca la direccion del cliente: ";
                    gets(direccion);

					Datos[nClientes].ActualizarCliente(nombre, direccion);
					nClientes++;

					cout <<"\t\t  "<< "Cliente creado correctamente.\n\n";
				}else{
					cout <<"\t\t  "<< "Error, limite de clietnes almacenados alcanzado.\n\n";
				}
				break;
			case 2:                                                //Cambiar la direccion de un cliente
                cout << "\n\n\t\t"<<char(201); for(int i = 0; i < 60; i++) cout << char(205); cout << char(187)<<"\n";
                cout << "\t\t"<< char(186)<<"             Cambiar la direccion de un cliente             " <<char(186)<<"\n";
                cout << "\t\t"<< char(200); for(int i = 0; i < 60; i++) cout << char(205); cout << char(188)<<"\n\n";

				cout <<"\t\t  "<< "Introduzca el nombre del cliente: ";
				cin.ignore();
				gets(nombre);

				pos = BuscarCliente(Datos, nClientes, nombre);
				if(pos == -1){
					cout <<"\t\t  "<< "Error, cliente no encontrado.\n\n";
				}else{
					cout <<"\t\t  "<< "Introduzca la direccion del cliente: ";
					gets(direccion);

					Datos[pos].ActualizarCliente(nombre, direccion);

					cout <<"\t\t  "<< "Cliente actualizado correctamente.\n\n";
				}
				break;
			case 3:                                                //Mostrar un cliente
                cout << "\n\n\t\t"<<char(201); for(int i = 0; i < 60; i++) cout << char(205); cout << char(187)<<"\n";
                cout << "\t\t"<< char(186)<<"                      Mostrar un cliente                    " <<char(186)<<"\n";
                cout << "\t\t"<< char(200); for(int i = 0; i < 60; i++) cout << char(205); cout << char(188)<<"\n\n";

				cout <<"\t\t  "<< "Introduzca el nombre del cliente: ";
				cin.ignore();
				gets(nombre);

				pos = BuscarCliente(Datos, nClientes, nombre);
				if(pos == -1){
					cout <<"\t\t  "<< "Error, cliente no encontrado.\n\n";
				}else{
					Datos[pos].Mostrar('t');
				}
				break;
			case 4:                                                //Mostrar todos los clientes
                cout << "\n\n\t\t"<<char(201); for(int i = 0; i < 60; i++) cout << char(205); cout << char(187)<<"\n";
                cout << "\t\t"<< char(186)<<"                  Mostrar todos los clientes                " <<char(186)<<"\n";
                cout << "\t\t"<< char(200); for(int i = 0; i < 60; i++) cout << char(205); cout << char(188)<<"\n\n";

				for(int i = 0; i < nClientes; i++){
					Datos[i].Mostrar('s');
				}
				cin.ignore();
				break;
			case 5:                                                //Submenu, gestionar cuentas
                cout << "\n\n\t\t"<<char(201); for(int i = 0; i < 60; i++) cout << char(205); cout << char(187)<<"\n";
                cout << "\t\t"<< char(186)<<"            Acceder al submenu: Gestion de cuentas          " <<char(186)<<"\n";
                cout << "\t\t"<< char(200); for(int i = 0; i < 60; i++) cout << char(205); cout << char(188)<<"\n\n";

				cout <<"\t\t  "<< "Introduzca el nombre del cliente: ";
				cin.ignore();
				gets(nombre);

				pos = BuscarCliente(Datos, nClientes, nombre);
				if(pos == -1){
					cout <<"\t\t  "<< "Error, cliente no encontrado.\n\n";
				}else{

					int supos = pos;
					bool submenu = true;
					int numero;
					float saldo;
					Cuenta cuenta;

					do{
						ch = MenuCuentas();
						system("cls");
						switch(ch){
							case 1:                                                //Crear una cuenta
                                cout << "\n\n\t\t"<<char(201); for(int i = 0; i < 60; i++) cout << char(205); cout << char(187)<<"\n";
                                cout << "\t\t"<< char(186)<<"                        Crear una cuenta                    " <<char(186)<<"\n";
                                cout << "\t\t"<< char(200); for(int i = 0; i < 60; i++) cout << char(205); cout << char(188)<<"\n\n";

                                cout <<"\t\t  "<< "Introduzca el numero de cuenta: ";
                                cin >> numero;
                                cout <<"\t\t  "<< "Introduzca el saldo de la cuenta: ";
                                cin >> saldo;

                                if(Datos[supos].CrearCuenta(Cuenta(numero, saldo)))
                                    cout <<"\n\t\t  "<< "Cuenta creada correctamente.\n\n";
                                else
                                    cout <<"\n\t\t  "<< "Error, la cuenta no pudo ser creada";
								break;
							case 2:                                                //Mostrar las cuentas
                                cout << "\n\n\t\t"<<char(201); for(int i = 0; i < 60; i++) cout << char(205); cout << char(187)<<"\n";
                                cout << "\t\t"<< char(186)<<"                   Mostrar todas las cuentas                " <<char(186)<<"\n";
                                cout << "\t\t"<< char(200); for(int i = 0; i < 60; i++) cout << char(205); cout << char(188)<<"\n\n";

								Datos[supos].Mostrar('c');
								break;
							case 3:                                                //Borrar una cuenta
                                cout << "\n\n\t\t"<<char(201); for(int i = 0; i < 60; i++) cout << char(205); cout << char(187)<<"\n";
                                cout << "\t\t"<< char(186)<<"                       Borrar una cuenta                    " <<char(186)<<"\n";
                                cout << "\t\t"<< char(200); for(int i = 0; i < 60; i++) cout << char(205); cout << char(188)<<"\n\n";

								cout <<"\t\t  "<< "Introduzca el numero de cuenta que desea eliminar: ";
								cin >> numero;

								if(Datos[supos].BorrarCuenta(numero))
                                    cout << "Cuenta eliminada con exito.\n\n";
                                else
                                    cout <<"\t\t  "<< "Error, no existe ningunacuenta guardada con el numero introducido.\n\n";
								break;
							case 4:                                                //Modificar el saldo
                                cout << "\n\n\t\t"<<char(201); for(int i = 0; i < 60; i++) cout << char(205); cout << char(187)<<"\n";
                                cout << "\t\t"<< char(186)<<"              Modificar el saldo de una cuenta              " <<char(186)<<"\n";
                                cout << "\t\t"<< char(200); for(int i = 0; i < 60; i++) cout << char(205); cout << char(188)<<"\n\n";

								cout <<"\t\t  "<< "Introduzca el numero de cuenta que desea modificar: ";
								cin >> numero;

								pos = Datos[supos].BuscarCuenta(numero);
								if(pos == -1){
									cout <<"\t\t  "<< "Error, no existe ningunacuenta guardada con el numero introducido.\n\n";
								}else{
									cout <<"\t\t  "<< "Introduzca el nuevo saldo: ";
									cin >> saldo;
									cuenta = Datos[supos].DameCuenta(pos);
									if(cuenta.ActualizarSaldo(saldo)){
										Datos[supos].ActualizarCuenta(cuenta);
										cout <<"\t\t  "<< "Cuenta modificada con exito.\n\n";
									}else{
										cout <<"\t\t  "<< "Cuenta bloqueada.\n"<<"\t\t  "<<"La operacion no pudo ser realizada.\n\n";
									}
								}
								break;
							case 5:                                                //Modificar el estado
                                cout << "\n\n\t\t"<<char(201); for(int i = 0; i < 60; i++) cout << char(205); cout << char(187)<<"\n";
                                cout << "\t\t"<< char(186)<<"              Modificar el estado de una cuenta             " <<char(186)<<"\n";
                                cout << "\t\t"<< char(200); for(int i = 0; i < 60; i++) cout << char(205); cout << char(188)<<"\n\n";

								cout <<"\t\t  "<< "Introduzca el numero de cuenta que desea modificar: ";
								cin >> numero;

								pos = Datos[supos].BuscarCuenta(numero);
								if(pos == -1){
									cout <<"\t\t  "<< "Error, no existe ningunacuenta guardada con el numero introducido.\n\n";
								}else{
									cout <<"\t\t  "<< "Introduzca 's' para bloquear la cuenta o 'n' para no bloquearla: ";
									cin >> ch;
									cuenta = Datos[supos].DameCuenta(pos);
									if(ch == 's'){
										cuenta.ActualizarBloqueo(true);
										cout <<"\t\t  "<< "Cuenta bloqueada con exito.\n\n";
										Datos[supos].ActualizarCuenta(cuenta);
									}else if(ch == 'n'){
										cuenta.ActualizarBloqueo(false);
										cout <<"\t\t  "<< "Cuenta desbloqueada con exito.\n\n";
										Datos[supos].ActualizarCuenta(cuenta);
									}else{
										cout <<"\t\t  "<< "Error al introducir el caracter requerido.\n\n";
									}
								}
								break;
							case 6:                                                //Salir
								submenu = false;
								break;
						}
						if(submenu){
							cout <<"\n\n\t"<< "Pulse una tecla para regresar al menu.";
							cin.ignore();
							cin.ignore();
							system("cls");
						}
					}while(submenu);
					system("cls");
				}
				break;
			case 6:                                                //Salir
				continuar = false;
				break;
		}
		if(continuar and ch != 6){
			cout <<"\n\n\t"<< "\nPulse una tecla para regresar al menu.";
			cin.ignore();
			system("cls");
		}
	}while(continuar);


	return 0;
}
