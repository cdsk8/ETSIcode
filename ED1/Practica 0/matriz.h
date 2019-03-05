#ifndef _MATRIZ_H_
#define _MATRIZ_H_

#include "quebrado.h"
#define MAXIMO 20
#define M 5

typedef quebrado tipoelemento;

class matriz {
private:
 tipoelemento celda[M][M];
 int fila,col;
public:
 matriz(int f=0, int c=0);
 int getfila() { return fila; }
 int getcol() { return col; }
 bool operator==(matriz m);
 matriz operator*(matriz m);
 matriz operator+(matriz m);
 matriz operator-(matriz m);
 matriz operator-();
 void mostrar();
 void cargar();
 void cargar(char cad[]);
};



#endif
