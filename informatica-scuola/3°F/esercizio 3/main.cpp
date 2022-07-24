//Vito Barra
//esercizio 3
///Ricerca di un elemento in un array
#include <iostream>
using namespace std;


void LeggiVet(int[], int);
void StampaVet(int[], int);
int CercaVet(int[], int, int);


int main()
{
	const int k = 10;
	int pos, ele, cercare;
	int Vet[k];

	cout << "quanti elementi vuoi?(Max 10)  ";
	cin >> ele;
	LeggiVet(Vet, ele);
	cout << endl;
	StampaVet(Vet, ele);
	cout << "che numero vuoi cercare?\t";
	cin >> cercare;
	pos = CercaVet(Vet, ele, cercare);
	if (pos == -1)
		cout << "numero non trovato";
	else
		cout << "l' elemento " << cercare << " e' alla posizione " << pos;
	system("pause>nul");
	return 0;
}



void LeggiVet(int V[], int k)
{
	for (int i = 0; i < k; i++)
	{
		cout << "dammi il " << i + 1 << " valore";
		cin >> V[i];
	}
}

void StampaVet(int V[], int k)
{
	for (int i = 0; i < k; i++)
		cout << V[i] << " ";
}

int CercaVet(int V[], int k, int c)
{
	for (int i = 0; i < k; i++)
		if (V[i] == c)
			return i;

	return -1;
}
