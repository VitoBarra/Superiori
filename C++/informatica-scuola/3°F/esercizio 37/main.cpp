//Vito Barra
//Esercizio 37
///gestione di una libreria con le seguenti operazioni :
///- creazione archivio
///- inserzione Libro
///- stampa Libro
///- Ricrerca Libro (data,autore)
///- uscita

#include <iostream>
#include <fstream>

using namespace std;



fstream F, F1;



struct Libro
{
	char Titolo[40] = { ' ' };
	char Autore[30] = { ' ' };
	char CasEd[30] = { ' ' };
	char Anno[15] = { ' ' };
};

//int Nlib();
void Reset_F();
void BuildLibro();
void DeconLibro();
void ModifLibro();
void StampaE();
void LeggiLibro();
void Ricerca();


int main()
{
	int s;
//	int Nlib;
//	
//	Nlib=Nlib();
	
	do
	{
		system("cls");

		if (s < 1 || s>8)
			cout << "digita un opsione valida\n";

//		cout <<"numero di libri presenti: "<<Nlib<<endl;	
		cout << "1)Reset archivio\n2)Inserisci un nuovo libro\n3)Elimina un libro\n4)Modifica i dati di un libro";
		cout << "\n5)Stampa elenco\n6)Leggi le info di un libro\n7)Ricerca libro\n8)Esci\nseleziona:\t";

		cin >> s;
		
		
		
		
		
		
		switch (s)
		{
		case 1:
			Reset_F();
			break;

		case 2:
			BuildLibro();
			break;

		case 3:
			DeconLibro();
			break;

		case 4:
			ModifLibro();
			break;

		case 5:
			StampaE();
			break;

		case 6:
			LeggiLibro();
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



//int Nlib()
//{
//F.open("archivio.txt",ios::in);
//
//}
bool RicCon(char conf[] ,char temp[], int a)
{
	bool validita = false;

		for (int j = 0; j < a; j++)
			if (conf[j] != temp[j])
				return false;
				
		return true;
}

void InputData(Libro& con)
{
	bool conr;
	cout << "iserimento dati del Libro\n";

	cin.get();
	cout << "Titolo:";
	cin.get(con.Titolo, 40);
	cin.get();

	cout << "Autore:";
	cin.get(con.Autore, 30);
	cin.get();


    cout << "Casa editrice:";
	cin.get(con.CasEd ,30);
	cin.get();
	 
	cout << "Anno(gg/mm/aaaa):";
	cin.get(con.Anno, 15);
	cin.get();
	
}
void outputData(Libro& con)
{
	cout << endl;
	cout << "Titolo: " << con.Titolo << endl;
	cout << "Autore: " << con.Autore << endl;
	cout << "Casa editrice: " << con.CasEd << endl;
	cout << "Anno: " << con.Anno << endl;
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

void BuildLibro()
{
	F.open("archivio.txt", ios::out | ios::app);

	if (!F)
		cout << "file non trovato";
	else
	{
		Libro con;

		system("cls");
		InputData(con);


		F.write((char*)&con, sizeof(Libro));
		
		cout << "\nil Libro " << con.Titolo << " e' stato aggiunto con successo\nLibri presenti: ";//<<++Nlib;


		F.clear();
		F.close();
		system("pause>nul");
	}

}

void DeconLibro()
{
	system("cls");
	StampaE();

	F.open("archivio.txt", ios::in | ios::out);
	F1.open("temp.txt", ios::out);
	if (!F)
		cout << "file non trovato";
	else
	{
		Libro con;
		char s;
		int pos, end;
		cout << "\nSelezione il Libro da eliminare: ";
		cin >> pos;
		F.seekg(sizeof(Libro) * (pos - 1));
		F.read((char*)&con, sizeof(Libro));


		cin.get();

		cout << "sicuro di voler eliminare il Libro " << con.Titolo << " (y/n):";
		cin >> s;
		if (s == 'y' || s == 'Y')
		{
			F.seekg(0, ios::end);
			end = F.tellg();
			for (int j = 0, n = 0, k = 0;
				j < end; j += sizeof(Libro), k++)
			{
				if (j<sizeof(Libro) * (pos - 1) || j>sizeof(Libro) * (pos - 1))
				{
					F.seekg(sizeof(Libro)*k);
					F.read((char*)&con, sizeof(Libro));

					F1.seekg(sizeof(Libro)*n);
					F1.write((char*)&con, sizeof(Libro));
					n++;
				}
			}
			F.clear();
			F.close();
			F1.clear();
			F1.close();
			remove("archivio.txt");
			rename("temp.txt", "archivio.txt");
			cout << "\nLibro eliminato con successo\nLibri presenti: ";//<<--Nlib;
			system("pause>nul");
		}

	}
	F.clear();
	F.close();
	F1.clear();
	F1.close();
}

void ModifLibro()
{
	system("cls");
	StampaE();
	F.open("archivio.txt", ios::in | ios::out);

	if (!F)
		cout << "file non trovato";
	else
	{

		Libro con;
		int pos;
		cout << "\nSelezione il Libro da modificare: ";
		cin >> pos;

		F.seekg(sizeof(Libro) * (pos - 1));
		F.read((char*)&con, sizeof(Libro));



		system("pause>nul");

		system("cls");

		cout << "dati attuali\n";
		outputData(con);
		cout << "\n\ninizio modifica:\n\n";
		InputData(con);

		F.seekg(sizeof(Libro) * (pos - 1));
		F.write((char*)&con, sizeof(Libro));
		cout << "\ni dati del Libro " << con.Titolo << " sono stati modificati con sucesso";


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
		Libro con;
		int n = 0;

		F.read((char*)&con, sizeof(Libro));
		while (!F.eof())
		{
			cout << ++n << ")" << con.Titolo << endl;
			F.read((char*)&con, sizeof(Libro));
		}
		system("pause>nul");
	}
	F.clear();
	F.close();

}

void LeggiLibro()
{
	system("cls");
	StampaE();
	F.open("archivio.txt", ios::in);

	if (!F)
		cout << "file non trovato";
	else
	{
		Libro con;
		int pos;
		cout << "Selezione il Libro da stampare: ";
		cin >> pos;

		F.seekg(sizeof(Libro) * (pos - 1));
		F.read((char*)&con, sizeof(Libro));
		

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
		Libro con;
		char temp[30]={' '};
		int s;
		system("cls");

		cout << "1)ricerca per autore\n2)ricerca per data\nselezione:\t";
		cin >> s;
		switch (s)
		{
		case 1:
		{
			int pos = 0;
			bool trovato = false;

			cin.get();
			cout << "\nAutore: ";
			cin.get(temp, 30);

			F.read((char*)&con, sizeof(Libro));
			while (!F.eof())
			{
				pos++;
				if (RicCon(con.Autore, temp, 30))
				{
					cout << pos << ")titolo: " << con.Titolo << endl;
					trovato = true;
				}

				F.read((char*)&con, sizeof(Libro));
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
			cout << "\nAnno(gg/mm/aaaa): ";
			cin.get(temp, 15);

			F.read((char*)&con, sizeof(Libro));
			while (!F.eof())
			{
				
				pos++;
				if (RicCon(con.Anno, temp, 15))
				{
					cout << pos << ")titolo: " << con.Titolo << endl;
					trovato = true;
				}

				
				
				F.read((char*)&con, sizeof(Libro));
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
