//Vito Barra
//Esercizio 13
///albero binario
///- inserimento elemento
///- stampa in order
///- esci

#include <iostream>

using namespace std;

struct Nodo
{
	Nodo* sx;
	int ele;
	Nodo* dx;
};

Nodo* root = nullptr;


void AddEleTree(int s);
void StampaInOrder(Nodo*);

int main()
{
	while (true)
	{
		int s,n;
		cout << "1)inserimento albero\n";
		cout << "2)Stampa in-order\n";
		cout << "3)esci\n";
		cout << "Seleziona:\n";
		cin >> s;
		switch (s)
		{
		case 1:
			cout << "quanti elementi: ";
				cin >> n;
				for (int j =0;j<n;j++)
				{
					cout << "n"<<j+1<<": ";
					cin >> s;
					AddEleTree(s);
				}
			break;
		case 2:
			StampaInOrder(root);
			system("pause>nul");
		case 3:
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


void AddEleTree(int add)
{
	Nodo* temp = root;


	if (temp != nullptr)
	{
		while (true)
		{
			if (temp->ele > add && temp->sx != nullptr)
				temp = temp->sx;
			else if (temp->ele > add)
			{
				temp->sx = new Nodo;
				temp->sx->sx = nullptr;
				temp->sx->ele = add;
				temp->sx->dx = nullptr;
				break;
			}
			else if (temp->ele < add && temp->dx != nullptr)
				temp = temp->dx;
			else if (temp->ele < add)
			{
				temp->dx = new Nodo;
				temp->dx->dx = nullptr;
				temp->dx->ele = add;
				temp->dx->sx = nullptr;
				break;
			}
			else
				break;
		}
	}
	else
	{
		root = new Nodo;
		root->sx = nullptr;
		root->ele = add;
		root->dx = nullptr;
	}
}

void StampaInOrder(Nodo* tempRic)
{
	if (tempRic != nullptr)
	{
		StampaInOrder(tempRic->sx);
		cout << tempRic->ele << " ";
		StampaInOrder(tempRic->dx);
	}
}
