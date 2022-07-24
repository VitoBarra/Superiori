//Vito Barra
//Esercizio 8
///gestione di una coda
///- aggiunta elemento in coda
///- eliminazione primo elemento
///- eliminazione ultimo elemento
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
void AddEnd(int); 
void RimozioneEle(int);
void PrimoEle();
void UltimoEle();

void EliminaLista();
void Stampa();



int main()
{
	while (true)
	{

		int s, ele;
		cout << "1)Inserimebto in coda\n2)Eliminazione primo elemento\n3)Eliminazione ultimo elemento\n4)Eliminazione elemento scelto\n5)stampa\n6)Elimina lista\n7)Esci\nselezione:";
		cin >> s;

		switch (s)
		{
		case 1:
		{
			cout << "\nelemento da inserire: ";
			cin >> ele;
			AddEnd(ele);
			Stampa();
			break;
		}
		case 2:
		{
			PrimoEle();
			Stampa();
			break;
		}	
		case 3:
		{
			UltimoEle();
			Stampa();
			break;
		}

		case 4:
		{
			cout << "\nelemento da eliminare: ";
			cin >> ele;
			RimozioneEle(ele);
			Stampa();
			break;
		}

		case 5:
		{
			Stampa();
			break;
		}
		case 6:
		{
			EliminaLista();
			break;
		}
		case 7:
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




void RimozioneEle(int remove)
{
	if (primo != nullptr)
	{
		Nodo* temp = primo;
		Nodo* temp2 = nullptr;
		if (primo->num != remove)
		{
			while (temp->next != nullptr)
			{
				if (temp->num == remove)
					if (temp2 != nullptr)
						temp2->next = temp->next;
					else
						temp = temp->next;
				temp2 = temp;
				temp = temp->next;
			}
			if (temp->num == remove)
				temp2->next = nullptr;
			else
				cout << "\nElemento non trovato\n";
		}
		else
			primo = primo->next;
	}
}

void AddStart(int add)
{
	Nodo* temp = primo;
	primo = new Nodo;
	primo->next = temp;
	primo->num = add;
}

void AddEnd(int add)
{
	if (primo != nullptr)
	{
		Nodo* temp = primo;
		while (temp->next != nullptr)
			temp = temp->next;
		temp->next = new Nodo;
		temp->next->next = nullptr;
		temp->next->num = add;
	}
	else
		AddStart(add);
}

void PrimoEle()
{
	if (primo != nullptr)
		primo = primo->next;
	else
		cout << "la lista è vuota";
}

void UltimoEle()
{
	if (primo != nullptr && primo->next != nullptr)
	{
		Nodo* temp = primo;
		while (temp->next->next != nullptr)
		{
			temp = temp->next;
		}
		temp->next = nullptr;
	}
	else if (primo != nullptr)
		if (primo->next == nullptr)
		{
			delete(primo);
			primo = nullptr;
		}

}

void Stampa()
{
	if (primo != nullptr)
	{
		cout << "lista:\n";
		Nodo* temp = primo;
		while (temp->next != nullptr)
		{
			cout << temp->num << " ";
			temp = temp->next;
		}
		cout << temp->num;
	}
	else
		cout << "la lista e' vuota";
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

