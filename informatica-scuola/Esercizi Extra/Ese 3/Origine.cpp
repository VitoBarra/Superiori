#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
int M[3] = {3,5,7};
string contenitore = "";

//FUNZIONI GENERALI
void swap_vettore(int Vet[], int a, int b)
{
	int c = Vet[a];
	Vet[a] = Vet[b];
	Vet[b] = c;
}

void codice_numeri_leng(const int Numero_simboli, const int Leng, bool SE_converti = false, string* Contenitore_Ris = nullptr)
{
	//inizializazione
	string* Sostituiti = new string[Numero_simboli];
	string* Da_Sostituire = new string[Numero_simboli];
	int* Risultato_V = new int[Leng];
	int Combinazioni = 1;
	//azeramento 
	for (int i = 0; i < Leng; i++)
		Risultato_V[i] = 0;
	Risultato_V[Leng - 1] = -1;

	//calcolo del numero di combinazioni
	for (int i = 0; i < Leng; i++)
		Combinazioni = Combinazioni *Numero_simboli;

	//se si vuole convertire in numeri specifici
	if (SE_converti)
	{
		for (int i = 0; i < Numero_simboli; i++)
		{
			Da_Sostituire[i]= static_cast<char>(i + 48);
			cout << "il " << Da_Sostituire[i] << " verra sostituito in: ";
			getline(cin, Sostituiti[i]);
		}
	}
	else
	{
		delete[] Sostituiti;
		delete[] Da_Sostituire;
	}
	//calcolo combinazioni
	for (int k = Combinazioni, i = Leng-1 ; k > 0; k--)
	{
		Risultato_V[i] += 1;
		for (int i = Leng - 1; i >= 0; i--)
		{
			if (Risultato_V[i] >= Numero_simboli - 1)
			{
				Risultato_V[i - 1] += Risultato_V[i] / Numero_simboli;
				Risultato_V[i] = Risultato_V[i] % Numero_simboli;
			}
		}
		for (int i = 0; i < Leng; i++)
			cout << Risultato_V[i];
		cout << endl;


		//se si vuole convertire in numeri specifici
		if (SE_converti)
		{
			//conversione
			for (int i = 0; i < Leng; i++)
				(*Contenitore_Ris) += to_string(Risultato_V[i]);
			(*Contenitore_Ris) += " ";
		}
	}
	if (SE_converti)
	{
		for (int i = 0; i < Numero_simboli; i++)
			replace((*Contenitore_Ris).begin(), (*Contenitore_Ris).end(), (*Da_Sostituire)[i], (*Sostituiti)[i]);
		cout << endl << contenitore;
		delete[] Sostituiti;
		delete[] Da_Sostituire;
	//	cout << endl << Contenitore_Str;
	}
	delete[] Risultato_V;
}


//FUNZIONI SPECIFICHE

bool controllo(int a[])
{
	bool b;
	for (int i = 0; i <4; i++)
		b = ((a[i] == 3) || (a[i] == 5) || (a[i] == 7));
	return b;
}

void stampa(int a[])
{
		if(controllo(a))
		{
			
		cout << "\nil risultato che sodisfa la traccia e': ";
		for (int i = 0; i < 4; i++)
			cout << a[i];
		}
	system("pause >nul");
}



int main()
{
	codice_numeri_leng(3, 3,true, &contenitore);
	
	system("pause>nul");
	return 0; 
}