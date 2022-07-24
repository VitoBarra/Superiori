//Vito Barra
//esercizio 1
///BubbleSort
#include <iostream>


using namespace std;

void BubbleSort(int[],int);
void Input(int[], int);
void Stampa(int[],int);

int main()
{
	const int NELE = 20;
	int vec[NELE];

	cout << "inserire " << NELE << " elementi separati da uno spazio:\n";
	Input(vec, NELE);

	cout << "\nstampa disordinata:";
	Stampa(vec, NELE);
	
	cout << "\nstampa ordinata:";
	BubbleSort(vec, NELE);
	Stampa(vec, NELE);

	system("pause>nul");
	return 0;
}

void Input(int v[], int length)
{
	for (int i = 0; i < length; i++)
		cin >> v[i];
}

void Stampa(int v[],int length)
{
	cout << endl;
	for (int i = 0; i < length; i++)
		cout << v[i] << " ";
}

void BubbleSort(int v[], int length)
{
	bool scambio;
	do
	{
		scambio = false;
		for (int i = 0; i < length - 1; i++)
		{
			if (v[i] > v[i + 1])
			{
				swap(v[i], v[i + 1]);
				scambio = true;
			}
		}
	} while (scambio);
}
