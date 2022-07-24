//Vito Barra
//esercizio 2
///bubblesort
#include <iostream>

using namespace std;

void Bublesort(int V[], int leng)
{

	int scambio = 0, dep;
	do
	{
		scambio = 0;
		for (int j = 0; j < leng - 1; j++)
		{
			if (V[j] > V[j + 1])
			{
				dep = V[j + 1];
				V[j + 1] = V[j];
				V[j] = dep;
				scambio = 1;
			}
		}
	} while (scambio);
}


int main()
{

	const int n = 10;
	int Vet[n] = { 7,10,1,4,13,9,11,29,3,2 };
	for (int j = 0; j < n; j++)
		cout << Vet[j] << "\t";
	Bublesort(Vet[], n);
	cout << "\nvettore ordinato\n";
	for (int j = 0; j < n; j++)
		cout << Vet[j] << "\t";
	system("pause<nul");
	return 0;
}
