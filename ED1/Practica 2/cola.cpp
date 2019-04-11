#include "cola.h"
#include <iostream>

/*
    -------------------------------------------
    |     |  1  |  1  |  1  |  1  |  1  |     |
    -------------------------------------------
          ^Inicio                 ^Fin
*/

Cola::Cola(){
    tabla = new Elemento[SALTO];
    inicio = 0;
    fin = -1;
    tamano = SALTO;
}
Cola::~Cola(){
    delete[] tabla;
}

void Cola::encolar(Elemento e){
    tabla[++fin] = e;
    optimizar();
}
void Cola::desencolar(){
    if(inicio <= fin){
        inicio++;
        optimizar();
    }
}
int Cola::longitud(){
    return fin-inicio+1;
}
Elemento Cola::primero(){
    return tabla[inicio];
}
bool Cola::esVacia(){
    return fin-inicio == -1;
}




void Cola::dibujar(){
    std::cout << "Tamano: " << tamano << "  Inicio: "<< inicio << "  Fin: "<<fin<<"\n";
    for(int i = 0; i < tamano; i++)
        std::cout << "  "<<(tabla[i].prioridad>0&&tabla[i].prioridad<10?tabla[i].comando:"X")<<"  |";
}

void Cola::optimizar(){
    if(inicio > SALTO){                 //Hay espacio desaprobechado
        escalarTabla(-SALTO);
    }else if(tamano-fin-1 < SALTO/2){   //Queda poco espacio
        escalarTabla(SALTO);
    }
}
void Cola::escalarTabla(int cantidad){
    tamano += cantidad;
    Elemento *tablaTMP = new Elemento[tamano];
    int diff = inicio;
    int pos = inicio;
    while(pos <= fin){   //Al ampliar tambien se desfragmenta
        tablaTMP[pos-diff] = tabla[pos];
        pos++;
        std::cout << "COPIO: "<<pos<<"\n";
    }
    fin -= diff;
    inicio -= diff;
    delete[] tabla;
    tabla = tablaTMP;
}
