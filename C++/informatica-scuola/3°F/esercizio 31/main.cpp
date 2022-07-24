//Vito Barra
//esercizio 31
///Caricare con un programma in un file nome, cognome e numero di assenze di n alunni. Scrivere poi in un secondo file 
///di testo nome cognome e assenze degli alunni il cui numero di assenze è superiore alla media degli inseriti
#include <iostream>
#include <fstream>

using namespace std;

fstream F, F1;

struct Alunno
{
	char Nome[15]{ ' ' };
	char Cognome[15]{ ' ' };
	int Assen;
};

void CaricaF();
float Med();
void Smista(float);

int main()
{
	CaricaF();
	Smista(Med());
	cout << "SALVATAGGIO DATI RIUSCITO";

	system("pause>nul");
	return 0;
}

void InputData(Alunno& alu)
{

	cout << "iserimento dati del alunno\n";

	cin.get();
	cout << "\nnome: ";
	cin.get(alu.Nome, 15);
	cin.get();

	cout << "cogmome: ";
	cin.get(alu.Cognome, 15);
	cin.get();

	cout << "numero di assenze: ";
	cin >> alu.Assen;
	cout << endl;

}

void CaricaF()
{
	F.open("Elenco.txt", ios::out | ios::trunc);

	Alunno alu;
	int n = 0;


	system("cls");
	cout << "quanti alunni vuoi aggiungere: ";
	cin >> n;
	for (int j = 0; j < n; j++)
	{
		InputData(alu);
		system("cls");
		F.write((char*)&alu, sizeof(Alunno));
	}
	F.clear();
	F.close();
}

float Med()
{
	F.open("Elenco.txt", ios::in);
	if (F.is_open())
	{
		Alunno alu;
		float s = 0;
		int n = 0;
		F.read((char*)&alu, sizeof(Alunno));
		while (!F.eof())
		{
			n++;
			s += alu.Assen;
			F.read((char*)&alu, sizeof(Alunno));
		}

		F.clear();
		F.close();
		return s / n;

	}
	else
		cout << "Elenco non trovato";


}

void Smista(float M)
{
	F.open("Elenco.txt", ios::in);
	F1.open("ElencoASM.txt", ios::out | ios::trunc);

	if (F.is_open())
	{
		Alunno  alu;

		F.read((char*)&alu, sizeof(Alunno));
		while (!F.eof())
		{
			if (alu.Assen > M)
				F1.write((char*)&alu, sizeof(Alunno));


			F.read((char*)&alu, sizeof(Alunno));
		}


		F1.clear();
		F1.close();
		F.clear();
		F.close();
	}
	else
		cout << "\nl elenco non e' stato trovato";

}
