//Vito Barra
//Esercizio 14
///albero binario
///- inserimento elemento
///- stampa in order
///- esci

#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
using namespace std;


struct Nodo
{
	Nodo* sx;
	string nome_cogome;
	string numero;
	string email;
	Nodo* dx;
};

fstream fin;

Nodo* root = nullptr;


void AddEleTree(Nodo);
void StampaInOrder(Nodo*);

int main()
{
	while (true)
	{
		
		int s;
		cout << "1)inserimento albero\n";
		cout << "2)input file\n";
		cout << "3)Stampa in-order \n";
		cout << "4)esci\n";
		cout << "Seleziona:\n";
		cin >> s;
		switch (s)
		{
		case 1:
		{
			fin.open("Input.txt", ios::out | ios::app);
			Nodo Nodetemp;
			int n;
			cout << "quanti elementi: ";
			cin >> n;
			cin.get();
			for (int j = 0; j < n; j++)
			{
				cout << "\n-------------------\n";
				cout << "\nN" << j + 1 << ":\n";
				cout << "nome: ";
				getline(cin, Nodetemp.nome_cogome);
				cout << "numero: ";
				getline(cin, Nodetemp.numero);
				cout << "email: ";
				getline(cin, Nodetemp.email);
				cout << "\n-------------------\n";
				fin.write((char*)&Nodetemp, sizeof(Nodetemp));

				AddEleTree(Nodetemp);
			}
				fin.clear();
				fin.close();
				break;
		}
		case 2:
		{
			fin.open("input.txt", ios::in);
			if (fin.is_open())
			{
				Nodo Nodetemp;
				int j = 0;
				fin.read((char*)&Nodetemp, sizeof(Nodetemp));
				while (!fin.eof())
				{
					cout << "\n-------------------\n";
					cout << "\nN" << 1 + j << ":\n";
					cout << "nome: " << Nodetemp.nome_cogome<<endl;
					cout << "numero: " << Nodetemp.numero << endl;
					cout << "email: " << Nodetemp.email << endl;
					cout << "\n-------------------\n";

					AddEleTree(Nodetemp);
					j++;
					fin.read((char*)&Nodetemp, sizeof(Nodetemp));
				}
			}
			fin.clear();
			fin.close();
			break;
		}
		case 3:
			StampaInOrder(root);
			system("pause>nul");
			break;
		case 4:
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



Nodo* GeneraNodo(Nodo add)
{
	Nodo* temp = new  Nodo;
	temp->sx = nullptr;
	temp->nome_cogome = add.nome_cogome;
	temp->numero = add.numero;
	temp->email = add.email;
	temp->dx = nullptr;
	return temp;
}



string Upper(string str)
{
	string temp="";
	for (int j = 0; j < str.length(); j++)
		temp += toupper(str[j]);
	return temp;
}


void AddEleTree(Nodo add)
{
	Nodo* temp = root;

	if (temp != nullptr)
	{
		while (true)
		{
			if (Upper(temp->nome_cogome) > Upper(add.nome_cogome) && temp->sx != nullptr)
				temp = temp->sx;
			else if (Upper(temp->nome_cogome) > Upper(add.nome_cogome))
			{
				temp->sx = GeneraNodo(add);
				break;
			}
			else if (Upper(temp->nome_cogome) < Upper(add.nome_cogome) && temp->dx != nullptr)
				temp = temp->dx;
			else if (Upper(temp->nome_cogome) < Upper(add.nome_cogome))
			{
				temp->dx = GeneraNodo(add);
				break;
			}
			else
				break;
		}
	}
	else
	{
		root = GeneraNodo(add);
	}
}

void StampaInOrder(Nodo* tempRic)
{
	if (tempRic != nullptr)
	{
		StampaInOrder(tempRic->sx);
		cout << "\n-------------------\n";
		cout << "nome:" << tempRic->nome_cogome << "\nNumero: " << tempRic->numero << "\nEmail: " << tempRic->email;
		cout << "\n-------------------\n";

		StampaInOrder(tempRic->dx);
	}
}
