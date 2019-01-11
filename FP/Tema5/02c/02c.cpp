#include <iostream>
#include <cstdlib>
#include <conio.h>
#include <cstring>
#include "cdrawer.h"

using namespace std;

const int posX[3] = {160,201,244};
const int posY[3] = {81,119,158};
char* fondoX = "sources/game/background_X.bmp";
char* fondoO = "sources/game/background_O.bmp";

class TicTacToe{
	private:
		char Tablero[3][3];
	public:
		TicTacToe();
		void LimpiarTablero();
		void Pintar(char turno, bool ganador);
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

void TicTacToe::Pintar(char turno, bool ganador){
	system("cls");
	dibujar(turno=='X'?fondoX:fondoO, 5, 5, 0, 6);

	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
                if(Tablero[i][j]=='X')
                    dibujar("sources/game/spr_sonic_head.bmp", posX[j], posY[i], RGB(255,0,255), 6);
                else if(Tablero[i][j]=='O')
                    dibujar("sources/game/spr_tails_head.bmp", posX[j]+1, posY[i]+1, RGB(255,0,255), 6);

		}
	}

	if(ganador){
        if(turno=='X'){
            dibujar("sources/game/spr_tails_static.bmp", 315, 145, RGB(255,0,255), 6,100, true);
            dibujarAnim("sources/game/spr_sonic_X.bmp", 25, 110, RGB(255,0,255), 16, 2, 75, 1);
        }else{
            dibujar("sources/game/spr_sonic_static.bmp", 25, 110, RGB(255,0,255), 6);
            dibujarAnim("sources/game/spr_tails_X.bmp", 315, 145, RGB(255,0,255), 19, 2, 75, 1, true);
        }
	}else{
        dibujar("sources/game/spr_sonic_static.bmp", 25, 110, RGB(255,0,255), 6);
        dibujar("sources/game/spr_tails_static.bmp", 315, 145, RGB(255,0,255), 6, 100, true);
	}
}

bool TicTacToe::PonerFicha(char ficha, int fila, int columna){
	if(Tablero[fila][columna] == ' '){
		Tablero[fila][columna] = ficha;
		/*if(ficha=='X')
            dibujar("sources/game/spr_sonic_head.bmp", posX[columna], posY[fila], RGB(255,0,255), 6);
        else if(ficha=='O')
            dibujar("sources/game/spr_tails_head.bmp", posX[columna]+1, posY[fila]+1, RGB(255,0,255), 6);*/
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
				error = true;
				break;
		}
	}while(error);

	cout << "\n";
}

int main(void){
	TicTacToe t;
	char respuesta[3] = "si";
	bool error, continuar = true, terminado = false;
	char turno = 'X';
	int fila, columna;

	while(continuar){
		do{
			t.Pintar(turno, false);
			pedirPosicion(turno, fila, columna);

			error = !t.PonerFicha(turno, fila, columna);
		}while(error);

		if(t.ComprobarColumna(turno, columna) or t.ComprobarFila(turno, fila) or t.ComprobarDiagonal(turno, fila, columna)){
			t.Pintar(turno, true);
			continuar = getch()=='s';
			terminado = true;
		}else{
			if(t.TableroCompleto()){
				t.Pintar(turno, false);
				continuar = getch()=='s';
                terminado = true;
			}else{
			    turno = turno=='X'?'O':'X';
			}
		}
		if(continuar && terminado){
            t.LimpiarTablero();
            turno = 'X';
            continuar = true;
            terminado = false;
        }
	}

	return 0;
}
