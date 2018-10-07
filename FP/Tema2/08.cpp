#include <iostream>

using namespace std;

int main(){
	int a, b;
		
	cout << "Ingrese el primer numero: ";
	cin >> a;
	cout << "Ingrese el segundo numero: ";
	cin >> b;
	
	cout << "\nSu suma: " << a + b;
	cout << "\nSu diferencia: " << a - b;
	cout << "\nSu producto: " << a * b;
	cout << "\nSu cociente: " << (double) a / b << "\n\n";
	
	system("pause");
	return 0;
}
