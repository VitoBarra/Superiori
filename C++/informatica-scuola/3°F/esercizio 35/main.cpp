//Vito Barra
//esercizio 35
///	Gestire un conto corrente con le seguenti operazioni:
///1- Crea e distruggi l'archivio
///2- Inserire un nuovo correntista
///3- Stampare l'elenco dei correntisti
///4- Trovare le informaioni relative ad un conto
///5- Deposito
///6- Prelievo
///7- Uscita 

#include <iostream>
#include <fstream>

using namespace std;



fstream F, F1;

struct Correntista
{
	char Nome[15] = { ' ' };
	char Cognome[15] = { ' ' };
	char Provincia[15] = { ' ' };
	char Citta[15] = { ' ' };
	char Indirizzo[25] = { ' ' };
	float Saldo = 0.0;
	char pas[15] = { ' ' };

};


void Reset_F();
void BuildCon();
void DeconCon();
void ModifCon();
void StampaE();
void LeggiCon();
void Prev();
void Depos();




int main()
{
	int s;
	do
	{


		system("cls");

		if (s < 1 || s>9)
			cout << "digita un opsione valida\n";



		cout << "1)Reset archivio\n2)Apri un nuovo conto\n3)chiudi un conto\n4)Modifica i dati di un Correntista";
		cout << "\n5)Stampa elenco\n6)Leggi le info di un account\n7)Preleva\n8)Deposita\n9)Esci\nseleziona:\t";

		cin >> s;
		switch (s)
		{
		case 1:
			Reset_F();
			break;

		case 2:
			BuildCon();
			break;

		case 3:
			DeconCon();
			break;

		case 4:
			ModifCon();
			break;

		case 5:
			StampaE();
			break;
		case 6:
			LeggiCon();
			break;

		case 7:
			Prev();
			break;

		case 8:
			Depos();
			break;

		case 9:
			return 0;
		}
		system("cls");


	} while (true);

}



