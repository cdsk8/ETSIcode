#include <iostream>
#include <cstdlib>

using namespace std;

int main(void){
	int a, b;

	cout << "Introduzca el primer numero: ";
	cin >> a;
	cout << "Introduzca el segundo numero: ";
	cin >> b;

	if(a > b){
		cout << "\n" << a << " es mayor que " << b << ".\n\n";
	}else if(b > a){
		cout << "\n" << b << " es mayor que " << a << ".\n\n";
	}else{
		cout << "\n" << a << " es igual a " << b << ".\n\n";
	}

	system("pause");
	return 0;
}
