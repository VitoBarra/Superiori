//Vito Barra
//Esercizio 7
///gestione di una lista
///- inserimento ordinato
///- conta elementi
///- stampa
///- eliminazione elemento
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
void InjectStart(int);
void InjectMiddle(int);
void InjectEnd(int);

void EliminaLista();
void Stampa();
void RimozioneEle(int);
int ContaEle();

int main()
{
	while (true)
	{

		int s, nele, ele;
		cout << "1)inserimento ordinato\n2)conta elementi\n3)stampa\n4)elimina elemento\n5)elimina lista\n6)esci\nselezione:";
		cin >> s;

		switch (s)
		{
		case 1:
		{
			cin >> ele;
			InjectMiddle(ele);
			Stampa();
			break;
		}
		case 2:
		{
			cout <<"gli elementi sono: " <<ContaEle(); 
			system("pause>nul");
			break;
		}
		case 3:
		{
			Stampa();
			break;
		}		
		case 4:
		{
			cout << "dammi l elemento da togliere: ";
			cin >> ele;
			RimozioneEle(ele);
			Stampa();
			break;
		}
		case 5:
		{
			EliminaLista();
			break;
		}
		case 6:
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
void InjectStart(int add)
{
	Nodo* temp = primo;
	primo = new Nodo;
	primo->next = temp;
	primo->num = add;
}
void InjectMiddle(int add)
{
	if (primo != nullptr)
	{
		Nodo* temp = primo;
		Nodo* temp2 = nullptr;
		Nodo* p = new Nodo;
		p->next = nullptr;
		p->num = add;
		do
		{
			if (temp->next != nullptr)
			{
				if (p->num > temp->num)
				{
					temp2 = temp;
					temp = temp->next;
				}
				else
				{
					if (temp2 != nullptr)
					{
						temp2->next = p;
						p->next = temp;
						break;
					}
					else
					{
						InjectStart(add);
						break;
					}
				}
			}
			else
			{
				if (p->num >= temp->num)
					InjectEnd(add);
				else if (p->num < temp->num)
				{
					if (primo->next != nullptr)
					{
						temp2->next = p;
						p->next = temp;
					}
					else
						InjectStart(add);
				}
				else
					InjectStart(add);
				break;
			}
		} while (temp !=nullptr);
	}
	else
		InjectStart(add);
}
void InjectEnd(int add) 
{
	if (primo != nullptr)
	{
		Nodo* temp=primo;
		while (temp->next != nullptr)
			temp = temp->next;
		temp->next = new Nodo;
		temp->next->next = nullptr;
		 temp->next->num = add;
	}
	else
		InjectStart(add);
}
void Stampa()
{
	if (primo != nullptr)
	{
		cout << "Lista:\n";
		Nodo* temp = primo;
		while (temp->next != nullptr)
		{
			cout << temp->num << " ";
			temp = temp->next;
		}
		cout << temp->num;
	}
	else
		cout<<"la lista e' vutota";
	system("pause>nll");
}
void EliminaLista()
{
	if (primo != nullptr)
	{
		delete(primo);
		primo = nullptr;
	}
	cout<<"lista eliminata con sucesso";
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
int ContaEle()
{
	if (primo != nullptr)
	{
		int s = 0;
		Nodo* temp = primo;
		while (temp->next != nullptr)
		{
			s++;
			temp = temp->next;
		}
		return s+1;
	}
	else
	{
		return 0;
	}
}
