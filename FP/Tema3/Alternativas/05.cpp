#include <iostream>
#include <cmath>

using namespace std;

class Fecha{
	private:
		int agno;
	public:
		bool bisiesto();
		void leer();
};

bool Fecha::bisiesto(){
	return agno%400 == 0 or (agno%4 == 0 and agno%100 != 0);
}

void Fecha::leer(){
	cout << "Introduzca un ano: ";
	cin >> agno;
	cout << "\n";
}

int main(){
	Fecha f;
	
	f.leer();
	cout << "El año introducido " << (f.bisiesto()?"si":"no") << " es bisiesto.\n\n";
	
	system("pause");
	return 0;
}
