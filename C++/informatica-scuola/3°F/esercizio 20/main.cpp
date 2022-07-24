//Vito Barra
//esercizio 20
/// Data una matrice costruire un array dal numero di elementi pari al numero di righe
///della matrice, dove ogni elemento dell'array è pari alla somma di ogni elemento della riga corrispondente

#include <iostream>

using namespace std;



void InputM(int[][10], int, int);
void StampaM(int[][10], int, int);
void MatVet(int[][10], int[], int, int);


int main()
{
	int M[10][10], v[10], y, x;


	cout << "dammi in numero di righe: ";
	cin >> y;
	cout << "dammi il numero di colonne: ";
	cin >> x;
	InputM(M, y, x);
	cout << "\nla matrice e':\n";
	StampaM(M, y, x);


	for (int j = 0; j < y; j++)
		v[j] = 0;

	MatVet(M, v, y, x);

	cout << "\nil vettore e':\n";
	for (int j = 0; j < y; j++)
		cout << v[j] << " ";



	system("pause>nul");
	return 0;
}

void InputM(int Mat[][10], int y, int x)
{
	for (int j = 0; j < y; j++)
		for (int i = 0; i < x; i++)
		{
			cout << "dammi la casella " << j << ", " << i << " : ";
			cin >> Mat[j][i];
		}
}

void StampaM(int Mat[][10], int y, int x)
{
	for (int j = 0; j < y; j++)
	{
		for (int i = 0; i < x; i++)
			cout << Mat[j][i] << " ";
		cout << endl;
	}
}

void MatVet(int Mat[][10], int vet[], int y, int x)
{
	for (int j = 0; j < y; j++)
		for (int i = 0; i < x; i++)
			vet[j] += Mat[j][i];

}

