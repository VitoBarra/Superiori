//Vito Barra
//esercizio 1
///soma degli elementi pare e'dispari di un array 
#include <iostream>

using namespace std;

int main()
{
	const int k = 10;
	int sommaP = 0, sommaD = 0;
	int Vet[k];

	for (int i = 0; i < k; i++)
	{
		cout << "dammi il " << i + 1 << " numero: ";
		cin >> Vet[i];
	}

	for (int i = 0; i < k; i++)
	{
		if (Vet[i] % 2)
			sommaD += Vet[i];
		else
			sommaP += Vet[i];
	}

	cout << "\nsomma Dispari: " << sommaD << "\nsomma Pari: " << sommaP;
	system("pause >nul");
	return 0;
}
