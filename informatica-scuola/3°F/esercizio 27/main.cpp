//vito barra
//esercizio 27
///nel file numeri.txt si trova una serie di numeri interi. Una funzione si dovrà occupare di collocare
///i numeri pari in un file e i numeri dispari in un altro. Il programma principale si occuperà di stampare quanti sono i numeri pari e quanti i dispari

#include <iostream>
#include <fstream>

using namespace std;

fstream F, FDis, FPar;


void Smista();
void stampa();


int main()
{
	Smista();
	stampa();
	system("pause>nul");
	return 0;
}


void Smista()
{
	F.open("input.txt", ios::in);
	FDis.open("dispari.txt", ios::out | ios::trunc);
	FPar.open("pari.txt", ios::out | ios::trunc);
	if (F.is_open())
	{
		int n = 0;
		while (!F.eof())
		{
			F >> n;
			if (n % 2)
				FDis << n << " ";
			else
				FPar << n << " ";

		}
	}


	F.clear();
	FDis.clear();
	FPar.clear();

	F.close();
	FDis.close();
	FPar.close();
}

void stampa()
{

	FDis.open("dispari.txt", ios::in);
	FPar.open("pari.txt", ios::in);
	if (FDis.is_open() && FPar.is_open())
	{
		int n;
		cout << "pari:\n";
		while (!FPar.eof())
		{
			FPar >> n;
			cout << n << " ";
		}
		FPar.clear();
		FPar.close();


		cout << "\ndispari:\n ";
		while (!FDis.eof())
		{
			FDis >> n;
			cout << n << " ";
		}
		FDis.clear();
		FDis.close();

	}


}