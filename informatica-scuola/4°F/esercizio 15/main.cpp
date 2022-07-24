//Vito Barra
//Esercizio 15
///media valutazioni struttura a puntatori
///- input
///- media
///- esci

#include <iostream>

using namespace std;


struct Node
{
	float voto;
	Node* next;
};


Node* primo =  nullptr;


void Push();
float Media();

int main()
{
	int n;
	while (true)
	{
		system("cls");
		cout << "1)carica voto\n2)calcola media\n3)esci\n\nselezione: ";
		cin >> n;
		switch (n)
		{
		case 1:
			Push();
			break;
		case 2:
			cout << "\n\nla media e': " << Media();
			system("pause>nul");
			break;
		case 3:
			return 0;
			break;
		default:
			cout << "comando non disponibile";
			break;
		}
	}
}



Node* NodeDataPack()
{
	Node* temp = new Node;
	cout << "\nvoto:";
	cin >> temp->voto;
	return temp;
}

void Push()
{
	if (primo == nullptr)
	{
		primo = NodeDataPack();
		primo->next = nullptr;
	}
	else
	{
		Node* temp = NodeDataPack();
		temp->next = primo;
		primo = temp;
	}
}



float Media()
{
	if (primo != nullptr)
	{
		float media = 0;
		int n = 0;
		for (Node*temp = primo; temp != nullptr; temp = temp->next)
		{
			media += temp->voto;
			n++;
		}
		return media/n;
	}
	else
		cout << "la lista non esiste";
}