bool Pasworld(char pas[])
{
	bool conf = false;
	char s = 'n';
	if (pas[0] != ' ')
	{
		do
		{
			char temp[15] = { ' ' };
			s = 'n';
			cin.get(temp, 15);

			for (int j = 0; j < 15; j++)
			{

				if (temp[j] != pas[j])
				{
					cout << "passworld non corispondente, riprovare?(y/n): "; cin >> s;
					break;
				}
				if (j == 14)
					conf = true;
			}

			if (s == 'y' || s == 'Y')
				cout << "\nriprova: ";
			else if (!conf)
			{
				cout << "\nOPERAZIONE ANNULATA";
				system("pause>nul");
			}

			cin.get();
		} while (s == 'y' || s == 'Y');
	}
	else
		conf = true;

	return conf;
}
void InputData(Correntista& con)
{
	cout << "iserimento dati del Correntista\n";

	cin.get();
	cout << "nome:";
	cin.get(con.Nome, 15);
	cin.get();

	cout << "cognome:";
	cin.get(con.Cognome, 15);
	cin.get();

	cout << "Provincia:";
	cin.get(con.Provincia, 15);
	cin.get();

	cout << "Citta:";
	cin.get(con.Citta, 15);
	cin.get();

	cout << "Indirizzo:";
	cin.get(con.Indirizzo, 25);
	cin.get();
}
void outputData(Correntista& con)
{
	cout << endl;
	cout << "nome: " << con.Nome << endl;
	cout << "cognome: " << con.Cognome << endl;
	cout << "Provincia: " << con.Provincia << endl;
	cout << "Citta: " << con.Citta << endl;
	cout << "Indirizzo: " << con.Indirizzo << endl;
	cout << "\nsaldo: " << con.Saldo << endl;
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

void BuildCon()
{
	F.open("archivio.txt", ios::out | ios::app);

	if (!F)
		cout << "file non trovato";
	else
	{
		Correntista con, tappo;

		system("cls");
		InputData(con);

		cout << "inserisci una pasworld per proteggere l accout (MAX 15):";
		cin.get(con.pas, 15);
		cin.get();

		con.Saldo = 0.0;



		cout << "ridigita la pasworld per conferma: ";
		if (Pasworld(con.pas))
		{
			F.write((char*)&con, sizeof(Correntista));
			cout << "\nil Correntista " << con.Nome << " " << con.Cognome << " e' stato creato con successo";
		}
		else
			cout << "\nERRORE: il Correntista " << con.Nome << " " << con.Cognome << " non e' stato creato";


		F.clear();
		F.close();
		system("pause>nul");
	}

}

void DeconCon()
{
	system("cls");
	StampaE();

	F.open("archivio.txt", ios::in | ios::out);
	F1.open("temp.txt", ios::out);
	if (!F)
		cout << "file non trovato";
	else
	{
		Correntista con;
		char s;
		int pos, end;
		cout << "\nSelezione il correntista da eliminare: ";
		cin >> pos;
		F.seekg(sizeof(Correntista) * (pos - 1));
		F.read((char*)&con, sizeof(Correntista));




		cout << "\naccesso all' account: " << con.Nome << " " << con.Cognome << "\nDigitare la pass: ";

		cin.get();
		if (Pasworld(con.pas))
		{

			cout << "sicuro di voler eliminare l'account " << con.Nome << " " << con.Cognome << " (y/n):";
			cin >> s;
			if (s == 'y' || s == 'Y')
			{
				F.seekg(0, ios::end);
				end = F.tellg();
				for (int j = 0, n = 0, k = 0;
					j < end; j += sizeof(Correntista), k++)
				{
					if (j<sizeof(Correntista) * (pos - 1) || j>sizeof(Correntista) * (pos - 1))
					{
						F.seekg(sizeof(Correntista)*k);
						F.read((char*)&con, sizeof(Correntista));

						F1.seekg(sizeof(Correntista)*n);
						F1.write((char*)&con, sizeof(Correntista));
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

	}
	F.clear();
	F.close();
	F1.clear();
	F1.close();
}

void ModifCon()
{
	system("cls");
	StampaE();
	F.open("archivio.txt", ios::in | ios::out);

	if (!F)
		cout << "file non trovato";
	else
	{

		Correntista con;
		int pos;
		cout << "Selezione il correntista da modificare: ";
		cin >> pos;

		F.seekg(sizeof(Correntista) * (pos - 1));
		F.read((char*)&con, sizeof(Correntista));



		system("pause>nul");
		cout << "accesso all' account: " << con.Nome << " " << con.Cognome << "\nDigitare la pass: ";


		cin.get();
		if (Pasworld(con.pas))
		{
			system("cls");
			cout << "accesso eseguito con successo\n";

			cout << "dati attuali";
			outputData(con);
			cout << "\n\ninizio modifica: \n";
			InputData(con);

			F.seekg(sizeof(Correntista) * (pos - 1));
			F.write((char*)&con, sizeof(Correntista));
			cout << "\ni dati del correntista " << con.Nome << " " << con.Cognome << " sono stati modificati con sucesso";
		}

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
		Correntista con;
		int n = 0;
		F.read((char*)&con, sizeof(Correntista));
		while (!F.eof())
		{
			cout << ++n << ")nome: " << con.Nome << " " << con.Cognome << endl;
			F.read((char*)&con, sizeof(Correntista));
		}

		system("pause>nul");
	}
	F.clear();
	F.close();

}

void LeggiCon()
{
	system("cls");
	StampaE();
	F.open("archivio.txt", ios::in);

	if (!F)
		cout << "file non trovato";
	else
	{
		Correntista con;
		int pos;
		cout << "Selezione il correntista da stampare: ";
		cin >> pos;

		F.seekg(sizeof(Correntista) * (pos - 1));
		F.read((char*)&con, sizeof(Correntista));

		cout << "accesso all' account: " << con.Nome << " " << con.Cognome << "\nDigitare la pass: ";

		cin.get();
		if (Pasworld(con.pas))
		{
			system("cls");
			cout << "accesso eseguito con successo\n";
			outputData(con);
		}

	}
	F.clear();
	F.close();
}

void Prev()
{
	system("cls");
	StampaE();
	F.open("archivio.txt", ios::in | ios::out);

	if (!F)
		cout << "file non trovato";
	else
	{
		Correntista con;
		int pos;
		float pre;
		cout << "Selezione il correntista da cui prelevare: ";
		cin >> pos;

		F.seekg(sizeof(Correntista) * (pos - 1));
		F.read((char*)&con, sizeof(Correntista));

		cout << "accesso all' account: " << con.Nome << " " << con.Cognome << "\nDigitare la pass: ";

		cin.get();
		if (Pasworld(con.pas))
		{
			system("cls");
			cout << "accesso eseguito con successo\n";
			cout << "\nil tuo saldo attuale e': " << con.Saldo << endl;
			cout << "quanto si vuole prelevare: "; cin >> pre;
			if (con.Saldo >= pre)
				con.Saldo -= pre;
			else
				cout << "non hai abastanza soldi sul conto per prelevare";

			cout << "\nil tuo saldo attuale e': " << con.Saldo;
			F.seekg(sizeof(Correntista) * (pos - 1));
			F.write((char*)&con, sizeof(Correntista));
		}
		else
			cout << "accesso negato";
		system("pause>nul");

	}
	F.clear();
	F.close();
}

void Depos()
{
	system("cls");
	StampaE();
	F.open("archivio.txt", ios::in | ios::out);

	if (!F)
		cout << "file non trovato";
	else
	{
		Correntista con;
		int pos;
		float dep;
		cout << "Selezione il correntista su cui depositare: ";
		cin >> pos;

		F.seekg(sizeof(Correntista) * (pos - 1));
		F.read((char*)&con, sizeof(Correntista));

		cout << "accesso all' account: " << con.Nome << " " << con.Cognome << "\nDigitare la pass: ";

		cin.get();
		if (Pasworld(con.pas))
		{
			system("cls");
			cout << "accesso eseguito con successo\n";
			cout << "\nil tuo saldo attuale e': " << con.Saldo << endl;
			cout << "quanto si vuole depositare: "; cin >> dep;
			con.Saldo += dep;
			cout << "\nil tuo saldo attuale e': " << con.Saldo;
			F.seekg(sizeof(Correntista) * (pos - 1));
			F.write((char*)&con, sizeof(Correntista));
		}
		else
			cout << "accesso negato";
		system("pause>nul");

	}
	F.clear();
	F.close();
}