//Vito Barra
//esercizio 7
///Scrivere un programma che tramite opportune funzioni legga due array A e B di 10 elementi
///e costruisca un terzo arrayu c i cui elementi di posto pari siano presi dagli elementi di 
///posto pari di A e gli elementi di posto dispari siano presi dagli elementi di posto dispari di B

#include <iostream>

using namespace std;

void Stampa(int [],int);
void Input (int [],int);
void Con(int [],int[],int [],int);

int main()
{
	int x;
	int V1[10], V2[10], V3[20];


	cout << "qunti elementi ha il vettore:\t";
	cin >> x;
	cout << "input del 1 vettore:\n";
	Input(V1, x);
	cout << "\ninput del 2 vettore:\n";

	Input(V2, x);
	Con(V3, V1, V2, x);
	Stampa(V3, x);

	return 0;

	system("pause>nul");
	return 0;
}


void Input(int vet[], int n)
{
	for (int j = 0; j < n; j++)
	{
		cout << "vettore pos " << j << " : ";
		cin >> vet[j];
	}
	cout << endl;
}
 
void Stampa(int vet[], int n)
{
	for (int j = 0; j < n; j++)
		cout << vet[j] << " ";
}
 
void Con(int VetR[], int VetA[], int VetB[], int n)
{
	for (int j = 0, i = 1; j < n; j += 2, i += 2)
	{
		VetR[j] = VetA[j];
		VetR[i] = VetB[i];
	}
}
