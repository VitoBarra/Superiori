//Vito Barra
//Esercizio 36
///gestione di una cineteca con le seguenti operazioni :
///- creazione archivio
///- inserzione film
///- stampa film
///- confronto film
///- filmografia regista
///- stampa tutti i film con un numero n di stelle
///- uscita

#include <iostream>
#include <fstream>

using namespace std;



fstream F, F1;

struct Film
{
	char Titolo[15] = { ' ' };
	char Regista[30] = { ' ' };
	char Voto[5] = { ' ' };
};


void Reset_F();
void BuildFilm();
void DeconFilm();
void ModifFilm();
void StampaE();
void LeggiFilm();
void Ricerca();


int main()
{
	int s;
	do
	{


		system("cls");
	

		if (s < 1 || s>8)
			cout << "digita un opsione valida\n";


		cout << "1)Reset archivio\n2)Inserisci un nuovo film\n3)Elimina un film\n4)Modifica i dati di un Film";
		cout << "\n5)Stampa elenco\n6)Leggi le info di un film\n7)Ricerca film\n8)Esci\nseleziona:\t";

		cin >> s;
		




		cin >> s;
		switch (s)
		{
		case 1:
			Reset_F();
			break;

		case 2:
			BuildFilm();
			break;

		case 3:
			DeconFilm();
			break;

		case 4:
			ModifFilm();
			break;

		case 5:
			StampaE();
			break;

		case 6:
			LeggiFilm();
			break;

		case 7:
			Ricerca();
			break;
		case 8:
			return 0;
		}
		system("cls");


	} while (true);

}


bool RicCon(char conf[] ,char temp[], int a)
{
	bool validita = false;

		for (int j = 0; j < a; j++)
		{
			if (conf[j] != temp[j])
				return false;
			if (j == a-1)
				return true;
		}
		cin.get();
}

void InputData(Film& con)
{
	bool conr;
	cout << "iserimento dati del Film\n";

	cin.get();
	cout << "Titolo:";
	cin.get(con.Titolo, 15);
	cin.get();

	cout << "Regista:";
	cin.get(con.Regista, 30);
	cin.get();

	cout << "Voto:";
	cin.get(con.Voto, 5);
	cin.get();
	
	
}
void outputData(Film& con)
{
	cout << endl;
	cout << "Titolo: " << con.Titolo << endl;
	cout << "CogTitolo: " << con.Regista << endl;
	cout << "Voto: " << con.Voto << endl;
	system("pause>nul");
}



void Reset_F()
{
	F.open("archivio.txt", ios::out);
	F.clear();
	F.close();
	system("cls");
	cout << "ARCHIVIO RESETTATO CON SUCCESSO";
	system("pause>nul");
}

void BuildFilm()
{
	F.open("archivio.txt", ios::out | ios::app);

	if (!F)
		cout << "file non trovato";
	else
	{
		Film con;

		system("cls");
		InputData(con);


		F.write((char*)&con, sizeof(Film));
		cout << "\nil Film " << con.Titolo << " e' stato aggiunto con successo";


		F.clear();
		F.close();
		system("pause>nul");
	}

}

void DeconFilm()
{
	system("cls");
	StampaE();

	F.open("archivio.txt", ios::in | ios::out);
	F1.open("temp.txt", ios::out);
	if (!F)
		cout << "file non trovato";
	else
	{
		Film con;
		char s;
		int pos, end;
		cout << "\nSelezione il Film da eliminare: ";
		cin >> pos;
		F.seekg(sizeof(Film) * (pos - 1));
		F.read((char*)&con, sizeof(Film));


		cin.get();

		cout << "sicuro di voler eliminare il film " << con.Titolo << " (y/n):";
		cin >> s;
		if (s == 'y' || s == 'Y')
		{
			F.seekg(0, ios::end);
			end = F.tellg();
			for (int j = 0, n = 0, k = 0;
				j < end; j += sizeof(Film), k++)
			{
				if (j<sizeof(Film) * (pos - 1) || j>sizeof(Film) * (pos - 1))
				{
					F.seekg(sizeof(Film)*k);
					F.read((char*)&con, sizeof(Film));

					F1.seekg(sizeof(Film)*n);
					F1.write((char*)&con, sizeof(Film));
					n++;
				}
			}
			F.clear();
			F.close();
			F1.clear();
			F1.close();
			remove("archivio.txt");
			rename("temp.txt", "archivio.txt");
			cout << "\naccount eliminato con successo";
			system("pause>nul");
		}

	}
	F.clear();
	F.close();
	F1.clear();
	F1.close();
}

