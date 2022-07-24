// vito barra
///esercizio 30
///data una matrice A quadrata, scrivere un programma che comprenda una funzione per trovare la media degli elementi della matrice e un altra funzione che
///data la media, costruisca una nuova matrice in cui ciascun elemento e dato dalla differenza tra il corrispondente valore della prima matrice e la media
#include <iostream>


using namespace std;

void InputM(float[][10], int, int);
void StampaM(float[][10], int, int);
float calcoloM(float[][10], int, int);
void CostM(float[][10], int, int, float);


int main()
{
	float Mat[10][10], M;
	int n;

	cout << "dammi in numero di righe e colonne: ";
	cin >> n;
	InputM(Mat, n, n);
	cout << "\nla matrice e':\n";
	StampaM(Mat, n, n);

	M = calcoloM(Mat, n, n);
	cout << "\nla media e': " << M;
	CostM(Mat, n, n, M);
	cout << "\nla nuova matrice e':\n";
	StampaM(Mat, n, n);




	system("pause>nul");


	return 0;
}

void InputM(float Mat[][10], int y, int x)
{
	for (int j = 0; j < y; j++)
		for (int i = 0; i < x; i++)
		{
			cout << "Dammi la casella " << j << ", " << i << " : ";
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

float calcoloM(float Mat[][10], int y, int x)
{
	float s = 0;
	for (int j = 0; j < y; j++)
		for (int i = 0; i < x; i++)
			s += Mat[j][i];

	return s / (y*x);
}

void CostM(float Mat[][10], int y, int x, float m)
{
	for (int j = 0; j < y; j++)
		for (int i = 0; i < x; i++)
			Mat[j][i] -= m;
}
