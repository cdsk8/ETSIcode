#include <iostream>
#include <cstdlib>
#include <conio.h>
#include <cstring>

using namespace std;

class TicTacToe{
	private:
		char Tablero[3][3];
	public:
		TicTacToe();
		void LimpiarTablero();
		void Pintar();
		bool PonerFicha(char ficha, int fila, int columna);
		bool ComprobarFila(char ficha, int fila);
		bool ComprobarColumna(char ficha, int columna);
		bool ComprobarDiagonal(char ficha, int fila, int columna);
		bool TableroCompleto();
};

TicTacToe::TicTacToe(){
	LimpiarTablero();
}

void TicTacToe::LimpiarTablero(){
	for(int i = 0; i < 3; i++)
		for(int j = 0; j < 3; j++)
			Tablero[i][j] = ' ';
}

void TicTacToe::Pintar(){
	system("cls");
	cout << char(201)<<char(205)<<char(203)<<char(205)<<char(203)<<char(205)<<char(187)<<"\n";
	for(int i = 0; i < 3; i++){
        cout << char(186);
		for(int j = 0; j < 3; j++){
			cout << Tablero[i][j];
			if(j != 2)
				cout << char(186);
		}
		cout << char(186) << "\n";
		if(i != 2)
			cout << char(204)<<char(205)<<char(206)<<char(205)<<char(206)<<char(205)<<char(185)<<"\n";
	}
	cout << char(200)<<char(205)<<char(202)<<char(205)<<char(202)<<char(205)<<char(188)<<"\n";
}

bool TicTacToe::PonerFicha(char ficha, int fila, int columna){
	if(Tablero[fila][columna] == ' '){
		Tablero[fila][columna] = ficha;
		return true;
	}
	return false;
}

bool TicTacToe::ComprobarFila(char ficha, int fila){
	return Tablero[fila][0] == ficha && Tablero[fila][1] == ficha && Tablero[fila][2] == ficha;
}
bool TicTacToe::ComprobarColumna(char ficha, int columna){
	return Tablero[0][columna] == ficha && Tablero[1][columna] == ficha & Tablero[2][columna] == ficha;
}
bool TicTacToe::ComprobarDiagonal(char ficha, int fila, int columna){
    bool diagonal;
	if(fila == 1 && columna == 1)
		diagonal = (Tablero[0][0] == ficha && Tablero[1][1] == ficha && Tablero[2][2] == ficha) || (Tablero[2][0] == ficha && Tablero[1][1] == ficha && Tablero[0][2] == ficha);
	else if((fila == 0 && columna == 0) || (fila == 2 && columna == 2))
		diagonal = Tablero[0][0] == ficha && Tablero[1][1] == ficha && Tablero[2][2] == ficha;
	else if((fila == 2 && columna == 0) || (fila == 0 && columna == 2))
		diagonal = Tablero[2][0] == ficha && Tablero[1][1] == ficha && Tablero[0][2] == ficha;
	else
		diagonal = false;
    return diagonal;
}
bool TicTacToe::TableroCompleto(){
	bool completo = true;
	int i, j;

	i = 0;
	while(i < 3 && completo){
        j = 0;
        while(j < 3 && completo){
            if(Tablero[i][j] == ' ')
                completo = false;
            j++;
        }
		i++;
	}

	return completo;
}


void pedirPosicion(char ficha, int &fila, int &columna){
	bool error;

	cout << "Jugador " << ficha << ", es su turno.\n";

	do{
		error = false;
		switch(getche()){
			case '7':
				fila = 0;
				columna = 0;
				break;
			case '8':
				fila = 0;
				columna = 1;
				break;
			case '9':
				fila = 0;
				columna = 2;
				break;
			case '4':
				fila = 1;
				columna = 0;
				break;
			case '5':
				fila = 1;
				columna = 1;
				break;
			case '6':
				fila = 1;
				columna = 2;
				break;
			case '1':
				fila = 2;
				columna = 0;
				break;
			case '2':
				fila = 2;
				columna = 1;
				break;
			case '3':
				fila = 2;
				columna = 2;
				break;
			default:
				cout << "Error, use el pad numero para senalar la posicion.\n";
				error = true;
				break;
		}
	}while(error);

	cout << "\n";
}

int main(void){
	TicTacToe t;
	char respuesta[3] = "si";
	bool error, continuar = true;
	char turno = 'X';
	int fila, columna;

	while(continuar){
		do{
			t.Pintar();
			pedirPosicion(turno, fila, columna);

			error = !t.PonerFicha(turno, fila, columna);
		}while(error);

		if(t.ComprobarColumna(turno, columna) or t.ComprobarFila(turno, fila) or t.ComprobarDiagonal(turno, fila, columna)){
			t.Pintar();
			cout << "El jugador " << turno << " ha ganado la partida.\n\nJugar otra vez? (si, no) ";
			cin >> respuesta;
				continuar = false;
		}else{
			if(t.TableroCompleto()){
				t.Pintar();
				cout << "Empate. El tablero esta lleno.\n\nJugar otra vez? (si, no) ";
				cin >> respuesta;
				continuar = false;
			}else{
			    turno = turno=='X'?'O':'X';
			}
		}
		if(!continuar && strcmp(respuesta,"si") == 0){
            t.LimpiarTablero();
            turno = 'X';
            continuar = true;
        }
	}

	return 0;
}