void ModifFilm()
{
	system("cls");
	StampaE();
	F.open("archivio.txt", ios::in | ios::out);

	if (!F)
		cout << "file non trovato";
	else
	{

		Film con;
		int pos;
		cout << "\nSelezione il Film da modificare: ";
		cin >> pos;

		F.seekg(sizeof(Film) * (pos - 1));
		F.read((char*)&con, sizeof(Film));



		system("pause>nul");

		system("cls");

		cout << "dati attuali\n";
		outputData(con);
		cout << "\n\ninizio modifica:\n\n";
		InputData(con);

		F.seekg(sizeof(Film) * (pos - 1));
		F.write((char*)&con, sizeof(Film));
		cout << "\ni dati del Film " << con.Titolo << " sono stati modificati con sucesso";


		F.clear();
		F.close();
		system("pause>nul");
	}


}

void StampaE()
{
	F.open("archivio.txt", ios::in);

	if (!F)
		cout << "file non trovato";
	else
	{
		system("cls");
		Film con;
		int n = 0;

		F.read((char*)&con, sizeof(Film));
		while (!F.eof())
		{
			cout << ++n << ")Titolo: " << con.Titolo << endl;
			F.read((char*)&con, sizeof(Film));
		}
		system("pause>nul");
	}
	F.clear();
	F.close();

}

void LeggiFilm()
{
	system("cls");
	StampaE();
	F.open("archivio.txt", ios::in);

	if (!F)
		cout << "file non trovato";
	else
	{
		Film con;
		int pos;
		cout << "Selezione il Film da stampare: ";
		cin >> pos;

		F.seekg(sizeof(Film) * (pos - 1));
		F.read((char*)&con, sizeof(Film));

		cin.get();

		system("cls");
		outputData(con);

	}
	F.clear();
	F.close();
}

void Ricerca()
{
	F.open("archivio.txt", ios::in);
	if (F.is_open())
	{
		Film con;
		char temp[30]{' '};
		int s;
		system("cls");

		cout << "1)ricerca per regista\n2)ricerca per voto\nselezione:\t";
		cin >> s;
		switch (s)
		{
		case 1:
		{
			int pos = 0;
			bool trovato = false;

			cin.get();
			cout << "\nRegista: ";
			cin.get(temp, 30);

			F.read((char*)&con, sizeof(Film));
			while (!F.eof())
			{
				pos++;
				if (RicCon(con.Regista, temp, 30))
				{
					cout << pos << ")titolo: " << con.Titolo << endl;
					trovato = true;
				}

				F.read((char*)&con, sizeof(Film));
			}

			if (!trovato)
				cout << "non e' stato trovato nulla";
			cin.get();
			system("pause>nul");
			break;
		}


		case 2:
		{
			int pos = 0;
			bool trovato = false;

			cin.get();
			cout << "\nVoto: ";
			cin.get(temp, 5);

			F.read((char*)&con, sizeof(Film));
			while (!F.eof())
			{
				
				pos++;
				if (RicCon(con.Voto, temp, 5))
				{
					cout << pos << ")titolo: " << con.Titolo << endl;
					trovato = true;
				}

				
				
				F.read((char*)&con, sizeof(Film));
			}
			cin.get();
			if (!trovato)
				cout << "non e' stato trovato nulla";
			system("pause>nul");
			break;
		}

		}
		F.clear();
		F.close();
	}
}
