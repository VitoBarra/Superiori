//Vito Barra
//esercizio 6
///Scrivere un programma che tramite opportune funzioni legga due array A e B, calcoli la somma degli elementi di 
///ciascuno e stampi la somma più grande
#include <iostream>

using namespace std;

void LeggiVet(int V[], int x)
{
	for (int j = 0; j < x; j++)
	{
		cout << "dammi il " << j + 1 << " numero:\t";
		cin >> V[j];
	}
	cout << endl;
}
int SommaVet(int V[], int x)
{
	int ris = 0;
	for (int j = 0; j < x; j++)
		ris += V[j];
	return ris;
}



int main()
{
	int risA, risB;
	int A[10], B[10];
	cout << "vettore A:\n";
	LeggiVet(A, 10);
	cout << "\nvettore B:\n";
	LeggiVet(B, 10);
	risA = SommaVet(A, 10);
	risB = SommaVet(B, 10);

	if (risA > risB)
		cout << "la somma piu grande e'del vettore A: " << risA;
	else
		cout << "la somma piu grande e' del vettore B: " << risB;

	system("pause>nul");
	return 0;
}
