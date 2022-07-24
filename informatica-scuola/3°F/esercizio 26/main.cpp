//Vito Barra
//esercizio 26
///Creare una struttura con cognome, nome, voto scritto, orale, pratico e media, per poi ordinare gli alunni in ordine decrescente di media
#include <iostream>

using namespace std;

struct alunno
{
	char nome[15];
	char cognome[15];
	int scritto;
	int orale;
	int pratico;
	float media;
};



void scritt(alunno[] , int);
void stampa(alunno[] , int);
void BubbleSort(alunno[] , int);




int main()
{

	alunno alun[100];
	int N;

	cout << "quanti alunni vuoi agiungere: ";
	cin >> N;

	scritt(alun,N);
	BubbleSort(alun, N);
	stampa(alun, N);

	
	system("pause>nul");
	return 0;
}


void swap(alunno& a, alunno& b)
{
	alunno temp = a;
	a = b;
	b = temp;
}


void scritt(alunno alu[], int n)
{
	for (int j = 0; j < n; j++)
	{
		cout << "Inserisci i dati del ragazzo/a numero " << j + 1;

		cin.get();
		cout << "\nNome: ";
		cin.get(alu[j].nome, 15);

		cin.get();
		cout << "Cognome: ";
		cin.get(alu[j].cognome, 15);
		cin.get();

		cout << "Voto scritto: ";
		cin >> alu[j].scritto;
		cout << "Voto orale: ";
		cin >> alu[j].orale;
		cout << "Voto pratico: ";
		cin >> alu[j].pratico;

		alu[j].media = (alu[j].scritto + alu[j].orale + alu[j].pratico) / 3.0;


		system("CLS");
	}
}

void stampa(alunno alu[], int n)
{
	for (int j = 0; j < n; j++)
	{
		cout << endl;
		cout << "Nome: " << alu[j].nome << endl;
		cout << "Cognome: " << alu[j].cognome << endl;
		cout << "Scritto: " << alu[j].scritto << endl;
		cout << "Orale: " << alu[j].orale << endl;
		cout << "Pratico: " << alu[j].pratico << endl;
		cout << "Media: " << alu[j].media << endl;
	}
}

void BubbleSort(alunno alu[], int n)
{
	bool scamb;

	do
	{
		scamb = false;
		for (int i = 0; i < n - 1; i++)
		{
			if (alu[i].media < alu[i + 1].media)
			{
				swap(alu[i], alu[i + 1]);
				scamb = true;
			}
		}
	} while (scamb);
}


