#include <iostream>

using namespace std;

class TablaMultiplicar{
	private:
		int Tabla;
	public:
		void PedirNoTabla();
		void MostrarTabla();
};

void TablaMultiplicar::PedirNoTabla(){
	cout << "Introduzca la tabla que quiere mostar: ";
	cin >> Tabla;
}

void TablaMultiplicar::MostrarTabla(){
	for(int i = 0; i <= 10; i++){
		cout << Tabla << " x " << i << " = " << (Tabla*i) << "\n";
	}
	cout << "\n";
}

int main(){
	TablaMultiplicar tm;
	
	tm.PedirNoTabla();
	tm.MostrarTabla();
	
	system("pause");
	return 0;
}
