/* 
 * La clase Test contiene los metodos para:
 * 1. Comprobar que el/los algoritmos funcionan adecuadamente.
 * 2. Calcular la eficiencia para los casos de un método de búsqueda,
 *    permitiendo guardar los datos e imprimir la gráfica correspondiente 
 * 3. Comparar el coste temporal de los casos de búsqueda
 *    secuencial, permitiendo guardar los datos e imprimir la 
 *    gráfica correspondiente.
 */
#include "Test.h"
//#include "Constantes.h"
#include "ConjuntoInt.h"
#include "Mtime.h"
#include <string>
#include <fstream>
#include <iomanip>
#include <iostream>
using namespace std;

const int SECUENCIALPEOR = 0, SECUENCIALMEDIO = 1, SECUENCIALMEJOR = 2;
const int tallaIni = 1000,
tallaFin = 10000,
incTalla = 1000;

TestAlgoritmo::TestAlgoritmo()
{
	nombreAlgoritmoCaso.push_back("SecuencialPeor");
	nombreAlgoritmoCaso.push_back("SecuencialMedio");
	nombreAlgoritmoCaso.push_back("SecuencialMejor");
} 
TestAlgoritmo::~TestAlgoritmo()
{
}

/*
	* Calcula el coste TEORICO de los casos de un metodo de búsqueda,
	* Permite las opciones de crear el fichero de datos y la gráfica correspondiente.
    * param metodo: caso de búsqueda a estudiar.
    */
void TestAlgoritmo::costeTeorico(int numerocaso)
	{
	ofstream f(nombreAlgoritmoCaso[numerocaso]+"Teorico.dat");
	system("cls"); 
	cout<<endl<<"Busqueda " << nombreAlgoritmoCaso[numerocaso]+" Teorico";
	cout<<"Tiempos de ejecucion "<<endl<<endl;
	cout<<endl;;
	cout<<"\tTalla\t\tTiempo (oe)"<<endl<<endl;
	double tiempo=0;
	for (int talla = tallaIni; talla <= tallaFin; talla += incTalla) 
		{
			
			switch (numerocaso){
			case SECUENCIALPEOR: /*Caso peor (T(n)= 7n+9)*/
			{
	    		  tiempo = 7*talla+9;
			}		
			break;
			case SECUENCIALMEDIO:/*Caso medio (T(n)= (7/2)n+9)*/
			{
					tiempo = ((7/2.0)*talla)+9;
			}
			break;
		case SECUENCIALMEJOR:/*Caso mejor (T(n)= 9)*/
			{
				tiempo = 9;
			}
			break;
			}
			f<<talla<<"\t"<< tiempo<<endl;
			cout<<"\t"<<talla<<"\t\t"<<setw(10)<<setprecision(2)<<(double)tiempo<<" \t\t" <<endl;
			cout<<endl;
	}
	f.close();
	cout <<endl<<"Datos guardados en el fichero "<<nombreAlgoritmoCaso[numerocaso]<<"Teorico.dat "<<endl;

		/* Generar grafica */
		char opc;
		cout<<endl<<"Generar grafica de resultados? (s/n): ";
		cin>>opc;
		switch (opc){
		case 's':
		case 'S':{
			int orden;
			switch (numerocaso)
			{
			case SECUENCIALMEJOR:
				{
					/* Ejecutar el fichero por lotes (comandos)*/
			system("start CmdMejorTeorico.gpl"); system("cls");
			cout <<endl<<"Grafica guardada en el fichero "<<nombreAlgoritmoCaso[numerocaso]+"Teorico"<<".pdf"<<endl;
				}
				break;
			case SECUENCIALPEOR:
				{
					/* Ejecutar el fichero por lotes (comandos)*/
			system("start CmdPeorTeorico.gpl"); system("cls");
			cout <<endl<<"Grafica guardada en el fichero "<<nombreAlgoritmoCaso[numerocaso]+"Teorico"<<".pdf"<<endl;
				}
				break;
			case SECUENCIALMEDIO:
			{
				/* Ejecutar el fichero por lotes (comandos)*/
			system("start CmdMedioTeorico.gpl"); 
			system("cls");
				//system((gpl).c_str());
			cout <<endl<<"Grafica guardada en el fichero "<<nombreAlgoritmoCaso[numerocaso]+"Teorico"<<".pdf"<<endl;
				}
			break;
			default: {cout <<"Error caso "<<endl;}
			break;
			}
			default: {cout <<"Grafica no guardada en fichero "<<endl;}
			break;
						 }
		}
	cout<<endl;
	system("pause");
	system("cls");

	}
