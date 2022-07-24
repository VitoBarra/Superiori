//Vito Barra
//esercizio 12
///Ordinamento indiretto con bubblesort
#include <iostream>

using namespace std;

void Bubble_Sort(int[], int[],int);
void Stampa_Vet(int[], int);

int main()
{
	int V[10], Vi[10], x;


	cout << "quanti elementi:  ";
	cin >> x;
	
	for (int j = 0; j < x; j++)
	{
		cout << j + 1 << " elemento: ";
		cin >> V[j];
		Vi[j] = j;
	}



	cout << "\nVettore originale: ";
	Stampa_Vet(V, x);
	cout << "\nVettore indici: ";
	Stampa_Vet(Vi, x);
	Bubble_Sort(V, Vi, x);
	cout << "\nVettore indici ordinato: ";
	Stampa_Vet(Vi, x);
	cout << "\nVettore ordinato indirettamente: ";
	for (int j = 0; j < x; j++)
		cout << V[Vi[j]] << " ";
		
	system("pause>nul");
	return 0;
}


void Bubble_Sort(int vit[], int pos[], int x)
{
	int ripeti = 1;
	int temp;
	while (ripeti)
	{
		ripeti = 0;
		for (int j = 0; j < x - 1; j++)
		{
			if (vit[pos[j]] > vit[pos[j + 1]])
			{
				temp = pos[j + 1];
				pos[j + 1] = pos[j];
				pos[j] = temp;

				ripeti = 1;
			}

		}

	}
}

void Stampa_Vet(int vet[], int x)
{
	for (int j = 0; j < x; j++)
		cout << vet[j] << " ";
}

