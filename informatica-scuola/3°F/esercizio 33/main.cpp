//vito Barra
//esercizio 33
/// Leggere una serie di numeri dal file input.txt e scriverne la somma in output.txt
#include <iostream>
#include <fstream>
using namespace std;
fstream F, F1;
void leggi();
void somma();
int main()
{
	leggi();
	system("cls");
	somma();

	system("pause>nul");
	return 0;
}
void leggi()
{
	F.open("input.txt", ios::out | ios::trunc);
	int n, m;
	cout << "quanti numeri vuoi leggere: ";
	cin >> m;
	for (int j = 0; j < m; j++)
	{
		cout << "N" << j + 1 << ": ";
		cin >> n;
		F << n << " ";
	}
	F.clear();
	F.close();
}
void somma()
{
	F.open("input.txt", ios::in);
	F1.open("output.txt", ios::out | ios::trunc);

	if (F.is_open())
	{
		int s = 0, temp;

		F >> temp;
		while (!F.eof())
		{
			s += temp;
			F >> temp;
		}
		F1 << s;
		F.clear();
		F.close();
		F1.clear();
		F1.close();
		cout << "SALVATAGGIO DATI ESEGUITA CON SUCESSO";
	}
	else
		cout << "file di input non trovato";
}
