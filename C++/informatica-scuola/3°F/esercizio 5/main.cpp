//Vito Barra
//esercizio 5
///Leggere un array di 10 elementi, aggiungere 1 agli elementi di posto pari e sottrarre 1 agli elementi di posto dispari


#include <iostream>

using namespace std;



void StampaVet(int[], int);
void FVet(int[], int);


int main()
{
	int v[10];
	int n;

	cout << "elementi del vettore vettore: ";
	cin >> n;

	for (int i = 0; i<n; i++)
	{
		cout << " dammi l'Elemento " << i << ":\t ";
		cin >> v[i];
	}

	cout << "vettore originale:\n";
	StampaVet(v, n);

	FVet(v, n);
	cout << "\nvettore:\n";
	StampaVet(v, n);

	system("pause > nul");
	return 0;
}

void StampaVet(int vet[], int l)
{
	for (int i = 0; i<l; i++)
		cout << vet[i] << " ";
	cout << "\n";
}

void FVet(int vet[], int l)
{
	for (int i = 0; i < l; i++)
	{
		if (i % 2)
			vet[i] = vet[i] - 1;
		else
			vet[i] = vet[i] + 1;
	}
}
