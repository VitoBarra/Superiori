//Vito barra
//esercizio 4
///Fusione di due array ordinati
#include <iostream>

using namespace std;




void fusione(int Vet_1[], int Vet_2[], int Vet_3[], int  x, int y, int& pv)
{
	int a = 0, b = 0;
	//prima parte
	for (int j = 0; j < (x + y); j++)
	{
		if (Vet_1[a] != Vet_2[b])
		{
			if (Vet_1[a] < Vet_2[b] && a < x)
			{
				Vet_3[pv] = Vet_1[a];
				a++;
				pv++;
			}
			else if (Vet_2[b] < Vet_1[a] && b < y)
			{
				Vet_3[pv] = Vet_2[b];
				b++;
				pv++;
			}
		}
		else
		{
			Vet_3[pv] = Vet_1[a];
			a++;
			b++;
			pv++;
		}
	}
	//2 parte
	if (a < x)
		for (; a <= x; a++, pv++)
			Vet_3[pv] = Vet_1[a];
	if (b < y)
		for (; b <= y; b++, pv++)
			Vet_3[pv] = Vet_2[b];
}



int main()
{
	int V1[10]{ 3,5,7,11,13,15,19,26 };
	int V2[10]{ 5,8,11,12,16,20,26,27 };
	int V3[20];
	int pv = 0;


	fusione(V1, V2, V3, 8, 8, pv);
	cout << "vettore unito:\n";

	for (int i = 0; i < pv - 1; i++)
		cout << V3[i] << " ";
	system("pause >nul");
	return 0;
}
