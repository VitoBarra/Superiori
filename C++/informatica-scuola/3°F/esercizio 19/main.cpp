//Vito Barra
//esercizio 19
///Calcolare l'elemento minimo di un array

#include <iostream>

using namespace std;


void StampaVet(int[], int);
int Minimo(int[], int);


int main()
{
	int v[10];
	int n, m;

	cout << "dammi la Lunghezza del vettore: ";
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cout << "dammi il " << i << " elemento : ";
		cin >> v[i];
	}

	StampaVet(v, n);
	m = Minimo(v, n);
	cout << "\nMinimo: " << m;

	system("pause > nun");
	return 0;
}

void StampaVet(int vet[], int l)
{
	for (int i = 0; i<l; i++)
		cout << vet[i] << " ";
	cout << "\n";
}

int Minimo(int vet[], int n)
{
	int min = vet[0];
	for (int i = 0; i < n; i++)
		if (vet[i] < min)
			min = vet[i];
	return min;
}
