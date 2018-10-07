#include <iostream>

using namespace std;

int main(){
	int bytes;
	double kbytes;
	
	cout << "Ingrese una cantidad de bites: ";
	cin >> bytes;
	
	kbytes = (double) bytes/1024;
	
	cout << bytes << " bytes equivalen a " << kbytes << " Kbytes.\n\n";
	
	system("pause");
	return 0;
}
