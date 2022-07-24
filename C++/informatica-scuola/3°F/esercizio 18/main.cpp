//Vito Barra
//esercizio 18
///Scrivere una funzione per individuare e stampare tutti gli elementi dispari di una matrice




#include <iostream>

using namespace std;



void InputM(int[][10], int, int);
void StampaM(int[][10], int, int);
void RicercaD(int[][10], int, int);


int main()
{
	int M[10][10], y, x, s;
	cout << "dammi in numero di righe e colonne separate da uno spazio: ";
	cin >> y; cin >> x;
	InputM(M, y, x);
	cout << "\nla matrice e':\n";
	StampaM(M, y, x);


	cout << "\ngli elementi dispari sono:\n";
	RicercaD(M, y, x);



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


void RicercaD(int Mat[][10], int y, int x)
{
	for (int j = 0; j < y; j++)
		for (int i = 0; i < x; i++)
		{
			if (Mat[j][i] % 2)
				cout << Mat[j][i] << " ";
		}
}