void TestAlgoritmo::compararTeorico(int metodo1, int metodo2, int metodo3) {

		//Graficas g;
	ofstream f(nombreAlgoritmoCaso[metodo1]+nombreAlgoritmoCaso[metodo2]+nombreAlgoritmoCaso[metodo3]+"Teorico.dat");
	system("cls"); 
	cout<<endl<<"Busqueda Secuencial" << " Teorico";
	cout<<". Tiempos de ejecucion "<<endl<<endl;
	cout<<endl;;
	cout<<"\tTalla\t\tTiempo (oe)"<<endl<<endl;
	double tiempoPeor=0;int tiempoMedio=0; int tiempoMejor=0;
	for (int talla = tallaIni; talla <= tallaFin; talla += incTalla) 
	{
		/* Caso peor (T(n)= 7n+9) */
		tiempoPeor = 7*talla+9;
		/*Caso medio (T(n)= (7/2)n+9)*/
		tiempoMedio = ((7/2.0)*talla)+9;
		/*Caso mejor (T(n)= 9)*/
		tiempoMejor = 9;
		/*escribir en el fichero*/
		f<<talla<<"\t"<< tiempoPeor<<"\t"<< tiempoMedio<<"\t"<< tiempoMejor<<endl;
		/*Visualizar en pantalla*/
		cout<<"\t"<<talla<<"\t\t"<<setw(10)<<setprecision(2)<<(double)tiempoPeor<<" \t"<<setw(10)<<setprecision(2)<<(double)tiempoMedio<<" \t"<<setw(10)<<setprecision(2)<<(double)tiempoMejor<<" \t\t" <<endl;
		cout<<endl;
	}
	f.close();
	cout <<endl<<"Datos guardados en el fichero "<<nombreAlgoritmoCaso[metodo1]+nombreAlgoritmoCaso[metodo2]+nombreAlgoritmoCaso[metodo3]<<"Teorico.dat "<<endl;
	/* Generar grafica */
		char opc;
		cout<<endl<<"Generar grafica de resultados? (s/n): ";
		cin>>opc;
		switch (opc){
		case 's':
		case 'S':{
			/* Ejecutar el fichero por lotes (comandos)*/
			system("start CmdCompararTeorico.gpl"); system("cls");
			//system((gpl).c_str());
			cout <<endl<<"Grafica guardada en el fichero "<<nombreAlgoritmoCaso[metodo1]+nombreAlgoritmoCaso[metodo2]+nombreAlgoritmoCaso[metodo3]+"Teorico"<<".pdf"<<endl;
						 }
						 break;
		default: cout <<"Grafica no guardada en fichero "<<endl;
			break;
		}
		cout<<endl;
		system("pause");
		system("cls");
}
void TestAlgoritmo::comprobarAlgoritmo() {
	int talla, clave;
	cout << "Introduzca la talla: ";
	cin >> talla;

	ConjuntoInt conjunto(talla);
	conjunto.GeneraVector(talla);
	cout << "\nConjunto de datos:\n";
	conjunto.escribe();

	cout << "\nIntroduzca la clave a buscar: ";
	cin >> clave;

	cout << "\nLa posicion de " << clave << " es " << conjunto.busquedaSecuencial(clave);

	cout << "\n\n\n\n\n\tPulse una tecla para regresar al menu.";
	cin.ignore();
	cin.get();
}