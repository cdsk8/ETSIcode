#include <iostream>

using namespace std;

class Sumar{
	private:
		int n;
	public:
		void informacion();
		int suma();
};

void Sumar::informacion(){
	cout << "Introduzca el numero hasta el que quieres sumar todos los no primos: ";
	cin >> n;
	cout << "\n";
}

int Sumar::suma(){
	int suma;
	bool primo;
	
	for(int i = 0; i<= n; i++){
		primo = true;
	
		int j = 2;
		do{
			if(i != j and i%j == 0)
				primo = false;
			j++;
		}while(j <= i/2 and primo);
		
		if(!primo)
			suma += i;
	}
	
	return suma;
}

int main(){
	Sumar s;
	
	s.informacion();
	cout << "La suma de los numeros enteros hasta el que has introducido, sin contar los primos, es " << s.suma() << ".\n\n";
	
	system("pause");
	return 0;
}
