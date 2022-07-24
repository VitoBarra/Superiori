//Vito Barra
//esercizo 16
/// Prodotto di due matrici

#include<iostream>

using namespace std;

void MulM(int[][10], int[][10],int [][10], int, int, int);
void InputM(int[][10], int, int);
void StampaM(int[][10], int, int);

int main()
{
	int V[10][10], V1[10][10], VR[10][10], n, m, t;



	cout << "1M:quante righe: "; cin >> m;
	cout << "1M:quante colonne: "; cin >> n;
	InputM(V, m, n);
	cout << endl;
	cout << "2M:quante colonne: "; cin >> t;
	InputM(V1, n, t);


	cout << "\mPrima matrice:\n";
	StampaM(V, m, n);
	cout << "\n\nSeconda matrice:\n";
	StampaM(V1, n, t);


	system("pause>nul");
	system("cls");


	for (int i = 0; i < m; i++)
		for (int j = 0; j < t; j++)
			VR[i][j] = 0;

	MulM(V, V1, VR, m, t, n);
	cout << "matrice risultato:\n\n";
	StampaM(VR, m, t);




	system("pause>nul");
	return 0;
}



void MulM(int M[][10], int M1[][10], int MR[][10], int f, int v, int p)
{
	for (int k = 0; k < f; k++)
		for (int i = 0; i < v; i++)
			for (int j = 0; j < p; j++)
				MR[k][i] += M[k][j] * M1[j][i];

}

void InputM(int Mat[][10],int y, int x)
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





