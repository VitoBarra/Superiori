//Vito Barra
//Esercizio 10
///caricamente lista da array
///- inserimento elementi array con ordinamento
///- caricamente in lista
///- stampa lista
///- eliminazione lista
///- esci

#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

struct Nodo
{
	int num;
	Nodo* next;
};

Nodo* primo = nullptr;

void CaricaVet(int[],int);
void CaricaNodi(int[], int);
void EliminaLista();
void Stampa();

int main()
{
	int s, vetLenght, vet[100];
	while (true)
	{
		cout << "1)carica vettore auto ordinante\n";
		cout << "2)caricamento in lista\n";
		cout << "3)stampa lista\n";
		cout << "4)Elimina lista\n";
		cout << "5)Esci\n";
		cout << "selezione:";
		cin >> s;
		switch (s)
		{
		case 1:

			cout << "quanti elementi: ";
			cin >> vetLenght;
			CaricaVet(vet, vetLenght);
			break;
		case 2:
			CaricaNodi(vet, vetLenght);
			break;
		case 3:
			Stampa();
			break;
		case 4:
			EliminaLista();
			break;
		case 5:
			return 0;
			break;
		default:
			cout << "opzione non valida";
			system("pause>nul");
			break;
		}
		system("cls");
	}
}

void BubbleSort(int vet[], int lenght)
{
	bool scambio = true;
	while (scambio)
	{
		scambio = false;
		for (int j = 0; j < lenght - 1; j++)
		{
			if (vet[j] > vet[j + 1])
			{
				swap(vet[j], vet[j + 1]);
				scambio = true;
			}
		}
	}
}
void CaricaVet(int vet[], int lenght)
{
	cout << "dammi " << lenght << " elemenbti(separati da uno spazio):\n ";
	for (int j = 0; j < lenght; j++)
		cin >> vet[j];
	BubbleSort(vet, lenght);
}

void AddStart(Nodo* nuovoNptr)
{
	Nodo* temp = primo;

	primo = nuovoNptr;
	primo->next = temp;
}
void CaricaNodi(int vet[], int legnth)
{
	for (int j = 0; j < legnth; j++)
	{
		Nodo* temp = new Nodo;
		temp->num = vet[j];
		AddStart(temp);
	}
	cout << "lista nodi caricata con successo";
	system("pause>nul");
}

void Stampa()
{
	if (primo != nullptr)
	{
		Nodo* temp = primo;
		cout << "lista:\n\n";
		while (temp->next != nullptr)
		{
			cout << temp->num<<" ";
			temp = temp->next;
		}
		cout << temp->num;
	}
	else
		cout << "la lista e' vuota";
	system("pause>nul");
}
void EliminaLista()
{
	if (primo != nullptr)
	{
		delete(primo);
		primo = nullptr;
		cout << "\nla lista e' stata eliminata";
	}
	else
		cout << "lista gia inisistente";

	system("pause>nul");
}
