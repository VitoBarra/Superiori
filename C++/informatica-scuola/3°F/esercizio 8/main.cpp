//Vito Barra
//esercizio 8
///scrivere un programma che dato un array di n alementi possa ordinarlo dal piu grande al piu piccolo 
///gli elementi di posti pari e dal piu piccolo al piu grande gli elementi di posto dispari
#include <iostream>

using namespace std;

void LeggiVet(int V[], int x)
{
	for (int j = 0; j < x; j++)
	{
		cout << "dammi il " << j + 1 << " numero:\t ";
		cin >> V[j];
	}
}

void Fun(int Vet[], int leng)
{
	int scambio = 1, x;

	while (scambio)
	{
		scambio = 0;
		for (int j = 0, i = 1; i < leng - 3; j += 2, i += 2)
		{
			if (Vet[j] < Vet[j + 2])
			{
				x = Vet[j + 2];
				Vet[j + 2] = Vet[j];
				Vet[j] = x;
				scambio = 1;
			}
			if (Vet[i] > Vet[i + 2])
			{
				x = Vet[i + 2];
				Vet[i + 2] = Vet[i];
				Vet[i] = x;
				scambio = 1;
			}

		}
	}
}

int main()
{

	int V[10],n;

	cout<<"quanti elementi:\t";
	cin>>n;
	LeggiVet(V, n);
	Fun(V, n);


	for (int j = 0; j < n; j++)
		cout << V[j] << "  ";

	system("pause>nul");
	return 0;
}
