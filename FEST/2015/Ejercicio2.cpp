#include <iostream>
#include <stdlib.h>

const int objetivo = 20;
double opciones = 0;

void rec(int n);

int main(void){
    rec(0);
    std::cout << opciones << "\n";
}

void rec(int n){
    if(n == objetivo){
        opciones++;
    }else if(n < objetivo){
        rec(n+1);
        rec(n+2);
    }
}
