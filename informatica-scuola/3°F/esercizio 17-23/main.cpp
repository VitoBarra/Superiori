//Vito Barra
//esercizio 17
///Leggere una matrice quadrata, stamparla, calcolare e stampare la somma degli elementi della diagonale principale

#include <iostream>

using namespace std;



void InputM(int[][10], int, int);
void StampaM(int[][10], int, int);
int SommaDP(int[][10], int);
int SommaDS(int[][10], int);

int main()
{
	int M[10][10], n, s;
	cout << "dammi in numero di righe e colonne: ";
	cin >> n;
	InputM(M, n, n);
	cout << "\nla matrice e':\n";
	StampaM(M, n, n);
	s = SommaDP(M, n);
	cout << "la somma della diagonale principale e':\t" << s;
	s = SommaDS(M, n);
	cout << "\nla somma della diagonale secondaria e':\t" << s;




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
int SommaDP(int Mat[][10], int y)
{
	int som = 0;
	for (int j = 0; j < y; j++)
		som += Mat[j][j];
	return som;
}

//esercizio 23
///Leggere una matrice quadrata, stamparla, calcolare e stampare la somma degli elementi della retrodiagonale
int SommaDS(int Mat[][10], int y)
{
	int som = 0;
	for (int j = 0, i = y - 1; j < y; j++, i--)
		som += Mat[j][i];
	return som;
}

