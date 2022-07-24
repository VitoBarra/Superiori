//Vito Barra
//esercizio 32
///Gestione di una rubrica telefonica tramite file di testo
#include <iostream>
#include <fstream>

using namespace std;

fstream F;
fstream F1;

struct persona
{

	char  Numero[15]{ ' ' };
	char Nome[30]{ ' ' };
	char  Ind[30]{ ' ' };
};

void RESET();
void StampaE();
void CaricaS();
void StampaS();
void EliminaC();


int main()
{

	int S;
	do
	{
		system("cls");

		cout << "1)resetta rubrica\n2)elenco contatti\n3)carica il contatto\n4)Leggi un contatto\n5)elimina contatto\n6)esci\nche vuoi fare: ";
		cin >> S;
		switch (S)
		{
		case 1:
			RESET();
			break;
		case 2:
			StampaE();
			break;
		case 3:
			CaricaS();
			break;

		case 4:
			StampaS();
			break;
		case 5:
			EliminaC();
			break;
		case 6:
			return 0;
			break;
		}
	} while (true);
}


void RESET()
{
	F.open("rubrica.txt", ios::out);
	F.clear();
	F.close();
	cout << "RUBRICA RESETTATA CON SUCCESSO";
	system("pause>nul");
	system("cls");
}

void StampaE()
{
	F.open("rubrica.txt", ios::in);

	if (F.is_open())
	{
		system("cls");
		persona con;
		int c = 0;
		cout << "contatti sulla tua rubrica:\n";
		F.read((char*)&con, sizeof(persona));
		while (!F.eof())
		{
			cout << ++c<< ")nome: " << con.Nome << endl;
			F.read((char*)&con, sizeof(persona));
		}
		system("pause>nul");
		F.clear();
		F.close();
	}
		
	else
		cout << "file non trovato";
	

}
void CaricaS()
{
	F.open("rubrica.txt", ios::out|ios::app);
	persona con;
	int n;
	system("cls");
	cout << "\nquanti contatti vuoi aggiungere: ";
	cin >> n;
	
	for (int j = 0; j<n; j++)
	{
		
		cin.get();
		cout << "Nome e cognome:\t";
		cin.get(con.Nome, 30);
		cin.get();
		cout << "Numero:\t";
		cin.get(con.Numero, 15);
		cin.get();
		cout << "Indirizzo:\t";
		cin.get(con.Ind, 30);
		cin.get();

		F.write((char*)&con, sizeof(persona));
	}
	F.clear();
	F.close();
}

void StampaS()
{

	StampaE();
	F.open("rubrica.txt", ios::in);
	if (F.is_open())
	{
		persona con;
		int pos;
		cout << "\nqueale contatto vuoi leggere: ";
		cin >> pos;

		F.seekg(sizeof(persona)*(pos - 1));
		F.read((char*)&con, sizeof(persona));


		cout << "\nNome e cognome:\t" << con.Nome<<endl;
		cout << "Numero:\t" << con.Numero << endl;
		cout << "Indirizzo:\t" << con.Ind << endl;
		system("pause>nul");


		F.clear();
		F.close();
	}
	else
		cout << "non esiste nessuna rubrica";
}

void EliminaC()
{
	system("cls");
	StampaE();

	F.open("rubrica.txt", ios::in | ios::out);
	F1.open("temp.txt", ios::out);
	if (F.is_open())
	{
		persona con;
		char s;
		int pos, end;
		cout << "\nSelezione il contatto da eliminare: ";
		cin >> pos;
		F.seekg(sizeof(persona) * (pos - 1));
		F.read((char*)&con, sizeof(persona));

		cin.get();

		cout << "sicuro di voler eliminare il contatto " << con.Nome << " (y/n):";
		cin >> s;
		if (s == 'y' || s == 'Y')
		{
			F.seekg(0, ios::end);
			end = F.tellg();
			for (int j = 0, n = 0, k = 0;
				j < end; j += sizeof(persona), k++)
			{
				if (j<sizeof(persona) * (pos - 1) || j>sizeof(persona) * (pos - 1))
				{
					F.seekg(sizeof(persona)*k);
					F.read((char*)&con, sizeof(persona));

					F1.seekg(sizeof(persona)*n);
					F1.write((char*)&con, sizeof(persona));
					n++;
				}
			}
			F.clear();
			F.close();
			F1.clear();
			F1.close();
			remove("rubrica.txt");
			rename("temp.txt", "rubrica.txt");
			cout << "\ncontatto eliminato con successo";
			system("pause>nul");
		}
		else
			cout << "\noperazione annulata";
		F.clear();
		F.close();
		F1.clear();
		F1.close();

	}
	else
		cout << "rubrica non esistente";
}