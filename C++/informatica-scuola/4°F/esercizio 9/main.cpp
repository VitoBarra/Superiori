//Vito Barra
//Esercizio 9
///gestione lista dopiamente concatenata
///- inserimento elemento
///- eliminazione elemento
///- stampa
///- stampa invertita
///- eliminazione lista
///- esci

#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

struct Nodo
{
	Nodo* prev;
	char nome[20];
	char cognome[20];
	char numero[20];
	Nodo* next;
};

Nodo* primo = nullptr;
Nodo* ultimo = nullptr;

Nodo *DataSet();
void AddMiddle();
void RimozioneEle(char[]);
void EliminaLista();
void Stampa();

int main()
{
	while (true)
	{
		int s;
		char con[20];
		cout << "1)inserimento ordinato\n2)Eliminazione elemento scelto\n3)stampa\n4)Elimina lista\n5)Esci\nselezione:";
		cin >> s;
		switch (s)
		{
		case 1:
			AddMiddle();
			Stampa();
			break;
		case 2:
			cin.get();
			cin.get(con, 20);
			RimozioneEle(con);
			Stampa();
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

Nodo*  DataSet()
{
	Nodo* temp = new Nodo;

	cin.get();
	cout << "inserire nome e cognome(separato da un invio):\n";
	cin.get(temp->nome, 20);
	cin.get();
	cin.get(temp->cognome, 20);
	cout << "inserire numero telefonico: ";
	cin.get();
	cin.get(temp->numero, 20);

	temp->next = nullptr;
	temp->prev = nullptr;

	return temp;
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
void AddEnd(Nodo* nuovoN)
{
	if (primo != nullptr)
	{
		Nodo* temp = primo;
		while (temp->next != nullptr)
			temp = temp->next;
		temp->next = nuovoN;
		temp->next->prev = temp;
		temp->next->next = nullptr;
		ultimo = temp;
	}
	else
		AddStart(nuovoN);
}
void AddMiddle()
{
	if (primo != nullptr)
	{
		Nodo* temp = primo;
		Nodo* nuovoNod = DataSet();
		nuovoNod->next = nullptr;
		nuovoNod->prev = nullptr;
		do
		{
			if (temp->next != nullptr)
			{
				if (strcmp(nuovoNod->cognome, temp->cognome) > 0)
					temp = temp->next;
				else
				{
					if (temp->prev != nullptr)
					{
						temp->prev->next = nuovoNod;
						nuovoNod->next = temp;
						nuovoNod->prev = temp->prev;
						temp->prev = nuovoNod;
						break;
					}
					else
					{
						AddStart(nuovoNod);
						break;
					}
				}
			}
			else
			{
				if (strcmp(nuovoNod->cognome, temp->cognome) >= 0)
					AddEnd(nuovoNod);
				else
				{
					if (primo->next != nullptr)
					{
						temp->prev->next = nuovoNod;
						nuovoNod->next = temp;
					}
				}
				break;
			}
		} while (temp != nullptr);
	}
	else
		AddStart(DataSet());
}

void PrimoEle()
{
	if (primo != nullptr)
		primo = primo->next;
	else
		cout << "la lista e' vuota";
}
void UltimoEle()
{
	if (ultimo->prev != nullptr)
	{
		ultimo = ultimo->prev;
		ultimo->next = nullptr;
	}
	else
	{
		ultimo = nullptr;
		primo = nullptr;
	}
}
void RimozioneEle(char remove[])
{
	if (primo != nullptr)
	{
		Nodo* temp = primo;
		Nodo* temp2 = nullptr;
		if (strcmp(primo->cognome, remove) != 0)
		{
			while (temp->next != nullptr)
			{
				if (strcmp(temp->cognome, remove) == 0)
					if (temp2 != nullptr)
						temp2->next = temp->next;
					else
						temp = temp->next;
				temp2 = temp;
				temp = temp->next;
			}
			if (strcmp(temp->cognome, remove) == 0)
				temp2->next = nullptr;
			else
				cout << "\nElemento non trovato\n";
		}
		else
			primo = primo->next;
	}
}

void Stampa()
{
	if (primo != nullptr)
	{
		Nodo* temp = primo;
		cout << "lista:\n\n-----------------------------\n";
		while (temp->next != nullptr)
		{
			cout << temp->cognome << " " << temp->nome << endl << "n:" << temp->numero << "\n-----------------------------\n";
			temp = temp->next;
		}
		cout << temp->cognome << " " << temp->nome << endl << "n:" << temp->numero << "\n-----------------------------\n";;
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
		ultimo = nullptr;
	}
	cout << "\nla lista e' stata eliminata";
	system("pause>nul");
}
