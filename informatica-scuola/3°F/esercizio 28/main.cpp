//vito barra
//esercizio 28
///In un file di testo è presente una serie di numeri interi.Occorre caricare tali numeri in un array. 
///Dopo averne calcolato la media, scrivere nel file maggiori.txt i numeri maggiori della media

#include <iostream>
#include <fstream>

using namespace std;

fstream F, F1;


void CaricaVet(int[], int&);
float Media(int[], int);
void SpostaN(int[], int, float);


int main()
{
	int vet[50], n = 0;
	CaricaVet(vet, n);
	SpostaN(vet, n, Media(vet, n));

	system("pause>nul");
	return 0;
}


void CaricaVet(int ve[], int& n)
{
	n = 0;
	F.open("input.txt", ios::in);
	if (F.is_open())
	{

		while (!F.eof())
			F >> ve[n++];
	}
	F.clear();
	F.close();
}

float Media(int ve[], int n)
{
	float s = 0;
	for (int j = 0; j < n; j++)
	{
		s += ve[j];
	}

	return s / n;
}

void SpostaN(int ve[], int n, float M)
{

	F.open("output.txt", ios::out | ios::trunc);

	if (F.is_open())
	{
		for (int j = 0; j < n; j++)
			if (ve[j] > M)
				F << ve[j] << " ";

		F.clear();
		F.close();
	}



}