#include <iostream>
#include <cstdlib>

using namespace std;

int main(){
	double nota1, nota2, nota3, nota4, nota5, media;

	cout << "Introduzca la primera nota: ";
	cin >> nota1;
	system("cls");
	cout << "Introduzca la segunda nota: ";
	cin >> nota2;
	system("cls");
	cout << "Introduzca la tercera nota: ";
	cin >> nota3;
	system("cls");
	cout << "Introduzca la cuarta nota: ";
	cin >> nota4;
	system("cls");
	cout << "Introduzca la quinta nota: ";
	cin >> nota5;
	system("cls");

	media = (nota1+nota2+nota3+nota4+nota5)/5;

	cout << "La media de las cinco notas es " << media << "\n\n";

	system("pause");
	return 0;
}
