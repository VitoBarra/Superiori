#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>

using namespace std;



fstream f;

struct Node
{
	char nome[20];
	char cognome[20];
	int voto;
	Node* next;
};





struct TabAlunni
{
	int voti[20];
	string nome;
};





Node* primo = NULL;



void AggPre();
void Preleva();
void Stampa();
void ReadToFile();

int main()
{
	TabAlunni alunni[20];



TabAlunni alunni[30];
int n;
	while(true)
	{
		system("clear");
		cout<<"1)aggiungi prenotazione\n2)interroga\n3)Stampa\n4)esci\nSelezione: ";
		cin>>n;
		switch(n)
		{
			case 1:
			AggPre();
			break;
			case 2:
			Preleva();
			break;
			case 3:
			Stampa();
			break;
			case 4:
			return 0;
			break;
			default:
			cout<<"opsione non valida";
			break;
		}
	}
}



Node* DataPack()
{
	Node* temp= new Node;
	cout<<"\ndammi il nome:";
	cin.get();
	cin.get(temp->nome,20);
	cout<<"dammi il cognome:";
	cin.get();
	cin.get(temp->cognome,20);
	temp->next=NULL;
	return temp;
}


void AggPre()
{
	if(primo==NULL)
	primo = DataPack();
	else
	{	
		Node* temp;
		for(temp=primo; temp->next !=NULL; temp =temp->next);
		temp ->next =DataPack();
	}
}


void Preleva()
{
	if(primo==NULL)
	{
		cout<<"lista inesistente" ;
		cin.get();cin.get();
	}
	else
	{
		float n;
		cout<<"Voto Avuto: "; 
		cin>>n;
		primo->voto =n;
		primo = primo->next;
	}
}

void Stampa()
{
	if(primo == NULL)
	cout<<"lista inserita";
	else
	{
		for(Node* temp =primo; temp !=NULL ; temp =temp ->next)
		{
			cout<<"\n-----------------------------------";
			cout<<"\nNome: "<<temp->nome;
			cout<<"\ncognome: "<<temp->cognome;
			cout<<"\nvoto: "<<temp->voto; 
			cout<<"\n-----------------------------------";
		}
		cin.get();cin.get();
	}
	
}


void ReadToFile();
{f.open("TabAlunni.txt", ios::in);
if(f.is_open())
{
	f.read((char*)&alunni[0],sizeof(TabAlunni));
for(int i=1;!f.eof;i++)
	{
			f.read((char*)&alunni[i],sizeof(TabAlunni));
	}
}
}
