//Vito Barra
///esercizio 11
///avendo una lista di nomi creare una nuova lista senza ripetizioni
#include <iostream>
#include <string>
using namespace std;

struct Nodo
{
	Nodo* prev;
	string nome;
	Nodo* next;
};


Nodo* primo = nullptr;
Nodo* list = nullptr;
Nodo* ultimo = nullptr;

void NuovaLista();
void Stampa();
void AddStart(Nodo*);
Nodo* NewEle();


int main()
{

	int s, n;

	while (true)
	{
		system("cls");
		cout << "1)nuovo/i elemento\n";
		cout << "2)stampa lista nuova\n";
		cout << "3)esci\n";
		cout << "seleziona: ";
		cin >> s;
		switch (s)
		{
		case 1:
			cout << "quanti elementi: ";
			cin >> n;
			cin.get();
			for (int j = 0; j < n; j++)
				AddStart(NewEle());
			break;

		case 2:
			Stampa();
			break;

		case 3:
			return 0;

		default:
			cout << "opsione non valida";
			break;
		}
	}
}


Nodo* NewEle()
{
	Nodo* temp = new Nodo;
	cout << "-----------------------------\n";
	cout << "nome:";
	getline(cin, temp->nome);
	return temp;
}


void NuovaLista()
{

	list = new Nodo;
	list->prev = nullptr;
	list->nome = primo->nome;
	list->next = nullptr;

	Nodo* Lptr = primo->next;
	Nodo* NewLista = list;

	while (Lptr != nullptr)
	{
		NewLista->next = new Nodo;
		NewLista->next->prev = NewLista;
		NewLista->next->nome = Lptr->nome;
		NewLista->next->next = nullptr;


		Lptr = Lptr->next;
		NewLista = NewLista->next;
	}
	for (NewLista = list; NewLista != nullptr; NewLista = NewLista->next)
	{
		for (Lptr = list; Lptr != nullptr; Lptr = Lptr->next)
		{
			if (NewLista->nome == Lptr->nome && NewLista != Lptr)
			{
				if (Lptr->next != nullptr)
					Lptr->next->prev = Lptr->prev;
				else
					Lptr->prev->next = nullptr;
				Lptr->prev->next = Lptr->next;
			}
		}

	}


	system("cls");
	cout << "LA NUOVA LISTA E'STATA CREATA";
	system("pause>nul");
}


void Stampa()
{
	NuovaLista();
	if (list != nullptr)
	{
		Nodo* stampaPtr;
		for (stampaPtr = list; stampaPtr != nullptr; stampaPtr = stampaPtr->next)
			cout << "\n-----------------------------\n" << "Nome: " << stampaPtr->nome << "\n";
		cout << "\n-----------------------------\n";
	}
	else
		cout << "la lista e' vuota";
	system("pause>nul");
}

void AddStart(Nodo* nuovoN)
{
	Nodo* temp = primo;

	primo = nuovoN;
	primo->next = temp;
	primo->prev = nullptr;
	if (ultimo == nullptr)
		ultimo = primo;
	else
		temp->prev = primo;
}
