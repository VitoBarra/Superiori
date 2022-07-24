//Vito Barra
//esercizio 11
///Data una funzione che calcoli il prodotto tramite somme ripetute scrivere un programma che calcoli una potenza come prodotti ripetuti
#include <iostream>

using namespace std;


int Prodotto(int, int);
int Potenza(int, int);


int main()
{
	int N1, N2, ris;
	cout << "dammi il numero da elevare:\t";
	cin >> N1;
	cout << "\nelevato alla:\t";
	cin >> N2;
	ris = Potenza(N1, N2);
	cout << endl << "risultato:\t" << ris;
	system("pause>nul");
	return 0;
}

int Prodotto(int F1, int F2)
{
	int rist = 0;
	for (int j = 0; j < F2; j++)
		rist += F1;
	return rist;
}

int Potenza(int N, int esp)
{
	int rest = 1;
	for (int j = 0; j < esp; j++)
		rest = Prodotto(rest, N);
	return rest;
}
