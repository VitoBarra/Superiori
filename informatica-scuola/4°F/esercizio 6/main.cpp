//Vito Barra
//Esercizio 6
///gestione di una pila
///- Push elemento
///- pop elemento
///- stampa
///- eliminazione lista
///- esci
#include <iostream>

using namespace std;

struct Nodo
{
	int num;
	Nodo* next;
};
Nodo* primo = nullptr;
void Push(int);
void Pop();

void EliminaLista();
void Stampa();

int main()
{
	while (true)
	{

		int s, nele, ele;
		cout << "1)Push in pila\n2)Pop elemento\n3)stampa\n4)elimina Pila\n5)esci\nselezione:";
		cin >> s;

		switch (s)
		{
		case 1:
		{
			cout << "\nelemento da inserire: ";
			cin >> ele;
			Push(ele);
			Stampa();
			break;
		}
		case 2:
		{
			Pop();
			Stampa();
			break;
		}
		case 3:
		{
			Stampa();
			break;
		}		
		case 4:
		{
			EliminaLista();
			break;
		}
		case 5:
		{
			return 0;
			break;
		}
		default:
		{
			cout << "opzione non valida";
			system("pause>nll");
			break;
		}
		}
			system("cls");
	}
}
void Push(int add)
{
	Nodo* temp = primo;
	primo = new Nodo;
	primo->next = temp;
	primo->num = add;
}
void Pop()
{
	if (primo != nullptr)
		primo = primo->next;
	else
		cout << "la lista è vuota";
}

void Stampa()
{
	if (primo != nullptr)
	{
		cout << "Pila:\n";
		Nodo* temp = primo;
		while (temp->next != nullptr)
		{
			cout << temp->num << " ";
			temp = temp->next;
		}
		cout << temp->num;
	}
	else
		cout << "la pila e' vuota";
	system("pause>nll");
}
void EliminaLista()
{
	if (primo != nullptr)
	{
		delete(primo);
		primo = nullptr;
	}
	cout << "\nla pila e' stata eliminata";
	system("pause> nul");
}
