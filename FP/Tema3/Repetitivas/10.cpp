#include <iostream>
#include <cstdlib>

using namespace std;

class Numero{
	private:
		int a, b;
	public:
		void informacion();
		int mcd();
};

void Numero::informacion(){
	cout << "Introduzca el primer numero: ";
	cin >> a;
	cout << "Introduzca el segundo numero: ";
	cin >> b;
	cout << "\n";
}

int Numero::mcd(){
	while(a != b){
		if(a > b)
			a -= b;
		else
			b -=a;
	}

	return a;
}

int main(){
	Numero n;

	n.informacion();
	cout << "El maximo comun divisor es " << n.mcd() << ".\n\n";

	system("pause");
	return 0;
}
