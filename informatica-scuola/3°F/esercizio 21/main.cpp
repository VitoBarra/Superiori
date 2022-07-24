//Vito Barra
//esercizio 21
///data una matrice quadrata stampare solo gli elementi della matrice triangolare bassa

#include<iostream>

using namespace std;

void InputM(int[][10], int, int);
void StampaM(int[][10], int, int);
void StampaTri(int[][10], int, int);


int main()
{
	int M[10][10], n;
	cout << "dammi in numero di righe e colonne: ";
	cin >> n; 
	InputM(M, n, n);
	cout << "\nla matrice e':\n";
	StampaM(M, n, n);
	cout << "\n\ntriangolo:\n";
	StampaTri(M, n, n);

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

void StampaTri(int Mat[][10], int y, int x)
{
	int n = x-1;
	for (int j = 0; j < y; j++)
	{
		for (int i = 0; i < x - n; i++)
			cout << Mat[j][i] << " ";
		n--;
		cout << endl;
	}
		
}

