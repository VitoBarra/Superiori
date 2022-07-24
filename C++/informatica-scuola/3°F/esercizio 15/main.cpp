//Vito Barra
//esercizio 15
///Ordinamento di una matrice
#include <iostream>

using namespace std;

void Input(int[][10],int,int);
void Stampa(int[][10],int,int);
void Bubble_Sort(int[],int,int);
void mat_to_vet(int[][10],int[],int,int);
void vet_to_mat (int[],int[][10],int,int);

int main()
{
	int Matx[10][10];
	int Vet[100];
	int x, y;
	cout << "dammi il numero di colonne:\t";
	cin >> x;
	cout << "\ndammi il numero di righe:\t";
	cin >> y;

	Input(Matx, x, y);
	mat_to_vet(Matx, Vet, x, y);
	Bubble_Sort(Vet, x, y);
	vet_to_mat(Vet, Matx, x, y);
	cout << endl;
	Stampa(Matx, x, y);


	system("pause>nul");

	return 0;
}


void Input(int Vet[][10], int x, int y)
{
	for (int j = 0; j < y; j++)
	{
		for (int i = 0; i < x; i++)
		{
			cout << "dammi la " << j << ", " << i << " casella:  ";
			cin >> Vet[j][i];
		}

	}
}

void Bubble_Sort(int Vet[], int x, int y)
{
	int temp;
	int scambio = 1;


	while (scambio == 1)
	{
		scambio = 0;
		for (int j = 0; j < y*x; j++)
		{
			if (Vet[j] > Vet[j + 1])
			{

				temp = Vet[j + 1];
				Vet[j + 1] = Vet[j];
				Vet[j] = temp;
				scambio = 1;
			}
		}
	}
}

void Stampa(int Vet[][10], int x, int y)
{
	for (int j = 0; j < y; j++)
	{
		for (int i = 0; i < x; i++)
			cout << Vet[j][i] << "  ";
		cout << endl;
	}
}

void mat_to_vet(int mat[][10], int vet[], int x, int y)
{
	int n = 0;
	for (int j = 0; j < y; j++)
	{
		for (int i = 0; i < x; i++)
		{
			vet[n] = mat[j][i];;
			n++;
		}

	}

}

void vet_to_mat(int vet[], int mat[][10], int x, int y)
{
	int n = 0;
	for (int j = 0; j < y; j++)
	{
		for (int i = 0; i < x; i++)
		{

			mat[j][i] = vet[n];
			n++;
		}
	}

}


