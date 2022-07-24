#include <iostream>

using namespace std;

void bobble_sort(int[], int);
void ord_ind(int[], int[],int [], int);
void stampaVet(int[], int);

int OdinamentoIndiretto()
{
	int V[10], Vi[10], RIS[10];
	int x;


	cout << "quanti elementi: ";
	cin >> x;
		for (int j = 0; j < x; j++)
		{
			cout << j + 1 << " elemento: ";
			cin >> V[j];
			Vi[j] = V[j];
		}

		bobble_sort(V, x);
		ord_ind(V, Vi, RIS, x);

		cout << "\nvettore originale: ";
		stampaVet(Vi, x);
		cout << "\nvettore ordinato: ";
		stampaVet(V, x);
		cout << "\nvettore ordinato indirettamente: ";
		stampaVet(RIS, x);

		system("pause>nul");
	return 0;
}






void bobble_sort(int vet[], int x)
{
	int ripeti = 1;
	int temp;

	while (ripeti)
	{
		ripeti = 0;
		for (int j = 0; j < x-1; j++)
		{	
			if (vet[j] > vet[j + 1])
			{
				temp = vet[j + 1];
				vet[j + 1] = vet[j];
				vet[j] = temp;
				ripeti = 1;
			}
		}
	}
}

void ord_ind(int vet[], int con[], int ret[],int x)
{
	int n = 0;
	for (int j = 0; j < x; j++)
	{
		for (int i = 0; i < x; i++)
			if (vet[j] == con[i])
			{
				ret[n] = i;
				n++;
			}
	}
}

void stampaVet(int vet[], int x)
{
	for (int j = 0; j < x; j++)
		cout << vet[j] << " ";
}