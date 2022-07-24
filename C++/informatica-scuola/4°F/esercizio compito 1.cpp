//Vito Barra
///esercizio compito
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

struct Nodo
{
	Nodo* prev;
	string nome;
	string numero;
	Nodo* next;
};


Nodo* primo = nullptr;
Nodo* list = nullptr;
Nodo* ultimo = nullptr;

void NuovaLista();
void Stampa();
void AddStart(Nodo*);


int main()
{
	Nodo* temp = nullptr;
	for (int j = 0; j<4; temp = temp->next, j++)
	{
		temp = new Nodo;
		getline(cin, temp->nome);
		getline(cin, temp->numero);
		AddStart(temp);
	}
	NuovaLista();
	Stampa();
	return 0;
}


void NuovaLista()
{

	list = new Nodo;
	list->prev = nullptr;
	list->nome = primo->nome;
	list->numero = primo->numero;
	list->next = nullptr;

	Nodo* Lptr = primo->next;
	Nodo* NewLista = list;

	while (Lptr != nullptr)
	{
		NewLista->next = new Nodo;
		NewLista->next->prev = NewLista;
		NewLista->next->nome = Lptr->nome;
		NewLista->next->numero = Lptr->numero;
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
}


void Stampa()
{
	if (primo != nullptr)
	{
		Nodo* stampaPtr;
		for (stampaPtr = list; stampaPtr != nullptr; stampaPtr = stampaPtr->next)
			cout << "Nome: "<<stampaPtr->nome << "\nn:" << stampaPtr->numero << "\n-----------------------------\n";
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
