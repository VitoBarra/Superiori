//Vito Barra
//esercizio 22
///data una matrice calcolare la media di ogni elemento e costruire una seconda matrice il cui ogni elemento è uguale alla differenza  fra l'elemento corrispondente della prima matrice e la media

#include <iostream>

using namespace std;



void InputM(float[][10], int, int);
void StampaM(float[][10], int, int);
float MediaM(float[][10], int, int);
void ConM(float[][10], float[][10], int, int, float);



int main()
{
	int  y, x;
	float M[10][10], M1[10][10], med;
	cout << "dammi in numero di righe: ";
	cin >> y;
	cout << "dammi il numero di colonne: ";
	cin >> x;
	InputM(M, y, x);
	cout << "\nla matrice e':\n";
	StampaM(M, y, x);

	med = MediaM(M, y, x);
	cout << "\nla media e': " << med;
	ConM(M, M1, y, x, med);

	cout << "\nnuova matrice:\n";
	StampaM(M1, y, x);



	system("pause>nul");
	return 0;
}

void InputM(float Mat[][10], int y, int x)
{
	for (int j = 0; j < y; j++)
		for (int i = 0; i < x; i++)
		{
			cout << "dammi la casella " << j << ", " << i << " : ";
			cin >> Mat[j][i];
		}
}

void StampaM(float Mat[][10], int y, int x)
{
	for (int j = 0; j < y; j++)
	{
		for (int i = 0; i < x; i++)
			cout << Mat[j][i] << " ";
		cout << endl;
	}
}

float MediaM(float Mat[][10], int y, int x)
{
	float m = 0;
	for (int j = 0; j < y; j++)
		for (int i = 0; i < x; i++)
			m += Mat[j][i];
	return m / (x * y);
}

void ConM(float Mat[][10], float Mat1[][10], int y, int x, float m)
{
	for (int j = 0; j < y; j++)
		for (int i = 0; i < x; i++)
			Mat1[j][i] = Mat[j][i] - m;

}





