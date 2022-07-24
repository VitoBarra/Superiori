//Vito Barra
//esercizio 13
///Lettura e stampa di una matrice date lunghezza e larghezza

#include <iostream>

using namespace std;

void Stampa(int[][10], int, int);
void Input(int[][10], int, int);
int SommaM(int[][10], int, int);

int main()
{
	int matr[10][10];
	int y, x, s;


	cout << "Quante colonne?\t";
	cin >> y;
	cout << "\nquante righe?\t";
	cin >> x;
	cout << endl;

	Input(matr, y, x);
	Stampa(matr, y, x);
	s = SommaM(matr, y, x);

	cout << "la somma di tutti gli elementi e':  " << s;
	system("pause >nul");
	return 0;

}

void Input(int SQ[][10], int y, int x)
{
	for (int j = 0; j < y; j++)
	{
		cout << "dammi la " << j + 1 << " riga( " << x << " elementi)\n";
		for (int i = 0; i < x; i++)
		{
			cin >> SQ[j][i];
			cout << " ";
		}
		cout << endl;
	}

}

void Stampa(int SQ[][10], int y, int x)
{
	for (int j = 0; j < y; j++)
	{
		cout << j + 1 << " riga:\t";
		for (int i = 0; i < x; i++)
			cout << SQ[j][i] << " ";
		cout << endl;
	}
}
//esercizio 14
//aggiungere al programma 13 una funzione che calcola la somma di tutti gli elementi della matrice

int SommaM(int SQ[][10], int y, int x)
{
	int som = 0;
	for (int j = 0; j < y; j++)
		for (int i = 0; i < x; i++)
			som += SQ[j][i];
	return som;
}
