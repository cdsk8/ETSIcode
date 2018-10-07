#include <iostream>

using namespace std;

class TablaMultiplicar{
	private:
		int TablaIni, TablaFin;
	public:
		void PedirNoTabla();
		void MostrarTabla();
};

void TablaMultiplicar::PedirNoTabla(){
	cout << "Introduzca la primetra tabla que quiere mostrar: ";
	cin >> TablaIni;
	cout << "Introduzca la ultima tabla que quiere mostrar: ";
	cin >> TablaFin;
}

void TablaMultiplicar::MostrarTabla(){
	for(int i = 0; i <= 10; i++){
		for(int j = TablaIni; j<= TablaFin; j++){
			cout << j << " x " << i << " = " << (j*i) << "\t";
		}
		cout << "\n";
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
