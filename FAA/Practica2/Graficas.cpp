/* 
 * Clase Graficas, contiene métodos crear los ficheros de comandos para dibujar 
 * la gráfica que corresponda. 
 */
#include "Graficas.h"
#include "Constantes.h"
#include <fstream>
#include <iostream>
using namespace std;

/*
 * Método generarGraficaMEDIO, genera el fichero de comandos para GNUPlot 
 * y dibuja la gráfica del caso medio de un método de
 * ordenación y su ajuste a la función correspondiente.  
 * param nombre_metodo: metodo de ordenacion.
 * param orden: Orden del metodo de ordenacion.
 */
void Graficas::generarGraficaMEDIO(string nombre_metodo,int orden)
{
	ofstream file("grafica.gpl");
	file << "#Archivo auto-generado, cortesia de B0vE\n";

	file << "set title \"Tiempo de ordenación por " << nombre_metodo << "\"\n"
		<< "set key top left vertical inside\n"
		<< "set grid\n"
		<< "set xlabel \"Talla (n)\"\n"
		<< "set ylabel \"Tiempo(ms)\"\n"
		<< "\n"
		<< "N(x) = ";

	for (int i = 0; i <= orden; i++) {
		file << char(97+i);
		for (int j = 0; j < orden - i; j++) {
			file << "*x";
		}
		file << ((i==orden)? "\n" : " + ");
	}
	file << "fit N(x) \"t" << nombre_metodo << ".dat\" using 1:2 via ";
	for (int i = 0; i <= orden; i++) {
		file << char(97 + i) << ((i==orden) ? "\n" : ",");
	}

	file << "plot N(x) title \"Aproximación\", \"t" << nombre_metodo << ".dat\" using 1:2 with lines title \"Resultado empírico\"\n"
		 << "\n"
		 << "set terminal pdf\n"
		 << "set output \"busqueda" << nombre_metodo << ".pdf\"\n"
		 << "replot\n"
		 << "#pause 5 \"Pulsa Enter para continuar...\"\n"
		 << "unset output";

	file.close();
}	

/*
 * Método generarGraficaCMP, genera el fichero de comandos para GNUPlot.
 * param nombre1: es el nombre del fichero de datos del primer método de ordenación 
 * param nombre2: es el nombre del fichero de datos del segundo método de ordenación 
 */
void  Graficas::generarGraficaCMP(string nombre1,string nombre2)
{
	ofstream file("grafica.gpl");
	file << "#Archivo auto-generado, cortesia de B0vE\n";

	file << "set title \"Comparativa " << nombre1 << " con " << nombre2 << "\"\n"
		<< "set key top left vertical inside\n"
		<< "set grid\n"
		<< "set xlabel \"Talla (n)\"\n"
		<< "set ylabel \"Tiempo(ms)\"\n"
		<< "\n";

	file << "plot \"t" << nombre1 << nombre2 << ".dat\" using 1:2 with lines title \""<< nombre1 <<"\", \"t"
		<< nombre1 << nombre2 << ".dat\" using 1:3 with lines title \"" << nombre2 << "\"\n"
		<< "\n"
		<< "set terminal pdf\n"
		<< "set output \"busqueda" << nombre1 << nombre2 << ".pdf\"\n"
		<< "replot\n"
		<< "#pause 5 \"Pulsa Enter para continuar...\"\n"
		<< "unset output";

	file.close();
}